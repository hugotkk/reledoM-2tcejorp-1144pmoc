#include "Minion.h"

void Minion::draw() {
	ModelerView::draw();

	// draw the sample model
	setAmbientColor(.5f, .5f, .5f);
	setDiffuseColor(COLOR_MBLUE);
	
	glPushMatrix();
		glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		glTranslated(0, -2, 0);
		glRotated(-90, 1.0, 0.0, 0.0);

		// body start
		glPushMatrix();
			drawCylinder(2, 1.75, 2); //¨­

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
				glRotated(VAL(HEAD_X_ROTATION), 1.0, 0.0, 0.0);
				glRotated(VAL(HEAD_Y_ROTATION), 0.0, 1.0, 0.0);
				glRotated(VAL(HEAD_Z_ROTATION), 0.0, 0.0, 1.0);
				drawCylinder(0.25, 0.25, 0.25); // head joint

				glPushMatrix();
					setDiffuseColor(COLOR_YELLOW);
					glTranslated(0, 0, 0.25);
					drawCylinder(2, 2, 2); // head

					glPushMatrix();
						glTranslated(0, 0, 2);
						drawSphere(2);    //¤ÑÆF»\

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
						drawCylinder(0.25, 0.75, 0.75); // ¥k²´Ãè

						glPushMatrix();
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0.0, 0.0, 0.25);
							drawCylinder(0.05, 0.6, 0.6); // ¥k²´

							glPushMatrix();
								setDiffuseColor(COLOR_BLACK);
								glTranslated(0.0, 0.0, 0.05);
								drawCylinder(0.05, 0.1, 0.1); // ¥k²´¯]
							glPopMatrix();

						glPopMatrix();

					glPopMatrix();

					glPushMatrix();
						setDiffuseColor(COLOR_GREY);
						glRotated(90, 1.0, 0.0, 0.0);
						glTranslated(-0.75, 2, 2);
						drawCylinder(0.25, 0.75, 0.75); // ¥ª²´Ãè

						glPushMatrix();
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0.0, 0.0, 0.25);
							drawCylinder(0.05, 0.6, 0.6); // ¥ª²´

							glPushMatrix();
								setDiffuseColor(COLOR_BLACK);
								glTranslated(0.0, 0.0, 0.05);
								drawCylinder(0.05, 0.1, 0.1); // ¥ª²´¯]
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
				glTranslated(-2.8, 0, 1);
				glTranslated(0, 0.25, 1.07);
				glRotated(-VAL(LEFT_UPPER_ARM_ROTATION), 1.0, 0.0, 0.0);
				glTranslated(0, -0.25, -1.07);
				drawBox(0.5, 0.5, 1.07);
				// arm joint start
				glPushMatrix();
					setDiffuseColor(COLOR_RED);
					glRotated(-VAL(LEFT_FORE_ARM_ROTATION), 1.0, 0.0, 0.0);
					glTranslated(0.25, 0.25, -0.13);
					drawCylinder(0.13, 0.125, 0.125);
					// arm2 start
					glPushMatrix();
						setDiffuseColor(COLOR_YELLOW);
						glTranslated(0, 0, -0.53);
						drawCylinder(0.53, 0.17, 0.17);
						// hand start
						glPushMatrix();
							setDiffuseColor(COLOR_BLACK);
							glTranslated(0, 0, -0.13);
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
				glTranslated(2.3, 0, 1);
				glTranslated(0, 0.25, 1.07);
				glRotated(-VAL(RIGHT_UPPER_ARM_ROTATION), 1.0, 0.0, 0.0);
				glTranslated(0, -0.25, -1.07);
				drawBox(0.5, 0.5, 1.07);
				// arm joint start
				glPushMatrix();
					setDiffuseColor(COLOR_RED);
					glRotated(-VAL(RIGHT_FORE_ARM_ROTATION), 1.0, 0.0, 0.0);
					glTranslated(0.25, 0.25, -0.13);
					drawCylinder(0.13, 0.125, 0.125);
					// arm2 start
					glPushMatrix();
						setDiffuseColor(COLOR_YELLOW);
						glTranslated(0, 0, -0.53);
						drawCylinder(0.53, 0.17, 0.17);
					// hand start
					glPushMatrix();
						setDiffuseColor(COLOR_BLACK);
						glTranslated(0, 0, -0.13);
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

			// ¥ª¸}
			glPushMatrix();
				// ¤jµÊ start
				setDiffuseColor(COLOR_MBLUE);
				glTranslated(-1.0, 0, -0.6);
				drawCylinder(0.5, 0.5, 0.6);
				// ¾c start
				glPushMatrix();
					setDiffuseColor(COLOR_BLACK);
					glTranslated(-0.5, -1.2, -0.5);
					drawBox(1.0, 1.5, 0.5);
				glPopMatrix();
				// ¾c end
				// ¤jµÊ end
			glPopMatrix();

			// ¥k¸}
			glPushMatrix();
				// ¤jµÊ start
				setDiffuseColor(COLOR_MBLUE);
				glTranslated(1.0, 0, -0.6);
				drawCylinder(0.5, 0.5, 0.6);
				// ¾c start
				glPushMatrix();
					setDiffuseColor(COLOR_BLACK);
					glTranslated(-0.5, -1.2, -0.5);
					drawBox(1.0, 1.5, 0.5);
				glPopMatrix();
			// ¾c end
			// ¤jµÊ end
			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
}