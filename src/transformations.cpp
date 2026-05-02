#include "transformations.hpp"

cv::Mat translate_x(const cv::Mat &m, size_t x) {
    if (m.empty()) return cv::Mat();

    std::vector<cv::Mat> channels_in, channels_out;
    cv::split(m, channels_in);
    
    channels_out.resize(channels_in.size());
    for (size_t i = 0; i < channels_in.size(); i++) {
        channels_out[i] = cv::Mat::zeros(m.size(), CV_8U);
    }

    int rows = m.rows;
    int cols = m.cols;
    int tx = (int)x;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int nj = j + tx;
            if (nj >= 0 && nj < cols) {
                for (size_t k = 0; k < channels_in.size(); k++) {
                    channels_out[k].at<uchar>(i, nj) = channels_in[k].at<uchar>(i, j);
                }
            }
        }
    }

    cv::Mat out;
    cv::merge(channels_out, out);
    return out;
}

cv::Mat translate_y(const cv::Mat &m, size_t y) {
    if (m.empty()) return cv::Mat();

    std::vector<cv::Mat> channels_in, channels_out;
    cv::split(m, channels_in);
    
    channels_out.resize(channels_in.size());
    for (size_t i = 0; i < channels_in.size(); i++) {
        channels_out[i] = cv::Mat::zeros(m.size(), CV_8U);
    }

    int rows = m.rows;
    int cols = m.cols;
    int ty = (int)y;

    for (int i = 0; i < rows; i++) {
        int ni = i + ty;
        if (ni >= 0 && ni < rows) {
            for (int j = 0; j < cols; j++) {
                for (size_t k = 0; k < channels_in.size(); k++) {
                    channels_out[k].at<uchar>(ni, j) = channels_in[k].at<uchar>(i, j);
                }
            }
        }
    }

    cv::Mat out;
    cv::merge(channels_out, out);
    return out;
}