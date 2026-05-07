#include <opencv2/opencv.hpp>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QString>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include <QDoubleValidator>

#include "aritmethic-operations.hpp"
#include "logic-operations.hpp"
#include "transformations.hpp"

#define WIDTH 600
#define HEIGHT 500

cv::Mat operate(const cv::Mat& x1, const cv::Mat& x2, std::string op, double val);

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Image Calculator - Manual Operations");
    window.resize(WIDTH, HEIGHT);

    QVBoxLayout *layout = new QVBoxLayout();
    
    QPushButton *btnA = new QPushButton("Upload Image A");
    QLabel *lblA = new QLabel("No image selected");
    
    QPushButton *btnB = new QPushButton("Upload Image B");
    QLabel *lblB = new QLabel("No image selected");

    QComboBox *opCombo = new QComboBox();
    opCombo->addItem("Addition");
    opCombo->addItem("Subtraction");
    opCombo->addItem("Multiplication");
    opCombo->addItem("Division");
    opCombo->addItem("AND");
    opCombo->addItem("OR");
    opCombo->addItem("Negative (Image A)");
    opCombo->addItem("Translate X (Image A)");
    opCombo->addItem("Translate Y (Image A)");

    QLabel *lblVal = new QLabel("Numeric Value:");
    QLineEdit *inputVal = new QLineEdit();
    QDoubleValidator *validator = new QDoubleValidator();
    inputVal->setValidator(validator);
    inputVal->setPlaceholderText("ej: 50");
    inputVal->setText("50");

    QPushButton *btnRun = new QPushButton("Calculate & Show");
    
    static QString pathA, pathB;

    QObject::connect(btnA, &QPushButton::clicked, [&]() {
        pathA = QFileDialog::getOpenFileName(nullptr, "Select Image A");
        if (!pathA.isEmpty()) lblA->setText(pathA.split("/").last());
    });

    QObject::connect(btnB, &QPushButton::clicked, [&] {
        pathB = QFileDialog::getOpenFileName(nullptr, "Select Image B");
        if (!pathB.isEmpty()) lblB->setText(pathB.split("/").last());
    });

    QObject::connect(btnRun, &QPushButton::clicked, [&]() {
        if (pathA.isEmpty()) {
            QMessageBox::warning(&window, "Error", "Image A is required");
            return;
        }

        cv::Mat a = cv::imread(pathA.toStdString());
        cv::Mat b;
        if (!pathB.isEmpty()) b = cv::imread(pathB.toStdString());

        std::string op = opCombo->currentText().toStdString();
        double val = inputVal->text().toDouble();
        
        if (op != "Negative (Image A)" && op != "Translate X (Image A)" && op != "Translate Y (Image A)" && op != "Grayscale (Image A)" && op != "Threshold (Image A)" && 
            op != "Brightness +50 (Image A)" && op != "Contrast x1.5 (Image A)" &&
            op != "Flip Horizontal (Image A)" && op != "Flip Vertical (Image A)" && op != "Box Blur 3x3 (Image A)" && b.empty()) {
            QMessageBox::warning(&window, "Error", "Image B is required for this operation");
            return;
        }

        cv::Mat result = operate(a, b, op, val);

        if (!result.empty()) {
            cv::imshow("Result", result);
            cv::imwrite("resultado.png", result);
            cv::waitKey(0);
            cv::destroyWindow("Result");
        } else {
            QMessageBox::critical(&window, "Error", "Operation failed. Check image sizes/types.");
        }
    });

    layout->addWidget(new QLabel("Image A:"));
    layout->addWidget(btnA);
    layout->addWidget(lblA);
    layout->addWidget(new QLabel("Image B:"));
    layout->addWidget(btnB);
    layout->addWidget(lblB);
    layout->addWidget(new QLabel("Operation:"));
    layout->addWidget(opCombo);
    layout->addWidget(lblVal);
    layout->addWidget(inputVal);
    layout->addWidget(btnRun);

    window.setLayout(layout);
    window.show();

    return app.exec();
}

cv::Mat operate(const cv::Mat &x1, const cv::Mat &x2, const std::string op, double val) {
    if (op == "Addition") return addition(x1, x2);
    if (op == "Subtraction") return substraction(x1, x2);
    if (op == "Multiplication") return multiplication(x1, x2);
    if (op == "Division") return division(x1, x2);
    if (op == "AND") return and_op(x1, x2);
    if (op == "OR") return or_op(x1, x2);
    if (op == "Negative (Image A)") return negative(x1);
    if (op == "Translate X (Image A)") return translate_x(x1, (int)val);
    if (op == "Translate Y (Image A)") return translate_y(x1, (int)val);
    return cv::Mat();
}
