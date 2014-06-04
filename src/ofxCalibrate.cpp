#include "ofxCalibrate.h"

void ofxCalibrate::drawCheckerBoard(){
    int width=ofGetWidth();
    int height=ofGetHeight();
    int squareSize = 30;
    int counter=0;
    
    
    
    ofPushStyle();
    for (int j=0; j<height;j=j+squareSize) {
        
        for (int i=0; i<width; i=i+squareSize*2){
            if (counter%2==0){
                ofSetColor(0);
                ofRect(i, j, squareSize, squareSize);
                ofSetColor(255);
                ofRect(i+squareSize, j, squareSize, squareSize);
            }else {
                ofSetColor(255);
                ofRect(i, j, squareSize, squareSize);
                ofSetColor(0);
                ofRect(i+squareSize, j, squareSize, squareSize);
            }
            
        }
        counter++;
    }
    ofPopStyle();
}

void ofxCalibrate::drawCheckerBoardAnim(){
    int width=ofGetWidth();
    int height=ofGetHeight();
    int squareSize = 30;
    int counter=0;
    

    
    ofPushStyle();
    for (int j=0; j<height;j=j+squareSize) {

        for (int i=0; i<width; i=i+squareSize*2){
            if (counter%2==0){
                ofSetColor(0);
                ofFill();
                ofRect(i, j, squareSize, squareSize);
                
                
                ofSetColor(255);
                ofFill();
                ofRect(i+squareSize, j, squareSize, squareSize);
                ofNoFill();
                ofCircle(i+squareSize/2, j+squareSize/2, squareSize/4*sin(i+1/150+5*ofGetElapsedTimef())+squareSize/4);
                ofSetColor(0);
                ofCircle(i+squareSize+squareSize/2, j+squareSize/2, squareSize/4*sin((i+1)/200+5*ofGetElapsedTimef())+squareSize/4);


            }else {
                ofSetColor(255);
                ofFill();
                ofRect(i, j, squareSize, squareSize);

                
                ofSetColor(0);
                ofFill();
                ofRect(i+squareSize, j, squareSize, squareSize);
                ofNoFill();
                ofCircle(i+squareSize/2, j+squareSize/2, squareSize/4*sin((i+1)/175+5*ofGetElapsedTimef())+squareSize/4);
                ofSetColor(255);
                ofCircle(i+squareSize+squareSize/2, j+squareSize/2, squareSize/4*sin((i+1)/250+5*ofGetElapsedTimef())+squareSize/4);
            }
            
        }
        counter++;
    }
    ofPopStyle();
}

void ofxCalibrate::drawMiniCheckerboard(){
    ofPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    for(int y = 0; y < ofGetHeight(); y++){
		for(int x = 0; x < ofGetWidth(); x=x+2){
            if (y%2==0) {
                pixels.setColor(x, y, ofColor::white);
                pixels.setColor(x+1, y, ofColor::black);
            }else{
                pixels.setColor(x, y, ofColor::black);
                pixels.setColor(x+1, y, ofColor::white);
            }
        }
    }
    
    

    ofImage image;
    image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    image.setFromPixels(pixels.getPixels(), ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    image.draw(0,0);
}

void ofxCalibrate::drawLines(bool horiz, int _spacing){
    ofPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    int spacing = _spacing;
    spacing = ofClamp(spacing, 2, 2000);
    
    if (horiz) {
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                if (y%spacing==0) {
                    pixels.setColor(x, y, ofColor::white);
                }else{
                    pixels.setColor(x, y, ofColor::black);
                }
            }
        }
    }else{
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                if (x%spacing==0) {
                    pixels.setColor(x, y, ofColor::white);
                }else{
                    pixels.setColor(x, y, ofColor::black);
                }
            }
        }
    }
    
    
    
    ofImage image;
    image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    image.setFromPixels(pixels.getPixels(), ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    image.draw(0,0);
}

void ofxCalibrate::drawGradientLines(bool horiz, bool animate, int _spacing){
    ofPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    int spacing = _spacing;
    spacing = ofClamp(spacing, 2, 2000);
    
    int timer=0;
    if (animate) {
        timer = 100*ofGetElapsedTimef();
    }
    
    if (horiz) {
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                if (y%spacing==0) {
                    pixels.setColor(x, y, ofColor((y+timer)%255));
                }else{
                    pixels.setColor(x, y, ofColor((y+timer)%255));
                }
            }
        }
    }else{
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                if (x%spacing==0) {
                     pixels.setColor(x, y, ofColor((x+timer)%255));
                }else{
                     pixels.setColor(x, y, ofColor((x+timer)%255));
                }
            }
        }
    }
    
    
    
    ofImage image;
    image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    image.setFromPixels(pixels.getPixels(), ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    image.draw(0,0);
}

void ofxCalibrate::drawSimpleGrid(int _spacing){
    ofPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    int spacing = _spacing;
    spacing = ofClamp(spacing, 2, 2000);
    

    for(int y = 0; y < ofGetHeight(); y++){
        for(int x = 0; x < ofGetWidth(); x++){
                if (y%spacing==0 || x%spacing==0) {
                    pixels.setColor(x, y, ofColor::white);
                }else{
                    pixels.setColor(x, y, ofColor::black);
                }
        }
    }

    
    
    
    
    ofImage image;
    image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    image.setFromPixels(pixels.getPixels(), ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    image.draw(0,0);
}

void ofxCalibrate::drawFancyGrid(){
    
    ofPushStyle();
    ofSetLineWidth(1);
    ofEnableAlphaBlending();
    
    int height = ofGetHeight();
    int width = ofGetWidth();
    
    ofFill();
    ofSetColor(255, 0, 0,100);
    ofRect(0,0,height, width);
    
    ofSetColor(0, 255, 0,100);
    ofRect(0,0.33*height,width, height/3);
    
    ofSetColor(0, 0, 255,100);
    ofRect(0,height-(height/3),width, height/3);
    
    ofFill();
    ofSetColor(255, 0, 255);
    ofLine(80, 0, 80, height);
    ofRect(0, 0, 80, height);
    ofSetColor(255, 255, 0);
    ofRect(1200, 0, 80, height);
    ofNoFill();
    
    
    ofSetColor(255);
    int spacing = 100;
    for (int i = 0; i<width; i=i+spacing) {
        if ((i/spacing)%3) {
            ofSetLineWidth(1);
            ofSetColor(127);
        }
        else{
            ofNoFill();
            ofCircle(i+1.5*spacing, width/2, spacing);
            ofSetLineWidth(2);
            ofSetColor(100, 100, ofMap(i,0,width,0,255));
            ofLine(i,0,i+spacing*3,width);
            ofSetColor(4, 5, 6);
            ofSetLineWidth(5);
        }
        ofLine(i, 0, i, height);
        ofDrawBitmapString(ofToString(i), i+5,20);
    }
    
    for (int i = 0; i<height; i=i+spacing) {
        if ((i/spacing)%3) {
            ofSetLineWidth(1);
        }
        else{
            ofSetLineWidth(5);
        }
        ofLine(0, i, width, i);
        ofDrawBitmapString(ofToString(i), 20,i+5);
        ofDrawBitmapString(ofToString(i), 200,i+5);
    }
    
    for(int i=1; i<3; i++){
        ofSetLineWidth(5);
        ofSetColor(255, 0, 0);
        ofLine(i*(width/3), 0, i*(width/3), height);
    }
    
    ofPopStyle();
    
}