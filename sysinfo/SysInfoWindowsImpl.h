#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include "SysInfo.h"
#include <QtGlobal>
#include <QVector>

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl : public SysInfo {
public:
    SysInfoWindowsImpl();

    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    // the Windows structure FILEFTIME stores 64-bit information on two 32-bit
    // parts (low and high); use the Windows structure ULARGE_INTEGER to
    // correctly build a 64-bit value in a single part before returning it as a
    // qulonglong type
    qulonglong convertFileTime(const FILETIME &filetime) const;

private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOWSIMPL_H
