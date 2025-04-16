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

    void adjustBG(float x);
    float basalDelivery(int insulinOnBoard);
    float readBG_mock();

private:
    float currentBloodGlucose;
    Profile *activeProfile;
    GlucoseReader_Mock *mock_reader;
};

#endif // CGM_H
