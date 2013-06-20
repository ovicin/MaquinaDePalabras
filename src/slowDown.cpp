#include "slowDown.h"
#include "slowDownCurve.h"

slowDown::slowDown(void)
{
	init();
}

slowDown::slowDown(unsigned long long time)
{
	init();
	slowDownTime = time;
}

void slowDown::init(void)
{
	initTime = 0;
	currentTime = 0;
	elapsedTime = 0;
	SlowingDown = false;
	slowDownSpeed = 1; /* init the speed with 1 to run with the normal speed at startup */
	slowDownCurve.setInterpolationCurve(fetchDefaultCurve());
	slowDownTime = getDefaultSlowDownTime();
		
}

vector <interpolationPoint_t> slowDown::fetchDefaultCurve(void)
{
	vector <interpolationPoint_t> curve;
	interpolationPoint_t interpolationPoint;
	int i;

	for(i=0;i<(sizeof(defaultX)/sizeof(float));i++)
	{
		interpolationPoint.x = defaultX[i];
		interpolationPoint.y = defaultY[i];
		curve.push_back(interpolationPoint);
	}

	return curve;

}
void slowDown::update(void)
{
	if (SlowingDown){
	currentTime = ofGetElapsedTimeMillis();
	elapsedTime = currentTime - initTime;
	//initTime = currentTime;
	cout <<"slowDownTime "<< slowDownTime <<"\n";
	cout <<"elapsedTime "<< elapsedTime <<" .... ";
	if (elapsedTime < slowDownTime){
		/* slowing down */
		slowDownSpeed = 1 - slowDownCurve.interpolate((float)(elapsedTime));
		cout <<"slowDownSpeed " << slowDownSpeed << "\n";
	}
	else{
	 SlowingDown = false;
	 slowDownSpeed = 0;
	}
	}
}

float slowDown::getSpeed(void)
{
	return slowDownSpeed;
}

unsigned long long slowDown::getDefaultSlowDownTime(void)
{
	return (unsigned long long)defaultX[(sizeof(defaultX)/sizeof(float))-1];
}

unsigned long long slowDown::getSlowDownTime(void)
{
	vector <interpolationPoint_t> curve;	
	curve = slowDownCurve.getInterpolationCurve();
	return (unsigned long long) curve[curve.size()-1].x;
}

void slowDown::setSlowDownCurve(vector <interpolationPoint_t> curve)
{
	slowDownCurve.setInterpolationCurve(curve);
	slowDownTime = getSlowDownTime();
}

void slowDown::startSlowingDown(void)
{
	SlowingDown=true;
	initTime = ofGetElapsedTimeMillis();
}

void slowDown::genRandomCurveEnd(float min, float max)
{
	vector <interpolationPoint_t> curve;	

	curve = slowDownCurve.getInterpolationCurve();
	curve[curve.size()-1].x = ofRandom(min,max);
	slowDownCurve.setInterpolationCurve(curve);
	slowDownTime = getSlowDownTime();
	
}