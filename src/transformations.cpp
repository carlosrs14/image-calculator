#include "transformations.hpp"

cv::Mat translate_x(const cv::Mat &m, const long int x) {
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

cv::Mat translate_y(const cv::Mat &m, const long int y) {
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

cv::Mat rotation(const cv::Mat &m, const long int angulo){
    if (m.empty()) return cv::Mat();

    int rows = m.rows;
    int cols = m.cols;

    cv::Mat out = cv::Mat::zeros(rows, cols, m.type());;
    int channels = m.channels();

    int centroX = cols / 2;
    int centroY = rows / 2;
    
    double rad = angulo * (M_PI / 180.0);
    double coseno = std::cos(rad);
    double seno = std::sin(rad);

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {

            int x = j - centroX;
            int y = i - centroY;

            int ni = (int)(-x * seno + y * coseno + centroY);
            int nj = (int)(x * coseno + y * seno + centroX);

            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                for (int c = 0; c < channels; c++) {
                    out.ptr<uchar>(ni)[nj * channels + c]= m.ptr<uchar>(i)[j * channels + c];
                }
            }
        }
    }

    return out;
}
