#include "logic-operations.hpp"

cv::Mat and_op(const cv::Mat& x1, const cv::Mat& x2) {
    if (x1.empty() || x2.empty() || x1.size() != x2.size() || x1.type() != x2.type()) {
        return cv::Mat();
    }

    cv::Mat out = x1.clone();
    int channels = x1.channels();

    for (int i = 0; i < x1.rows; i++) {
        for (int j = 0; j < x1.cols; j++) {
            for (int c = 0; c < channels; c++) {
                uchar pix1 = x1.ptr<uchar>(i)[j * channels + c];
                uchar pix2 = x2.ptr<uchar>(i)[j * channels + c];
                out.ptr<uchar>(i)[j * channels + c] = (pix1 & pix2);
            }
        }
    }
    return out;
}

cv::Mat or_op(const cv::Mat& x1, const cv::Mat& x2) {
    if (x1.empty() || x2.empty() || x1.size() != x2.size() || x1.type() != x2.type()) {
        return cv::Mat();
    }

    cv::Mat out = x1.clone();
    int channels = x1.channels();

    for (int i = 0; i < x1.rows; i++) {
        for (int j = 0; j < x1.cols; j++) {
            for (int c = 0; c < channels; c++) {
                uchar pix1 = x1.ptr<uchar>(i)[j * channels + c];
                uchar pix2 = x2.ptr<uchar>(i)[j * channels + c];
                out.ptr<uchar>(i)[j * channels + c] = (pix1 | pix2);
            }
        }
    }
    return out;
}

cv::Mat xor_op(const cv::Mat& x1, const cv::Mat& x2) {
    if (x1.empty() || x2.empty() || x1.size() != x2.size() || x1.type() != x2.type()) {
        return cv::Mat();
    }

    cv::Mat out = x1.clone();
    int channels = x1.channels();

    for (int i = 0; i < x1.rows; i++) {
        for (int j = 0; j < x1.cols; j++) {
            for (int c = 0; c < channels; c++) {
                uchar pix1 = x1.ptr<uchar>(i)[j * channels + c];
                uchar pix2 = x2.ptr<uchar>(i)[j * channels + c];
                out.ptr<uchar>(i)[j * channels + c] = (pix1 ^ pix2);
            }
        }
    }
    return out;
}

cv::Mat negative(const cv::Mat& x) {
    if (x.empty()) return cv::Mat();

    cv::Mat out = x.clone();
    int channels = x.channels();

    for (int i = 0; i < x.rows; i++) {
        for (int j = 0; j < x.cols; j++) {
            for (int c = 0; c < channels; c++) {
                out.ptr<uchar>(i)[j * channels + c] = MAX_PIX - x.ptr<uchar>(i)[j * channels + c];
            }
        }
    }
    return out;
}
