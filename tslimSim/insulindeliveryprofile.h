#ifndef INSULINDELIVERYPROFILE_H
#define INSULINDELIVERYPROFILE_H

#include <string>

class InsulinDeliveryProfile
{
    public:
    InsulinDeliveryProfile(float basalRate, float carbRatio, float correctionFactor, float targetGlucose, const std::string& time);

    //print function
    void print() const;

    //getters
    float getBasalRate() const;
    float getCarbRatio() const;
    float getCorrectionFactor() const;
    float getTargetGlucose() const;
    const std::string& getTime() const;

    //setters
    void setBasalRate(float b);
    void setCarbRatio(float c);
    void setCorrectionFactor(float cf);
    void setTargetGlucose(float g);
    void setTime(const std::string& t);

private:
    float basalRate;
    float carbRatio;
    float correctionFactor;
    float targetGlucose;
    std::string time;
};

#endif // INSULINDELIVERYPROFILE_H
