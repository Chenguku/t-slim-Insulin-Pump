#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H


#include "profile.h"
#include "insulindeliveryprofile.h"

#define ICR 1 //insulin to carb ratio (1 : 1)
#define CF  1 //correction factor, 1 unit per mmol/L


class BolusCalculator
{
public:
    BolusCalculator(float c, float bg, InsulinDeliveryProfile* curProfile, float IOB);


    //getters
    float getCarbValue() const;
    float getBloodGlucose() const;

    float getFoodBolus() const;
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
    InsulinDeliveryProfile* curProfile;
    float IOB;

};

#endif // BOLUSCALCULATOR_H
