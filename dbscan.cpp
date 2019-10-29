// Adapted from https://github.com/bowbowbow/DBSCAN/blob/master/clustering.cpp

#include <vector>

using namespace std;

namespace DBSCAN {
    const int NOISE = -2;
    const int NOT_CLASSIFIED = -1;

    class Point {
    public:
        double x, y;
        int neighborsCnt, cluster;

        double getDistSquare(const Point &ot) {
            double a = x - ot.x, b = y - ot.y;
            return a * a + b * b;
        }
    };

    class DBSCAN {
    public:
        int minPts;
        double eps;
        vector<Point> points;
        int size;
        vector<vector<int> > adjPoints;
        vector<bool> visited;
        vector<vector<int> > cluster;
        int clusterIdx;

        DBSCAN(double eps, int minPts, const vector<Point> &points) {
            this->eps = eps;
            this->minPts = minPts;
            this->points = points;
            this->size = (int) points.size();
            adjPoints.resize(size);
            this->clusterIdx = -1;
        }

        void run() {
            checkNearPoints();

            for (int i = 0; i < size; i++) {
                if (points[i].cluster != NOT_CLASSIFIED) continue;

                if (isCoreObject(i)) {
                    dfs(i, ++clusterIdx);
                } else {
                    // Border points have been ignored.
                    points[i].cluster = NOISE;
                }
            }

            cluster.resize(clusterIdx + 1);
            for (int i = 0; i < size; i++) {
                if (points[i].cluster != NOISE) {
                    cluster[points[i].cluster].emplace_back(i);
                }
            }
        }

        void dfs(int now, int c) {
            // Border points have been ignored.
            if (!isCoreObject(now)) return;
            points[now].cluster = c;

            for (auto &next: adjPoints[now]) {
                if (points[next].cluster != NOT_CLASSIFIED) continue;
                dfs(next, c);
            }
        }

        void checkNearPoints() {
            double epsSquare = eps * eps;
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; (points[j].x - points[i].x <= eps) && j < size; j++) {
                    if (points[i].getDistSquare(points[j]) <= epsSquare) {
                        points[i].neighborsCnt++;
                        points[j].neighborsCnt++;
                        adjPoints[i].emplace_back(j);
                        adjPoints[j].emplace_back(i);
                    }
                }
            }
        }

        bool isCoreObject(int idx) {
            return points[idx].neighborsCnt >= minPts;
        }

        vector<vector<int> > getCluster() {
            return cluster;
        }
    };
}


