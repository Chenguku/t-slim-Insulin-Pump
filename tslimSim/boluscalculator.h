#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H


#include "profile.h"
#include "mainwindow.h"

//define an insulin to carb ratio (1 : 1)
#define ICR 1


class BolusCalculator
{
public:
    BolusCalculator(float c, float bg);


    //getters
    float getCarbValue() const;
    float getBloodGlucose() const;

    float getCarbBolus() const;
    float getCorrectionBolus() const;
    float getTotalBolus() const;
    float getFinalBolus() const;
    float getImmediateBolus() const;
    float getExtendedBolus() const;
    float getBolusRate() const;


    //setters
    void setCarbValue(float c);
    void setBloodGlucose(float bg);


private:
    float carbValue;
    float bloodGlucose;

};

#endif // BOLUSCALCULATOR_H
