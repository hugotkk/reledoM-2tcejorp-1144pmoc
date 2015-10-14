#ifndef MINION_H
#define MINION_H

#include "modelerview.h"
#include "modelerdraw.h"
#include "modelerglobals.h"
#include "modelerapp.h"
#include "LSystem.h"
#include "bitmap.h"

class Minion : public ModelerView {
private:
	double attrs[NUMCONTROLS];
	bool direction[NUMCONTROLS] = {};
	double animate(int control, double max, double min, double delta) {
		if (ModelerApplication::Instance()->isAnimating()) {
			double value = attrs[control];

			if (direction[control]) {
				value += delta;
			} else {
				value -= delta;
			} 
				
			if (value >= max) {
				value = max;
				direction[control] = false;
			}
			if (value <= min)
			{
				value = min;
				direction[control] = 1;
			}
			attrs[control] = value;
		} else {
			attrs[control] = VAL(control);
		}
		return attrs[control];
	}
public:
	Minion(int x, int y, int w, int h, char *label) : ModelerView(x, y, w, h, label) {
		attrs[LEFT_UPPER_ARM_ROTATION_X] = 0;
		direction[LEFT_UPPER_ARM_ROTATION_X] = true;
		attrs[RIGHT_UPPER_ARM_ROTATION_X] = 0;
		direction[RIGHT_UPPER_ARM_ROTATION_X] = false;
		attrs[LEFT_LEG_ROTATION] = 0;
		direction[LEFT_LEG_ROTATION] = false;
		attrs[RIGHT_LEG_ROTATION] = 0;
		direction[RIGHT_LEG_ROTATION] = true;
	}
	virtual void draw();
};

#endif