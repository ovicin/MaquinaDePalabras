#include "interpolation.h"

interpolation::interpolation()
{
	interpolationCurve.clear();
}

float interpolation::interpolate(float input)
{
	int i;

	if (interpolationCurve.size() > 2){
		for (i=1;i<interpolationCurve.size();i++)
			if((interpolationCurve[i-1].x < input) && (input < interpolationCurve[i].x))
				return ofMap(input,interpolationCurve[i-1].x,interpolationCurve[i].x ,interpolationCurve[i-1].y,interpolationCurve[i].y);
	}
	else
		/* wee need at least 2 points on the curve in order to be able to make the interpolation */
		return 0;
	
}

void interpolation::addInterpolationPoint(interpolationPoint_t point)
{
	interpolationCurve.push_back(point);
}

void interpolation::setInterpolationCurve(vector <interpolationPoint_t> curve)
{
	interpolationCurve=curve;
}

vector <interpolationPoint_t> interpolation::getInterpolationCurve(void)
{
	return interpolationCurve;
}

void interpolation::clearAllPoints(void)
{
	interpolationCurve.clear();
}