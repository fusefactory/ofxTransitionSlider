#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(5);
    gui.setup("gui");
    gui.add(transitionIntSlider.setup("transition int slider", 100, 0, 300));
    gui.loadFromFile("settings.xml");
    
    
    transitionIntSlider.setTransitionTimeBased(false);
    transitionIntSlider.setFramerateReference(60);
    
    //set duration of the transition
    transitionIntSlider.setTransitionDuration(1000);
}

//--------------------------------------------------------------
void ofApp::update(){
    transitionIntSlider.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    gui.draw();
    ofDrawBitmapStringHighlight("FPS: " + ofToString(ofGetFrameRate(), 3), 10, 20, ofColor(0, 127), ofColor(255));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        transitionIntSlider = 200;
    }
    if(key == 'b'){
        bool timeBased = transitionIntSlider.isTransitionTimeBased();
        transitionIntSlider.setTransitionTimeBased(! timeBased);
    }
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
