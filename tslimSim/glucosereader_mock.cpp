#include "glucosereader_mock.h"
#include <iostream>

GlucoseReader_Mock::GlucoseReader_Mock(){}

GlucoseReader_Mock::~GlucoseReader_Mock(){}

GlucoseReader_Sine::GlucoseReader_Sine()
{
    seed = 0;
    amplitude = 5;
    period = 0.5;
    midline = 6.95;
}

GlucoseReader_Sine::GlucoseReader_Sine(float amp, float per, float mid){
   seed = 0;
   amplitude = amp;
   period = per;
   midline = mid;
}

float GlucoseReader_Sine::readBG_mock(){
    float bg = amplitude * sin((1 / period) * (seed * M_PI / 64)) + midline;
    seed++;
    return bg;
}
