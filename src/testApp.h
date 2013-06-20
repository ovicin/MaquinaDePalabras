#pragma once

#include "ofMain.h"
#include "slowDown.h"

typedef enum{
	RUNNING = 0,
	SLOWING_DOWN,
	STOP
}MainStates_t;

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void buttonPressed(void);
		void tuneFrame(unsigned char);

		ofVideoPlayer 		Movie1, Movie2, Movie3;
		bool                frameByframe;

		slowDown slDo1, slDo2, slDo3;

		MainStates_t mainState;
};

