#ifndef INSULINDELIVERYPROFILE_H
#define INSULINDELIVERYPROFILE_H

#include <string>
#include <QTime>

class InsulinDeliveryProfile
{
    public:
    InsulinDeliveryProfile(float basalRate, float carbRatio, float correctionFactor, float targetGlucose, const QTime& time);

    //print function
    void print() const;

    //getters
    float getBasalRate() const;
    float getCarbRatio() const;
    float getCorrectionFactor() const;
    float getTargetGlucose() const;
    const QTime& getTime() const;

    //setters
    void setBasalRate(float b);
    void setCarbRatio(float c);
    void setCorrectionFactor(float cf);
    void setTargetGlucose(float g);
    void setTime(const QTime& t);

private:
    float basalRate;
    float carbRatio;
    float correctionFactor;
    float targetGlucose;
    QTime time;
};

#endif // INSULINDELIVERYPROFILE_H
