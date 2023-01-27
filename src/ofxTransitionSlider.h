//
//  TransitionSlider.hpp
//  ExampleTransitionSlider
//
//  Created by Matteo on 27/07/2019.
//

#ifndef TransitionSlider_hpp
#define TransitionSlider_hpp

#include <stdio.h>
#include "ofxSlider.h"

template<typename Type>
class ofxTransitionSlider{

public:
    double operator=(Type v);
    operator const float & ();
    
    ofxTransitionSlider();
    
    ofxBaseGui * setup(std::string _name, Type _value, Type _min, Type _max);
    Type getValue() { return value; };
    float getTransitionPct(){return transitionPct; };
    void update(float _transitionDuration = -1.0);
	void jumpToFinalValue();                                            //stop the transition and jump to finalValue
    void jumpToValue(Type final_value);                                 //stop the transition andh jump to this (final_value) value
    void setChangingColor(ofColor color){changingColor = color;}                //color during transition
    void setDefaultColor(ofColor color){defaultFillColor = color;}
    void setTransitionDuration(float duration){if(duration >= 0) durationTransition = duration;}   //duration of transition in ms
    void setDrawSliderDuringTransition(bool show){bDrawSliderDuringTransition = show;}
    void setFramerateReference(int framerate){framerateReference = framerate;}
    void setTransitionTimeBased(bool transitionTimeBased){bTransitionTimeBased = transitionTimeBased;}
    void stopTransition();    // it stop the transition to the current value

    
    bool isTransitionTimeBased() {return bTransitionTimeBased;}
	ofxSlider<Type> &getSlider() { return ofxSlider; }

protected:
    ofxSlider<Type> ofxSlider;
    
    Type startValue;
    Type finalValue;
    float value;
    float transitionPct;
    float durationTransition = 2000;
    bool bTransition;
    int framerateReference = 60.0f;                                //fps to generate a transition not time base, but frames based
    bool bTransitionTimeBased = true;                                     //if true the transition is time based, if false is frame based
    bool bDrawSliderDuringTransition = true;
    ofColor changingColor = ofColor(64, 64, 255);
    ofColor defaultFillColor = ofColor(128);
    uint64_t changedTime;
    int frameCounter = 0;                                           //frame counter used in frame based mode
};

typedef ofxTransitionSlider<float> ofxTransitionFloatSlider;
typedef ofxTransitionSlider<int> ofxTransitionIntSlider;


#endif /* TransitionSlider_hpp */
