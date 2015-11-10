#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableDepthTest();
    ofSetBackgroundColor(0,0,0);



    fftlive.setMirrorData(false);
    fftlive.setup();
    ofSetSmoothLighting(true);
   // spotLight.setPosition(ofGetMouseX(), ofGetMouseY(), 0);


}

//--------------------------------------------------------------
void ofApp::update(){
    float * audiodata = new float [16];
    fftlive.update();

    fftlive.getFftPeakData(audiodata, 16);



    for (int i=0; i<16; i++){
        spotLight.setPosition(ofGetMouseX(),ofGetMouseY(),200+audiodata[i]);
        if(audiodata[i]>.9){
            spotLight.enable();
           }
        if(audiodata[i]<.9){
            spotLight.disable();
        }
    }



    delete [] audiodata;


}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetBackgroundColor(0,0,0,255);
    //ofSetColor(ofGetMouseX(),ofGetMouseY(),ofGetMouseX()-ofGetMouseY());
   // spotLight.setAmbientColor(ofFloatColor::fromHsb(ofGetMouseX(),ofGetMouseY(), 10, 255));
    //ofNoFill();


    spotLight.draw();
    ofDrawBox(ofGetWidth()*.4, ofGetHeight()*.4, 0, 200, 100, 200);


//    audiodata.draw;


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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
