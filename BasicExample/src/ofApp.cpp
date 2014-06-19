#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    whichCalib = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if (whichCalib==0) {
        calibrate.drawCheckerBoard();
    }else if( whichCalib==1){
          calibrate.drawMiniCheckerboard();
    }else if(whichCalib==2){
        calibrate.drawFancyGrid();
    }else if(whichCalib==3){
        calibrate.drawCheckerBoardAnim();
    }else if(whichCalib==4){
        calibrate.drawLines(ofGetMousePressed(),ofMap(mouseX, 0, ofGetWidth(), 2,200));
    }else if(whichCalib==5){
        calibrate.drawSimpleGrid(ofMap(mouseX, 0, ofGetWidth(), 2,200));
    }else if(whichCalib==6){
        calibrate.drawGradientLines(ofGetMousePressed(), true);
    }else if(whichCalib==7){
        calibrate.drawFloatGradientLines(ofGetMousePressed(), false);
    }else if(whichCalib==8){
        calibrate.drawColorGradientLines(ofGetMousePressed(), false);
    }



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
    whichCalib++;
    whichCalib = ofWrap(whichCalib, 0, 9);
    }
    
    if(key=='f'){
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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