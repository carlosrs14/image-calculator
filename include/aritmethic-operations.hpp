#pragma once
#include <opencv2/opencv.hpp>
#ifndef MAX_PIX
    #define MAX_PIX 255
#endif

cv::Mat substraction(const cv::Mat& minued, const cv::Mat& subtrahend);
