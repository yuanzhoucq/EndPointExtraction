#include <opencv2/opencv.hpp>

using namespace cv;

// Adapted from OpenCV's adaptiveThreshold method.
void customAdaptiveThreshold(InputArray _src, OutputArray _dst, double maxValue,
                             InputArray _kernel, int type, double delta, double trunc, int offset) {

    Mat src = _src.getMat().clone();
    CV_Assert(src.type() == CV_8UC1);
    CV_Assert(type == THRESH_BINARY || type == THRESH_BINARY_INV);
    Size size = src.size();

    cv::threshold(src, src, trunc, trunc, cv::THRESH_TRUNC);

    _dst.create(size, src.type());
    Mat dst = _dst.getMat();

    if (maxValue < 0) {
        dst = Scalar(0);
        return;
    }

    Mat mean;

    Mat kernel = _kernel.getMat();
    filter2D(src, mean, src.type(), kernel, Point(-1, -1), offset);

    // std::cout << mean.colRange(0,1);

    int i, j;
    uchar imaxval = saturate_cast<uchar>(maxValue);
    int idelta = type == THRESH_BINARY ? cvCeil(delta) : cvFloor(delta);
    uchar tab[768];

    if (type == THRESH_BINARY)
        for (i = 0; i < 768; i++)
            tab[i] = (uchar) (i - 255 > -idelta ? imaxval : 0);
    else // (type == THRESH_BINARY_INV)
        for (i = 0; i < 768; i++)
            tab[i] = (uchar) (i - 255 <= -idelta ? imaxval : 0);

    if (src.isContinuous() && mean.isContinuous() && dst.isContinuous()) {
        size.width *= size.height;
        size.height = 1;
    }

    for (i = 0; i < size.height; i++) {
        const uchar *sdata = src.ptr(i);
        const uchar *mdata = mean.ptr(i);
        uchar *ddata = dst.ptr(i);

        for (j = 0; j < size.width; j++)
            ddata[j] = tab[sdata[j] - mdata[j] + 255];
    }
}
