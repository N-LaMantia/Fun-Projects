// glut_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//this code creates a heart in openGL language
#include <iostream>


float spin = 0.0; 

#include  "glut.h"

void init(void)
{
  gluOrtho2D(-1, 1, -1, 1); //window size, -x, x, -y, y

}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);


  glPushMatrix(); 
  glRotatef(spin, 0.0, 1.0, 1.0);
  
  glBegin(GL_POLYGON);
  //glVertex3f(0.0, 0.5, 0.0);
  //glVertex3f(-0.1, 0.6, 0.0);
  //glVertex3f(-0.2, 0.7, 0.0); 
  //glVertex3f(-0.3, 0.8, 0.0); 
  //glVertex3f(-0.4, 0.9, 0.0);
  //glVertex3f(-0.5, 1.0, 0.0);

  //glVertex3f(-0.6, 0.9, 0.0);
  //glVertex3f(-0.5, 0.8, 0.0);
  //glVertex3f(-0.4, 0.7, 0.0);
  //glVertex3f(-0.3, 0.6, 0.0);
  /*
  glVertex3f(-0.2, 0.5, 0.0);
  glVertex3f(-0.1, 0.4, 0.0);
  glVertex3f(0.0, 0.3, 0.0);
  glVertex3f(0.1, 0.2, 0.0); 
  glVertex3f(0.2, 0.1, 0.0);
  glVertex3f(0.3, 0.0, 0.0); */
  glVertex3f(0.0, 0.0, 0.0);
  glColor3f(1.0, 0.2, 0.0);
  glVertex3f(0.1, 0.1, 0.0);
  glVertex3f(0.2, 0.2, 0.0);// right side of heart
  glVertex3f(0.3, 0.3, 0.0);
  glVertex3f(0.4, 0.4, 0.0);
  glColor3f(0.8, 0.4, 0.0); 
  glVertex3f(0.5, 0.5, 0.0);

  glVertex3f(-0.0, 0.0, 0.0);
  glVertex3f(-0.1, 0.1, 0.0);
 
  glVertex3f(-0.2, 0.2, 0.0);
  glVertex3f(-0.3, 0.3, 0.0); //left side of heart
  glVertex3f(-0.4, 0.4, 0.0);
  glVertex3f(-0.5, 0.5, 0.0);
  glColor3f(0.6, 0.3, 0.0); 
  
  glVertex3f(-0.48, 0.52, 0.0);
  glVertex3f(-0.46, 0.54, 0.0);
  glVertex3f(-0.44, 0.56, 0.0); 
  glVertex3f(-0.42, 0.58, 0.0); //left curved side of heart 
  glVertex3f(-0.4, 0.6, 0.0);
  
  
  glVertex3f(-0.38, 0.62, 0.0);
  glVertex3f(-0.3, 0.7, 0.0);
  glVertex3f(-0.1, 0.55, 0.0);
  glVertex3f(-0.05, 0.505, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
 
 
  
  glVertex3f(0.48, 0.52, 0.0);
  glVertex3f(0.46, 0.54, 0.0);
   
  glVertex3f(0.44, 0.56, 0.0); //right curved side
  glVertex3f(0.42, 0.58, 0.0);
  glVertex3f(0.4, 0.6, 0.0);
 
 
  glVertex3f(0.38, 0.62, 0.0);
  glVertex3f(0.3, 0.7, 0.0);
  glVertex3f(0.1, 0.55, 0.0);
  glVertex3f(0.05, 0.505, 0.0);
  glVertex3f(0.0, 0.5, 0.0); 
  
 
  glutSwapBuffers(); 
  
  glEnd();
  glPopMatrix();
  glFlush();
}

void Timer(int value)
{
  spin = spin + 1;

  if (spin > 360.0) {
    spin = spin + 360;
  }

  glutPostRedisplay();

  glutTimerFunc(30, Timer, 0);

}

int main(int argc, char** argv)
{
  glutCreateWindow("My love for you");
  init();
  glutDisplayFunc(display);
  glutTimerFunc(0, Timer, 0); 
  glutMainLoop();

  return 0;
}
