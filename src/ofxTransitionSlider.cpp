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
    transitionPct = 0;
    ofxSlider.setFillColor(defaultFillColor);
    
    return ofxSlider.setup(_name, _value, _min, _max);
}

template<typename Type>
double ofxTransitionSlider<Type>::operator=(Type v){
    ofxSlider = v;
    return v;
}

template<typename Type>
ofxTransitionSlider<Type>::operator const float & (){
    return value;
}

template<typename Type>
void ofxTransitionSlider<Type>::update(float _transitionDuration){
    
    if (_transitionDuration >= 0) {
        setTransitionDuration(_transitionDuration);
    }
    
    if(! bTransition && ofxSlider != finalValue) {
        if (durationTransition > 0){
            bTransition = true;
            startValue = finalValue;
            finalValue = ofxSlider;
            ofxSlider.setFillColor(changingColor);
            changedTime = ofGetSystemTimeMillis();
            frameCounter = 0;
        }
    }
    
    if(bTransition && abs(value - finalValue) == 0){
        bTransition = false;
        ofxSlider.setFillColor(defaultFillColor);
    }
    
    if(bTransition){
        float transition = 0;
        
        //time based transition
        if(bTransitionTimeBased){
            uint64_t curTime = ofGetSystemTimeMillis();
            uint64_t endTime = changedTime + durationTransition;
            float transition =  ofMap(curTime, changedTime, endTime, 0.0, 1.0, true);
            if(curTime >= endTime) transition = 1.0;
            value = (Type) ofMap(transition, 0.0, 1.0, startValue, finalValue, true);

            if(transition == 1.0) value = finalValue;
            transitionPct = float(value);
        }
        //frame based transition
        else{
            int durationTransitionFrame = (durationTransition / 1000.0f * framerateReference);
            
            float updateIncrement = (finalValue - startValue) / durationTransitionFrame;
            float newValue = value + updateIncrement;
            value = (Type) newValue;
        
            
            frameCounter ++;
            transitionPct = float(frameCounter) /float( durationTransitionFrame);
            if (frameCounter >= durationTransitionFrame) {
                value = finalValue;
            }
        }
        
        if(bDrawSliderDuringTransition)ofxSlider = value;
    }
    else{
        value = ofxSlider;
    }
}

template<typename Type>
void ofxTransitionSlider<Type>::jumpToFinalValue() {
    jumpToValue(ofxSlider);
}

template<typename Type>
void ofxTransitionSlider<Type>::jumpToValue(Type final_value) {
    bTransition = false;
    if(final_value != ofxSlider)  ofxSlider = final_value;
    startValue = ofxSlider;
    finalValue = ofxSlider;
    value = ofxSlider;
    ofxSlider.setFillColor(defaultFillColor);
}

template<typename Type>
void ofxTransitionSlider<Type>::stopTransition() {
    if (bTransition) {
        bTransition = false;
        ofxSlider = value;
        finalValue = value;
        ofxSlider.setFillColor(defaultFillColor);
    }
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

//for some reason osx errors if this isn't defined 
#ifdef TARGET_OSX
template class ofxSlider<typename std::conditional<std::is_same<uint32_t, size_t>::value || std::is_same<uint64_t, size_t>::value, bool, size_t>::type>;
#endif
