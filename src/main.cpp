#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QString>

#define WIDTH 800
#define HEIGHT 600

cv::Mat operate(const cv::Mat& x1, const cv::Mat& x2, std::string op);

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *btnA = new QPushButton("Upload Image A");
    QPushButton *btnB = new QPushButton("Upload Image B");
    QLineEdit *opInput = new QLineEdit();
    QPushButton *btnRun = new QPushButton("Calculate");
    
    QString pathA, pathB;

    QObject::connect(btnA, &QPushButton::clicked, [&]() {
        pathA = QFileDialog::getOpenFileName(nullptr, "Image A");
    });

    QObject::connect(btnB, &QPushButton::clicked, [&] {
        pathB = QFileDialog::getOpenFileName(nullptr, "Image B");
    });

    QObject::connect(btnRun, &QPushButton::clicked, [&]() {
        if (pathA.isEmpty() || pathB.isEmpty()) return;

        cv::Mat a = cv::imread(pathA.toStdString());
        cv::Mat b = cv::imread(pathB.toStdString());

        std::string op = opInput->text().toStdString();

        cv::Mat result = operate(a, b, op);

        if (!result.empty()) {
            cv::imwrite("resultado.png", result);
        }
    });

    layout->addWidget(btnA);
    layout->addWidget(btnB);
    layout->addWidget(opInput);
    layout->addWidget(btnRun);

    window.setLayout(layout);
    window.resize(WIDTH, HEIGHT);
    window.show();

    return app.exec();
}

cv::Mat operate(const cv::Mat &x1, const cv::Mat &x2, std::string op) {
    return cv::Mat();
}
