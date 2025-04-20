#include "glucosereader_mock.h"
#include <iostream>

GlucoseReader_Mock::GlucoseReader_Mock(){
    currentBG = 6.95;
}

GlucoseReader_Mock::GlucoseReader_Mock(float initialBG){
    currentBG = initialBG;
}

GlucoseReader_Mock::~GlucoseReader_Mock(){}

float GlucoseReader_Mock::getBG(){
    currentBG = readBG_mock();
    return currentBG;
}

void GlucoseReader_Mock::addEffect(const GlucoseEffect &effect){
    effects.push_back(effect);
}

float GlucoseReader_Mock::applyEffects(float possibleBGReduction){
    float bgChange = 0;
    for(auto it = effects.begin(); it != effects.end();){
        if(bgChange + it->changePerTick > possibleBGReduction){
            currentBG -= possibleBGReduction + bgChange;
            bgChange = possibleBGReduction;
            it = effects.erase(it);
            return bgChange;
        }
        currentBG -= it->changePerTick;
        bgChange += it->changePerTick;
        it->duration--;

        if(it->duration <= 0){
            it = effects.erase(it);
        }
        else{
            it++;
        }
    }
    return bgChange;
}

float GlucoseReader_Mock::getIOB(){
    float IOB = 0;
    for (auto it = effects.begin(); it != effects.end(); it++){
        IOB += it->changePerTick * it->duration;
    }
    return IOB;
}

GlucoseReader_Sine::GlucoseReader_Sine()
{
    seed = 0;
    amplitude = 5;
    period = 0.5;
    midline = 6.95;
}

GlucoseReader_Sine::GlucoseReader_Sine(float initialBG): GlucoseReader_Mock(initialBG){}


GlucoseReader_Sine::GlucoseReader_Sine(float amp, float per, float mid){
   seed = 0;
   amplitude = amp;
   period = per;
   midline = mid;
}

GlucoseReader_Sine::GlucoseReader_Sine(float amp, float per, float mid, float initialBG): GlucoseReader_Mock(initialBG) {
   seed = 0;
   amplitude = amp;
   period = per;
   midline = mid;
}


float GlucoseReader_Sine::readBG_mock(){
    float prevIncrement = amplitude * sin((1 / period) * ((seed - 1) * M_PI / 64)) + midline;
    float bgIncrement = amplitude * sin((1 / period) * (seed * M_PI / 64)) + midline;
    seed++;
    float updatedBG = currentBG + bgIncrement - prevIncrement;
    return updatedBG;
}

GlucoseReader_Random::GlucoseReader_Random(){}

GlucoseReader_Random::GlucoseReader_Random(float initialBG): GlucoseReader_Mock(initialBG) {}

float GlucoseReader_Random::readBG_mock(){
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1);
    float randomNum = dist(gen);
    float updatedBG = currentBG + randomNum;
    if(updatedBG < 0){
        updatedBG = 0;
    }
    return updatedBG;
}

GlucoseReader_SineVariance::GlucoseReader_SineVariance(){}

GlucoseReader_SineVariance::GlucoseReader_SineVariance(float amp, float per, float mid, float initialBG): GlucoseReader_Mock(initialBG), GlucoseReader_Sine(amp, per, mid) {}

float GlucoseReader_SineVariance::readBG_mock(){
    float prevIncrement = amplitude * sin((1 / period) * ((seed - 1) * M_PI / 64)) + midline;
    float bgIncrement = amplitude * sin((1 / period) * (seed * M_PI / 64)) + midline;
    seed++;
    float updatedBG = currentBG + bgIncrement - prevIncrement;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-0.5, 1);
    float randomNum = dist(gen);
    updatedBG += randomNum;
    if(updatedBG < 0){
        updatedBG = 0;
    }
    return updatedBG;
}
