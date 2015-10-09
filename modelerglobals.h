#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.

enum SampleModelControls
{ 
	XPOS, 
	YPOS, 
	ZPOS,
	// HEIGHT, 
	// ROTATE,
	HEAD_X_ROTATION,
	HEAD_Y_ROTATION,
	HEAD_Z_ROTATION,
	LEFT_UPPER_ARM_ROTATION_X,
	LEFT_UPPER_ARM_ROTATION_Y,
	LEFT_UPPER_ARM_ROTATION_Z,
	LEFT_FORE_ARM_ROTATION_Y,
	LEFT_FORE_ARM_ROTATION_Z,
	RIGHT_UPPER_ARM_ROTATION_X,
	RIGHT_UPPER_ARM_ROTATION_Y,
	RIGHT_UPPER_ARM_ROTATION_Z,
	RIGHT_FORE_ARM_ROTATION_Y,
	RIGHT_FORE_ARM_ROTATION_Z,
	WHOLE_SCALE_X,
	WHOLE_SCALE_Y,
	WHOLE_SCALE_Z,
	LIGHT_POSITION_X,
	LIGHT_POSITION_Y,
	LIGHT_POSITION_Z,
	LEVEL,
	FOG,
	NUMCONTROLS
};


// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_MBLUE		0.34f, 0.6f, 0.79f
#define COLOR_GREY		0.5f, 0.5f, 0.5f
#define COLOR_WHITE     1.0f,1.0f,1.0f
#define COLOR_BLACK     0.0f,0.0f,0.0f

#define COLOR_YELLOW    1.0f, 1.0f, 0.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif