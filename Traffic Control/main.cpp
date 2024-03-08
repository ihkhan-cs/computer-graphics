#include <iostream>
using namespace std;
#include <windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include <math.h>



#define pi 3.14159265358979323846

GLfloat car1 = 0.0f, car2 = 0.0f, car3 = 0.0f, car4 = 0.0f;
GLfloat rainX = 0.0f, rainY = 0.0f;
GLfloat day_r = 1.0f, day_g = 1.0f, day_b = 0.8f;
GLfloat sun_x = 800.0f, sun_y = 850.0f, sun_r = 1.0f, sun_g = 0.7f, sun_b = 0.0f;
GLfloat t1r[3]={0,0,0}, t1g[3]={0,0,1}, t1b[3]={0,0,0};
GLfloat birdX=0.7f,birdY=-0.15f;


int t1ch = 1;


bool rain = false;
bool day = true;
bool isFullScreen = false;

void birdMoves(int x)
{
    if (birdX < -1.00 || birdY > 1.00) {
      if (!day) return;
      birdX = 0.7;
      birdY = -0.15;
    }
    birdX-=.001;
    birdY+=.0001;

}

void runCars (int v) {
  if (!(t1ch == 0 && (car1 >= -0.85f && car1 <= -0.80f))&&car3>-.25&&car4>-.25)
    car1 += 0.0012f;
  if (car1 > 3.0f) {
    car1 = -2.0f;
  }
  if (!(t1ch == 0 && (car2 >= -0.07f && car2 <= -0.05f))&&car3>-.25&&car4>-.15)
    car2 += 0.0011f;
  if (car2 > 3.0f) {
    car2 = -2.0f;
  }

  if ((t1ch == 0|| (car3<-.25||(car3<.6&&car3>-.20)))&&(car1< -.2&&car2< -0.05)) {
    car3 -= 0.0012f;

    if (car3 < -1.5f) car3 = 0.2f;

  }
  if ((t1ch == 0 || (car4<-.25||(car4<.6&&car4>-.10)))&&(car1<-.2&&car2<-0.05)) {
    car4 -= 0.001f;
  if (car4 < -1.5f) car4 = 0.4f;
  }
}
void bird()
{

  glScalef(1.3,1.3,0);
  glTranslatef(0,-.1,0);
  glPushMatrix();
  glTranslatef(birdX,birdY,0);
  glBegin(GL_LINES);

  glColor3f(1,0,0);
  glVertex2f(0.2f,0.8f);
  glVertex2f(0.18f,0.77f);

  glVertex2f(0.18f,0.77f);
  glVertex2f(0.15f,0.79f);

  glVertex2f(0.13f,0.8f);
  glVertex2f(0.11f,0.77f);

  glVertex2f(0.11f,0.77f);
  glVertex2f(0.08f,0.79f);

  glEnd();
  glPopMatrix();
  glLoadIdentity();
  glutTimerFunc(100,birdMoves,0);

}


void keepRaining (int v) {
   if (rain) {
     rainX -= 0.1f;
     rainY -= 0.1f;
     if (rainX < -0.1f) {
      rainX = 0.0f;
      rainY = 0.0f;
     }

     glutTimerFunc(100, keepRaining, 0);
   }

}

void raiseMoon (int v) {
   if (sun_b == 0.0f) {
     sun_g = 1.0f; sun_b = 1.0f;
   }
   if (sun_y < 850.0f) {
     sun_y += 10.0f;
     glutTimerFunc(100, raiseMoon, 0);
   }
   else return;
}

void raiseSun (int v) {
   if (sun_b == 1.0f) {
     sun_g = 0.7f, sun_b = 0.0f;
   }
   if (sun_y < 850.0f) {
     sun_y += 10.0f;
     glutTimerFunc(100, raiseSun, 0);

   }
}

void day_night (int v) {
   if (!day) {
     if (day_r <= 0.0f && day_g <= 0.0f && day_b <= 0.0f) {

        glutTimerFunc(100, raiseMoon, 0);
        return;
     }

     if (day_g > 0.0f) day_g -= 0.03f;
     else if (day_r > 0.0f) day_r -= 0.03f;
     else if (day_b > 0.0f) day_b -= 0.03f;
     if (sun_y > 400) sun_y -= 10.0f;
     glutTimerFunc(100, day_night, 0);
   }
   else {
     if (day_r == 1.0f && day_g == 1.0f && day_b == 0.8f) {
       glutTimerFunc(100, raiseSun, 0);
      // bird();
       return;
     }
     if (day_r < 1.0f) day_r += 0.03f;
     else if (day_b < 0.8f) day_b += 0.03f;
     else if (day_g < 1.0f) day_g += 0.03f;
     if (sun_y > 400) sun_y -= 10.0f;
     glutTimerFunc(100, day_night, 0);
   }
}

void Idle()
{
    glutPostRedisplay();
}

void keyboardControl (unsigned char key, int x, int y) {
    switch (key) {
      case 'r':
      if (rain) {
        rain = false;
        sndPlaySound(" ", SND_ASYNC);
      }
      else {
        rain = true;
        sndPlaySound("C:/Users/User/Desktop/Traffic Control/audio/rain.wav", SND_ASYNC);
        glutTimerFunc(100, keepRaining, 0);
      }
      break;

      case 'f':
            isFullScreen = !isFullScreen;
            (isFullScreen) ? glutFullScreen() : glutReshapeWindow(1200, 800);
        break;

      case 'e':
            exit(0);

      case 't':
      t1ch++;
      t1ch %= 3;
      if(!rain){
            sndPlaySound("C:/Users/User/Desktop/Traffic Control/audio/horn.wav", SND_ASYNC);
      }

      for (int i = 0; i < 3; i++) {
        t1r[i] = 0.0f; t1g[i] = 0.0f; t1b[i] = 0.0f;
      }

      if (t1ch == 1) {
        t1r[1] = 1.0f; t1g[1] = 1.0f; t1b[1] = 0.0f;
      }
      else if (t1ch == 2) {
        t1r[2] = 0.0f; t1g[2] = 1.0f; t1b[2] = 0.0f;
      }
      else {
        t1r[0] = 1.0f; t1g[0] = 0.0f; t1b[0] = 0.0f;
      }

      break;
    }
    glutPostRedisplay();
}


void showText(string text, float x, float y, int R, int G, int B){
    glColor3ub(R, G, B);
    glRasterPos2f(x, y);
    int i;
    for (i = 0; i < text.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void instructions(){
    showText("t = traffic control; r = rain;", 0.37, -0.85, 255, 255, 255);
    showText("f = fullscreen; e = exit!", 0.37, -0.9, 255, 255, 255);
}


void mouseControl (int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
      if (day) {
        day = false;

        glutTimerFunc(100, day_night, 0);
      }
    }
    else if (button == GLUT_RIGHT_BUTTON) {
      if (!day) {

        day = true;
        glutTimerFunc(100, day_night, 0);

      }
    }
}

void drawCircle (GLfloat x, GLfloat y, GLfloat rad, GLfloat a, GLfloat b, GLfloat c) {
	x /= 1000.0; y /= 1000.0; rad /= 1000.0;
	int triangleAmount = 100;
	GLfloat twicePi = 2.0f * pi;
	glBegin(GL_TRIANGLE_FAN);
    glColor3f(a, b, c);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++) {
       glVertex2f( x + (rad * cos(i *  twicePi / triangleAmount)),
       y + (rad * sin(i * twicePi / triangleAmount)));
    }
	glEnd();
}

void drawTriangle (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat a, GLfloat b, GLfloat c) {
    x1 /= 1000.0; y1 /= 1000.0; x2 /= 1000.0; y2 /= 1000.0; x3 /= 1000.0; y3 /= 1000.0;
    glBegin(GL_TRIANGLES);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawLine (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat a, GLfloat b, GLfloat c , int w) {
    x1 /= 1000.0; y1 /= 1000.0; x2 /= 1000.0; y2 /= 1000.0;
    glLineWidth(w);
    glBegin(GL_LINES);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawQuad (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat a, GLfloat b, GLfloat c) {
    x1 /= 1000.0; y1 /= 1000.0; x2 /= 1000.0; y2 /= 1000.0; x3 /= 1000.0; y3 /= 1000.0; x4 /= 1000.0; y4 /= 1000.0;
    glBegin(GL_QUADS);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}




void display() {

	glClearColor(day_r, day_g, day_b, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0.0f, 0.0f, 0.0f);

	drawCircle(sun_x, sun_y, 130, sun_r, sun_g, sun_b);
    drawCircle(sun_x, sun_y, 130, sun_r, sun_g, sun_b);
	bird();

    // Upper Left box


    drawQuad(-1000, -250, -300, -250, -300, 500, -1000, 500, 0.8, 0.9, 0.5);
    drawQuad(-1000, -200, -350, -200, -350, 500, -1000, 500, 0, 0.6, 0.2);
    glLoadIdentity();
    glTranslatef(-0.06f,0.0f,0.0f);
    drawQuad(-400,-150,-400,400,-900,400,-900,-150,0.7,0,0);
    drawTriangle(-350,400,-950,400,-650,550,0.1,0.2,0.27);
    drawLine(-400,125,-900,125,1,1,1,2);
    drawQuad(-600,-150,-600,50,-700,50,-700,-150,1,1,1);
    drawQuad(-850,70,-750,70,-750,-20,-850,-20,1,1,1);
    drawQuad(-450,70,-550,70,-550,-20,-450,-20,1,1,1);
    drawQuad(-550,200,-750,200,-750,350,-550,350,1,1,1);


    glLoadIdentity();

    //Upper Right box

    drawQuad(1000, -250, 1000, 500, 300, 500, 300, -250, 255, 255, 255);
    drawQuad(1000, -200, 1000, 500, 350, 500, 350, -200, 0, 0.6, 0.2);

    glTranslatef(1.32f,0.0f,0.0f);
    drawQuad(-400,-150,-400,400,-900,400,-900,-150,0.7,0,0);
    drawTriangle(-350,400,-950,400,-650,550,0.1,0.2,0.27);
    drawLine(-400,125,-900,125,1,1,1,2);
    drawQuad(-600,-150,-600,50,-700,50,-700,-150,1,1,1);
    drawQuad(-850,70,-750,70,-750,-20,-850,-20,1,1,1);
    drawQuad(-450,70,-550,70,-550,-20,-450,-20,1,1,1);
    drawQuad(-550,200,-750,200,-750,350,-550,350,1,1,1);
    glLoadIdentity();




    // Lower - left corner
    drawQuad(-1000, -750, -1000, -1000, -300, -1000, -300, -750, 0, 0.6, 0.2);

    // Lower - Right corner
    drawQuad(1000, -750, 300, -750, 300, -1000, 1000, -1000, 0, 0.6, 0.2);

    //Roads

    drawQuad(300, -1000, -300, -1000, -300, 500, 300, 500, 0.8, 0.9, 1.0);
    drawQuad(1000, -750, -1000, -750, -1000, -250, 1000, -250, 0.8, 0.9, 1.0);


    // Car1
    glTranslatef(car1, 0, 0);
    glTranslatef(0.0, 0.0, 0);
    drawCircle(10, -480, 50, 0, 0, 0);
    drawCircle(10, -480, 10, 1, 1, 1);
    drawCircle(300, -480, 50, 0, 0, 0);
    drawCircle(300, -480, 10, 1, 1, 1);
    drawQuad(-40, -460, 350, -460, 350, -350, -40, -350, 0.7, 0.3, 0.9);
    drawCircle(-40, -405, 55, 0.7, 0.3, 0.9);
    drawCircle(350, -405, 55, 0.7, 0.3, 0.9);
    drawCircle(380, -405, 25, 1, 1, 1);
    drawQuad(340, -350, 300, -270, 10, -270, -30, -350, 0, 0.0, 0.0);
    drawQuad(-20, -350, 330, -350, 290, -290, 20, -290, 0.5, 1.0, 0.9);
    drawLine(162, -270, 162, -350, 0, 0.0, 0.0, 3);
    drawLine(-30, -352, 340, -350, 0, 0, 0, 2);
    drawLine(165, -350, 165, -460, 0, 0, 0, 2);
    glLoadIdentity();
    // End

    // Car2
    glTranslatef(car2, 0, 0);
    glTranslatef(-0.8, -0.2, 0);
    drawCircle(10, -480, 50, 0, 0, 0);
    drawCircle(10, -480, 10, 1, 1, 1);
    drawCircle(300, -480, 50, 0, 0, 0);
    drawCircle(300, -480, 10, 1, 1, 1);
    drawQuad(-40, -460, 350, -460, 350, -350, -40, -350, 0.9, 0.0, 0.0);
    drawCircle(-40, -405, 55, 0.9, 0.0, 0.0);
    drawCircle(350, -405, 55, 0.9, 0.0, 0.0);
    drawCircle(380, -405, 25, 1, 1, 1);
    drawQuad(340, -350, 300, -270, 10, -270, -30, -350, 0, 0.0, 0.0);
    drawQuad(-20, -350, 330, -350, 290, -290, 20, -290, 0.5, 1.0, 0.9);
    drawLine(162, -270, 162, -350, 0, 0.0, 0.0, 3);
    drawLine(-30, -352, 340, -350, 0, 0, 0, 2);
    drawLine(165, -350, 165, -460, 0, 0, 0, 2);
    glLoadIdentity();






    //3rd car
    glPushMatrix();
    glTranslatef(0, car3, 0);
    drawQuad(30,100,90,100,90,70,30,70,0,0,0);
    drawQuad(155,100,215,100,215,70,155,70,0,0,0);
    drawQuad(0,100,250,100,250,220,0,220,.7,.2,.5);
    drawQuad(0,220,250,220,200,350,50,350,0,0,0);
    drawQuad(30,220,220,220,180,320,80,320,.5,1,.9);
    drawCircle(60,150,40,1,1,1);
    drawCircle(185,150,40,1,1,1);
    glPopMatrix();
    glLoadIdentity();
    //End

    //4th car
    glPushMatrix();
    glTranslatef(0, car4, 0);
    glTranslatef(-.28,-0.2,0);
    drawQuad(30,100,90,100,90,70,30,70,0,0,0);
    drawQuad(155,100,215,100,215,70,155,70,0,0,0);
    drawQuad(0,100,250,100,250,220,0,220,.1,.4,.7);
    drawQuad(0,220,250,220,200,350,50,350,0,0,0);
    drawQuad(30,220,220,220,180,320,80,320,.5,1,.9);
    drawCircle(60,150,40,1,1,1);
    drawCircle(185,150,40,1,1,1);
    glLoadIdentity();

    // Raining
    if (rain) {
       glTranslatef(rainX, rainY, 0);
	   for (double i = -1.0f; i < 1.0f; i += 0.15f) {
          for (double j = -1.0f; j < 1.0f; j += 0.15f) {
            drawLine(i * 1000, j * 1000, (i - 0.1f) * 1000, (j - 0.1f) * 1000, 1, 1, 1, 1);
          }
	   }
	   glLoadIdentity();
    }


    //Traffic light
    glTranslatef(0.3, -0.9, 0);
    drawLine(50, 50, 50, 300, 0, 0, 0, 20);
    drawCircle(50, 550, 50, t1r[0], t1g[0], t1b[0]);
    drawCircle(50, 450, 50, t1r[1], t1g[1], t1b[1]);
    drawCircle(50, 350, 50, t1r[2], t1g[2], t1b[2]);

    glLoadIdentity();

    //show instructions

    glutTimerFunc(100, runCars, 0);\
    instructions();

	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutCreateWindow("Traffic Control");
	glutInitWindowSize(1200, 800);
	glutDisplayFunc(display);
	glutIdleFunc(Idle);
	glutKeyboardFunc(keyboardControl);
	glutMouseFunc(mouseControl);
	glutMainLoop();
	return 0;
}
