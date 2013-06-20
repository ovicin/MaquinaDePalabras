#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;

	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	mainState = RUNNING;
	
	Movie1.loadMovie("movies/fingers.mov");
	Movie1.play();
	Movie1.setSpeed(1);
	slDo1.genRandomCurveEnd(5000,6000);

	Movie2.loadMovie("movies/fingers.mov");
	Movie2.play();
	Movie2.setSpeed(1);
	slDo2.genRandomCurveEnd(5000,6000);

	Movie3.loadMovie("movies/fingers.mov");
	Movie3.play();
	Movie3.setSpeed(1);
	slDo3.genRandomCurveEnd(5000,6000);
}

//--------------------------------------------------------------
void testApp::update(){
    
	switch(mainState){
	case RUNNING:
		/* in the running mode play at the normal speed*/
		Movie1.setSpeed(1);
		Movie2.setSpeed(1);
		Movie3.setSpeed(1);
		break;
	case SLOWING_DOWN:
		/*slowing down the videos*/
		slDo1.update();
		Movie1.setSpeed(slDo1.getSpeed());    
		slDo2.update();
		Movie2.setSpeed(slDo2.getSpeed());	
		slDo3.update();
		Movie3.setSpeed(slDo3.getSpeed());

		/* tune the frame for the videos that stoped */
		if (false == slDo1.SlowingDown)
			tuneFrame(1);
		if (false == slDo2.SlowingDown)
			tuneFrame(2);
		if (false == slDo3.SlowingDown)
			tuneFrame(3);

		/* switch to the STOP state when the slowing down is done for all the movies */
		if ((false == slDo1.SlowingDown) &&
			(false == slDo2.SlowingDown) &&
			(false == slDo3.SlowingDown)){
			
				mainState = STOP;
		}
		break;
	case STOP:
		/* stop when finished */
		Movie1.setSpeed(0);
		Movie2.setSpeed(0);
		Movie3.setSpeed(0);
		break;
		

	}
	Movie1.update();
	Movie2.update();
	Movie3.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetHexColor(0xFFFFFF);

    Movie1.draw(20,20);
    Movie2.draw(360,20);
	Movie3.draw(780,20);


    ofSetHexColor(0x000000);
	ofDrawBitmapString("press f to change",20,320);
    if(frameByframe) ofSetHexColor(0xCCCCCC);
    ofDrawBitmapString("mouse speed position",20,340);
    if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
    ofSetHexColor(0x000000);

    ofDrawBitmapString("frame: " + ofToString(Movie1.getCurrentFrame()) + "/"+ofToString(Movie1.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(Movie1.getPosition()*Movie1.getDuration(),2) + "/"+ofToString(Movie1.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(Movie1.getSpeed(),2),20,420);

    if(Movie1.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    switch(key){
        case 'f':
            frameByframe=!frameByframe;
            Movie1.setPaused(frameByframe);
        break;
        case OF_KEY_LEFT:
            Movie1.previousFrame();
        break;
        case OF_KEY_RIGHT:
            Movie1.nextFrame();
        break;
        case '0':
            Movie1.firstFrame();
        break;
		case 's':
			buttonPressed();
        break;
    }
}

void testApp::buttonPressed(void)
{
	if (mainState == RUNNING){/* if button pressed in running go to slowing down */
		/* start the speed calculation */
		slDo1.startSlowingDown();
		slDo2.startSlowingDown();
		slDo3.startSlowingDown();

		/*switch to the slowing down state*/
		mainState = SLOWING_DOWN;
	}
	if (mainState == STOP) /*if button pressed in STOP go to RUNNING */
		mainState = RUNNING;
}

void testApp::tuneFrame(unsigned char movie)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
