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
    

private:
    std::string name;
    float basalRate;
    float carbRatio;
    float correctionFactor;
    float targetGlucose;
};

#endif // PROFILE_H
