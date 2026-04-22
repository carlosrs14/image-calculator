#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    cv::Mat minuendo = cv::imread("./images/minuendo.jpeg");
    cv::Mat sustraendo = cv::imread("./images/sustraendo.jpeg");

    if (minuendo.empty() || sustraendo.empty()) {
        return EXIT_FAILURE;
    }

    std::vector<cv::Mat> m_channels, s_channels;
    cv::split(minuendo, m_channels);
    cv::split(sustraendo, s_channels);

    std::vector<cv::Mat> out_channels;
    for (int i = 0; i < 3; i++) {
        out_channels.push_back(m_channels[i] - s_channels[i]);
    }

    cv::Mat out;
    cv::merge(out_channels, out);
    
    cv::namedWindow("minuendo", cv::WINDOW_NORMAL);
    cv::namedWindow("sustraendo", cv::WINDOW_NORMAL);
    cv::namedWindow("resultado", cv::WINDOW_NORMAL);

    cv::imshow("minuendo", minuendo);
    cv::imshow("sustraendo", sustraendo);
    cv::imshow("resultado", out);

    cv::waitKey(0);
    return EXIT_SUCCESS;
}