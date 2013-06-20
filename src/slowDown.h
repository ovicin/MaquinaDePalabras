#ifndef SLOWDOWN_H
#define SLOWDOWN_H

#include "ofMain.h"
#include "interpolation.h"


class slowDown{
public:
	slowDown(void);
	slowDown(unsigned long long);
	void init(void);
	void update(void);
	float getSpeed(void);
	unsigned long long getDefaultSlowDownTime(void);
	unsigned long long getSlowDownTime(void);
	void setSlowDownCurve(vector <interpolationPoint_t>);
	void startSlowingDown(void);
	void genRandomCurveEnd(float, float);
	bool SlowingDown;

private:
	vector <interpolationPoint_t> fetchDefaultCurve(void);
	unsigned long long initTime, currentTime, elapsedTime,slowDownTime;
	float slowDownSpeed;
	
	interpolation slowDownCurve;
};


#endif