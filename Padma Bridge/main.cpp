//Padma bridge
#include <iostream>
using namespace std;
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846

GLfloat rain_pos = 0.0f, rain_speedX=0.15f, rain_speedY=0.3f;
int sky_r = 50, sky_g = 153, sky_b = 204, moon_r = 50, moon_g = 153, moon_b = 204, wat_r=48,wat_g=98,wat_b=159;
GLfloat sun_x = 0.0f, sun_y = .9f, moon_x=0.0f, moon_y=0.0f ;
GLfloat birdX=0.7f,birdY=-0.15f;
GLfloat x,y,z,d=0,n=1,radius, twicePi;
int triangleAmount,i;

GLfloat positionc = 0.0f;
GLfloat speedc = 0.02f;

GLfloat positiont = 0.0f;
GLfloat speedt = 0.04f;

GLfloat positiontr = 0.0f;
GLfloat speedtr = 0.04f;

GLfloat position = 0.0f;
GLfloat speed = 0.05f;

GLfloat positionr = 0.0f;           //rain
GLfloat speedr = 0.06f;

GLfloat position1 = 0.0f;
GLfloat speed1 = 0.02f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.02f;

bool is_rain = false, day = true;
void display();
void day_night (int v);
void keep_raining(int v);
void sound();
void sound2();


void update(int value) {

    if(position >2.0)
        position = -2.0f;

    position += speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void updatet(int value) {

    if(positiont >1.0)
        positiont = -2.4f;

    positiont += speedt; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, updatet, 0);
}
void updatetr(int value) {

    if(positiontr <-1.0)
        positiontr = 2.4f;

    positiontr -= speedtr; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, updatetr, 0);
}
void updater(int value) {

    if(positionr <-1.4)
        positionr = 1.0f;

    positionr -= speedr; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, updater, 0);
}
void update1(int value) {

    if(position1 >1.9)
        position1 = -1.5f;

    position1 += speed1; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}
void update2(int value) {

    if(position2 <-1.5)
        position2 = 1.5f;

    position2 -= speed2; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update2, 0);
}
void updatec(int value){
    if(positionc >1.2)
        positionc = -2.4f;

    positionc += speedc; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, updatec, 0);
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'p':

     speedc = 0.0f;
     speedt = 0.0f;
     speedtr = 0.0f;
     speed = 0.0f;//rain
     speedr = 0.0f;
     speed1 = 0.0f;
     speed2 = 0.0f;


    break;
case 'r':
    speedc = 0.02f;
     speedt = 0.04f;
     speedtr = 0.04f;
     speed = 0.05f;//rain
     speedr = 0.06f;
     speed1 = 0.02f;
     speed2 = 0.02f;
    break;
case '+':
    speedc += 0.005f;
     speedt += 0.009f;
     speedtr += 0.009f;
     speed += 0.009f;//rain
     speedr += 0.005f;
     speed1 += 0.005f;
     speed2 += 0.005f;
    break;
case '_':
    speedc -= 0.005f;
     speedt -= 0.009f;
     speedtr -= 0.009f;
     speed -= 0.009f;//rain
     speedr -= 0.005f;
     speed1 -= 0.005f;
     speed2 -= 0.005f;

    break;
glutPostRedisplay();
	}
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
        if (day) {
        day = false;
        glutTimerFunc(100, day_night, 0);
      }

	}

    if (button == GLUT_RIGHT_BUTTON)
    {
        if (!day) {

        day = true;
        glutTimerFunc(100, day_night, 0);

      }

    }
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{
    case GLUT_KEY_UP:
        if (is_rain) {

            is_rain = false;
            sound2();
            glutPostRedisplay();
            //glutTimerFunc(100, keep_raining, 0);
            }
            break;
    case GLUT_KEY_DOWN:
        if (!is_rain) {

        is_rain = true;
        sound();
        glutTimerFunc(100, keep_raining, 0);

      }
    break;
    case GLUT_KEY_LEFT:

    break;
    case GLUT_KEY_RIGHT:

    break;
}
glutPostRedisplay();
}

void sound()
{
    PlaySound("rain.wav",NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound2()
{
    //PlaySound(".wav",NULL, SND_ASYNC);
    PlaySound(NULL, 0, 0);
}

void keep_raining (int v) {
   if (is_rain) {
     rain_pos -= 0.1f;
     if (rain_pos < -2.0f) {
      rain_pos = 1.0f;
     }
     glutTimerFunc(100, keep_raining, 0);
   }
   else
   {
       glutPostRedisplay();
   }
}


void raiseMoon (int v) {
   if (moon_r < 254 || moon_g<252 || moon_b<215) {
        if(moon_r < 254)
        {
            moon_r += 2;
        }

        if(moon_g < 252)
        {
            moon_g += 2;
        }
        if(moon_b < 215)
        {
            moon_b += 2;

        }

     glutTimerFunc(40, raiseMoon, 0);
   }
   else
   {
       return;
   }
}

void day_night (int v) {
   if (!day) {

     if (sky_r > 10)
     {
         sky_r -= 2;
         moon_r=sky_r;
     }
      if (sky_g > 13)
     {
         sky_g -= 7;
         moon_g=sky_g;
     }
      if (sky_b > 44)
     {
         sky_b -= 8;
         moon_b=sky_b;
     }

     if (wat_r > 2)
     {
         wat_r -= 2;

     }
      if (wat_g > 41)
     {
         wat_g -= 3;

     }
      if (wat_b > 107)
     {
         wat_b -= 2.5;

     }

     if (sun_y > .5f)
     {
         sun_y -= .05f;
     }

     d=1;
     n=0;

     if (sky_r <= 10 && sky_g <= 13 && sky_b <= 44 && wat_r <= 2) {

        glutTimerFunc(100, raiseMoon, 0);

        return;
     }
     glutTimerFunc(100, day_night, 0);
   }
   else
    {

     if (sky_r >= 50 && sky_g >= 153 && sky_b >= 204 && wat_r >= 48) {
       //glutTimerFunc(100, raiseSun, 0);
      // bird();
      wat_r=48,wat_g=98,wat_b=159;
       return;
     }
     if (sky_r < 50)
     {
         sky_r += 2;
         moon_r=sky_r;
     }
    if (sky_g < 153)
     {
         sky_g += 7;
         moon_g=sky_g;
     }
    if (sky_b < 204)
     {
         sky_b += 8;
         moon_b=sky_b;
     }

     if (wat_r <48)
     {
         wat_r += 2;

     }
      if (wat_g <98)
     {
         wat_g += 3;

     }
      if (wat_b <159)
     {
         wat_b += 2.5;

     }

     if (sun_y < .93f)
     {
         sun_y += .02f;
     }
     d=0;
     n=1;

     glutTimerFunc(100, day_night, 0);
   }
}


void screen()
{
    gluOrtho2D(-1,1,-1,1);
}
void Idle()
{
    glutPostRedisplay();                  // marks the current window as needing to be redisplayed
}

void draw_circle (GLfloat x=0, GLfloat y=0, GLfloat rad=0.05, GLfloat r=10, GLfloat g=10, GLfloat b=100)
{
	int triangleAmount = 100;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x + (rad * cos(i *  twicePi / triangleAmount)),
                        y + (rad * sin(i * twicePi / triangleAmount)));
        }
	glEnd();
}

void draw_triangle (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat r=100, GLfloat g=100, GLfloat b=100)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void draw_line (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat r=100, GLfloat g=100, GLfloat b=100 , int w=1)
{
    glLineWidth(w);
    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void draw_quad (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat r=100, GLfloat g=100, GLfloat b=100)
{
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void draw_container (GLfloat x1, GLfloat y1, GLfloat height, GLfloat weight, GLfloat r=40, GLfloat g=70, GLfloat b=70)
{
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x1 + weight, y1);
    glVertex2f(x1 + weight, y1 + height);
    glVertex2f(x1, y1 + height);
    glEnd();
}

void draw_container_3d(GLfloat x1, GLfloat y1, GLfloat height, GLfloat weight, GLfloat r=40, GLfloat g=70, GLfloat b=70)
{
    GLfloat y2=y1 + height;
    GLfloat h=height*.3;

    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);//A
    glVertex2f(x1 + weight, y1);//B
    glVertex2f(x1 + weight, y1 + height);//C
    glVertex2f(x1, y1 + height);//D

    glColor3ub(r-10, g-10, b-10);
    glVertex2f(x1, y2);//A
    glVertex2f(x1 + weight, y2);//B
    glVertex2f(x1 + weight, y2 + h);//C
    glVertex2f(x1, y2 + h);//D
    glEnd();
}

void draw_window (GLfloat x, GLfloat y, GLfloat inc) {
   draw_quad(x, y, x + inc, y, x + inc, y + inc, x, y + inc, 90, 0, 0);
   draw_quad(x + inc*0.1, y + inc*0.1, x + inc - (inc*0.1), y + inc*0.1, x + inc - inc*0.1, y + inc - inc*0.1, x + inc*0.1, y + inc - inc*0.1, 50, 100, 90);
}

void rail_line(GLfloat y=0,GLfloat r=81, GLfloat g=81, GLfloat b=81)
{
    for (double i = -1.1f; i < 1.1f; i += .07) {
            draw_line(i, y-.01, i, (y + 0.04f), r, g, b, 8.0);         // vertical line on padma bridge
    }


    draw_line(-1.0,y+.03,1.0,y+.03,r,g,b,3);
    draw_line(-1.0,y,1.0,y,r,g,b,3);
}

void draw_pillar(GLfloat x=0, GLfloat y=0, GLfloat z=0, GLfloat xs=1, GLfloat ys=1, GLfloat zs=1)
{
    glTranslatef(x, y, z);
    glScalef(xs, ys, zs);
    glBegin(GL_POLYGON);
    glColor3ub(127, 127, 127);
    glVertex2f(-0.69f, 0.0f);   // bridge pillar under bottom
	glVertex2f(-0.86f, 0.0f);
	glVertex2f(-0.86f, -0.03f);
	glVertex2f(-0.83f, -0.07f);
	glVertex2f(-0.72f, -0.07f);
	glVertex2f(-0.69f, -0.03f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(132, 132, 132);
    glVertex2f(-0.72f, 0.04f);   // bridge pillar bottom
	glVertex2f(-0.83f, 0.04f);
	glVertex2f(-0.86f, 0.0f);
	glVertex2f(-0.83f, -0.04f);
	glVertex2f(-0.72f, -0.04f);
	glVertex2f(-0.69f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(138, 138, 138);    // bridge pillar head
	glVertex2f(-0.7f, 0.18f);
	glVertex2f(-0.85f, 0.18f);
	glVertex2f(-0.85f, 0.14f);
	glVertex2f(-0.7f, 0.14f);

	glColor3ub(130, 130, 130);
	glVertex2f(-0.85f, 0.14f);
	glVertex2f(-0.83f, 0.12f);
	glVertex2f(-0.72f, 0.12f);
	glVertex2f(-0.7f, 0.14f);

	glColor3ub(136, 136, 136);
	glVertex2f(-0.72f, 0.12f);   // bridge pillar body
	glVertex2f(-0.83f, 0.12f);
	glVertex2f(-0.83f, 0.0f);
	glVertex2f(-0.72f, 0.0f);
    glEnd();

    glLoadIdentity();
}

void draw_v_angle(GLfloat x=0, GLfloat y=0, GLfloat z=0, GLfloat r=150, GLfloat g=150, GLfloat b=150)
{
    glTranslatef(x-.025,y,z);
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2f(-0.95f, 0.44);                 // train side block back slash
	glVertex2f(-1.0f, 0.44f);
	glVertex2f(-0.8f, 0.18f);
    glVertex2f(-0.75f, 0.18f);

    glVertex2f(-0.55f, 0.44);                 // train side block forward slash
	glVertex2f(-0.6f, 0.44f);
	glVertex2f(-0.8f, 0.18f);
    glVertex2f(-0.75f, 0.18f);
    glEnd();
    glLoadIdentity();
}

void lampost(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
    glPushMatrix();
    glTranslated(x,y,z);

    draw_line(0.0f, .43f, 0.0f,.57f,70,55,70,5);   // lampost
    draw_line(0.0f,.57f,.03f,.6f,60,55,70,4);
    draw_circle(.03f,.6f,.007);

    glPopMatrix();
}
void light(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
    glPushMatrix();
    glTranslated(x,y+n,z);

    draw_triangle(.03f,.6f,-.03f,.43f,.09f,.43f,200,200,0);

    glPopMatrix();
}
void light_back(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
    glPushMatrix();
    glTranslated(x,y+n,z);

    draw_triangle(.03f, .73f, -.03f, .56f,.09f,.56f,200,200,0);

    glPopMatrix();
}
void lampost_back(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
    glPushMatrix();
    glTranslated(x,y,z);

    draw_line(0.0f, .57f, 0.0f,.7f,70,55,70,5);   // lampost back
    draw_line(0.0f,.7f,.03f,.73f,60,55,70,4);
    draw_circle(.03f,.73f,.007);

    glPopMatrix();
}

void cloud1()
{
    glPushMatrix();
    glTranslatef(positionc,d,0);
    glScalef(1,1,0);

    x=0.1f; y=0.8f;   radius =0.04f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),                   // cloud
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



    x=0.15f; y=0.82f;   radius =0.05f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),                 //cloud 2nd circle
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    x=0.21f; y=0.825f;   radius =0.04f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),            //cloud circle 3rd & end cloud
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();

}
void cloud2()
{

    glPushMatrix();
    glTranslatef(positionc+1.0,d+.02,0);
    glScalef(1,1,0);

    x=0.1f; y=0.8f;   radius =0.04f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),                   // cloud
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



    x=0.15f; y=0.82f;   radius =0.05f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),                 //cloud 2nd circle
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    x=0.21f; y=0.825f;   radius =0.04f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),            //cloud circle 3rd & end cloud
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();

}
void tire(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
    glPushMatrix();
    glTranslated(x,y,z);
    x=0.05f; y=0.0f; radius =.02f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(40, 45, 40);
		glVertex2f(x, y);           // Port Main vehicle tyre 1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.19f; y=0.0f; radius =.02f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(40, 45, 40);
		glVertex2f(x, y);           // Port Main vehicle tyre 1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glPopMatrix();
}
void train(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
     glPushMatrix();
     glTranslated(positiont+x,y,z);
     tire();
     tire(.27);
     tire(-.27);
     tire(.54);
     tire(-.54);
     tire(-.81);
     draw_line(.79f,0.015,-.81f,.015f,140,140,40,9);
     draw_container_3d(0.0,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(0.27,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(-0.27,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(0.54,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(-0.54,0.0,0.10,0.25, 89, 26, 38);

     draw_container_3d(-0.81,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(0.79,0.0,0.05,0.05, 89, 26, 38);

     glPopMatrix();
}
void trainr(GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
     glPushMatrix();
     glTranslated(positiontr+x,y,z);

     tire();
     tire(.27);
     tire(-.27);
     tire(.54);
     tire(-.54);
     tire(-.81);
     draw_line(.79f,0.015,-.81f,.015f,140,140,40,9);
     draw_container_3d(0.0,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(0.27,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(-0.27,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(0.54,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(-0.54,0.0,0.10,0.25, 89, 26, 38);

     draw_container_3d(-0.81,0.0,0.10,0.25, 89, 26, 38);
     draw_container_3d(-0.85,0.0,0.05,0.05, 89, 26, 38);
     glPopMatrix();
}
void car_pickup()
{
    glPushMatrix();
glTranslatef(position,.44,0);
glScalef(.5,.4,0);
//1
//polygon began
glBegin(GL_POLYGON);

	glColor3ub(102, 0, 0);
	glVertex2f(0.15f, 0.05f);
	glVertex2f(0.1f, 0.15f);
	glVertex2f(-0.35f, 0.15f);
	glVertex2f(-0.35f, 0.05f);

	glEnd();
//polygon end

//1
 x=-0.2f;
  y=0.05f;
  radius =0.05f;
 triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(18, 16, 19);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//circle end

//circle start
//2
    x=0.0f; y=.05f;   radius =.05f;
	triangleAmount = 20;
	twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(18, 16, 19);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//circle end
//polygon began
//4
glBegin(GL_POLYGON);

	glColor3ub(189, 216, 249);
	glVertex2f(0.1f, 0.15f);
	glVertex2f(0.05f, 0.2f);
	glVertex2f(0.0f, 0.2f);
	glVertex2f(0.0f, 0.15f);

	glEnd();
//polygon end
//triangle start
//5
glBegin(GL_TRIANGLES);
	glColor3ub(102, 0, 0);
	glVertex2f(0.05f, 0.2f);
	glVertex2f(0.0f, 0.25f);
	glVertex2f(0.0f, 0.2f);
	glEnd();
//triangle end

//quads start
//6
glBegin(GL_QUADS);
	glColor3ub(102, 0, 0);
	glVertex2f(0.0f, 0.25f);
	glVertex2f(-0.05f, 0.25f);
	glVertex2f(-0.05f, 0.15f);
	glVertex2f(0.0f, 0.15f);
	glEnd();
//quads end



//quads start
//7
glBegin(GL_QUADS);
	glColor3ub(41, 84, 44);
	glVertex2f(-0.05f, 0.2f);
	glVertex2f(-0.15f, 0.2f);
	glVertex2f(-0.15f, 0.15f);
	glVertex2f(-0.05f, 0.15f);
	glEnd();
//quads end
//quads start
//10
glBegin(GL_QUADS);
	glColor3ub(-0, 120, 255);
	glVertex2f(-0.1f, 0.3f);
	glVertex2f(-0.2f, 0.3f);
	glVertex2f(-0.2f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glEnd();
//quads end

//quads start
//8
glBegin(GL_QUADS);
	glColor3ub(18, 16, 19);
	glVertex2f(-0.15f, 0.15f);
	glVertex2f(-0.15f, 0.25f);
	glVertex2f(-0.25f, 0.25f);
	glVertex2f(-0.25f, 0.15f);
	glEnd();
//quads end
//quads start
//9
glBegin(GL_QUADS);
	glColor3ub(-0, 0, 255);
	glVertex2f(-0.25f, 0.15f);
	glVertex2f(-0.25f, 0.2f);
	glVertex2f(-0.3f, 0.2f);
	glVertex2f(-0.3f, 0.15f);
	glEnd();
//quads end
glPopMatrix();
glLoadIdentity();
//car end
}

void new_car_r()
{
    glPushMatrix();
    glTranslatef(positionr+0.5,.6,0);
    glScalef(.2,.2,0);

    glBegin(GL_POLYGON);
    glColor3ub(55, 16, 149);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(-0.6f, 0.1f);
    glVertex2f(-0.7f, -0.1f);
    glVertex2f(0.4f, -0.1f);
    glEnd();

    glBegin(GL_POLYGON);
  glColor3ub(55, 16, 149);
  glVertex2f(-0.2f, 0.1f);
  glVertex2f(-0.2f, 0.3f);
  glVertex2f(-0.4f, 0.3f);
  glVertex2f(-0.6f, 0.1f);
  glEnd();

  glBegin(GL_POLYGON);

  glColor3ub(0, 2, 0);

  glVertex2f(-0.34f, 0.16f);
  glVertex2f(-0.34f, 0.26f);
  glVertex2f(-0.44f, 0.26f);
  glVertex2f(-0.54f, 0.16f);

  glEnd();

      x=-.35; y=-.13;   radius =0.13f;
  triangleAmount = 20;
  twicePi = 2.0f * PI;
  glBegin(GL_TRIANGLE_FAN);
  glColor3ub(25, 25, 25);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++) {
      glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
          y + (radius * sin(i * twicePi / triangleAmount))
      );
    }
  glEnd();

  x=.16; y=-.13;   radius =0.13f;
  triangleAmount = 20;
  twicePi = 2.0f * PI;
  glBegin(GL_TRIANGLE_FAN);
  glColor3ub(25, 25, 25);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount;i++) {
      glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
          y + (radius * sin(i * twicePi / triangleAmount))
      );
    }
  glEnd();
  glPopMatrix();
}

void lorry(){
    glPushMatrix();
    glTranslatef(position,.46,0);
    glScalef(1,1,0);

    glBegin(GL_POLYGON);
    glColor3ub(10, 70, 120);
    glVertex2f(0.76f, 0.05f);
    glVertex2f(0.45f, 0.05f);    // Port Transportation vehicle(truck) back body
	glVertex2f(0.45f, 0.03f);
	glVertex2f(0.76f, 0.03f);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(120, 70, 120);
    glVertex2f(0.82f, 0.11f);
    glVertex2f(0.77f, 0.11f);    // Port Transportation vehicle(truck) front body
	glVertex2f(0.76f, 0.03f);
	glVertex2f(0.85f, 0.03f);
	glVertex2f(0.85f, 0.05f);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(229, 233, 254);
    glVertex2f(0.81f, 0.1f);
    glVertex2f(0.784f, 0.1f);    // Port Transportation vehicle(truck) front body window
	glVertex2f(0.78f, 0.07f);
	glVertex2f(0.82f, 0.07f);
    glEnd();

	x=0.8f; y=0.02f; radius =.025f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(56, 53, 56);
		glVertex2f(x, y);           // Port Main vehicle tyre 1
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.8f; y=0.02f; radius =.01f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(199, 200, 204);
		glVertex2f(x, y);           // Port Main vehicle tyre 1 ring
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.73f; y=0.019f; radius =.024f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(56, 53, 56);
		glVertex2f(x, y);           // Port Main vehicle tyre 2
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.73f; y=0.019f; radius =.008f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(199, 200, 204);
		glVertex2f(x, y);           // Port Main vehicle tyre 2 ring
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.54f; y=0.019f; radius =.024f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(56, 53, 56);
		glVertex2f(x, y);           // Port Main vehicle tyre 3
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.54f; y=0.019f; radius =.008f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(199, 200, 204);
		glVertex2f(x, y);           // Port Main vehicle tyre 3 ring
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.49f; y=0.019f; radius =.024f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(56, 53, 56);
		glVertex2f(x, y);           // Port Main vehicle tyre 4
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.49f; y=0.019f; radius =.008f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(199, 200, 204);
		glVertex2f(x, y);           // Port Main vehicle tyre 4 ring
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glPopMatrix();

}
void ship1()
{
    glPushMatrix();
    glTranslatef(position1,-.1,0);
    //ship
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.0,0.0);
    glVertex2f(-0.833f,-0.66f);
    glVertex2f(-0.33f, -0.66f);
    glVertex2f(-0.25f, -0.583f);
    glVertex2f(-0.916f,-0.583f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.4);
    glVertex2f(-0.833f,-0.583f);
    glVertex2f(-0.33f, -0.583f);
    glVertex2f(-0.416f, -0.5f);
    glVertex2f(-0.75f,-0.5f);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(111,151,170);
    glVertex2f(-0.66f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.583f,-0.33f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-0.583f,-0.33f);
    glVertex2f(-0.583f, -0.166f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,70,0);
    glVertex2f(-0.583f,-0.283f);
    glVertex2f(-0.48,-0.283f);
    glVertex2f(-0.48,-0.2166f);
    glVertex2f(-0.583f,-0.2166f);
    glEnd();

    draw_circle(-.532,-.2498,.025,200,0,0);

    //shipwindows//

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.75f,-0.566f);
    glVertex2f(-0.7f, -0.566f);
    glVertex2f(-0.7f, -0.516f);
    glVertex2f(-0.75f,-0.516f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.633f,-0.566f);
    glVertex2f(-0.583f, -0.566f);
    glVertex2f(-0.583f, -0.516f);
    glVertex2f(-0.633f,-0.516f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.516f,-0.566f);
    glVertex2f(-0.46f, -0.566f);
    glVertex2f(-0.46f, -0.516f);
    glVertex2f(-0.516f,-0.516f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.56,0.698);
    glVertex2f(-0.833f,-0.6833f);
    glVertex2f(-0.33f, -0.6833f);
    glVertex2f(-0.33f, -0.66f);
    glVertex2f(-0.833f,-0.66f);
    glEnd();

    glPopMatrix();
}

void ship2()
{
    glPushMatrix();
    glTranslatef(position2,-.1,0);
    glLineWidth(2);

	//glTranslatef(0.65,0,0);

	glBegin(GL_POLYGON);
    glColor3ub(67, 94, 114);
    glVertex2f(-0.2f, 0.0f);    // ship body 1
	glVertex2f(-.72f, 0.0f);
	glVertex2f(-0.64f, -0.1f);
	glVertex2f(-0.24f, -0.1f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(73, 61, 83);
    glVertex2f(-0.2f, 0.06f);    // ship 1 body block
	glVertex2f(-.33f, 0.06f);
	glVertex2f(-0.33f, -0.0f);
	glVertex2f(-0.2f, 0.0f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(177, 176, 174);
    glVertex2f(-0.2f, 0.06f);    // ship 1 body block top
	glVertex2f(-.2f, 0.12f);
	glVertex2f(-0.25f, 0.12f);
	glVertex2f(-0.25f, 0.06f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(251, 179, 12);
    glVertex2f(-0.29f, 0.12f);    // ship 1 crane body
	glVertex2f(-.32f, 0.12f);
	glVertex2f(-0.32f, 0.06f);
	glVertex2f(-0.29f, 0.06f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(224, 122, 23);
    glVertex2f(-0.28f, 0.15f);    // ship 1 crane head
	glVertex2f(-.3f, 0.15f);
	glVertex2f(-0.31f, 0.14f);
	glVertex2f(-0.32f, 0.12f);
	glVertex2f(-0.28f, 0.12f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(250, 171, 6);
    glVertex2f(-0.3f, 0.15f);    // ship 1 crane hand
	glVertex2f(-.47f, 0.21f);
	glVertex2f(-0.31f, 0.14f);
    glEnd();


	//ship 1 crane hand top circle
    x=-0.47f; y=0.21f; radius =.01f;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 183, 76);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


	//glLineWidth(0.01);
	glBegin(GL_LINES);// x,y axis
	glColor3ub(203, 203, 203);
	glVertex2f(-0.47f, 0.21f);    // crane hanging rope
	glVertex2f(-0.47f, 0.08f);
	glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(234, 89, 63);
    glVertex2f(-0.48f, 0.04f);    // ship 1 container 1
	glVertex2f(-.58f, 0.04f);
	glVertex2f(-0.58f, 0.0f);
	glVertex2f(-0.48f, 0.0f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(150, 225, 252);
    glVertex2f(-0.34f, 0.04f);    // ship 1 container 2
	glVertex2f(-.46f, 0.04f);
	glVertex2f(-0.46f, 0.0f);
	glVertex2f(-0.34f, 0.0f);
    glEnd();


	glBegin(GL_POLYGON);
    glColor3ub(10, 170, 120);
    glVertex2f(-0.42f, 0.08f);    // ship 1 container 3
	glVertex2f(-.52f, 0.08f);
	glVertex2f(-0.52f, 0.04f);
	glVertex2f(-0.42f, 0.04f);
    glEnd();

    glPopMatrix();
}
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glBegin(GL_QUADS);
    glColor3ub(sky_r, sky_g, sky_b);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);                // sky block
    glEnd();

    draw_circle(.8,.9,.05,moon_r,moon_g,moon_b);   //bright moon
    draw_circle(.83,.92,.05,sky_r, sky_g, sky_b);   //bright moon cover

    draw_circle(sun_x,sun_y,.05,251,252,170);  // sun

    cloud1();
    cloud2();

    glBegin(GL_QUADS);
    glColor3ub(wat_r,wat_g,wat_b);
    glVertex2f(1.0f, 0.55);                 // Water block
	glVertex2f(-1.0f, 0.55f);
	glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();

    draw_v_angle(0,.15,0,130,130,130);
    draw_v_angle(0.4,.15,0,130,130,130);
    draw_v_angle(0.8,.15,0,130,130,130);          //train inner side railing boundary
    draw_v_angle(1.2,.15,0,130,130,130);
    draw_v_angle(1.6,.15,0,130,130,130);

	glBegin(GL_QUADS);
    glColor3ub(33, 33, 33);
    glVertex2f(1.0f, 0.59f);
    glVertex2f(-1.0f, 0.59f);             // bridge road block
	glVertex2f(-1.0f, 0.44f);
	glVertex2f(1.0f, 0.44);
    glEnd();

    draw_line(-1.0f, 0.59f, 1.0f, 0.59f,136, 136, 136,10); // bridge back side railing
    draw_line(-1.0f, 0.51f, 1.0f, 0.51f,136, 136, 136,7); // bridge mid railing


    lampost_back();
    lampost_back(.4f);
    lampost_back(.8);
    lampost_back(-.4f);
    lampost_back(-.8f);
    light_back();
    light_back(.4f);
    light_back(.8f);
    light_back(-.4f);
    light_back(-.8);
    //vehicles
    lorry();
    car_pickup();
    // reverse vehicle
    new_car_r();

    light();
    light(.4f);
    light(.8f);
    light(-.4f);
    light(-.8);

    lampost();
    lampost(.4f);
    lampost(.8f);
    lampost(-.4f);
    lampost(-.8);


    glBegin(GL_QUADS);
    glColor3ub(33, 33, 33);
    glVertex2f(1.0f, 0.33f);
    glVertex2f(-1.0f, 0.33f);
	glVertex2f(-1.0f, 0.18f);                // bridge train road x axis
	glVertex2f(1.0f, 0.18f);
    glEnd();

    rail_line(0.205);
    rail_line(0.27);
    trainr(0,.28);
    train(0,.21);


    draw_v_angle(0);
    draw_v_angle(0.4);
    draw_v_angle(0.8);          //train front side railing boundary
    draw_v_angle(1.2);
    draw_v_angle(1.6);

    draw_line(-1.0f, 0.43f,1.0f, 0.43f,136, 136, 136,10);        // bridge road front side railing


	glBegin(GL_QUADS);
	glColor3ub(136, 136, 136);    // bridge side railing bottom axis
	glVertex2f(1.0f, 0.18f);
	glVertex2f(-1.0f, 0.18f);
	glVertex2f(-1.0f, 0.16f);
	glVertex2f(1.0f, 0.16);
	glEnd();

	draw_pillar();
	draw_pillar(1.55);
    //glPushMatrix();

    ship2();
    ship1();



    // Raining
    if (is_rain) {
        glPushMatrix();
        glTranslatef(rain_pos, rain_pos, 0);
	    for (double i = -2.0f; i < 3.0f; i += rain_speedX) {
          for (double j = 2.5f; j >= -2.0f; j -= rain_speedY) {
            draw_line(i, j, (i - 0.01f), (j - 0.05f), 250, 250, 250, 2.0);         // Raining on the padma bridge
          }
	    }
        glPopMatrix();
	    glLoadIdentity();
    }
	glLoadIdentity();
    glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(1280, 720);         // Set the window's initial width & height
	glutCreateWindow("Click left: nignt, Click right: day, Press down: rain, Press up: rain stop, Press p: stop all,Press r:start all,"); // Create a window with the given title
	glutDisplayFunc(display);              // Register display callback handler for window re-paint

	glutTimerFunc(100, keep_raining, 0);
	glutTimerFunc(100, updatec, 0);
	glutTimerFunc(100, updatet, 0);
	glutTimerFunc(100, updatetr, 0);
	glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, updater, 0);

    glutSpecialFunc(SpecialInput);
	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(handleMouse);

	glutIdleFunc(Idle);
	glutMainLoop();                        // Enter the event-processing loop

	return 0;
}
