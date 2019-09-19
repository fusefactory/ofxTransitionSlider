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
    operator const float & ();
    
    ofxTransitionSlider();
    
    ofxBaseGui * setup(std::string _name, Type _value, Type _min, Type _max);
    Type getValue(){return value;};
    void update(float _transitionDuration = -1.0);
    
    void setChangingColor(ofColor color){changingColor = color;}                //color during transition
    void setTransitionDuration(float duration){if(duration >= 0) durationTransition = duration;}   //duration of transition in ms
    void setDrawSliderDuringTransition(bool show){bDrawSliderDuringTransition = show;}
	ofxSlider<Type> &getSlider() { return ofxSlider; }

protected:
    ofxSlider<Type> ofxSlider;
    
    Type startValue;
    Type finalValue;
    float value;
    float durationTransition = 2000;
    bool bTransition;
    bool bDrawSliderDuringTransition = true;
    ofColor changingColor;
    uint64_t changedTime;
};

typedef ofxTransitionSlider<float> TransitionFloatSlider;
typedef ofxTransitionSlider<int> TransitionIntSlider;


#endif /* TransitionSlider_hpp */
