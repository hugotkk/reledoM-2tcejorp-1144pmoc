#include "Minion.h"

void Minion::draw() {
	ModelerView::draw();

	// draw the sample model
	setAmbientColor(.5f, .5f, .5f);
	setDiffuseColor(COLOR_MBLUE);
	
	glPushMatrix();
		glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		glScaled(VAL(WHOLE_SCALE_X),VAL(WHOLE_SCALE_Y),VAL(WHOLE_SCALE_Z));
		
		glTranslated(0, -3, 0);
		glRotated(-90, 1.0, 0.0, 0.0);

		// body rt:
		
		
		glPushMatrix(); 
		drawTextureCylinder(2, 1.75, 2);

			if(VAL(LEVEL)>=1){
			glPushMatrix();
			setDiffuseColor(COLOR_BLACK);
			glRotated(90,1,0,0);
			glTranslated(0,1.5,-2.1);
			drawWing();
			glPopMatrix();
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
			}

			// head start 
			
			if(VAL(LEVEL)>=2){
			glPushMatrix(); 
				setDiffuseColor(COLOR_RED);
				glTranslated(0, 0, 2);
				glRotated(VAL(HEAD_X_ROTATION), 1.0, 0.0, 0.0);
				glRotated(VAL(HEAD_Y_ROTATION), 0.0, 0.0, 1.0);
				glRotated(VAL(HEAD_Z_ROTATION), 0.0, 1.0, 0.0);
				drawCylinder(0.25, 0.25, 0.25); // head joint 

				
				if(VAL(LEVEL)>=3){
				glPushMatrix();
					setDiffuseColor(COLOR_YELLOW);
					glTranslated(0, 0, 0.25);
					drawCylinder(2, 2, 2); // head

					if(VAL(LEVEL)>=4){

					glPushMatrix(); 

						setDiffuseColor(COLOR_YELLOW);
						glTranslated(0, 0, 2);
						drawSphere(2);    // forehead 

						// Hair 
						if(VAL(LEVEL)>=5){


						glPushMatrix();
						setDiffuseColor(COLOR_DARK);
						//1.75
						glTranslated(0, 0, -0.25);
						drawCylinder(0.5, 2.1, 2.1); // 頭巾
						glPopMatrix();

						LSystem lSystem("X", VAL(L_SYSTEM_DEPTH), VAL(L_SYSTEM_ANGLE));
						lSystem.expan(0);

						glPushMatrix(); 
							setDiffuseColor(COLOR_BLACK);
							glTranslated(0, 0, 1);
							//drawCylinder(0.6, 0.1, 0.1);
							glPushMatrix();
								glRotated(90, 1.0, 0.0, 0.0);
								lSystem.drawLSystem();
							glPopMatrix();
						glPopMatrix();
						
						glPushMatrix(); 
							setDiffuseColor(COLOR_BLACK);
							glRotated(-10, 0.0, 1.0, 0.0);
							glTranslated(0, 0, 1);
							//drawCylinder(0.6, 0.1, 0.1);
							glPushMatrix();
								glRotated(90, 1.0, 0.0, 0.0);
								lSystem.drawLSystem();
							glPopMatrix();
						glPopMatrix();
						
						glPushMatrix(); 
							setDiffuseColor(COLOR_BLACK);
							glRotated(10, 0.0, 1.0, 0.0);
							glTranslated(0, 0, 1);
							//drawCylinder(0.6, 0.1, 0.1);
							glPushMatrix();
								glRotated(90, 1.0, 0.0, 0.0);
								lSystem.drawLSystem();
							glPopMatrix();
						glPopMatrix();
						}

					glPopMatrix();
					}

					
					if(VAL(LEVEL)>=4){
					glPushMatrix(); 
						setDiffuseColor(COLOR_GREY);
						glRotated(90, 1.0, 0.0, 0.0);
						glTranslated(0.75, 2, 2);
						drawCylinder(0.25, 0.75, 0.75); // glasses 

						
						if(VAL(LEVEL)>=5){
						glPushMatrix(); 
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0.0, 0.0, 0.25);
							drawCylinder(0.05, 0.6, 0.6); // eye 

							
							if(VAL(LEVEL)>=6){
							glPushMatrix(); 
								setDiffuseColor(COLOR_BLACK);
								glTranslated(0.0, 0.0, 0.05);
								drawCylinder(0.05, 0.1, 0.1); // eye pig 
							glPopMatrix();
							}

						glPopMatrix();
						}

					glPopMatrix();
					}

					
					if(VAL(LEVEL)>=4){
					glPushMatrix(); 
						setDiffuseColor(COLOR_GREY);
						glRotated(90, 1.0, 0.0, 0.0);
						glTranslated(-0.75, 2, 2);
						drawCylinder(0.25, 0.75, 0.75); // glasses 

						
						if(VAL(LEVEL)>=5){
						glPushMatrix(); 
							setDiffuseColor(COLOR_WHITE);
							glTranslated(0.0, 0.0, 0.25);
							drawCylinder(0.05, 0.6, 0.6); // eye

							
							if(VAL(LEVEL)>=6){
							glPushMatrix(); 
								setDiffuseColor(COLOR_BLACK);
								glTranslated(0.0, 0.0, 0.05);
								drawCylinder(0.05, 0.1, 0.1); // eye pig
							glPopMatrix();
							}
						glPopMatrix();
						}

					glPopMatrix();
					}

					
					if(VAL(LEVEL)>=4){
					glPushMatrix(); 
						// Mouth
						setDiffuseColor(COLOR_BLACK);
						glTranslated(-1, -2.0, 0);
						drawBox(2, 1.5, 1);

						// Tongue
						
						if(VAL(LEVEL)>=5){
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
						}
					glPopMatrix();
					}

				glPopMatrix();
				}

			glPopMatrix();
			
			// head end

			// left hand
			

			glPushMatrix(); 
				// arm1 start
				setDiffuseColor(COLOR_YELLOW);
				glTranslated(-2.8, 0, 1);
				glTranslated(0, 0.25, 1.07);
				glRotated(-animate(LEFT_UPPER_ARM_ROTATION_X, 110, -110, 11), 1.0, 0.0, 0.0);
				glRotated(-VAL(LEFT_UPPER_ARM_ROTATION_Y), 0.0, 0.0, 1.0);
				glTranslated(0, -0.25, -1.07);
				drawBox(0.5, 0.5, 1.07);
				// arm joint start
				
				if(VAL(LEVEL)>=3){
				glPushMatrix(); 
					glRotated(VAL(LEFT_UPPER_ARM_ROTATION_Z), 0.0, 1.0, 0.0);
					setDiffuseColor(COLOR_RED);
					glTranslated(0.25, 0.25, -0.13);
					drawCylinder(0.13, 0.125, 0.125);
					// arm2 start
					
					if(VAL(LEVEL)>=4){
					glPushMatrix(); 
						glRotated(-VAL(LEFT_FORE_ARM_ROTATION_Y), 0.0, 0.0, 1.0);
						glRotated(VAL(LEFT_FORE_ARM_ROTATION_Z), 0.0, 1.0, 0.0);
						setDiffuseColor(COLOR_YELLOW);
						glTranslated(0, 0, -0.53);
						drawCylinder(0.53, 0.17, 0.17);
						// hand start
						
						if(VAL(LEVEL)>=5){
						glPushMatrix(); 
							setDiffuseColor(COLOR_BLACK);
							glTranslated(0, 0, -0.13);
							drawSphere(0.27);
						glPopMatrix();
						}
					// hand end
					glPopMatrix();
					}
				// arm2 end
				glPopMatrix();
				}
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
				glRotated(-animate(RIGHT_UPPER_ARM_ROTATION_X, 110, -110, 11), 1.0, 0.0, 0.0);
				glRotated(VAL(RIGHT_UPPER_ARM_ROTATION_Y), 0.0, 0.0, 1.0);
				glTranslated(0, -0.25, -1.07);
				drawBox(0.5, 0.5, 1.07);
				// arm joint start
				
				if(VAL(LEVEL)>=3){
				glPushMatrix(); 
					glRotated(-VAL(RIGHT_UPPER_ARM_ROTATION_Z), 0.0, 1.0, 0.0);
					setDiffuseColor(COLOR_RED);
					glTranslated(0.25, 0.25, -0.13);
					drawCylinder(0.13, 0.125, 0.125);
					// arm2 start
					
					if(VAL(LEVEL)>=4){
					glPushMatrix(); 
						glRotated(VAL(RIGHT_FORE_ARM_ROTATION_Y), 0.0, 0.0, 1.0);
						glRotated(-VAL(RIGHT_FORE_ARM_ROTATION_Z), 0.0, 1.0, 0.0);
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
					}
				// arm2 end
				glPopMatrix();
				}
				// arm joint end
				// arm1 end
			glPopMatrix();
			
			// right hand end

			// left leg
			

			glPushMatrix(); 
				// leg start
				setDiffuseColor(COLOR_MBLUE);
				glRotated(animate(LEFT_LEG_ROTATION, 15, -15, 1.5), 1.0, 0.0, 0.0);
				glTranslated(-1.0, 0, -0.6);
				drawCylinder(0.5, 0.5, 0.6);
				// shoe start
				
				if(VAL(LEVEL)>=3){
				glPushMatrix(); 
					setDiffuseColor(COLOR_BLACK);
					glTranslated(-0.5, -1.2, -0.5);
					drawBox(1.0, 1.5, 0.5);
				glPopMatrix();
				}
				// shoe end
				// leg end
			glPopMatrix();
			}

			// right leg
			
			if(VAL(LEVEL)>=2){
			glPushMatrix(); 
				// leg start
				setDiffuseColor(COLOR_MBLUE);
				glRotated(animate(RIGHT_LEG_ROTATION, 15, -15, 1.5), 1.0, 0.0, 0.0);
				glTranslated(1.0, 0, -0.6);
				drawCylinder(0.5, 0.5, 0.6);
				// shoe start
				
				if(VAL(LEVEL)>=3){
				glPushMatrix(); 
					setDiffuseColor(COLOR_BLACK);
					glTranslated(-0.5, -1.2, -0.5);
					drawBox(1.0, 1.5, 0.5);
				glPopMatrix();
				}
			// shoe end
			// leg end
			glPopMatrix();
			}

		glPopMatrix();
		

	glPopMatrix(); 
}
