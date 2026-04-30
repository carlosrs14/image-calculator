#pragma once
#include <opencv2/opencv.hpp>
#ifndef MAX_PIX
    #define MAX_PIX 255
    #define MIN_PIX 0
#endif

cv::Mat and_op(const cv::Mat& x1, const cv::Mat& x2);
cv::Mat or_op(const cv::Mat& x1, const cv::Mat& x2);
cv::Mat negative(const cv::Mat& x);
