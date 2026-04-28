#include "logic-operations.hpp"
#include <vector>

cv::Mat and_op(const cv::Mat& x1, const cv::Mat& x2) {
    if (x1.empty() || x2.empty() || x1.size() != x2.size()) {
        return cv::Mat();
    }
    
    std::vector<cv::Mat> x1_channels, x2_channels;
    cv::split(x1, x1_channels);
    cv::split(x2, x2_channels);

    std::vector<cv::Mat> out_channels;
    size_t rows = x1.rows;
    size_t cols = x1.cols;

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            for (size_t c = 0; c < out_channels.size(); c++) {
                uchar pix1 = x1_channels[c].at<uchar>(i, j);
                uchar pix2 = x2_channels[c].at<uchar>(i, j);
                
                out_channels[c].at<uchar>(i, j) = pix1 && pix2 ? MAX_PIX : MIN_PIX; 
            }
        }
    }
    
    cv::Mat out;
    cv::merge(out_channels, out);
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
