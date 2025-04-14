#include "glucosereader_sine.h"

GlucoseReader_Sine::GlucoseReader_Sine()
{
    seed = 0;
    amplitude = 10;
    period = 0.5;
    midline = 6.95;
}

int GlucoseReader_Sine::readBG_mock(){
    int bg = amplitude * sin((1 / period) * seed) + midline;
    seed += M_PI / 8;
    return bg;
}
