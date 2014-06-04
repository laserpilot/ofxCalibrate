#pragma once

#include "ofMain.h"

class ofxCalibrate : public ofBaseApp{
	public:

		void drawCheckerBoard();
        void drawCheckerBoardAnim();
        void drawMiniCheckerboard();
        void drawFancyGrid();
        void drawSimpleGrid(int _spacing);
        void drawLines(bool horiz, int _spacing);
            void drawGradientLines(bool horiz, bool animate, int _spacing);
        void drawGradient();
		
//		void keyPressed(int key);
//		void keyReleased(int key);
//		void mouseMoved(int x, int y);
//		void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void windowResized(int w, int h);

};
