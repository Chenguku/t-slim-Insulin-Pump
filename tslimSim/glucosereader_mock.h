#ifndef GLUCOSEREADER_MOCK_H
#define GLUCOSEREADER_MOCK_H
#include <cmath>
#include <random>

typedef struct GlucoseEffect{
    float changePerTick;
    int duration;
} GlucoseEffect;

class GlucoseReader_Mock
{
protected:
    float currentBG;
    std::vector<GlucoseEffect> effects;
public:
    GlucoseReader_Mock();
    GlucoseReader_Mock(float initialBG);
    float getBG();
    void addEffect(const GlucoseEffect& effect);
    float applyEffects(float insulinOnBoard);
    virtual ~GlucoseReader_Mock() = 0;
    virtual float readBG_mock() = 0;
};

class GlucoseReader_Sine : virtual public GlucoseReader_Mock
{
protected:
    int seed;
    float amplitude;
    float period;
    float midline;
public:
    GlucoseReader_Sine();
    GlucoseReader_Sine(float initialBG);
    GlucoseReader_Sine(float amp, float per, float mid);
    GlucoseReader_Sine(float amp, float per, float mid, float initialBG);
   float readBG_mock() override;
};

class GlucoseReader_Random : virtual public GlucoseReader_Mock
{
protected:
    std::random_device rd;
public:
    GlucoseReader_Random();
    GlucoseReader_Random(float initialBG);
    float readBG_mock() override;
};

class GlucoseReader_SineVariance : public GlucoseReader_Sine, public GlucoseReader_Random
{
public:
    GlucoseReader_SineVariance();
    GlucoseReader_SineVariance(float amp, float per, float mid, float initialBG);
    float readBG_mock() override;
};

#endif // GLUCOSEREADER_MOCK_H
