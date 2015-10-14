#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <FL/gl.h>

class LSystem
{
private:
	const float ANGLE = 20.0f;
	
	std::string str;
	int DEPTH;
	int currentDepth;
public:
	LSystem(std::string initialString,int depth);
	void expan(int depth);
	const char * printString();
	void rotateLeft();
	void rotateRight();
	void drawLine();
	void push();
	void pop();
	void drawLSystem();
	~LSystem();
};

