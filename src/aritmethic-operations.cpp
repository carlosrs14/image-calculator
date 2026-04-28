#include "aritmethic-operations.hpp"
#include <vector>

cv::Mat substraction(const cv::Mat& minued, const cv::Mat& subtrahend) {
    if (minued.empty() || subtrahend.empty() || minued.size() != subtrahend.size()) {
        return cv::Mat();
    }

    std::vector<cv::Mat> m_channels, s_channels;
    cv::split(minued, m_channels);
    cv::split(subtrahend, s_channels);

    std::vector<cv::Mat> out_channels;
    
    for (size_t i = 0; i < m_channels.size(); i++) {
        out_channels.push_back(m_channels[i] - s_channels[i]);
    }

    cv::Mat out;
    cv::merge(out_channels, out);
    return out;
}
