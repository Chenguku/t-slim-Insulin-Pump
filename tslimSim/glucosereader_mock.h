#ifndef GLUCOSEREADER_MOCK_H
#define GLUCOSEREADER_MOCK_H
#include <cmath>

class GlucoseReader_Mock
{
public:
    GlucoseReader_Mock();
    virtual ~GlucoseReader_Mock() = 0;
    virtual float readBG_mock() = 0;
};

class GlucoseReader_Sine : public GlucoseReader_Mock
{
    int seed;
    float amplitude;
    float period;
    float midline;
public:
    GlucoseReader_Sine();
    GlucoseReader_Sine(float amp, float per, float mid);
   float readBG_mock() override;
};



#endif // GLUCOSEREADER_MOCK_H
