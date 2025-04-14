#ifndef PROFILE_H
#define PROFILE_H
#include <iostream>

class Profile
{
public:
    Profile();

    //print function
    void print() const;

    //getters
    float getBasalRate() const;
    float getCarbRatio() const;
    float getCorrectionFactor() const;
    float getTargetGlucose() const;

private:
    std::string name;
    float basalRate;
    float carbRatio;
    float correctionFactor;
    float targetGlucose;
};

#endif // PROFILE_H
