#ifndef CGM_H
#define CGM_H

#include "profile.h"

class CGM
{
public:
    CGM(float initialBG);

    bool getStatus() const;

    float getCurrentBG() const;
    void setCurrentBG(float cbg);

    void adjustBG(float x);

private:
    bool isConnected;
    float currentBloodGlucose;
    Profile *activeProfile;
};

#endif // CGM_H
