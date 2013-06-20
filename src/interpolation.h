#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "ofMain.h"

typedef struct{
	float x;
	float y;
}interpolationPoint_t;

class interpolation{
public:
	interpolation();	
	float interpolate(float);
	void addInterpolationPoint(interpolationPoint_t);
	void setInterpolationCurve(vector <interpolationPoint_t>);
	vector <interpolationPoint_t> getInterpolationCurve(void);
	void clearAllPoints(void);
private:
	vector <interpolationPoint_t> interpolationCurve;
};

#endif
