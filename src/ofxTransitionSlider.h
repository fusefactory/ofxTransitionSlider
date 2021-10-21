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
    Type getValue(){return value;};
    void update(float _transitionDuration = -1.0);
	void jumpToFinalValue();
    void setChangingColor(ofColor color){changingColor = color;}                //color during transition
    void setDefaultColor(ofColor color){defaultFillColor = color;}
    void setTransitionDuration(float duration){if(duration >= 0) durationTransition = duration;}   //duration of transition in ms
    void setDrawSliderDuringTransition(bool show){bDrawSliderDuringTransition = show;}
    void stopTransition();                                                                         // it stop the transition to the current value
	ofxSlider<Type> &getSlider() { return ofxSlider; }

protected:
    ofxSlider<Type> ofxSlider;
    
    Type startValue;
    Type finalValue;
    float value;
    float durationTransition = 2000;
    bool bTransition;
    bool bDrawSliderDuringTransition = true;
    ofColor changingColor = ofColor(64, 64, 255);
    ofColor defaultFillColor = ofColor(128);
    uint64_t changedTime;
};

typedef ofxTransitionSlider<float> ofxTransitionFloatSlider;
typedef ofxTransitionSlider<int> ofxTransitionIntSlider;


#endif /* TransitionSlider_hpp */
