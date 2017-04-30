#include "FilterGreyscale.h"
#include <opencv/cv.h>

FilterGreyscale::FilterGreyscale() {
}

FilterGreyscale::~FilterGreyscale() {
}

QImage FilterGreyscale::process(const QImage &image) {
    // QImage -> cv::Mat
    cv::Mat tmp(image.height(),
        image.width(),
        CV_8UC4,
        (uchar *)image.bits(),
        image.bytesPerLine());

    cv::Mat resultMat;
    cv::cvtColor(tmp,
        resultMat,
        CV_BGR2GRAY);

    // cv::Mat -> QImage
    QImage resultImage((const uchar *)resultMat.data,
        resultMat.cols,
        resultMat.rows,
        resultMat.step,
        QImage::Format_Grayscale8);
    return resultImage.copy();
}
