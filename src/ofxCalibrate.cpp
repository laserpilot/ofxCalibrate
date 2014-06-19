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
        //This one will murder your FPS - use sparingly or only during calibration
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
        //This one will murder your FPS - use sparingly or only during calibration
    ofPushStyle();
    
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
    
    //draw numbering
    if(horiz){
        for(int y = 0; y < ofGetWidth(); y++){
            if (y%spacing==0 && spacing >25) {
                ofSetColor(255);
                ofDrawBitmapString(ofToString(y), 20,y);
            }
        }
    }else{
        for(int x = 0; x < ofGetWidth(); x++){
            if (x%spacing==0 && spacing >25) {
                ofSetColor(255);
                ofDrawBitmapString(ofToString(x), x,20);
            }
        }
    }
    ofPopStyle();
}

void ofxCalibrate::drawGradientLines(bool horiz, bool animate){
    //This one will murder your FPS - use sparingly or only during calibration
    ofPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    int spacing = 1;
    
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

void ofxCalibrate::drawColorGradientLines(bool horiz, bool animate){
    //This one will murder your FPS - use sparingly or only during calibration
    //Would be best in a shader
    ofPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    int spacing = 1;
    
    int timer=0;
    if (animate) {
        timer = 100*ofGetElapsedTimef();
    }
    
    ofColor temp = ofColor(255,0,0);
    
    if (horiz) {
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                    temp.setHue(((y+timer)%255));
                    pixels.setColor(x, y, temp);
            }
        }
    }else{
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                temp.setHue(((x+timer)%255));
                pixels.setColor(x, y, temp);
            }
        }
    }
    
    
    
    ofImage image;
    image.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    image.setFromPixels(pixels.getPixels(), ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    image.draw(0,0);
}

void ofxCalibrate::drawFloatGradientLines(bool horiz, bool animate){
    
    //This one will murder your FPS - use sparingly or only during calibration
    //Would be better to do this in a shader
    ofFloatPixels pixels;
    pixels.allocate(ofGetWidth(), ofGetHeight(), 3);
    
    int spacing = 1;
   
    
    int timer=0;
    if (animate) {
        timer = 100*ofGetElapsedTimef();
    }
    
    if (horiz) {
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                if (y%spacing==0) {
                    pixels.setColor(x, y, ofFloatColor((float)((y+timer)%1000)/ofGetHeight()));
                }else{
                    pixels.setColor(x, y, ofFloatColor((float)((y+timer)%1000)/ofGetHeight()) );
                }
            }
        }
    }else{
        for(int y = 0; y < ofGetHeight(); y++){
            for(int x = 0; x < ofGetWidth(); x++){
                if (x%spacing==0) {
                    pixels.setColor(x, y, ofFloatColor((float)((x+timer)%ofGetWidth())/ofGetWidth()));
                }else{
                    pixels.setColor(x, y, ofFloatColor((float)((x+timer)%ofGetWidth())/ofGetWidth()));
                }
            }
        }
    }
    
    
    
    ofFloatImage image;
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
    

    for(int x = 0; x < ofGetWidth(); x++){
        if (x%spacing==0 && spacing >25) {
            ofSetColor(255);
            ofDrawBitmapString(ofToString(x), x,20);
        }
    }
    
    for(int y = 0; y < ofGetWidth(); y++){
        if (y%spacing==0 && spacing >25) {
            ofSetColor(255);
            ofDrawBitmapString(ofToString(y), 20,y);
        }
    }
    
}

void ofxCalibrate::drawFancyGrid(){
    
    ofPushStyle();
    ofSetLineWidth(1);
    ofEnableAlphaBlending();
    
    int height = ofGetHeight();
    int width = ofGetWidth();
    
    ofFill();
    ofSetColor(255, 0, 0,100);
    ofRect(0,0,width, height/3);
    
    ofSetColor(0, 255, 0,100);
    ofRect(0,height/3,width, height/3);
    
    ofSetColor(0, 0, 255,100);
    ofRect(0,height-(height/3),width, height/3);
    
    ofFill();
    ofSetColor(255, 0, 255);
    ofLine(80, 0, 80, height);
    ofRect(0, 0, 80, height);
    ofSetColor(255, 255, 0);
    ofRect(width-80, 0, 80, height);
    ofNoFill();
    
    ofSetCircleResolution(40);
    ofSetColor(255);
    int spacing = 100;
    for (int i = 0; i<width; i=i+spacing) {
        if ((i/spacing)%3) {
            ofSetLineWidth(1);
            ofSetColor(127);
        }
        else{
            ofNoFill();
            ofSetColor(255);
            ofCircle(i+1.5*spacing, height/2, (height/3)/2);
            ofRect(i+1.5*spacing, height/2, (height/3)/2,(height/3)/2);
            ofRect(i+1.5*spacing-((height/3)/2), (height/2)- (height/3)/2, (height/3)/2,(height/3)/2);
            ofSetLineWidth(2);
            ofSetColor(100, 100, ofMap(i,0,width,0,255));
            ofLine(i,0,i+spacing*3,height);
                        ofLine(i+spacing*3,0,i,height);
        }
        ofLine(i, 0, i, height);
        ofDrawBitmapString(ofToString(i), i+5,20);
    }
    //Text
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

    ofPopStyle();
    
}