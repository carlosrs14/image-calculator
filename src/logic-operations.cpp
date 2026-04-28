#include "logic-operations.hpp"
#include <vector>

cv::Mat and_op(const cv::Mat& x1, const cv::Mat& x2) {
    if (x1.empty() || x2.empty() || x1.size() != x2.size()) {
        return cv::Mat();
    }
    cv::Mat out;
    cv::bitwise_and(x1, x2, out);
    return out;
}

cv::Mat negative(const cv::Mat& x) {
    if (x.empty()) return cv::Mat();

    std::vector<cv::Mat> channels;
    cv::Mat out;
    
    cv::split(x, channels);
    int rows = x.rows;
    int cols = x.cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (size_t c = 0; c < channels.size(); c++) {
                channels[c].at<uchar>(i, j) = MAX_PIX - channels[c].at<uchar>(i, j);
            }
        }
    }
    
    cv::merge(channels, out);
    return out;
}
