#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("gui");
    gui.add(transitionFloatSlider.setup("transition float slider", 0.0, 0.0, 100.0));
    gui.add(transitionIntSlider.setup("transition int slider", 0, 1000, 5000));
    gui.loadFromFile("settings.xml");
    
    //if true always draw current value, but you can't see the value with mouse
    transitionIntSlider.setDrawSliderDuringTransition(false);
    
    //set duration of the transition
    transitionIntSlider.setTransitionDuration(0);
}

//--------------------------------------------------------------
void ofApp::update(){    
    transitionFloatSlider.update();
    transitionIntSlider.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
