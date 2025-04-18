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

    float basalDelivery(int insulinOnBoard);
    void addEffect(const GlucoseEffect &effect);
    float readBG_mock();
    float predictBG(int ticks);

private:
    float currentBloodGlucose;
    float previousBloodGlucose;
    Profile *activeProfile;
    GlucoseReader_Mock *mock_reader;
};

#endif // CGM_H
