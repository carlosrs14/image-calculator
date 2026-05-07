#pragma once
#include <opencv2/opencv.hpp>

cv::Mat translate_x(const cv::Mat& m, const long int x);
cv::Mat translate_y(const cv::Mat& m, const long int y);
cv::Mat rotation(const cv::Mat& m, const long int angulo);
