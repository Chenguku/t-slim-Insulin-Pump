#ifndef GLUCOSEREADER_SINE_H
#define GLUCOSEREADER_SINE_H
#include <cmath>
#include <glucosereader_mock.h>

class GlucoseReader_Sine : private GlucoseReader_Mock
{
    int seed;
    float amplitude;
    float period;
    float midline;
public:
    GlucoseReader_Sine();
   int readBG_mock() override;
};

#endif // GLUCOSEREADER_SINE_H
