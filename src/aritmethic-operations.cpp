#include "aritmethic-operations.hpp"

cv::Mat addition(const cv::Mat& m1, const cv::Mat& m2) {
    if (m1.empty() || m2.empty() || m1.size() != m2.size() || m1.type() != m2.type()) {
        return cv::Mat();
    }

    cv::Mat out = m1.clone();
    int channels = m1.channels();

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            for (int c = 0; c < channels; c++) {
                float val1 = (float) ((int) m1.ptr<uchar>(i)[j * channels + c] * 0.8f);
                float val2 = (float) ((int) m2.ptr<uchar>(i)[j * channels + c] * 0.2f);
                int val = (int) (val1 + val2);
                out.ptr<uchar>(i)[j * channels + c] = (uchar)(val);
            }
        }
    }
    return out;
}

cv::Mat substraction(const cv::Mat& minued, const cv::Mat& subtrahend) {
    if (minued.empty() || subtrahend.empty() || minued.size() != subtrahend.size() || minued.type() != subtrahend.type()) {
        return cv::Mat();
    }

    cv::Mat out = minued.clone();
    int channels = minued.channels();

    for (int i = 0; i < minued.rows; i++) {
        for (int j = 0; j < minued.cols; j++) {
            for (int c = 0; c < channels; c++) {
                int val = (int)minued.ptr<uchar>(i)[j * channels + c] - (int)subtrahend.ptr<uchar>(i)[j * channels + c];
                out.ptr<uchar>(i)[j * channels + c] = (uchar)(val < 0 ? 0 : val);
            }
        }
    }
    return out;
}

cv::Mat multiplication(const cv::Mat& m1, const cv::Mat& m2) {
    if (m1.empty() || m2.empty() || m1.size() != m2.size() || m1.type() != m2.type()) {
        return cv::Mat();
    }

    cv::Mat out = m1.clone();
    int channels = m1.channels();

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            for (int c = 0; c < channels; c++) {
                float v1 = m1.ptr<uchar>(i)[j * channels + c] / 255.0f;
                float v2 = m2.ptr<uchar>(i)[j * channels + c] / 255.0f;
                out.ptr<uchar>(i)[j * channels + c] = (uchar)(v1 * v2 * 255.0f);
            }
        }
    }
    return out;
}

cv::Mat division(const cv::Mat& m1, const cv::Mat& m2) {
    if (m1.empty() || m2.empty() || m1.size() != m2.size() || m1.type() != m2.type()) {
        return cv::Mat();
    }

    cv::Mat out = m1.clone();
    int channels = m1.channels();

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            for (int c = 0; c < channels; c++) {
                uchar v2 = m2.ptr<uchar>(i)[j * channels + c];
                if (v2 == 0) {
                    out.ptr<uchar>(i)[j * channels + c] = MAX_PIX;
                } else {
                    float val = (float)m1.ptr<uchar>(i)[j * channels + c] / (float)v2;
                    val *= 255.0f;
                    out.ptr<uchar>(i)[j * channels + c] = (uchar)(val > MAX_PIX ? MAX_PIX : val);
                }
            }
        }
    }
    return out;
}

cv::Mat escalar(const cv::Mat &m, const double value){
    if (m.empty()) return cv::Mat();
    if(value<0) return cv::Mat();

    cv::Mat out = m.clone();
    int channels = m.channels();

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            for (int c = 0; c < channels; c++) {
                double val= m.ptr<uchar>(i)[j * channels + c] * value;

                if(val>255) val=255;

                out.ptr<uchar>(i)[j * channels + c]=(uchar) val;

            }
        }
    }

    return out;
}

