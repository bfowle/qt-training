#include "CpuWidget.h"
#include "SysInfo.h"

using namespace QtCharts;

CpuWidget::CpuWidget(QWidget *parent) :
    SysInfoWidget(parent),
    mSeries(new QPieSeries(this)) {
    mSeries->setHoleSize(0.35);
    mSeries->append("CPU Load", 0.0);
    mSeries->append("CPU Free", 100.0);

    QChart *chart = chartView().chart();
    chart->addSeries(mSeries);
    chart->setTitle("CPU Average Load");
}

void CpuWidget::updateSeries() {
    double cpuLoadAverage = SysInfo::instance().cpuLoadAverage();
    mSeries->clear();
    mSeries->append("CPU Load", cpuLoadAverage);
    mSeries->append("CPU Free", 100.0 - cpuLoadAverage);
}
