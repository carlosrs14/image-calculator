#pragma once
#include <opencv2/opencv.hpp>
#ifndef MAX_PIX
    #define MAX_PIX 255
#endif

cv::Mat addition(const cv::Mat& m1, const cv::Mat& m2);
cv::Mat substraction(const cv::Mat& minued, const cv::Mat& subtrahend);
cv::Mat multiplication(const cv::Mat& m1, const cv::Mat& m2);
cv::Mat division(const cv::Mat& m1, const cv::Mat& m2);
cv::Mat Escalar(const cv::Mat& m,const double value);