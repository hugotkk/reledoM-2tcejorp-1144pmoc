#ifndef MINION_H
#define MINION_H

#include "modelerview.h"
#include "modelerdraw.h"
#include "modelerglobals.h"
#include "modelerapp.h"

class Minion : public ModelerView {

public:
	Minion(int x, int y, int w, int h, char *label) : ModelerView(x, y, w, h, label) { }
	virtual void draw();
};

#endif