// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include "Minion.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new Minion(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();
	// draw the floor
	// setAmbientColor(.1f,.1f,.1f);
	// setDiffuseColor(COLOR_RED);
	// glPushMatrix();
	// glTranslated(-5,0,-5);
	// drawBox(10,0.01f,10);
	// glPopMatrix();

	// draw the sample model
	setAmbientColor(.5f,.5f,.5f);
	setDiffuseColor(COLOR_MBLUE);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
	glTranslated(0, -2, 0);
	glRotated(-90, 1.0, 0.0, 0.0);

		// body start
		glPushMatrix();
		drawCylinder(2, 1.75, 2); //身

		glPushMatrix();
			setDiffuseColor(COLOR_YELLOW);
			glTranslated(-0.3, 0, 1.5);
			drawCylinder(0.5, 1.8, 1.8);
		glPopMatrix();

		glPushMatrix();
			setDiffuseColor(COLOR_YELLOW);
			glTranslated(0.3, 0, 1.5);
			drawCylinder(0.5, 1.8, 1.8);
		glPopMatrix();

		glPushMatrix();
			setDiffuseColor(COLOR_YELLOW);
			glTranslated(-0.5, -2.05, 1.5);
			drawBox(1, 4.1, 0.5);
		glPopMatrix();

		// head start

			glPushMatrix();
			setDiffuseColor(COLOR_RED);
			glTranslated(0, 0, 2);
			glRotated(VAL(ROTATE), 1.0, 0.0, 0.0);
			drawCylinder(0.25, 0.25, 0.25); // head joint

				glPushMatrix();
				setDiffuseColor(COLOR_YELLOW);
				glTranslated(0, 0, 0.25);
				drawCylinder(2, 2, 2); // head

					glPushMatrix();
						glTranslated(0, 0, 2);
						drawSphere(2);    //天靈蓋

						// Hair
						glPushMatrix();
							setDiffuseColor(COLOR_BLACK);
							glTranslated(0, 0, 2);
							drawCylinder(0.6, 0.1, 0.1);
						glPopMatrix();
						glPushMatrix();
							setDiffuseColor(COLOR_BLACK);
							glRotated(-10, 0.0, 1.0, 0.0);
							glTranslated(0, 0, 2);
							drawCylinder(0.6, 0.1, 0.1);
						glPopMatrix();
						glPushMatrix();
							setDiffuseColor(COLOR_BLACK);
							glRotated(10, 0.0, 1.0, 0.0);
							glTranslated(0, 0, 2);
							drawCylinder(0.6, 0.1, 0.1);
						glPopMatrix();					

					glPopMatrix();

					glPushMatrix();
						setDiffuseColor(COLOR_GREY);
						glRotated(90, 1.0, 0.0, 0.0);
						glTranslated(0.75, 2, 2);
						drawCylinder(0.25, 0.75, 0.75); // 右眼鏡

						glPushMatrix();
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0.0, 0.0, 0.25);
							drawCylinder(0.05, 0.6, 0.6); // 右眼

							glPushMatrix();
							setDiffuseColor(COLOR_BLACK);
							glTranslated(0.0, 0.0, 0.05);
							drawCylinder(0.05, 0.1, 0.1); // 右眼珠
							glPopMatrix();

						glPopMatrix();

					glPopMatrix();

					glPushMatrix();
						setDiffuseColor(COLOR_GREY);
						glRotated(90, 1.0, 0.0, 0.0);
						glTranslated(-0.75, 2, 2);
						drawCylinder(0.25, 0.75, 0.75); // 左眼鏡

						glPushMatrix();
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0.0, 0.0, 0.25);
							drawCylinder(0.05, 0.6, 0.6); // 左眼

							glPushMatrix();
							setDiffuseColor(COLOR_BLACK);
							glTranslated(0.0, 0.0, 0.05);
							drawCylinder(0.05, 0.1, 0.1); // 左眼珠
							glPopMatrix();
						glPopMatrix();

					glPopMatrix();

					glPushMatrix();
						// Mouth
						setDiffuseColor(COLOR_BLACK);
						glTranslated(-1, -2.0, 0);
						drawBox(2, 1.5, 1);

						// Tongue
						glPushMatrix();
							setDiffuseColor(COLOR_RED);
							drawTriangle(0, -0.1, 0, 2, -0.1, 0, 1, -0.1, 0.5);
						glPopMatrix();

						// Tooth
						glPushMatrix();
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0, -0.1, 0.75);
							drawBox(2, 0.01, 0.25);
						glPopMatrix();
					glPopMatrix();					

				glPopMatrix();

			glPopMatrix();
			// head end

			// left hand
			glPushMatrix();
			// arm1 start
			setDiffuseColor(COLOR_YELLOW);
			glTranslated(-2.8,0,1);
			glTranslated(0, 0.25, 1);
			glRotated(VAL(ROTATE), 1.0, 0, 0);
			glTranslated(0, -0.25, -1.07);
			drawBox(0.5,0.5,1.07);
			// arm joint start
			glPushMatrix();
			setDiffuseColor(COLOR_RED);
				glTranslated(0.25,0.25, -0.13);
				drawCylinder(0.13,0.125,0.125);	
				// arm2 start
				glPushMatrix();
				setDiffuseColor(COLOR_YELLOW);
				glTranslated(0,0,-0.53);
				drawCylinder(0.53,0.17,0.17);
					// hand start
					glPushMatrix();
					setDiffuseColor(COLOR_BLACK);
					glTranslated(0,0,-0.13);
					drawSphere(0.27);
					glPopMatrix();
					// hand end
				glPopMatrix();
				// arm2 end
			glPopMatrix();
			// arm joint end
			// arm1 end
			glPopMatrix();
			// left hand end

			// right hand start
			glPushMatrix();
			// arm1 start
			setDiffuseColor(COLOR_YELLOW);
			glTranslated(2.3,0,1);
			drawBox(0.5,0.5,1.07);
			// arm joint start
			glPushMatrix();
			setDiffuseColor(COLOR_RED);
				glTranslated(0.25,0.25, -0.13);
				drawCylinder(0.13,0.125,0.125);	
				// arm2 start
				glPushMatrix();
				setDiffuseColor(COLOR_YELLOW);
				glTranslated(0,0,-0.53);
				drawCylinder(0.53,0.17,0.17);
					// hand start
					glPushMatrix();
					setDiffuseColor(COLOR_BLACK);
					glTranslated(0,0,-0.13);
					drawSphere(0.27);
					glPopMatrix();
					// hand end
				glPopMatrix();
				// arm2 end
			glPopMatrix();
			// arm joint end
			// arm1 end
			glPopMatrix();
			// right hand end

			// 左腳
			glPushMatrix();
			// 大脾 start
			setDiffuseColor(COLOR_MBLUE);
			glTranslated(-1.0,0,-0.6);
			drawCylinder(0.5,0.5, 0.6);
				// 鞋 start
				glPushMatrix();
				setDiffuseColor(COLOR_BLACK);
				glTranslated(-0.5,-1.2,-0.5);
				drawBox(1.0, 1.5, 0.5);
				glPopMatrix();
				// 鞋 end
			// 大脾 end
			glPopMatrix();

			// 右腳
			glPushMatrix();
			// 大脾 start
			setDiffuseColor(COLOR_MBLUE);
			glTranslated(1.0,0,-0.6);
			drawCylinder(0.5,0.5, 0.6);
				// 鞋 start
				glPushMatrix();
				setDiffuseColor(COLOR_BLACK);
				glTranslated(-0.5,-1.2,-0.5);
				drawBox(1.0, 1.5, 0.5);
				glPopMatrix();
				// 鞋 end
			// 大脾 end
			glPopMatrix();

		// glPushMatrix();
		// glTranslated(-1.5, 0, -2);
		// glScaled(3, 1, 4);
		// drawBox(1,1,1);
		// glPopMatrix();

		// // draw cannon
		// glPushMatrix();
		// glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		// glRotated(-90, 1.0, 0.0, 0.0);
		// drawCylinder(VAL(HEIGHT), 0.1, 0.1); // square

		// glTranslated(0.0, 0.0, VAL(HEIGHT));
		// drawCylinder(1, 1.0, 0.9); // head

		// glTranslated(0.0, 0.0, 0.5);
		// glRotated(90, 1.0, 0.0, 0.0);
		// drawCylinder(4, 0.1, 0.2); // canon

		// glPopMatrix();
		glPopMatrix();
		// body end

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
	controls[HEAD_X_ROTATION] = ModelerControl("Head X Rotate", -5, 5, 1, 0);
	controls[HEAD_Y_ROTATION] = ModelerControl("Head Y Rotate", -5, 5, 1, 0);
	controls[HEAD_Z_ROTATION] = ModelerControl("Head Z Rotate", -30, 30, 1, 0);
	controls[LEFT_UPPER_ARM_ROTATION] = ModelerControl("Left Upper Arm Rotation", -110, 180, 1, 0);
	controls[LEFT_FORE_ARM_ROTATION] = ModelerControl("Left Fore Arm Rotation", 0, 160, 1, 0);
	controls[RIGHT_UPPER_ARM_ROTATION] = ModelerControl("Right Upper Arm Rotation", -110, 180, 1, 0);
	controls[RIGHT_FORE_ARM_ROTATION] = ModelerControl("Right Fore Arm Rotation", 0, 160, 1, 0);
    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
