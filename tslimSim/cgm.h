#ifndef CGM_H
#define CGM_H

#include "profile.h"
#include "glucosereader_mock.h"

class CGM
{
public:
    CGM();
    CGM(float initialBG);

    bool getStatus() const;

    float getCurrentBG() const;
    void setCurrentBG(float cbg);
    void setProfile(Profile *p);
    void setBGReader(GlucoseReader_Mock *r);

    void adjustBG(float x);
    float readBG_mock();

private:
    bool isConnected;
    float currentBloodGlucose;
    Profile *activeProfile;
    GlucoseReader_Mock *mock_reader;
};

#endif // CGM_H
