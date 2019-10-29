#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "dbscan.cpp"
#include "customAdaptiveThreshold.cpp"

// Shortcut of displaying image for debug
void imshow(const cv::Mat &src) {
    cv::imshow("img", src);
    cv::waitKey(0);
}

/**
 * Extract all the end points of laser lines from an input image.
 * @param src self-explained parameter.
 * @param endPoints self-explained parameter.
 * @param epsilon `epsilon` and `minPts` are used by DBSCAN algorithm. Briefly, every point inside a laser line must
 *                 have at least `minPts` laser points in its `epsilon`-neighborhood.
 * @param minPts explained above.
 * @param minLineSize the minimum number of points a valid laser must have. The invalid laser lines found by DBSCAN will
 *                    be skipped when locating end points.
 * @param debug if the function prints some debug information or not.
 */
void
extractEndPoints(const cv::Mat &src, std::vector<cv::Point> &endPoints, const int epsilon = 8, const int minPts = 5,
                 const int minLineSize = 200, const bool debug = false) {
    // Timestamp for profiling.
    int64 ts = 0;
    // Make kernel for custom threshold
    cv::Mat kernel = cv::Mat(11, 11, CV_32F, Scalar(0));
    for (int j = 3; j < 8; j++) {
        for (int i = 0; i < 11; i++) {
            kernel.at<float>(j, i) = -2. / 11. / 5.;
        }
    }
    cv::Mat rotateMat = cv::getRotationMatrix2D(cv::Point2f(5, 5), -2, 1);
    cv::warpAffine(kernel, kernel, rotateMat, kernel.size());
    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < 11; i++) {
            if (kernel.at<float>(j, i) > -0.0001) kernel.at<float>(j, i) = 3. / 11. / 6.;
        }
    }
    if (debug) ts = cv::getTickCount();
    cv::Mat binary;
    customAdaptiveThreshold(src, binary, 255, kernel, cv::THRESH_BINARY, -20);
    // Replace the previous line with the next one to compare it with standard adaptive threshold provided by OpenCV.
    // cv::adaptiveThreshold(src, binary, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, -40);

    // Get white points from binary image
    std::vector<cv::Point> locations;
    for (int col = 0; col < src.cols; col++) {
        for (int row = 0; row < src.rows; row++) {
            if (binary.at<uchar>(row, col) > 0) locations.emplace_back(col, row);
        }
    }
    if (debug) std::cout << locations.size() << std::endl;

    std::vector<DBSCAN::Point> points;
    for (auto &p: locations) {
        auto x = (double) p.x, y = (double) p.y;
        points.push_back({x, y, 0, DBSCAN::NOT_CLASSIFIED});
    }
    DBSCAN::DBSCAN scanner = DBSCAN::DBSCAN(epsilon, minPts, points);
    scanner.run();

    for (auto &cluster: scanner.cluster) {
        if (cluster.size() < minLineSize) continue;
        endPoints.push_back(locations[cluster.front()]);
        endPoints.push_back(locations[cluster.back()]);
    }

    if (debug) std::cout << (double) (cv::getTickCount() - ts) / cv::getTickFrequency() << "s\n";
}
