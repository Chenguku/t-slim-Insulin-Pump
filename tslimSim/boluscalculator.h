#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H


#include "profile.h"
#include "insulindeliveryprofile.h"

#include <QString>

#define ICR 1 //insulin to carb ratio (1 : 1)
#define CF  1 //correction factor, 1 unit per mmol/L

//define default values for extended bolus
#define DELIVER_NOW 50
#define DELIVER_LATER 50
#define DEFAULT_DURATION 120


class BolusCalculator
{
public:
    BolusCalculator(float c, float bg, InsulinDeliveryProfile* curProfile, float IOB, int now, int later, QTime duration);


    //getters
    float getCarbValue() const;
    float getBloodGlucose() const;
    InsulinDeliveryProfile* getCurProfile() const;
    float getIOB() const;
    int getNow() const;
    int getLater() const;
    QTime getDuration() const;
    int getDurationMinutes() const;

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
    void setCurProfile(InsulinDeliveryProfile* profile);
    void setIOB(float IOB);
    void setNow(int now);
    void setLater(int later);
    void setDuration(const QTime& duration);


    QString logCalculations() const;
    void populateDefaultValues();


private:
    float carbValue;
    float bloodGlucose;
    InsulinDeliveryProfile* curProfile;
    float IOB;
    int deliverNowPercentage;
    int deliverLaterPercentage;
    QTime duration;
};

#endif // BOLUSCALCULATOR_H
