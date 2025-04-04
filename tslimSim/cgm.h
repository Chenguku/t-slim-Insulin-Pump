#ifndef CGM_H
#define CGM_H


class CGM
{
public:
    CGM(float initialBG);

    float getCurrentBG() const;
    void setCurrentBG(float cbg);

    void increaseBG(float x);
    void decreaseBG(float x);

private:
    float currentBloodGlucose;

};

#endif // CGM_H
