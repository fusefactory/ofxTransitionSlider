//
//  TransitionSlider.cpp
//  ExampleTransitionSlider
//
//  Created by Matteo on 27/07/2019.
//

#include "ofxTransitionSlider.h"

template<typename Type>
ofxTransitionSlider<Type>::ofxTransitionSlider(){
}

template<typename Type>
ofxBaseGui * ofxTransitionSlider<Type>::setup(std::string _name, Type _value, Type _min, Type _max){
    startValue = _value;
    finalValue = _value;
    ofxSlider.setFillColor(defaultFillColor);
    return ofxSlider.setup(_name, _value, _min, _max);
}

template<typename Type>
ofxTransitionSlider<Type>::operator const float & (){
    return value;
}

template<typename Type>
void ofxTransitionSlider<Type>::update(float _transitionDuration){
    
    if (_transitionDuration >= 0) setTransitionDuration(_transitionDuration);
    
    if(! bTransition && ofxSlider != finalValue) {
        if (durationTransition > 0){
            bTransition = true;
            startValue = finalValue;
            finalValue = ofxSlider;
            ofxSlider.setFillColor(changingColor);
            changedTime = ofGetSystemTimeMillis();
        }
    }
    
    if(bTransition && abs(value - finalValue) == 0){
        bTransition = false;
        ofxSlider.setFillColor(defaultFillColor);
    }
    
    if(bTransition){
        uint64_t curTime = ofGetSystemTimeMillis();
        uint64_t endTime = changedTime + durationTransition;
        float transition =  ofMap(curTime, changedTime, endTime, 0.0, 1.0, true);
        if(curTime >= endTime) transition = 1.0;
        
        value = (Type) ofMap(transition, 0.0, 1.0, startValue, finalValue, true);
        if(transition == 1.0) value = finalValue;
        
        if(bDrawSliderDuringTransition)ofxSlider = value;
    }
    else{
        value = ofxSlider;
    }
}

template<typename Type>
void ofxTransitionSlider<Type>::jumpToFinalValue() {
	bTransition = false;
	startValue = ofxSlider;
	finalValue = ofxSlider;
    value = ofxSlider;
	ofxSlider.setFillColor(defaultFillColor);
}

template class ofxTransitionSlider<int8_t>;
template class ofxTransitionSlider<uint8_t>;
template class ofxTransitionSlider<int16_t>;
template class ofxTransitionSlider<uint16_t>;
template class ofxTransitionSlider<int32_t>;
template class ofxTransitionSlider<uint32_t>;
template class ofxTransitionSlider<int64_t>;
template class ofxTransitionSlider<uint64_t>;
template class ofxTransitionSlider<float>;
template class ofxTransitionSlider<double>;

template class ofxTransitionSlider<typename std::conditional<std::is_same<uint32_t, size_t>::value || std::is_same<uint64_t, size_t>::value, bool, size_t>::type>;
