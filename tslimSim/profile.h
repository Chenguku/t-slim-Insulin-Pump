#ifndef PROFILE_H
#define PROFILE_H


class Profile
{
public:
    Profile(float basalRate, float carbRatio, float correctionFactor, float targetGlucose);

    //print function
    void print() const;

    //getters
    float getBasalRate() const;
    float getCarbRatio() const;
    float getCorrectionFactor() const;
    float getTargetGlucose() const;

    //setters
    void setBasalRate(float b);
    void setCarbRatio(float c);
    void setCorrectionFactor(float cf);
    void setTargetGlucose(float g);

private:
    float basalRate;
    float carbRatio;
    float correctionFactor;
    float targetGlucose;
};

#endif // PROFILE_H
