#ifndef CGM_H
#define CGM_H

#include "profile.h"
#include "glucosereader_mock.h"

class CGM
{
public:
    CGM();
    CGM(float initialBG);

    float getCurrentBG() const;
    void setProfile(Profile *p);
    void setBGReader(GlucoseReader_Mock *r);
    void setInsulinUnits(float units);
    void adjustBG(float x);

    float basalDelivery();
    void addEffect(const GlucoseEffect &effect);
    float readBG_mock();
    float predictBG(int ticks);
    float getIOB();

private:
    float currentBloodGlucose;
    float previousBloodGlucose;
    float insulinUnits;
    Profile *activeProfile;
    GlucoseReader_Mock *mock_reader;
};

#endif // CGM_H
