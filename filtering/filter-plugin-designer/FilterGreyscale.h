#ifndef FILTERGREYSCALE_H
#define FILTERGREYSCALE_H

#include "Filter.h"

class FilterGreyscale : public Filter {
public:
    FilterGreyscale();
    ~FilterGreyscale();

    QImage process(const QImage &image) override;
};

#endif // FILTERGREYSCALE_H
