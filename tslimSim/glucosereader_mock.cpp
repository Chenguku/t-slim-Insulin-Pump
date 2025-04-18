#include "glucosereader_mock.h"
#include <iostream>

GlucoseReader_Mock::GlucoseReader_Mock(){
    currentBG = 6.95;
}

GlucoseReader_Mock::~GlucoseReader_Mock(){}

float GlucoseReader_Mock::getBG(){
    currentBG = readBG_mock();
    return currentBG;
}

void GlucoseReader_Mock::addEffect(const GlucoseEffect &effect){
    effects.push_back(effect);
}

void GlucoseReader_Mock::applyEffects(){
    for(auto it = effects.begin(); it != effects.end();){
        currentBG += it->changePerTick;
        it->duration--;

        if(it->duration <= 0){
            it = effects.erase(it);
        }
        else{
            it++;
        }
    }
}

GlucoseReader_Sine::GlucoseReader_Sine()
{
    seed = 0;
    amplitude = 5;
    period = 0.5;
    midline = 6.95;
}

GlucoseReader_Sine::GlucoseReader_Sine(float amp, float per, float mid){
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

GlucoseReader_Random::GlucoseReader_Random(){
    currentBG = 7;
}

GlucoseReader_Random::GlucoseReader_Random(float initialBG){
    currentBG = initialBG;
}

float GlucoseReader_Random::readBG_mock(){
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1.5, 1.5);
    float randomNum = dist(gen);
    float updatedBG = currentBG + randomNum;
    return updatedBG;
}

