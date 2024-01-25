#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include <mmsystem.h>
#define PI 3.141516

    float benchPosition = 0.0f;
    int benchSpeed = 45;
    float stopstart=0.0f;
    bool f= false;
    float cloudPosition=-1.0;
    float cloudSpeed=0.005;
    float sunPosition=-0.5;
    float sunSpeed=0.01;
    float ghostX = 0.0f;
    float ghostY = 0.0f;
    float ghostmovement = 1.5f;
    float ghostmovement3rd = 1.2f;
    float move_flow = 0.0f;
    float move_speed_boat =1.0f;
    float boatstartstop=0.5;
    float watermove =  0.05;
    float watermove2 = 0.053;
    float watermove3 = 0.048;
    float watermove4 = 0.047;
    float angle=0,bx=0.0,by=0.0;
    float angle_speed =0.0f;
    float bardspeed=0.02;
    float bardposition = 20;
    float trainmovent = 1.0f;
    float trainstartstop = 0.02f;
    int trainspeed = 35;
    float chairmove = 0.02f;
    float chairmove2 = 0.05f;
    float chairmove3 = 0.08f;
    float blackshipupdate= 1.0f;
    float blackshipstartstop = 0.0;
    float chairmovespeed = 0.0f;
    float chairmove2speed = 0.0f;
    bool fountainRunning = false;
    float centerX = 0.5f;
    float centerY = 0.5f;
    float angularFrequency = 0.1f;
    int rotationCount = 0;
    float translationSpeed = 0.0000005f; // Adjusted translation speed
    bool p = false;
    float glowAlpha = 0.0f; // Initial glow value
    bool isColorOn = false;  // Flag to indicate whether the circle color is on or off
    float speed = 0.02f;
    int resumeGhostMovement = 50;
    float speedMultiplier = 1.0f;    // Initial speed multiplier
    float scale = 1.0f; // Initial scale factor
    bool increasingScale = true; // Flag to control scale direction
    bool k = false;


    void circle1(float p1, float q1, float r1) //F1
{
    int i;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glVertex2f (p1,q1);
    for(i= 0; i<=tringle2; i++)
    {
        glVertex2f (
            p1+(r1*cos(i*tp2/tringle2)),
            q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd();
}

void circle_c(float radius, float cX, float cY) //F2
{

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
   glColor3ub(1.0,1.0,1.0);
    for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}

void circle_black(float radius, float cX, float cY) //F3
{

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(105,105,105);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}


void circle_all(float radius, float cX, float cY) //F4
{

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(241.0f,235.0f,156.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
   glEnd();
}

void circle_tree(float radius, float cX, float cY) //F5;
{
   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(0,102,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cX,y+cY);
        }
}


void circle_lamp(float radius, float cX, float cY, float alpha) //F6
{
    if (isColorOn)
    {
        glBegin(GL_POLYGON);
        for (int i = 0; i < 200; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 200;
            float r = radius;
            float x = r * cos(A);
            float y = r * sin(A);

            // Adjust the brightness based on glow effect
            float brightness = 0.5f + 0.5f * alpha;
            glColor3f(241.0f / 255.0f * brightness, 235.0f / 255.0f * brightness, 156.0f / 255.0f * brightness);
            glVertex2f(x + cX, y + cY);
        }
        glEnd();
    }
    else
    {
        glBegin(GL_POLYGON);
        for (int i = 0; i < 200; i++)
        {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 200;
            float r = radius;
            float x = r * cos(A);
            float y = r * sin(A);

            // Grey color when turned off
            glColor3ub(224.0f, 224.0f, 224.0f);
            glVertex2f(x + cX, y + cY);
        }
        glEnd();
    }
}


void HalfCircle(float r1,float r,float g,float b) //F7
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416/2;
        float A=(i*2*pi)/200;
        float r=r1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void ship() //F8
{


    // Draw your scene here using OpenGL functions
        // Base Line
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-7.5361338242086, 4.68160920905);
    glVertex2f(-5.9114381559027,0.7001945951846);
    glVertex2f(8.0228373829087, 0.7001945951846);
    glVertex2f(8.4408858318646, 3.6962084793681);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(165,42,42);
    glVertex2f(-6.2894634356413, 1.4943545306619);
    glVertex2f(-6.1083014376502, 1.0939117134655);
    glVertex2f(8.0673884661971, 1.1016139011283);
    glVertex2f(8.154664161649, 1.4725356067989);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(-3.7521939293472, 6.3786860268347);
    glVertex2f(-3.7447742018042, 4.4607806803594);
    glVertex2f(8.0198139848403, 3.7238835807652);
    glVertex2f(8.0455695423341, 5.1599337396419);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(-7.4101178577108, 5.3684022751914);
    glVertex2f(-7.4069735012713, 4.6738823080316);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(-7.4101178577108, 5.3684022751914);
    glVertex2f(-3.3167267950182, 5.0722846238477);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(-3.3167267950182, 5.0722846238477);
    glVertex2f(-3.2993081096451, 4.4277932650408);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(5.6, 7.0832325579927);
    glVertex2f(5.6, 5.4353160798914);
    glVertex2f(6.3, 5.378556402866);
    glVertex2f(6.3, 7.0832325579927);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(7.0, 7.5478002987359);
    glVertex2f(7.0, 5.2973123087423);
    glVertex2f(7.7, 5.2157995919706);
    glVertex2f(7.7, 7.5478002987359);
    glEnd();

    circle_c(0.4,2.8372947931585, 4.7063083271131);
    glEnd();
    circle_c(0.4,4.4288537924416, 4.7100329947702);
    glEnd();
    circle_c(0.4,6.034437199091, 4.6992098303546);
    glEnd();


    circle_c(0.75,-4.0, 3.0);
    glEnd();
    circle_black(0.5,-4.0, 3.0);
    glEnd();


    circle_c(0.75,-2,3.0);
    glEnd();
    circle_black(0.5,-2, 3);
    glEnd();



}





void cloud(float xc, float yc) //F9
{
    glColor3f(1, 1, 1);
    circle1(xc-0.12, yc-0.05, 0.05f);
    circle1(xc-0.16, yc-0.1, 0.05f);
    circle1(xc-0.09, yc-0.1, 0.05f);
}

void sky() //F10
{
    ///sky
    glBegin(GL_QUADS);            //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 1.0f, 1.0f); //// sky-blue
    glVertex2f(-1.0f, 0.4f);    //// x, y
    glVertex2f(1.0f, 0.4f);    //// x, y
    glVertex2f(1.0f, 1.0f);    //// x, y
    glVertex2f(-1.0f, 1.0f);    //// x, y
    glEnd();
}


void sun() //F11
{
    ///sun
    glColor3f(1,0.80,0);
    glPushMatrix();
    glTranslatef(0,sunPosition,0);
    circle1(0.8, 0.9, 0.05);
    glPopMatrix();
}
void Cloud() //F12
{
    ///cloud
    glPushMatrix();
    glTranslatef(cloudPosition+0.48,0.9,0);
    cloud(-0.3,0.0);
    cloud(0.2,0.1);
    cloud(0.5,-0.05);
    glPopMatrix();
}


void buildings() //F13
{

    ///1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(204.0f, 255.0f, 255.0f); //// sky-blue
    glVertex2f(-0.86f, 0.4f);    //// x, y
    glVertex2f(-0.76f, 0.4f);    //// x, y
    glVertex2f(-0.76f, 0.65f);    //// x, y
    glVertex2f(-0.86f, 0.65f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(192.0f, 192.0f, 192.0f); //// sky-blue
    glVertex2f(-0.76f, 0.4f);    //// x, y
    glVertex2f(-0.73f, 0.4f);    //// x, y
    glVertex2f(-0.73f, 0.62f);    //// x, y
    glVertex2f(-0.76f, 0.65f);    //// x, y
    glEnd();

    ///windows
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.84f, 0.43f);    //// x, y
    glVertex2f(-0.81f, 0.43f);    //// x, y
    glVertex2f(-0.81f, 0.48f);    //// x, y
    glVertex2f(-0.84f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.8f, 0.43f);    //// x, y
    glVertex2f(-0.77f, 0.43f);    //// x, y
    glVertex2f(-0.77f, 0.48f);    //// x, y
    glVertex2f(-0.8f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.84f, 0.5f);    //// x, y
    glVertex2f(-0.81f, 0.5f);    //// x, y
    glVertex2f(-0.81f, 0.55f);    //// x, y
    glVertex2f(-0.84f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.8f, 0.5f);    //// x, y
    glVertex2f(-0.77f, 0.5f);    //// x, y
    glVertex2f(-0.77f, 0.55f);    //// x, y
    glVertex2f(-0.8f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.84f, 0.57f);    //// x, y
    glVertex2f(-0.81f, 0.57f);    //// x, y
    glVertex2f(-0.81f, 0.62f);    //// x, y
    glVertex2f(-0.84f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.8f, 0.57f);    //// x, y
    glVertex2f(-0.77f, 0.57f);    //// x, y
    glVertex2f(-0.77f, 0.62f);    //// x, y
    glVertex2f(-0.8f, 0.62f);    //// x, y
    glEnd();

    ///2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(204.0f, 255.0f, 255.0f); //// sky-blue
    glVertex2f(-0.72f, 0.4f);    //// x, y
    glVertex2f(-0.62f, 0.4f);    //// x, y
    glVertex2f(-0.62f, 0.71f);    //// x, y
    glVertex2f(-0.72f, 0.71f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(192.0f, 192.0f, 192.0f); //// sky-blue
    glVertex2f(-0.62f, 0.4f);   //// x, y
    glVertex2f(-0.59f, 0.4f);    //// x, y
    glVertex2f(-0.59f, 0.65f);    //// x, y
    glVertex2f(-0.62f, 0.71f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.7f, 0.43f);    //// x, y
    glVertex2f(-0.67f, 0.43f);    //// x, y
    glVertex2f(-0.67f, 0.48f);    //// x, y
    glVertex2f(-0.7f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.66f, 0.43f);    //// x, y
    glVertex2f(-0.63f, 0.43f);    //// x, y
    glVertex2f(-0.63f, 0.48f);    //// x, y
    glVertex2f(-0.66f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.7f, 0.5f);    //// x, y
    glVertex2f(-0.67f, 0.5f);    //// x, y
    glVertex2f(-0.67f, 0.55f);    //// x, y
    glVertex2f(-0.7f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.66f, 0.5f);    //// x, y
    glVertex2f(-0.63f, 0.5f);    //// x, y
    glVertex2f(-0.63f, 0.55f);    //// x, y
    glVertex2f(-0.66f, 0.55f);    //// x, y
    glEnd();

    ///p3
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.7f, 0.57f);    //// x, y
    glVertex2f(-0.67f, 0.57f);    //// x, y
    glVertex2f(-0.67f, 0.62f);    //// x, y
    glVertex2f(-0.7f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.66f, 0.57f);    //// x, y
    glVertex2f(-0.63f, 0.57f);    //// x, y
    glVertex2f(-0.63f, 0.62f);    //// x, y
    glVertex2f(-0.66f, 0.62f);    //// x, y
    glEnd();

    ///p4
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.7f, 0.64f);    //// x, y
    glVertex2f(-0.67f, 0.64f);    //// x, y
    glVertex2f(-0.67f, 0.69f);    //// x, y
    glVertex2f(-0.7f, 0.69f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.66f, 0.64f);    //// x, y
    glVertex2f(-0.63f, 0.64f);    //// x, y
    glVertex2f(-0.63f, 0.69f);    //// x, y
    glVertex2f(-0.66f, 0.69f);    //// x, y
    glEnd();

    ///////////////
    ///4
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(255, 153, 153); //// sky-blue
    glVertex2f(-0.58f, 0.4f);    //// x, y
    glVertex2f(-0.48f, 0.4f);    //// x, y
    glVertex2f(-0.48f, 0.5f);    //// x, y
    glVertex2f(-0.58f, 0.5f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.48f, 0.4f);    //// x, y
    glVertex2f(-0.47f, 0.4f);    //// x, y
    glVertex2f(-0.47f, 0.48f);    //// x, y
    glVertex2f(-0.48f, 0.5f);    //// x, y
    glEnd();

    ///windows
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.56f, 0.43f);    //// x, y
    glVertex2f(-0.53f, 0.43f);    //// x, y
    glVertex2f(-0.53f, 0.48f);    //// x, y
    glVertex2f(-0.56f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.52f, 0.43f);    //// x, y
    glVertex2f(-0.49f, 0.43f);    //// x, y
    glVertex2f(-0.49f, 0.48f);    //// x, y
    glVertex2f(-0.52f, 0.48f);    //// x, y
    glEnd();

    ///5
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(138, 43, 226); //// sky-blue
    glVertex2f(-0.45f, 0.4f);    //// x, y
    glVertex2f(-0.35f, 0.4f);    //// x, y
    glVertex2f(-0.35f, 0.72f);    //// x, y
    glVertex2f(-0.45f, 0.72f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.3f, 0.3f, 0.3f); //// sky-blue
    glVertex2f(-0.35f, 0.4f);   //// x, y
    glVertex2f(-0.33f, 0.4f);    //// x, y
    glVertex2f(-0.33f, 0.67f);    //// x, y
    glVertex2f(-0.35f, 0.72f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.43f, 0.43f);    //// x, y
    glVertex2f(-0.4f, 0.43f);    //// x, y
    glVertex2f(-0.4f, 0.48f);    //// x, y
    glVertex2f(-0.43f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.39f, 0.43f);    //// x, y
    glVertex2f(-0.36f, 0.43f);    //// x, y
    glVertex2f(-0.36f, 0.48f);    //// x, y
    glVertex2f(-0.39f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.43f, 0.5f);    //// x, y
    glVertex2f(-0.4f, 0.5f);    //// x, y
    glVertex2f(-0.4f, 0.55f);    //// x, y
    glVertex2f(-0.43f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.39f, 0.5f);    //// x, y
    glVertex2f(-0.36f, 0.5f);    //// x, y
    glVertex2f(-0.36f, 0.55f);    //// x, y
    glVertex2f(-0.39f, 0.55f);    //// x, y
    glEnd();

    ///p3
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.43f, 0.57f);    //// x, y
    glVertex2f(-0.4f, 0.57f);    //// x, y
    glVertex2f(-0.4f, 0.62f);    //// x, y
    glVertex2f(-0.43f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.39f, 0.57f);    //// x, y
    glVertex2f(-0.36f, 0.57f);    //// x, y
    glVertex2f(-0.36f, 0.62f);    //// x, y
    glVertex2f(-0.39f, 0.62f);    //// x, y
    glEnd();

    ///p4
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.43f, 0.64f);    //// x, y
    glVertex2f(-0.4f, 0.64f);    //// x, y
    glVertex2f(-0.4f, 0.69f);    //// x, y
    glVertex2f(-0.43f, 0.69f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.39f, 0.64f);    //// x, y
    glVertex2f(-0.36f, 0.64f);    //// x, y
    glVertex2f(-0.36f, 0.69f);    //// x, y
    glVertex2f(-0.39f, 0.69f);    //// x, y
    glEnd();

    ///6
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(255.0f, 69.0f, 0.0f); //// sky-blue
    glVertex2f(-0.3f, 0.4f);    //// x, y
    glVertex2f(-0.2f, 0.4f);    //// x, y
    glVertex2f(-0.2f, 0.6f);    //// x, y
    glVertex2f(-0.3f, 0.6f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(153.0f, 76.0f, 0.0f); //// sky-blue
    glVertex2f(-0.2f, 0.4f);    //// x, y
    glVertex2f(-0.18f, 0.4f);    //// x, y
    glVertex2f(-0.18f, 0.57f);    //// x, y
    glVertex2f(-0.2f, 0.6f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.28f, 0.43f);    //// x, y
    glVertex2f(-0.25f, 0.43f);    //// x, y
    glVertex2f(-0.25f, 0.48f);    //// x, y
    glVertex2f(-0.28f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.24f, 0.43f);    //// x, y
    glVertex2f(-0.21f, 0.43f);    //// x, y
    glVertex2f(-0.21f, 0.48f);    //// x, y
    glVertex2f(-0.24f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.28f, 0.5f);    //// x, y
    glVertex2f(-0.25f, 0.5f);    //// x, y
    glVertex2f(-0.25f, 0.55f);    //// x, y
    glVertex2f(-0.28f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.24f, 0.5f);    //// x, y
    glVertex2f(-0.21f, 0.5f);    //// x, y
    glVertex2f(-0.21f, 0.55f);    //// x, y
    glVertex2f(-0.24f, 0.55f);    //// x, y
    glEnd();

    ///9
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(255.0f, 215.0f, 0.0f); //// sky-blue
    glVertex2f(0.08f, 0.4f);    //// x, y
    glVertex2f(0.18f, 0.4f);    //// x, y
    glVertex2f(0.18f, 0.6f);    //// x, y
    glVertex2f(0.08f, 0.6f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.5f, 0.0f); //// sky-blue
    glVertex2f(0.07f, 0.4f);    //// x, y
    glVertex2f(0.08f, 0.4f);    //// x, y
    glVertex2f(0.08f, 0.6f);    //// x, y
    glVertex2f(0.07f, 0.55f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.09f, 0.43f);    //// x, y
    glVertex2f(0.12f, 0.43f);    //// x, y
    glVertex2f(0.12f, 0.48f);    //// x, y
    glVertex2f(0.09f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.13f, 0.43f);    //// x, y
    glVertex2f(0.16f, 0.43f);    //// x, y
    glVertex2f(0.16f, 0.48f);    //// x, y
    glVertex2f(0.13f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.09f, 0.5f);    //// x, y
    glVertex2f(0.12f, 0.5f);    //// x, y
    glVertex2f(0.12f, 0.55f);    //// x, y
    glVertex2f(0.09f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.13f, 0.5f);    //// x, y
    glVertex2f(0.16f, 0.5f);    //// x, y
    glVertex2f(0.16f, 0.55f);    //// x, y
    glVertex2f(0.13f, 0.55f);    //// x, y
    glEnd();

    ///10
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.7f, 0.7f, 0.7f); //// sky-blue
    glVertex2f(0.22f, 0.4f);    //// x, y
    glVertex2f(0.32f, 0.4f);    //// x, y
    glVertex2f(0.32f, 0.65f);    //// x, y
    glVertex2f(0.22f, 0.65f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.5f, 0.5f); //// sky-blue
    glVertex2f(0.2f, 0.4f);    //// x, y
    glVertex2f(0.22f, 0.4f);    //// x, y
    glVertex2f(0.22f, 0.65f);    //// x, y
    glVertex2f(0.2f, 0.62f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.24f, 0.43f);    //// x, y
    glVertex2f(0.27f, 0.43f);    //// x, y
    glVertex2f(0.27f, 0.48f);    //// x, y
    glVertex2f(0.24f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.28f, 0.43f);    //// x, y
    glVertex2f(0.31f, 0.43f);    //// x, y
    glVertex2f(0.31f, 0.48f);    //// x, y
    glVertex2f(0.28f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.24f, 0.5f);    //// x, y
    glVertex2f(0.27f, 0.5f);    //// x, y
    glVertex2f(0.27f, 0.55f);    //// x, y
    glVertex2f(0.24f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.28f, 0.5f);    //// x, y
    glVertex2f(0.31f, 0.5f);    //// x, y
    glVertex2f(0.31f, 0.55f);    //// x, y
    glVertex2f(0.28f, 0.55f);    //// x, y
    glEnd();

    ///p3
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.24f, 0.57f);    //// x, y
    glVertex2f(0.27f, 0.57f);    //// x, y
    glVertex2f(0.27f, 0.62f);    //// x, y
    glVertex2f(0.24f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(0.28f, 0.57f);    //// x, y
    glVertex2f(0.31f, 0.57f);    //// x, y
    glVertex2f(0.31f, 0.62f);    //// x, y
    glVertex2f(0.28f, 0.62f);    //// x, y
    glEnd();


}

void body() //F14
{
    //middle
    glBegin(GL_QUADS);
    glColor3ub(58,73,80);
    glVertex2f(-7.0f,-10.0f);
    glVertex2f(-7.0f,10.0f);
    glVertex2f(8.0f,10.0f);
    glVertex2f(8.0f,-10.0f);
    glEnd();

    //shed
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-7.0f,10.0f);
    glVertex2f(-7.0f,11.0f);
    glVertex2f(8.0f,11.0f);
    glVertex2f(8.0f,10.0f);
    glEnd();


    //left line
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-2.0f, 10.0f);
    glVertex2f(-2.0f, -10.0f);
    glEnd();

    //middle line
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(3.0f, 10.0f);
    glVertex2f(3.0f, -10.0f);
    glEnd();


    //left tola
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-7.0f,-10.0f);
    glVertex2f(-7.0f,-9.0f);
    glVertex2f(-2.0f,-9.0f);
    glVertex2f(-2.0f,-10.0f);
    glEnd();

    //right tola
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(3.0f,-10.0f);
    glVertex2f(3.0f,-9.0f);
    glVertex2f(8.0f,-9.0f);
    glVertex2f(8.0f,-10.0f);
    glEnd();


    //left 5th window
    glBegin(GL_QUADS);
    glColor3ub(207, 216, 220);
    glVertex2f(-5.5f,7.0f);
    glVertex2f(-5.5f,9.0f);
    glVertex2f(-3.0f,9.0f);
    glVertex2f(-3.0f,7.0f);
    glEnd();


    //left 4th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,3.0f);
glVertex2f(-5.5f,5.0f);
glVertex2f(-3.0f,5.0f);
glVertex2f(-3.0f,3.0f);
glEnd();

//left 3th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,-1.0f);
glVertex2f(-5.5f,1.0f);
glVertex2f(-3.0f,1.0f);
glVertex2f(-3.0f,-1.0f);
glEnd();

//left 2th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,-5.0f);
glVertex2f(-5.5f,-3.0f);
glVertex2f(-3.0f,-3.0f);
glVertex2f(-3.0f,-5.0f);
glEnd();

//left 1st window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,-8.2f);
glVertex2f(-5.5f,-6.5f);
glVertex2f(-3.0f,-6.5f);
glVertex2f(-3.0f,-8.2f);
glEnd();

 //Right 5th window
    glBegin(GL_QUADS);
    glColor3ub(207, 216, 220);
    glVertex2f(4.5f,7.0f);
    glVertex2f(4.5f,9.0f);
    glVertex2f(7.0f,9.0f);
    glVertex2f(7.0f,7.0f);
    glEnd();

//Right 4th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,3.0f);
glVertex2f(4.5f,5.0f);
glVertex2f(7.0f,5.0f);
glVertex2f(7.0f,3.0f);
glEnd();

//Right 3th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,-1.0f);
glVertex2f(4.5f,1.0f);
glVertex2f(7.0f,1.0f);
glVertex2f(7.0f,-1.0f);
glEnd();

//right 2th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,-4.7f);
glVertex2f(4.5f,-3.0f);
glVertex2f(7.0f,-3.0f);
glVertex2f(7.0f,-4.7f);
glEnd();

//right 1st window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,-8.2f);
glVertex2f(4.5f,-6.5f);
glVertex2f(7.0f,-6.5f);
glVertex2f(7.0f,-8.2f);
glEnd();


    //middle 5th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,7.0f);
glVertex2f(-0.7f,9.0f);
glVertex2f(2.0f,9.0f);
glVertex2f(2.0f,7.0f);
glEnd();

//middle 4th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,3.0f);
glVertex2f(-0.7f,5.0f);
glVertex2f(2.0f,5.0f);
glVertex2f(2.0f,3.0f);
glEnd();

//middle 3th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,-1.0f);
glVertex2f(-0.7f,1.0f);
glVertex2f(2.0f,1.0f);
glVertex2f(2.0f,-1.0f);
glEnd();

//middle 2th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,-4.7f);
glVertex2f(-0.7f,-3.0f);
glVertex2f(2.0f,-3.0f);
glVertex2f(2.0f,-4.7f);
glEnd();

}


void Tree() //F15
{
    //tree
glBegin(GL_QUADS);
glColor3ub(123.00f,51.0f,0.0f);
glVertex2f(-15.0f,-8.0f);
glVertex2f(-15.0f,-2.0f);
glVertex2f(-14.0f,-2.0f);
glVertex2f(-14.0f,-8.0f);
glEnd();

circle_tree(2.0,-16.0,-2.7);
glEnd();

glColor3ub(0, 204,0);
circle_tree(2.0,-14.0,-1.5);
glEnd();

circle_tree(2.0,-13.0,-2.7);
glEnd();

}

void sea() //F16
{
    ///sea
    glBegin(GL_QUADS);            /// Each set of 4 vertices form a quad
    glColor3ub(0.0f, 102.0f, 204.0f); /// blue
    glVertex2f(-1.0f, -0.1f);    /// x, y
    glVertex2f(1.0f, -0.1f);    /// x, y
    glVertex2f(1.0f, 0.4f);    /// x, y
    glVertex2f(-1.0f, 0.4f);    /// x, y
    glEnd();

    ///bank river
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-1.0,0.4);
    glVertex2f(1.0, 0.4);
    glEnd();
    float x=0.1,y=0.1;
    ///flow
    glPushMatrix();
    glTranslatef(move_flow, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5,0.3);
    glVertex2f(0.6, 0.3);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.3-x);
    glVertex2f(0.6-x, 0.3-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x,0.3-x-x);
    glVertex2f(0.6-x-x, 0.3-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x, 0.3-x-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x,0.3-x-x-x+0.05);
    glVertex2f(0.6-x-x-x-2*x, 0.3-x-x-x+0.05);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x+0.15);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12, 0.3-x-x-x+0.15);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x-0.05);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x-0.05);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x,0.3-x-x-x+0.1);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x, 0.3-x-x-x+0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x,0.3-x-x-x-0.08);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x, 0.3-x-x-x-0.08);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x, 0.3-x-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17,0.3);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17, 0.3);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.3+0.06);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.3+0.06);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.2);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.2);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.2);
    glVertex2f(0.6-x,0.2);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x,0.1);
    glVertex2f(0.6-x+2*x,0.1);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x,0.1+y);
    glVertex2f(0.6-x+2*x+x,0.1+y);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.1+y+y);
    glVertex2f(0.6-x+2*x+x+x,0.1+y+y);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.0);
    glVertex2f(0.6-x+2*x+x+x,0.0);
    glEnd();
    glPopMatrix();
}



void window() //F17
{
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(0.015,-0.04);
    glVertex2f(-0.015, -0.04);
    glColor3ub(160,160,160);
    glVertex2f(-0.015, -0.00);
    glVertex2f(0.015, -0.00);
    glEnd();
    glTranslatef(-0.0005,0,0);
    HalfCircle(0.015,160,160,160);
    glLoadIdentity();
}

void light_house() //F18
{

    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.14,0.00);
    glColor3ub(255,255,255);
    glVertex2f(-0.22, 0.00);
    glVertex2f(-0.22, 0.47);
    glColor3ub(128,128,128);
    glVertex2f(-0.14, 0.47);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(50);
    glColor3ub(190,190,190);
    glVertex2f(-0.13,0.47);
    glVertex2f(-0.23, 0.47);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(50);
    glColor3ub(190,190,190);
    glVertex2f(-0.12,0.26);
    glVertex2f(-0.24, 0.26);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(40);
    glColor3ub(190,190,190);
    glVertex2f(-0.11,0.00);
    glVertex2f(-0.25, 0.00);
    glEnd();

    glScalef(0.55,0.55,0);
    glTranslatef(-0.33,0.63,0);
    window();
    glLoadIdentity();

    glScalef(0.55,0.55,0);
    glTranslatef(-0.33,0.32,0);
    window();
    glLoadIdentity();

    glScalef(0.55,0.55,0);
    glTranslatef(-0.33,0.12,0);
    window();
    glLoadIdentity();

}



void ground() //F19
{
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad

    glColor3ub(51.0f, 102.0f, 0.0f); // Red
    glVertex2f(-1.0f, -1.0f);    // x, y
    glColor3ub(76.0f, 153.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);    // x, y
    glColor3ub(76.0f, 153.0f, 0.0f); // Red
    glVertex2f(1.0f, -0.1f);    // x, y
    glColor3ub(102.0f, 204.0f, 0.0f); // Red
    glVertex2f(-1.0f, -0.1f);    // x, y




    glEnd();
}



void Lampost() //F20
{
    circle_lamp(0.0145239316937, 0.1477264524784, -0.0772219536772, glowAlpha); // left
    circle_lamp(0.0197921878293, 0.192787594241, -0.0553003171441, glowAlpha); // middle
    circle_lamp(0.0145239316937, 0.2379955904464, -0.0770311098337, glowAlpha); // right

    // Lamp stand
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Red
    glVertex2f(0.1890898766711, -0.1517335194932);    //T12
    glVertex2f(0.1959794679766, -0.1516306897722);    //U12
    glVertex2f(0.1956233509927, -0.0748883028168);    //Z12
    glVertex2f(0.1888341164192, -0.074693633317);    //V12
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1475994640695, -0.0917453302057);
    glVertex2f(0.1475576020546, -0.1039184550827);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1475576020546, -0.1039184550827);
    glVertex2f(0.2380067980133, -0.1041399677207);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.2380067980133, -0.1041399677207);
    glVertex2f(0.2381165549024, -0.0915545377846);
    glEnd();
}

void set_lampPost() //F21
{
    glPushMatrix();
    glTranslatef(-1.13f, 0.15f, 0.0f);
    Lampost();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15f, 0.15f, 0.0f);
    Lampost();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.73f, 0.15f, 0.0f);
    Lampost();
    glPopMatrix();
}

void Bench()  //F22
{

    glPushMatrix();
    glScalef(0.028f,0.05f,1.0f);

    glLineWidth(2.5);

    //middle
    glBegin(GL_QUADS);
    glColor3f(0.749f,0.376f,0.024f);
    glVertex2f(14.0f,-7.0f);
    glVertex2f(14.0f,-5.0f);
    glVertex2f(18.0f,-5.0f);
    glVertex2f(18.0f,-7.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.749f,0.376f,0.024f);
    glVertex2f(16.0f,-8.0f);
    glVertex2f(14.0f,-7.0f);
    glVertex2f(18.0f,-7.0f);
    glVertex2f(20.0f,-8.0f);
    glEnd();

    //leg
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(14.0f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(16.0f, -8.0f);    // x, y
    glVertex2f(16.0f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(19.8f, -8.0f);    // x, y
    glVertex2f(19.8f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.3f, -8.0f);    // x, y
    glVertex2f(18.3f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(16.0f, -8.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(18.0f, -7.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.0f, -7.0f);    // x, y
    glVertex2f(20.0f, -8.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(14.0f, -5.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -5.0f);    // x, y
    glVertex2f(18.0f, -5.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.0f, -5.0f);    // x, y
    glVertex2f(18.0f, -7.0f);    // x, y
    glEnd();

    glPopMatrix();
    glLoadIdentity();



}


void fench() //F23
{
    float L = 0.05;
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.95f,-0.01f);
    glVertex2f(-0.95f,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.9f,-0.01f);
    glVertex2f(-0.9f,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f,-0.01f);
    glVertex2f(-0.85f,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+L,-0.01f);
    glVertex2f(-0.85f+L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+2*L,-0.01f);
    glVertex2f(-0.85f+2*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+3*L,-0.01f);
    glVertex2f(-0.85f+3*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+4*L,-0.01f);
    glVertex2f(-0.85f+4*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+5*L,-0.01f);
    glVertex2f(-0.85f+5*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+6*L,-0.01f);
    glVertex2f(-0.85f+6*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+7*L,-0.01f);
    glVertex2f(-0.85f+7*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+8*L,-0.01f);
    glVertex2f(-0.85f+8*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+9*L,-0.01f);
    glVertex2f(-0.85f+9*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+10*L,-0.01f);
    glVertex2f(-0.85f+10*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+11*L,-0.01f);
    glVertex2f(-0.85f+11*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+12*L,-0.01f);
    glVertex2f(-0.85f+12*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+13*L,-0.01f);
    glVertex2f(-0.85f+13*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+14*L,-0.01f);
    glVertex2f(-0.85f+14*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+15*L,-0.01f);
    glVertex2f(-0.85f+15*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+16*L,-0.01f);
    glVertex2f(-0.85f+16*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+17*L,-0.01f);
    glVertex2f(-0.85f+17*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+18*L,-0.01f);
    glVertex2f(-0.85f+18*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+19*L,-0.01f);
    glVertex2f(-0.85f+19*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+20*L,-0.01f);
    glVertex2f(-0.85f+20*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+21*L,-0.01f);
    glVertex2f(-0.85f+21*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+22*L,-0.01f);
    glVertex2f(-0.85f+22*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+23*L,-0.01f);
    glVertex2f(-0.85f+23*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+24*L,-0.01f);
    glVertex2f(-0.85f+24*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+25*L,-0.01f);
    glVertex2f(-0.85f+25*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+26*L,-0.01f);
    glVertex2f(-0.85f+26*L,-0.1f);
    glEnd();glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+27*L,-0.01f);
    glVertex2f(-0.85f+27*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+28*L,-0.01f);
    glVertex2f(-0.85f+28*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+29*L,-0.01f);
    glVertex2f(-0.85f+29*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+30*L,-0.01f);
    glVertex2f(-0.85f+30*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+31*L,-0.01f);
    glVertex2f(-0.85f+31*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+32*L,-0.01f);
    glVertex2f(-0.85f+32*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+33*L,-0.01f);
    glVertex2f(-0.85f+33*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+34*L,-0.01f);
    glVertex2f(-0.85f+34*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+35*L,-0.01f);
    glVertex2f(-0.85f+35*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+36*L,-0.01f);
    glVertex2f(-0.85f+36*L,-0.1f);
    glEnd();

    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(2.0f);
    glVertex2f(-1.0,-0.01f);
    glVertex2f(1.0f,-0.01f);
    glEnd();

}


void HauntedHouse() //F24
{
    glBegin(GL_TRIANGLES);
    glColor3ub(5,1,74);

    // Left shade
    glVertex2f(-0.9052998158133, -0.156396506655);
    glVertex2f(-0.9433887865386, -0.2688496583202);
    glVertex2f(-0.8920444844303, -0.2565818747899);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,1,74);
    glVertex2f(-0.9433887865386, -0.2688496583202);
    glVertex2f(-1.0050566439034, -0.3468413602815);
    glVertex2f(-0.954271349603, -0.3486551207923);
    glVertex2f(-0.8621887122427, -0.3479586320914);
    glVertex2f(-0.8218668323198, -0.3450275997708);
    glVertex2f(-0.8920444844303, -0.2565818747899);
    glEnd();

    // Right shade
    glBegin(GL_TRIANGLES);
    glColor3ub(5,1,74);
    glVertex2f(-0.7311788067834, -0.0983561703117);
    glVertex2f(-0.7632572096799, -0.195342654441);
    glVertex2f(-0.7015390021384, -0.2072115405067);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,1,74);
    glVertex2f(-0.7632572096799, -0.195342654441);
    glVertex2f(-0.8454457189593, -0.2688496583202);
    glVertex2f(-0.7985865378978, -0.2732520214242);
    glVertex2f(-0.679238608755, -0.271139668696);
    glVertex2f(-0.6404907812469, -0.2688496583202);
    glVertex2f(-0.7015390021384, -0.2072115405067);
    glEnd();

    // Wall
    glBegin(GL_POLYGON);
    glColor3ub(51,0,102);
    glVertex2f(-0.954271349603, -0.3486551207923);
    glVertex2f(-0.9237096973566, -0.5117130189388 - 0.1);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.8558556696574, -0.383242726495 - 0.05);
    glVertex2f(-0.8621887122427, -0.3479586320914);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51,0,102);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.7850104042242, -0.5113849740625 - 0.1);
    glVertex2f(-0.8106196511913, -0.3868616079723 - 0.05);
    glVertex2f(-0.8558556696574, -0.383242726495 - 0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51,0,102);
    glVertex2f(-0.7985865378978, -0.2732520214242);
    glVertex2f(-0.8106196511913, -0.3868616079723 - 0.1);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.7325330296947, -0.5113849740625 - 0.1);
    glVertex2f(-0.7045868414933, -0.3778134814697);
    glVertex2f(-0.679238608755, -0.271139668696);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51,0,102);
    glVertex2f(-0.7325330296947, -0.5113849740625 - 0.1);
    glVertex2f(-0.6321916761987, -0.5125383229532 - 0.1);
    glVertex2f(-0.6327678690856, -0.4297725922336);
    glVertex2f(-0.5951020420498, -0.4303211236952);
    glVertex2f(-0.6321916761987, -0.3781731771798);
    glVertex2f(-0.7045868414933, -0.3778134814697);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51,0,102);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.7325330296947, -0.5113849740625 - 0.1);
    glVertex2f(-0.7321867242007, -0.4680063641405 - 0.1);
    glVertex2f(-0.8333257562177, -0.4696920146741 - 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51,0,102);
    glVertex2f(-0.7996127455453, -0.4309220524009 - 0.1);
    glVertex2f(-0.8333257562177, -0.4696920146741 - 0.1);
    glVertex2f(-0.7321867242007, -0.4680063641405 - 0.1);
    glVertex2f(-0.7574714822049, -0.4292364018673 - 0.1);
    glEnd();

    ////door
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(224,224,224); // Red
    glVertex2f(-0.8328743831907, -0.5108082996171-0.1); //j2
    glVertex2f(-0.7325330296947, -0.5113849740625-0.1);//e2   // x, y
    glVertex2f(-0.7321867242007, -0.4680063641405-0.1); //f2
    glVertex2f(-0.8333257562177, -0.4696920146741-0.1); //i2
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(224,224,224); // Red
    glVertex2f(-0.7996127455453, -0.4309220524009-0.1); //h2
    glVertex2f(-0.8333257562177, -0.4696920146741-0.1);//i2   // x, y
    glVertex2f(-0.7321867242007, -0.4680063641405-0.1); //f2
    glVertex2f(-0.7574714822049, -0.4292364018673-0.1); //g2
    glEnd();


    circle_lamp(0.03,-0.8901412862041-0.025, -0.370843479522-0.025,glowAlpha);
    glEnd();
    circle_lamp(0.035,-0.7496272346364, -0.3146200253607-0.005,glowAlpha);
    glEnd();


}

void Chair() //F25
{

    //Lower Part
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.9455132503274, -0.1881016149557);
	glVertex2f(-0.9117827691956, -0.1892810024078);
	glVertex2f(-0.9108392592338, -0.1803176577714);
	glVertex2f(-0.9467113974835, -0.1799542142943);
	glEnd();

	//Upper Part
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.9467113974835, -0.1799542142943);
	glVertex2f(-0.9429185979327, -0.1798459027905);
	glVertex2f(-0.9448056178561, -0.1425772593022);
	glVertex2f(-0.9525895750404, -0.1399826069074);
	glEnd();


    //Seat
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.9429185979327, -0.1798459027905);
	glVertex2f(-0.9108392592338, -0.1803176577714);
	glVertex2f(-0.907460644422, -0.1733532615283);
	glVertex2f(-0.9068604661657, -0.1632702668225);
	glVertex2f(-0.944371607184, -0.1636303737763);
	glEnd();

	//stand
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.931124723411, -0.1810252902427);
    glVertex2f(-0.9268637380383, -0.180909977323);
    glVertex2f(-0.9251416185163, -0.0275102435472);
    glVertex2f(-0.9311792933833, -0.0278620514147);
	glEnd();


	//glutSwapBuffers();

}

void ride() //F26
{
    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.925, 0); //k3
    glVertex2f(-0.925, -0.028);//a3
    glVertex2f(-0.67, -0.028); //d3
    glVertex2f(-0.67, 0); //z3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.9310733313146, -0.0220430556755); //h3
    glVertex2f(-0.9310558673343, -0.028);//g3
    glVertex2f(-0.666, -0.028); //b4
    glVertex2f(-0.6659185882569, -0.0220430556755); //c4
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.925, -0.028);//a3
    glVertex2f(-0.8871775329089, -0.0754764506258); //z2
    glVertex2f(-0.7076831338211, -0.0754764506258); //e3
    glVertex2f(-0.67, -0.028); //d3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.8871775329089, -0.0754764506258); //z2
    glVertex2f(-0.8871775329089, -0.0875701527496);//w2
    glVertex2f(-0.7076831338211, -0.0875947606018); //f3
    glVertex2f(-0.7076831338211, -0.0754764506258); //e3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(219.0f, 189.0f, 38.0f);
    glVertex2f(-0.8871775329089, -0.0875701527496);//w2
    glVertex2f(-0.8638515621642, -0.0999611737789); //v2
    glVertex2f(-0.7311788067834, -0.0999611737789); //o1
    glVertex2f(-0.7076831338211, -0.0875947606018); //f3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.8638515621642, -0.0999611737789);//v2
    glVertex2f(-0.85, -0.2); //u2
    glVertex2f(-0.75, -0.2); //u5
    glVertex2f(-0.7311788067834, -0.0999611737789); //o1
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.85, -0.2);//u2
    glVertex2f(-0.8651011820348, -0.281799069355); //t2
    glVertex2f(-0.7333179038519, -0.281799069355); //r5
    glVertex2f(-0.75, -0.2); //u5
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.85, -0.2); //u2
    glVertex2f(-0.75, -0.2); //u5
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.97, -0.28);//s2
    glVertex2f(-0.9774863264877, -0.3); //v5
    glVertex2f(-0.62, -0.3); //z5
    glVertex2f(-0.6262041464756, -0.28); //w5
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.8000975214123, 0.0570655431202);//a6
    glVertex2f(-0.87, 0);//n3
    glVertex2f(-0.7277590432943, -0.0000107017145);//k1
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f);//white
    glVertex2f(-0.8000975214123, 0.0570655431202);//a6
    glVertex2f(-0.835, 0);//o3
    glVertex2f(-0.82,0);//q3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f);//white
    glVertex2f(-0.8000975214123, 0.0570655431202);//a6
    glVertex2f(-0.78, 0);//r3
    glVertex2f(-0.7656735622151, 0.0000750589451);//t3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 96.0f);//pink
    glVertex2f(-0.885, 0);//l3
    glVertex2f(-0.8775590270233, -0.0101782141455);//m3
    glVertex2f(-0.87, 0);//n3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 96.0f, 0.0f);//yellow
    glVertex2f(-0.835, 0);//o3
    glVertex2f(-0.8274072532665, -0.0101782141455);//p3
    glVertex2f(-0.82, 0);//q3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 96.0f);//pink
    glVertex2f(-0.78, 0);//r3
    glVertex2f(-0.7731646935298, -0.0101128796429);//s3
    glVertex2f(-0.7656735622151, 0.0000750589451);//t3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 96.0f, 0.0f);//yellow
    glVertex2f(-0.7277590432943, -0.0000107017145);//u3
    glVertex2f(-0.72, -0.01);//v3
    glVertex2f(-0.7136851108911, 0);//w3
    glEnd();

    glPushMatrix();
    glTranslatef(chairmove, 0.0f, 0.0f);
    Chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.13, 0.0f, 0.0f);
    glTranslatef(chairmove2, 0.0f, 0.0f);
    Chair();
    glPopMatrix();

   /*
    glPushMatrix();
    glTranslatef(0.25, 0.0f, 0.0f);
    glTranslatef(chairmove3, 0.0f, 0.0f);
    Chair();
    glPopMatrix();
    */



    //if necessary
    /*
    glPushMatrix();
    glTranslatef(0.38, 0.0f, 0.0f);
    ChairStand();
    Chair();
    glPopMatrix();
    */

}

void horse() //F27
{


    //Horse Head
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(161,61,45); // Red
    glVertex2f(0.6230289295598, -0.07153140419);    // x, y
    glVertex2f(0.6204933293862, -0.0845218808048);    // x, y
    glVertex2f(0.5952168105742, -0.1214119352872);    // x, y
    glVertex2f(0.6152677031054, -0.1300933856185);    // x, y
    glVertex2f(0.6353763352827, -0.1138653666684);    // x, y
    glVertex2f(0.6630081138722, -0.0945747376603);   // x, y
    glVertex2f(0.6477565923213, -0.0799660124065);    // x, y
    glVertex2f(0.63, -0.08);
    glEnd();

    // Horse Ear
    glBegin(GL_TRIANGLES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6204933293862, -0.0745218808048f);    // x, y
    glVertex2f(0.63, -0.07f);    // x, y
    glVertex2f(0.6230289295598, -0.06153140419f);    // x, y
    glEnd();

    //Horse Body
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(161,61,45); // Red
    glVertex2f(0.6353763352827, -0.1138653666684);    // s6
    glVertex2f(0.6427847787164, -0.1322100837424);    // t6
    glVertex2f(0.6364346843446, -0.1614910744567);    // u6
    glVertex2f(0.6371402503859, -0.1741912632002);    // v6
    glVertex2f(0.6652170320805, -0.1823792364382);    // a7
    glVertex2f(0.7469470057857, -0.1818270068861);   // b7
    glVertex2f(0.7734540242846, -0.1790658591258);    // e7
    glVertex2f(0.7733144963582, -0.142793574362);       // o6
    glVertex2f(0.7695884174202, -0.1348874949609);      // h7
    glVertex2f(0.7581448264701, -0.126565555412);    // n6
    glVertex2f(0.7330972320037, -0.1258599893707);    // m6
    glVertex2f(0.7147525149297, -0.1293878195772);    // l6
    glVertex2f(0.7034634582688, -0.1290350365565);    // k6
    glVertex2f(0.6886465714014, -0.12550720635);   //j6
    glVertex2f(0.6630081138722, -0.0945747376603); //i6
    glEnd();

    //Horse Front Leg
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(44,45,45); // Red

    glVertex2f(0.6342368822203, -0.2248317806397);    // w6
    glVertex2f(0.6485590055079, -0.2244737275575);    // Z6
    glVertex2f(0.6652170320805, -0.1823792364382);    // A7
    glVertex2f(0.6371402503859, -0.1741912632002);    // v6
    glEnd();

    //Horse Front Leg Horseshoe
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // Red

    glVertex2f(0.6306563513984, -0.2309186830369);    // L7
    glVertex2f(0.6478766558479, -0.2307468511194);    // J7
    glVertex2f(0.6485590055079, -0.2244737275575);    // Z6
    glVertex2f(0.6342368822203, -0.2248317806397);    // w6
    glEnd();


    //Horse Back Leg
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(44,45,45); // Red

    glVertex2f(0.7717292657813, -0.2245769480091);    // C7
    glVertex2f(0.7835450174936, -0.2241156744753);    // D7
    glVertex2f(0.7734540242846, -0.1790658591258);    // E7
    glVertex2f(0.7469470057857, -0.1818270068861);    // B7
    glEnd();

    //Horse Back Leg Horseshoe
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // Red

    glVertex2f(0.7692518015035, -0.2298319430705);    // K7
    glVertex2f(0.7855341793726, -0.2297248716381);    // L7
    glVertex2f(0.7835450174936, -0.2241156744753);    // D7
    glVertex2f(0.7717292657813, -0.2245769480091);    // C7
    glEnd();


    //Horse Lengur

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // Red

    glVertex2f(0.7733144963582, -0.142793574362);    // O6
    glVertex2f(0.8, -0.15);                             // P6
    glVertex2f(0.803274420096, -0.1702301862928);    // R6
    glVertex2f(0.8353037341156, -0.1531110701789);    // F7
    glVertex2f(0.8043788792001, -0.1282607403361);    // G7
    glVertex2f(0.7695884174202, -0.1348874949609);    // H7
    glEnd();

}

void Carousel() //F28
{
    //Horse Building Structure
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(184, 173, 173); // Red

    glVertex2f(0.6469362786402, -0.2307682123178);    // H8
    glVertex2f(0.7742691404413, -0.2298197125607);    // K8
    glVertex2f(0.7708206462465, -0.0131777323474);    // l8
    glVertex2f(0.6440323872888, -0.0149066631513);    // G8
    glEnd();
    //Triangle
    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(185,96,236); // Red
    glVertex2f(0.5072739941155, 0.0355885447244);    // N7
    glVertex2f(0.9111285277335, 0.0365501031378);    //v7                      // T7
    glVertex2f(0.7063165856844, 0.15962958005);    // V7
    glEnd();


    //Triangle Base

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(56,172,236); // Red
    glVertex2f(0.4512152034121, 0.007414334689);    // W7
    glVertex2f(0.962155655219, 0.0098746783722);    //E8                     // T7
    glVertex2f(0.9611295652291, 0.0375116615512);    // U7
    glVertex2f(0.452465164553, 0.0365501031378);    // M7
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(188,207,236); // Red
    glVertex2f(0.4538499988523, -0.0154829734193);    // F8
    glVertex2f(0.9540873114671, -0.0126014220794);    //J8                    // T7
    glVertex2f(0.962155655219, 0.0098746783722);    //E8
    glVertex2f(0.4512152034121, 0.007414334689);    // W7
    glEnd();

    //Leg Basement

    //First Basement
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(52.0f, 61.0f, 235.0f); // Red
    glVertex2f(0.4569623148533, -0.2858343211071);    //p8
    glVertex2f(0.9647104079067, -0.2798019186316);    //n8                    // T7
    glVertex2f(0.9629772196723, -0.2285125058642);    // m8
    glVertex2f(0.4538499988523, -0.2321756341833);    // l8
    glEnd();


    //Bottom Basement

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(56,172,236); // Red
    glVertex2f(0.4359129315107, -0.3051218849393);    //R8
    glVertex2f(0.9848799046873, -0.3014903503868);    //S8                    // T7
    glVertex2f(0.9862766869929, -0.2792028553237);    //O8
    glVertex2f(0.4340971642345, -0.2857537006596);    //Q8
    glEnd();


    /*glPushMatrix();
    glTranslatef(-0.15, 0.0f, 0.0f);
    horse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.005f, 0.0f);
    horse();
    glPopMatrix();

    */

    }


void Ferris_Wheel_Box() //F29
{

    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.0070925788264, 0.0100271080899);
	glVertex2f(-0.0065262479132, -0.065861234269);
	glVertex2f(-0.0699553101834, -0.065861234269);
	glVertex2f(-0.0705216410965, 0.0094607771768);
	glEnd();

    glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.0407381118577, -0.0060621666345);
	glVertex2f(-0.0387660340241, -0.0054821437423);
	glVertex2f(-0.0432081038632, 0.0177307806438);
	glVertex2f(-0.0444809600007, 0.017057184183);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.0665573247046, -0.0437743286571);
	glVertex2f(-0.0122214568576, -0.043575970705);
	glVertex2f(-0.0127558879576, -0.0063964883908);
	glVertex2f(-0.0665573247046, -0.0058301574777);
	glEnd();

}

void Ferris_Stucut() //F30
{
    // Bottom Rectangle
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.3096608460677f, -0.3065404744871f);
    glVertex2f(-0.0371610716596f, -0.3060380409959f);
    glVertex2f(-0.0439667166987f, -0.2871604321096f);
    glVertex2f(-0.308290638259f, -0.2873792054854f);
    glEnd();

    // Left Piller
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.265462072651f, -0.2868300240855f);
    glVertex2f(-0.2430138070153f, -0.286997961871f);
    glVertex2f(-0.1798456047657f, -0.0587666146482f);
    glVertex2f(-0.1857520627791f, -0.057459481894f);
    glEnd();

    // Right Piller
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.1042949131319f, -0.2874730134383f);
    glVertex2f(-0.0810640372311f, -0.2874730134383f);
    glVertex2f(-0.1678730123114f, -0.0580330565503f);
    glVertex2f(-0.1729344011929f, -0.0588904606151f);
    glEnd();
}

void Ferris_Wheel_Box(float angle, float centerX, float centerY) //F31
{
    glPushMatrix();
    glTranslatef(centerX, centerY, 0.0f);
    glRotatef(angle + glutGet(GLUT_ELAPSED_TIME) * 0.3f, 0.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.0070925788264, 0.0100271080899);
    glVertex2f(-0.0065262479132, -0.065861234269);
    glVertex2f(-0.0699553101834, -0.065861234269);
    glVertex2f(-0.0705216410965, 0.0094607771768);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.0407381118577, -0.0060621666345);
    glVertex2f(-0.0387660340241, -0.0054821437423);
    glVertex2f(-0.0432081038632, 0.0177307806438);
    glVertex2f(-0.0444809600007, 0.017057184183);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.0665573247046, -0.0437743286571);
    glVertex2f(-0.0122214568576, -0.043575970705);
    glVertex2f(-0.0127558879576, -0.0063964883908);
    glVertex2f(-0.0665573247046, -0.0058301574777);
    glEnd();

    glPopMatrix();
}

void Ferris_Wheel2() //F32
{
    // Draw the central circle without rotation
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float theta = (i * pi) / 50;
        float r = 0.0324787890821;
        float x = -0.1763900029793 + r * cos(theta);
        float y = -0.05882803763165 + r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw Ferris Wheel boxes and stands at different angles
    for (int i = 0; i < 6; ++i) {
        float angle = i * 60.0f; // Adjust the number of boxes as needed
        float centerX = -0.1763900029793;
        float centerY = -0.05882803763165;

        // Box
        Ferris_Wheel_Box(angle, centerX, centerY);


    }
}



void Froghopper() //F33
{
    //Stand
    glPushMatrix();
    glScalef(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.2975812230974f,-0.2706178068053f-0.5);    // x, y
    glColor3ub(178,34,34);
    glVertex2f(0.3626871800881f,-0.2697379965757f-0.5);    // x, y // lowerpoint
    glVertex2f(0.3500357081808, 0.1359212367917);    // x, y
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(0.3099537246946, 0.1361314569848);    // x, y upper point
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.0,benchPosition,0.0);

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 0.0f); // Red
    glVertex2f(0.2395137479435f, -0.1861560247634f);    // x, y
    glVertex2f(0.4185551296679f, -0.1830766889597f);    // x, y
    glVertex2f(0.4172354143235f, -0.1544828564976f);    // x, y
    glVertex2f(0.2395421009271f, -0.1591253399728f);    // x, y
    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 250.0f, 0.0f); // Red
    glVertex2f(0.2295641457125f, -0.2284237649445f);    // x, y
    glVertex2f(0.4216344654715f, -0.2121104265367f);    // x, y
    glVertex2f(0.4185551296679f, -0.1830766889597f);    // x, y
    glVertex2f(0.2395137479435f, -0.1861560247634f);    // x, y
    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 120.0f, 0.0f); // Red
    glVertex2f(0.2295641457125f, -0.2284237649445f);    // x, y
    glVertex2f(0.4277931370787f, -0.2248676748659f);    // x, y
    glVertex2f(0.4216344654715f, -0.2121104265367f);    // x, y
    glVertex2f(0.2375858385045f, -0.2165110616948f);    // x, y
    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 230.0f, 0.0f); // Red
    glVertex2f(0.2295641457125f, -0.2495633923737f);
    glVertex2f(0.4281485245931f, -0.244438634209f);
    glVertex2f(0.4277931370787f, -0.2248676748659f);
    glVertex2f(0.2295641457125f, -0.2284237649445f);
    glEnd();

    glPopMatrix();



}


void Bat() //F34
{

    //head left

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.4794296974, 0.483162683194);  //W14
    glVertex2f(0.4879352209436, 0.4836758369816);    //R15
    glVertex2f(0.4877632543751, 0.4883756675795);   //A15
    glVertex2f(0.4826481127162, 0.4945217960749);   //Z14
    glEnd();


    //head right

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2f(0.4879352209436, 0.4836758369816);    //R15
    glVertex2f(0.4956926190924, 0.4841438549962);  //C15
    glVertex2f(0.4928847697259, 0.4941800516436);   //B14
    glVertex2f(0.4877632543751, 0.4883756675795);   //A15

    glEnd();


    //left wing first segment

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.4275296599459, 0.4616867617925);    //G15
    glVertex2f(0.4568344911265, 0.4612808462672);  //J15
    glVertex2f(0.474867028814, 0.4544893710342);   //K15
    glVertex2f(0.4794296974, 0.483162683194);   //W14
    glVertex2f(0.4646628506548, 0.4865704170582); //v14

    glEnd();

    //left wing second segment

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.4018090927138, 0.496225663007);    //T14
    glVertex2f(0.4227955183753, 0.483085081692);  //I15
    glVertex2f(0.4275296599459, 0.4616867617925);    //G15
    glVertex2f(0.4646628506548, 0.4865704170582); //v14
    glVertex2f(0.4597405684064, 0.496225663007); //u14

    glEnd();


    //middle stomach segment

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.474867028814, 0.4544893710342);   //K15
    glVertex2f(0.4882157904787, 0.4383303437558);  //L15
    glVertex2f(0.5032038737515, 0.4554261262387);    //M15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glVertex2f(0.4794296974, 0.483162683194);   //W14

    glEnd();

    //right wing first segment

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.5032038737515, 0.4554261262387);    //M15
    glVertex2f(0.52, 0.46);  //N15
    glVertex2f(0.5420792147401 , 0.4629201678751 );    //O15
    glVertex2f(0.5479339347685, 0.4619834126706); //P15
    glVertex2f(0.5514467667856, 0.4795475727558); //Q15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glEnd();

    //right wing second segment

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.5514467667856, 0.4795475727558); //Q15
    glVertex2f(0.5738691757898, 0.4963182108585); //E15
    glVertex2f(0.5178143888124, 0.4979308554635);//F15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glEnd();

}

void Bat2() //F35
{
    glPushMatrix();  // Save the current matrix state

    // Calculate the rotation angle based on time
    float rotationAngle = sin(glutGet(GLUT_ELAPSED_TIME) * 0.10 * angularFrequency) * 45.0f;

    // Apply rotation around the center
    glTranslatef(centerX, centerY, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-centerX, -centerY, 0.0f);

    // Move the bat upward after a certain number of rotations
    if (rotationCount >= 10) {
        centerY += translationSpeed;
    }

    // Existing bat drawing code here...

    // head left
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4794296974, 0.483162683194);  //W14
    glVertex2f(0.4879352209436, 0.4836758369816);    //R15
    glVertex2f(0.4877632543751, 0.4883756675795);   //A15
    glVertex2f(0.4826481127162, 0.4945217960749);   //Z14
    glEnd();

    // head right
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4879352209436, 0.4836758369816);    //R15
    glVertex2f(0.4956926190924, 0.4841438549962);  //C15
    glVertex2f(0.4928847697259, 0.4941800516436);   //B14
    glVertex2f(0.4877632543751, 0.4883756675795);   //A15
    glEnd();

    // left wing first segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4275296599459, 0.4616867617925);    //G15
    glVertex2f(0.4568344911265, 0.4612808462672);  //J15
    glVertex2f(0.474867028814, 0.4544893710342);   //K15
    glVertex2f(0.4794296974, 0.483162683194);   //W14
    glVertex2f(0.4646628506548, 0.4865704170582); //v14
    glEnd();

    // left wing second segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4018090927138, 0.496225663007);    //T14
    glVertex2f(0.4227955183753, 0.483085081692);  //I15
    glVertex2f(0.4275296599459, 0.4616867617925);    //G15
    glVertex2f(0.4646628506548, 0.4865704170582); //v14
    glVertex2f(0.4597405684064, 0.496225663007); //u14
    glEnd();

    // middle stomach segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.474867028814, 0.4544893710342);   //K15
    glVertex2f(0.4882157904787, 0.4383303437558);  //L15
    glVertex2f(0.5032038737515, 0.4554261262387);    //M15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glVertex2f(0.4794296974, 0.483162683194);   //W14
    glEnd();

    // right wing first segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.5032038737515, 0.4554261262387);    //M15
    glVertex2f(0.52, 0.46);  //N15
    glVertex2f(0.5420792147401 , 0.4629201678751 );    //O15
    glVertex2f(0.5479339347685, 0.4619834126706); //P15
    glVertex2f(0.5514467667856, 0.4795475727558); //Q15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glEnd();

    // right wing second segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.5514467667856, 0.4795475727558); //Q15
    glVertex2f(0.5738691757898, 0.4963182108585); //E15
    glVertex2f(0.5178143888124, 0.4979308554635);//F15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glEnd();

    glPopMatrix();  // Restore the previous matrix state
}



void TentHouse()//F36
{

    //Whole Border
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.5352946604884, -0.2137213219901);    // x, y
    glVertex2f(-0.5341626405179, -0.4044666870249);    // x, y
    glVertex2f(-0.2426674981056, -0.4039006770396);    // x, y
    glVertex2f(-0.245497548032, -0.2165513719164);
    glEnd();


    //Left White part top
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f); // White
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.4887871675063, -0.2320600455263);    // x, y
    glVertex2f(-0.440631330625, -0.2320024348871);
    glEnd();


    //Left White part top
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f); // White
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.4887871675063, -0.2320600455263);    // x, y
    glVertex2f(-0.440631330625, -0.2320024348871);
    glEnd();

    //Left White part down
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f); // White
    glVertex2f(-0.4887871675063, -0.2320600455263);    // x, y
    glVertex2f(-0.4866178017555, -0.3993725971575);
    glVertex2f(-0.4396389729784, -0.3999386071427);
    glVertex2f(-0.440631330625, -0.2320024348871);
    glEnd();


    //Right White part top
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f); // White
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.337876042845, -0.2321057353565);    // x, y
    glVertex2f(-0.2924763768091, -0.2301356115628);
    glEnd();

    //Right White part down
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 255.0f, 255.0f); // White
    glVertex2f(-0.2924763768091, -0.2301356115628);    // x, y
    glVertex2f(-0.2924763768091, -0.3991556327941);
    glVertex2f(-0.34, -0.4003490456219);
    glVertex2f(-0.337876042845, -0.2321057353565);
    glEnd();

    //Middle Black Door
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // White
    glVertex2f(-0.4396389729784, -0.3999386071427);    // x, y
    glVertex2f(-0.34, -0.4003490456219);
    glVertex2f(-0.366623684879, -0.3246592791023);
    glVertex2f(-0.3711517647611, -0.2827745401926);

    glVertex2f(-0.3768683954017, -0.2325145418793);
    glVertex2f(-0.4023856124878, -0.2325145418793);
    glVertex2f(-0.386623684879, -0.3246592791023);

    glEnd();

    //Middle Door Left Brown
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 215.0f, 0.0f); // White
    glVertex2f(-0.4079424138035, -0.2839065601631);    // x, y
    glVertex2f(-0.4583173024922, -0.3110750394559);
    glVertex2f(-0.4396389729784, -0.3999386071427);
    glEnd();

    //Middle Door Right Brown
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 215.0f, 0.0f); // White
    glVertex2f(-0.3711517647611, -0.2827745401926);    // x, y
    glVertex2f(-0.321908896043, -0.3127730694117);
    glVertex2f(-0.34, -0.4003490456219);
    glEnd();


    //Top Flag

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(235.0f, 204.0f, 52.0f); // yellow
    glVertex2f(-0.391172070257, -0.0686145571218);    // x, y
    glVertex2f(-0.391172070257, -0.0920908404058);
    glVertex2f(-0.346852357889, -0.0923102449225);
    glVertex2f(-0.36, -0.08);
    glVertex2f(-0.3455359307889, -0.0686145571218);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.3911489791823, -0.0646577053519);
    glVertex2f(-0.391172070257, -0.1028416617228);
    glEnd();


}


void Ghost()//F37
{


    //Ghost Hat
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.5324120085967, 0.4132103872745); //U22
    glVertex2f(-0.4727072133115, 0.4146601452409); //F23
    glVertex2f(-0.4645636637043, 0.4225128537907);//G23
    glVertex2f(-0.4299535778738, 0.4236762180203); //H23
    glVertex2f(-0.414829842889, 0.4318197676275); //l23
    glVertex2f(-0.4, 0.44); //J23
    glVertex2f(-0.3662849321763, 0.4365047130341);//E23
    glVertex2f(-0.3944944633464, 0.4512287122303); //D23
    glVertex2f(-0.4015367157788, 0.4512455791154); //C23
    glVertex2f(-0.4358439504053, 0.438275770903); //B23
    glVertex2f(-0.4723213381552, 0.449694008614);//A23
    glVertex2f(-0.4832902700612, 0.4492170985311); //Z22
    glVertex2f(-0.5030820385003, 0.4461171829924); //W22
    glVertex2f(-0.5202508014836, 0.4346713410036); //V22


    glEnd();


    //Ghost Face
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.5355119241354, 0.4031952755342); //Q22
    glVertex2f(-0.4601691638938, 0.3730884872031); //S23
    glVertex2f(-0.4101763859706, 0.375396602492);//R23
    glVertex2f(-0.3915625582971 , 0.387030244788); //Q23
    glVertex2f(-0.407558816454, 0.3852851984436); //P23
    glVertex2f(-0.3866182603213, 0.4091341651503); //O23
    glVertex2f(-0.4, 0.4);//N23
    glVertex2f(-0.4171565713482, 0.3989547281414); //M23
    glVertex2f(-0.4107580680854, 0.4021539797727); //L23
    glVertex2f(-0.4407146969976, 0.4027356618875); //K23
    glVertex2f(-0.4727072133115, 0.4146601452409);//F23
    glVertex2f(-0.5324120085967, 0.4132103872745); //U22
    glEnd();

    //Ghost face down
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.5355119241354, 0.4031952755342); //Q22
    glVertex2f(-0.5355119241354, 0.3919878885868); //P22
    glVertex2f(-0.5414733001712, 0.3853111474266);//O22
    glVertex2f(-0.5438578505856, 0.3733883953549); //N22
    glVertex2f(-0.531458188431 , 0.3795882264322); //M22
    glVertex2f(-0.5338427388453, 0.3707653898991); //L22
    glVertex2f(-0.5309812783481, 0.3669501092362);//K22
    glVertex2f(-0.5347391611688, 0.3602242211769); //H22
    glVertex2f(-0.5249995708677, 0.3576111603644); //J22
    glVertex2f(-0.5169228374474, 0.3609368741258); //l22
    glVertex2f(-0.508608553044, 0.3595115682281);//G22
    glVertex2f(-0.4976812078282, 0.3535727936543); //F22
    glVertex2f(-0.4540933856379, 0.3602728675073); //W23
    glVertex2f(-0.4354795579644, 0.3620179138517); //V23
    glVertex2f(-0.4488582466047, 0.3643446423108);//U23
    glVertex2f(-0.4343161937348, 0.3675438939422); //T23
    glVertex2f(-0.4601691638938, 0.3730884872031); //S23
    glEnd();

    //Hat sharp Phase

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);

    glVertex2f(-0.5324120085967, 0.4132103872745); //U22
    glVertex2f(-0.5557806026573, 0.4055798259486); //T22
    glVertex2f(-0.5691340849776, 0.4031952755342);//S22
    glVertex2f(-0.5665110795219 ,0.4005722700784); //R22
    glVertex2f(-0.5355119241354, 0.4031952755342); //Q22

    glEnd();

    //Hand

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.6460918890339, 0.2978225035081); //C22
    glVertex2f(-0.6110612242307, 0.2915125800089); //U27
    glVertex2f(-0.599820883082, 0.2935131465918);//V27
    glVertex2f(-0.5937079006987, 0.2875827089398); //W27
    glVertex2f(-0.5724377946139, 0.2837079221724); //B22
    glVertex2f(-0.494633281804, 0.3092503837857); //A22
    glVertex2f(-0.4976812078282, 0.3535727936543);//F22
    glVertex2f(-0.553033249933, 0.3190037068883);//E22
    glVertex2f(-0.5984636743787, 0.3037756630716); //D22

    glEnd();


    //upper body

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4976812078282, 0.3535727936543);//F22
    glVertex2f(-0.494633281804, 0.3092503837857); //A22
    glVertex2f(-0.4513333862673, 0.2777595506682);//Z21
    glVertex2f(-0.3869091013787, 0.2826183051817); //G24
    glVertex2f(-0.3496814460316, 0.2677854112543); //F24
    glVertex2f(-0.3162347244307, 0.2733113913449); //E24
    glVertex2f(-0.3141988370289, 0.309084841405);//D24
    glVertex2f(-0.3240874329805, 0.3093756824624);//C24
    glVertex2f(-0.3575341545814, 0.310539046692); //B24
    glVertex2f(-0.3810922802307, 0.3244994174472); //A24
    glVertex2f(-0.441005538055, 0.3532926821297); //Z23
    glVertex2f(-0.4540933856379, 0.3602728675073); //W23
    glEnd();


    //Lower body

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4513333862673, 0.2777595506682);//Z21
    glVertex2f(-0.5455369079553, 0.240253621215); //J24
    glVertex2f(-0.5499682908322, 0.2285421093261);//K24
    glVertex2f(-0.4952090595676, 0.1839117532087); //L24
    glVertex2f(-0.4898280946456, 0.1750489874548); //M24
    glVertex2f(-0.4759513199637, 0.1746003427975); //Z24
    glVertex2f(-0.4614130867907, 0.171575045721);//B25
    glVertex2f(-0.4453488505378, 0.1695886232068); //T25
    glVertex2f(-0.4355608248445, 0.1691535998426); //U25
    glVertex2f(-0.4277304042899, 0.170349914094); //V25
    glVertex2f(-0.4287092068592, 0.1738301010072);//W25
    glVertex2f(-0.4145709475244, 0.170349914094); //Z25
    glVertex2f(-0.38066742649, 0.1732509037213); //A26
    glVertex2f(-0.3327028268984, 0.1993955420233); //B26
    glVertex2f(-0.3565533852501 , 0.2024354865511);//C26
    glVertex2f(-0.3725063115439, 0.2100170752848); //D26
    glVertex2f(-0.3723483617786, 0.2191781616713); //E26
    glVertex2f(-0.4012531688257, 0.2324459419552); //F26
    glVertex2f(-0.4039383148355, 0.2392377818624); //G26
    glVertex2f(-0.3927238815003, 0.2521896626158);//H26
    glVertex2f(-0.3882228158251, 0.2608278988578); //I24
    glVertex2f(-0.3844244876449, 0.2703237193083); //H24
    glVertex2f(-0.3869091013787, 0.2826183051817); //G24
    glEnd();

    //Front Leg
    glPushMatrix();
    glTranslatef(0.0f, 0.01f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4812655120916, 0.1745573497223);//G12
    glVertex2f(-0.4815753934812, 0.1600962182062); //U12
    glVertex2f(-0.4850873825637, 0.1514195392966);//V12
    glVertex2f(-0.4869466709015, 0.1450153239109); //W12
    glVertex2f(-0.4884960778497, 0.1394374588975); //Z12
    glVertex2f(-0.4912850103563, 0.1355122946289); //A13
    glVertex2f(-0.5036802659416, 0.1343760628669);//J12
    glVertex2f(-0.4997551016729, 0.1316904241567); //C13
    glVertex2f(-0.4866367895119, 0.1301410172086); //D13
    glVertex2f(-0.4818852748709, 0.1312772489706); //E13
    glVertex2f(-0.4672175557617, 0.1444988549281);//F13
    glVertex2f(-0.4697999006753, 0.1484240191968); //G13
    glVertex2f(-0.4677340247444, 0.1485273129933); //H13
    glVertex2f(-0.4641187418654, 0.1461515556728); //l13
    glVertex2f(-0.4579211140728, 0.149973426145);//j13
    glVertex2f(-0.4698755125084, 0.1703358813453); //L12
    glVertex2f(-0.4675590640932, 0.164888060828); //H12

    glEnd();
    glPopMatrix();


    //Back Leg
    glPushMatrix();
    glTranslatef(0.01f, 0.01f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4543189400492, 0.1701417715099);//l12
    glVertex2f(-0.4563717071246, 0.1582369298684); //j12
    glVertex2f(-0.4558552381419, 0.1504898951277);//k12
    glVertex2f(-0.456061825735, 0.1446021487247); //l12
    glVertex2f(-0.458540876852, 0.1352024132392); //M12
    glVertex2f(-0.4613298093587, 0.1279718474812); //N12
    glVertex2f(-0.466701086779, 0.1230137452471);   //O12
    glVertex2f(-0.475067884299, 0.1209478693162); //P12
    glVertex2f(-0.4712460138269, 0.1183655244026); //Q12
    glVertex2f(-0.4543058311937, 0.1179523492165); //R12
    glVertex2f(-0.4672175557617, 0.1444988549281);//F13
    glVertex2f(-0.4416006942189, 0.1303476048017); //S12
    glVertex2f(-0.442943513574, 0.1341694752738); //T12
    glVertex2f(-0.4372623547641, 0.1324134807326); //Q13
    glVertex2f(-0.4308581393784, 0.1384045209321);//P13
    glVertex2f(-0.4438731577428, 0.1519360082793); //O13
    glVertex2f(-0.4450513861298, 0.1646182269369); //N13
    glEnd();

    glPopMatrix();


    //Broom Brush
    glPushMatrix();
    glTranslatef(-0.01f, 0.023f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(150, 105, 25);

    glVertex2f(-0.3727039192255, 0.2223922836999);//H12
    glVertex2f(-0.376718712988, 0.2175986659684); //j12
    glVertex2f(-0.3730002622554, 0.2175986659684);//k12
    glVertex2f(-0.376718712988, 0.2148502458616); //l12
    glVertex2f(-0.3694434832937, 0.2116168104419); //M12
    glVertex2f(-0.3742936364233, 0.2091917338771); //N12
    glVertex2f(-0.35, 0.21);   //O12
    glVertex2f(-0.3388875185773, 0.2046649242895); //P12
    glVertex2f(-0.3173851730362, 0.1854259835422); //Q12
    glVertex2f(-0.2894159566556, 0.1728155854053); //R12
    glVertex2f(-0.2908710025945, 0.175887349054);//F13
    glVertex2f(-0.2635484732979, 0.1556783776808); //S13
    glVertex2f(-0.2847274752971, 0.1783124256188); //R13
    glVertex2f(-0.2803623374804, 0.1783124256188); //Q13
    glVertex2f(-0.250453059848, 0.1640853097721);//P13
    glVertex2f(-0.2680752828855, 0.1808991739546); //O13
    glVertex2f(-0.251261418703, 0.1718455547794); //N13
    glVertex2f(-0.2536864952678, 0.1754023337411); //P12
    glVertex2f(-0.2383276770241, 0.1681271040467); //Q12
    glVertex2f(-0.2685602981985, 0.1909228237557); //R12
    glVertex2f(-0.2583749766264, 0.187366044794);//F13
    glVertex2f(-0.2669435804886, 0.1946412744884); //S13
    glVertex2f(-0.2417227842148, 0.188012731878); //R13
    glVertex2f(-0.2517464340159, 0.1952879615723); //Q13
    glVertex2f(-0.2300824167038, 0.1914078390687);//P13
    glVertex2f(-0.25, 0.2); //O13
    glVertex2f(-0.2412377689018, 0.2015931606408); //N13
    glVertex2f(-0.2554648847486, 0.2048265960605); //P12
    glVertex2f(-0.2564349153745, 0.2078983597092); //Q12
    glVertex2f(-0.2441478607796, 0.210323436274); //R12
    glVertex2f(-0.2548181976647, 0.2164669635715);//F13
    glVertex2f(-0.2452795631765, 0.221963803785); //S13
    glVertex2f(-0.26225509913, 0.2213171167011); //R13
    glVertex2f(-0.2498063727641, 0.2255205827467); //Q13
    glVertex2f(-0.2706620312213, 0.2260055980597);//P13
    glVertex2f(-0.2941044380142, 0.2310174229602); //O13
    glVertex2f(-0.3146367529295, 0.2303707358763); //N13
    glVertex2f(-0.3461627482717, 0.222125475556);//P13
    glVertex2f(-0.3523062755692, 0.222125475556); //O13
    glVertex2f(-0.3645933301641, 0.2308557511892); //N13

    glEnd();
    glPopMatrix();

    //dandi
    glPushMatrix();
    glTranslatef(-0.01f, 0.023f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3ub(153,101,21);
    glVertex2f(-0.6515749481072, 0.2945418174205);
    glVertex2f(-0.3727039192255, 0.2223922836999);
    glEnd();
    glPopMatrix();

    }






void blackship()//F38
{

    glPushMatrix();
    glScaled(0.5,0.2,0);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f); //ship body front
    glVertex2d(0.0f,0.0f);
    glVertex2d(-3.0f,7.0f);
    glVertex2d(10.0f,7.0f);
    glVertex2d(8.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f); //green box front
    glVertex2d(2.0f,7.0f);
    glVertex2d(2.0f,9.0f);
    glVertex2d(8.0f,9.0f);
    glVertex2d(8.0f,7.0f);

    glColor3f(0.0f,0.0f,1.0f); //blue box front
    glVertex2d(3.0f,9.0f);
    glVertex2d(3.0f,11.0f);
    glVertex2d(7.0f,11.0f);
    glVertex2d(7.0f,9.0f);

    glColor3f(1.0f,0.0f,0.0f); //red stand front
    glVertex2d(4.0f,9.0f);
    glVertex2d(4.0f,15.0f);
    glVertex2d(6.0f,15.0f);
    glVertex2d(6.0f,9.0f);

    glEnd();
    glPopMatrix();
}


void Bard()//F39
{

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();

}


void wheerligig()//F40
{
    glPushMatrix();
    glPushMatrix();
    glTranslated(13,-5,1);
    glScaled(0.4,0.25,0);
    glColor3f(0.184,0.31,0.31);
    glBegin(GL_QUADS);
    glVertex2d(0,-10);
    glVertex2d(1,-10);
    glVertex2d(1,30);
    glVertex2d(0,30);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(13.25,2.5,1);
    glScaled(0.35,0.2,0);
    glRotated(angle,0,0,1);
    glPushMatrix();
    glTranslatef(10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();



    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();


    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

    glColor3f(1,0,0);
    glBegin(GL_LINES);

    glVertex2d(0,0);
    glVertex2d(10,13);
    glVertex2d(0,0);
    glVertex2d(10,-13);
    glVertex2d(0,0);       //4 cross lines
    glVertex2d(-10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,13);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,0);
    glColor3f(0.545,0,0);
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
}


void TrainLineStand()//F41
{

    //left stand;
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-1, 0.15);
    glVertex2f(-0.3401491747484, 0.289164780547);
    glVertex2f(-0.5377171099902, 0.2720197377969);
    glVertex2f(-0.9997158107161, 0.1721983055444);
    glEnd();

    //right stand;
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(1.0026810730535, 0.1620790406772);
    glVertex2f(0.56011358327, 0.2724813880009);
    glVertex2f(0.5267765560807, 0.2724673694045);
    glVertex2f(0.9989775639092, 0.1398579858116);
    glEnd();

    //middle stand;
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-0.6441776006153, 0.237546840868);
    glVertex2f(0.6660538061076, 0.2333537928378);
    glVertex2f(0.6218413507372, 0.2457700866546);
    glVertex2f(-0.5998366919368, 0.2484565151401);
    glEnd();

}

/////////////////////////////////////////////////

void TrainPart()//F42
{

    //4rd part

    //Wheel
    glBegin(GL_POLYGON);
    glColor3ub(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.4181430288752)+x,(0.2894196624232+y));
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.371613308143)+x,(0.2894196624232+y));
        }
    glEnd();

    //body
    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2f(-0.4602711712901, 0.2895573360912);
    glVertex2f(-0.3401491747484, 0.289164780547);
    glVertex2f(-0.3405417302927, 0.4045761105575);
    glVertex2f(-0.4602711712901, 0.4041835550133);
    glEnd();

    //window;
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2f(-0.4444807563549, 0.3467918795839);
    glVertex2f(-0.35477913555, 0.3463841449438);
    glVertex2f(-0.35518687019, 0.3928658939064);
    glVertex2f(-0.4444807563549, 0.3930697612264);
    glEnd();

    //roof
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4664292636764, 0.4042190946974);
    glVertex2f(-0.3321551175367, 0.4046504975766);
    glVertex2f(-0.3405417302927, 0.4045761105575);
    glVertex2f(-0.4662135622368, 0.4105822871651);
    glEnd();




}

////////////////////////////////////////////////////////


void TrainlineCross()//F43
{

    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-1, 0.2557167785128);
    glVertex2f(-0.9754293048045, 0.2559914983469);
    glVertex2f(-0.9754293048045, 0.3308351580175);
    glVertex2f(-0.9999374245239, 0.3309822446475);
    glEnd();
}


void TrainLine()//F44
{

    TrainLineStand();
    TrainlineCross();

    glPushMatrix();
    glTranslatef(0.08, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.32, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.40, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.56, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.64, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.72, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.80, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.96, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.04, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.12, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.20, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.28, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.36, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.44, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.52, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.60, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.68, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.76, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.84, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.92, 0.0f, 0.0f);
    TrainlineCross();
    glPopMatrix();


    //upper line
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9999980648384, 0.2973152032047);
    glVertex2f(0.9993365381334, 0.2966981573604);
    glVertex2f(0.9989458922249, 0.310761410068);
    glVertex2f(-0.9999950657936, 0.3109950845453);
    glEnd();

    //Lower Line;
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9998269964605, 0.2718254153711);
    glVertex2f(0.9999385462274, 0.2726663393647);
    glVertex2f(0.9999385462274, 0.2837025492797);
    glVertex2f(-0.9997272625358, 0.2838398841969);
    glEnd();

}


void Train()//F45
{

    // joint train part;
    glBegin(GL_QUADS);
    glColor3ub(255,229,204);
    glVertex2f(-0.3402231651472, 0.310917957778);
    glVertex2f(-0.1610147523435, 0.3108970084688);
    glVertex2f(-0.1609295978501, 0.3353789253159);
    glVertex2f(-0.3403063732809, 0.3353811490888);
    glEnd();

    //4rd part;
    TrainPart();

    //3nd part;
    glPushMatrix();
    glTranslatef(0.15, 0.0f, 0.0f);
    TrainPart();
    glPopMatrix();

    //2st part

    //Wheel;
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.1184279303271)+x,(0.2894196624232+y));
        }
    glEnd();

    //body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.1610904547415, 0.2891325690472);
    glVertex2f(-0.070441741507, 0.2885268983575);
    glVertex2f(-0.0710474121967, 0.4052194512518);
    glVertex2f(-0.1606866742816, 0.4052194512518);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
    glVertex2f(-0.1450919680854, 0.3468529025678);
    glVertex2f(-0.0856103973306, 0.3466934345497);
    glVertex2f(-0.0859293333668, 0.3930188938105);
    glVertex2f(-0.1449325000673, 0.3930188938105);
    glEnd();


    //1st part

    //Wheel
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.0416272514535)+x,(0.2894196624232+y));
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.0014289931996)+x,(0.2894196624232+y));
        }
    glEnd();

    //body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.070441741507, 0.2885268983575);
    glVertex2f(0.0199086787311, 0.2888198246858);
    glVertex2f(0.020236893377, 0.3465856023667);
    glVertex2f(-0.0707430913649, 0.3465869709834);
    glEnd();

    //upper body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.0256704631673, 0.3475450809554);
    glVertex2f(0.0042924418657, 0.3473263736193);
    glVertex2f(0.0042924418657, 0.3812260107004);
    glVertex2f(-0.0258891705033, 0.3812260107004);
    glEnd();
    //upper top roof
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.0321678925792, 0.3810613944403);
    glVertex2f(0.0112403848194, 0.3812956117644);
    glVertex2f(0.0110061674953, 0.3869168275426);
    glVertex2f(-0.0322459650206, 0.3870729724253);
    glEnd();

}



void leafless_tree() //F46
{

    //gacher gora
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);
    glVertex2f(-0.629419862086, -0.4953445671983);//k24
    glVertex2f(-0.6371391079331, -0.5143070624314);//l24
    glVertex2f(-0.6505638833194, -0.5275640281254);//m24
    glVertex2f(-0.6663457537908, -0.5353027647459);//n24
    glVertex2f(-0.6749605988491, -0.5382318120657);//o24
    glVertex2f(-0.6842367068845, -0.5397854892693);//r15
    glVertex2f(-0.674788301948, -0.5428838283972);//s15
    glVertex2f(-0.6489437667729, -0.5421946407925);//v15
    glVertex2f(-0.6347006479162, -0.5355112836743);//w15

    glVertex2f(-0.6382613589006, -0.5477081416299);//z15
    glVertex2f(-0.6623829250639, -0.5694175511769);//a16
    glVertex2f(-0.6427410783309, -0.5625256751302);//b16
    glVertex2f(-0.63, -0.55);//c16
    glVertex2f(-0.6125722184429, -0.5345464950871);//d16
    glVertex2f(-0.6010452282486, -0.5285831856004);//e16

    glVertex2f(-0.5969101026206, -0.5413331562867);//f16
    glVertex2f(-0.5884675544634, -0.5563229866882);//g16
    glVertex2f(-0.5827817567249, -0.5618364875256);//h16
    glVertex2f(-0.5863999916494, -0.5461574695194);//i16
    glVertex2f(-0.5863999916494, -0.5308230453155);//j16

    glVertex2f(-0.5754113918399, -0.5410031944066);//m16
    glVertex2f(-0.5641736913989, -0.5477081416299);//p16
    glVertex2f(-0.5474474060663, -0.5523615281652);//q16
    glVertex2f(-0.5372953748169, -0.5525324548626);//r16
    glVertex2f(-0.5468982978086, -0.5481883054067);//s16
    glVertex2f(-0.5569372215499, -0.5397824841762);//v16
    glVertex2f(-0.5657243635094, -0.5311676391179);//w16
    glVertex2f(-0.5729608333584, -0.5175561839257);//z16
    glVertex2f(-0.5770090305441, -0.5060598715996);//a17
    glVertex2f(-0.5779574434922, -0.4956744774775);//b17

    glEnd();

    //kando
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5779574434922, -0.4956744774775);//b17
    glVertex2f(-0.5775341257166, -0.4834062407073);//c17
    glVertex2f(-0.5769934966787, -0.4717827163905);//d17
    glVertex2f(-0.5778044402356, -0.4558341597698);//e17
    glVertex2f(-0.5786153837926, -0.4331277401741);//f17
    glVertex2f(-0.5769934966787, -0.4247479900853);//g17
    glVertex2f(-0.5742903514887, -0.4125838367305);//h17
    glVertex2f(-0.5805075854256, -0.383389868679);//j18
    glVertex2f(-0.5842919886915, -0.3701444572482);//k18
    glVertex2f(-0.5845623032105, -0.3541959006275);//l18
    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24
    glVertex2f(-0.62, -0.36);//e24
    glVertex2f(-0.6218657068319, -0.385552384831);//f24
    glVertex2f(-0.6261907391358, -0.4071775463506);//g24
    glVertex2f(-0.6279095748551, -0.4283884999593);//h24
    glVertex2f(-0.6272383360858, -0.4485256630387);//i24
    glVertex2f(-0.6278126262498, -0.4755671196564);//j24
    glVertex2f(-0.629419862086, -0.4953445671983);//k24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5779574434922, -0.4956744774775);//b17
    glVertex2f(-0.5775341257166, -0.4834062407073);//c17
    glVertex2f(-0.5769934966787, -0.4717827163905);//d17
    glVertex2f(-0.5778044402356, -0.4558341597698);//e17
    glVertex2f(-0.5786153837926, -0.4331277401741);//f17
    glVertex2f(-0.5769934966787, -0.4247479900853);//g17
    glVertex2f(-0.5742903514887, -0.4125838367305);//h17
    glVertex2f(-0.5805075854256, -0.383389868679);//j18
    glVertex2f(-0.5842919886915, -0.3701444572482);//k18
    glVertex2f(-0.5845623032105, -0.3541959006275);//l18
    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24
    glVertex2f(-0.62, -0.36);//e24
    glVertex2f(-0.6218657068319, -0.385552384831);//f24
    glVertex2f(-0.6261907391358, -0.4071775463506);//g24
    glVertex2f(-0.6279095748551, -0.4283884999593);//h24
    glVertex2f(-0.6272383360858, -0.4485256630387);//i24
    glVertex2f(-0.6278126262498, -0.4755671196564);//j24
    glVertex2f(-0.629419862086, -0.4953445671983);//k24


    glEnd();

    //right nicher daal
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);
    glVertex2f(-0.5742903514887, -0.4125838367305);//h17
    glVertex2f(-0.57, -0.4);//i17
    glVertex2f(-0.5542232194806, -0.3826965358376);//j17
    glVertex2f(-0.5388170165041, -0.3662278361042);//k17
    glVertex2f(-0.5225253995635, -0.3547174545701);//l17
    glVertex2f(-0.5127021164438, -0.3490035629226);//m17
    glVertex2f(-0.5035775407305, -0.3463945633069);//n17
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17
    glVertex2f(-0.5064108654158, -0.337894589251);//c18
    glVertex2f(-0.5145566738861, -0.3412591623148);//d18
    glVertex2f(-0.5247716963228, -0.3473569496866);//e18
    glVertex2f(-0.53, -0.35);//f18
    glVertex2f(-0.5409420100181, -0.3564882824984);//g18
    glVertex2f(-0.5616606967795, -0.3726028166461);//h18
    glVertex2f(-0.5765155595475, -0.3842717996158);//i18
    glVertex2f(-0.5805075854256, -0.383389868679);//j18

    glEnd();

    //nicher daal#1
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5035775407305, -0.3463945633069);//n17
    glVertex2f(-0.4908362742112, -0.3409682973457);//o17
    glVertex2f(-0.4762728946815, -0.3333431316486);//p17
    glVertex2f(-0.4716209260509, -0.329615132874);//q17
    glVertex2f(-0.4841396780074, -0.3353054746723);//r17
    glVertex2f(-0.5014153329261, -0.3417239443968);//s17
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5035775407305, -0.3463945633069);//n17
    glVertex2f(-0.4908362742112, -0.3409682973457);//o17
    glVertex2f(-0.4762728946815, -0.3333431316486);//p17
    glVertex2f(-0.4716209260509, -0.329615132874);//q17
    glVertex2f(-0.4841396780074, -0.3353054746723);//r17
    glVertex2f(-0.5014153329261, -0.3417239443968);//s17
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17

    glEnd();

    //nicher daal#2
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5051712858659, -0.3414362451076);//t17
    glVertex2f(-0.4987362206542, -0.3321753134787);//u17
    glVertex2f(-0.493077220391, -0.3186417255983);//v17
    glVertex2f(-0.4913457815259, -0.3095288894661);//w17
    glVertex2f(-0.4914369098872, -0.2995958980819);//z17
    glVertex2f(-0.4951731727014, -0.3174570569011);//a18
    glVertex2f(-0.5020989281619, -0.3319464663514);//b18
    glVertex2f(-0.5064108654158, -0.337894589251);//c18

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17
    glVertex2f(-0.4987362206542, -0.3321753134787);//u17
    glVertex2f(-0.493077220391, -0.3186417255983);//v17
    glVertex2f(-0.4913457815259, -0.3095288894661);//w17
    glVertex2f(-0.4914369098872, -0.2995958980819);//z17
    glVertex2f(-0.4951731727014, -0.3174570569011);//a18
    glVertex2f(-0.5020989281619, -0.3319464663514);//b18
    glVertex2f(-0.5064108654158, -0.337894589251);//c18

    glEnd();

    //daal 2
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.5784633950618, -0.306215395255);//n18
    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5817135361927, -0.2676026561615);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22
    glVertex2f(-0.601477651402, -0.2967217859033);//m22
    glVertex2f(-0.6021585196228, -0.3080110729981);//n22
    glVertex2f(-0.6047716706036, -0.3162223795766);//o22
    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.5784633950618, -0.306215395255);//n18
    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5817135361927, -0.2676026561615);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22
    glVertex2f(-0.601477651402, -0.2967217859033);//m22
    glVertex2f(-0.6021585196228, -0.3080110729981);//n22
    glVertex2f(-0.6047716706036, -0.3162223795766);//o22
    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glEnd();

    /////////

    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5543691583961, -0.2560190688682);//p18
    glVertex2f(-0.5443383215231, -0.230296562445);//q18
    glVertex2f(-0.5384463743403, -0.2068294920212);//r18
    glVertex2f(-0.5331714313819, -0.1696755459664);//s18
    glVertex2f(-0.5298274947868, -0.1431832072954);//t18
    glVertex2f(-0.5398224464164, -0.1835509394005);//u18
    glVertex2f(-0.5464234004575, -0.2104604556683);//v18
    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19
    glVertex2f(-0.5594913081571, -0.2317677261959);//l19
    glVertex2f(-0.5637576830347, -0.2450081999537);//m19
    glVertex2f(-0.5703779199136, -0.2550121134597);//n19
    glVertex2f(-0.5759683421669, -0.2638390959649);//o19
    glVertex2f(-0.5817058807953, -0.2667814234666);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5543691583961, -0.2560190688682);//p18
    glVertex2f(-0.5443383215231, -0.230296562445);//q18
    glVertex2f(-0.5384463743403, -0.2068294920212);//r18
    glVertex2f(-0.5331714313819, -0.1696755459664);//s18
    glVertex2f(-0.5298274947868, -0.1431832072954);//t18
    glVertex2f(-0.5398224464164, -0.1835509394005);//u18
    glVertex2f(-0.5464234004575, -0.2104604556683);//v18
    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19
    glVertex2f(-0.5594913081571, -0.2317677261959);//l19
    glVertex2f(-0.5637576830347, -0.2450081999537);//m19
    glVertex2f(-0.5703779199136, -0.2550121134597);//n19
    glVertex2f(-0.5759683421669, -0.2638390959649);//o19
    glVertex2f(-0.5817058807953, -0.2667814234666);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5526765644741, -0.2120102962617);//z18
    glVertex2f(-0.5562884122295, -0.2070472401577);//a19
    glVertex2f(-0.5624544661448, -0.1907793532322);//b19
    glVertex2f(-0.5656292438359, -0.1831144162457);//c19
    glVertex2f(-0.5678166053575, -0.1713822044479);//d19
    glVertex2f(-0.5679160308812, -0.1543804398936);//e19
    glVertex2f(-0.5665214378762, -0.1414509219098);//f19
    glVertex2f(-0.5698012537886, -0.1550949561053);//g19
    glVertex2f(-0.5704572169711, -0.1739866957607);//h19
    glVertex2f(-0.5682269421507, -0.1874995373198);//i19
    glVertex2f(-0.5636351998733, -0.2066536622482);//j19
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5526765644741, -0.2120102962617);//z18
    glVertex2f(-0.5562884122295, -0.2070472401577);//a19
    glVertex2f(-0.5624544661448, -0.1907793532322);//b19
    glVertex2f(-0.5656292438359, -0.1831144162457);//c19
    glVertex2f(-0.5678166053575, -0.1713822044479);//d19
    glVertex2f(-0.5679160308812, -0.1543804398936);//e19
    glVertex2f(-0.5665214378762, -0.1414509219098);//f19
    glVertex2f(-0.5698012537886, -0.1550949561053);//g19
    glVertex2f(-0.5704572169711, -0.1739866957607);//h19
    glVertex2f(-0.5682269421507, -0.1874995373198);//i19
    glVertex2f(-0.5636351998733, -0.2066536622482);//j19
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19


    glEnd();

    //left nicher daal
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6166306093697, -0.319136491991);//q22
    glVertex2f(-0.6269242733611, -0.3102758533167);//r22
    glVertex2f(-0.6485142846929, -0.2890819889818);//s22
    glVertex2f(-0.6649543850649, -0.2768014320774);//t22
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6916943073566, -0.260163258207);//e23
    glVertex2f(-0.71, -0.25);//f23
    glVertex2f(-0.7709558165106, -0.2157474982364);//g23
    glVertex2f(-0.7071440402363, -0.257984449724);//h23
    glVertex2f(-0.6772349419692, -0.2785840935635);//i23
    glVertex2f(-0.6627755765819, -0.290468503471);//j23
    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24
    glVertex2f(-0.6347897722405, -0.3228362034847);//c24
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6166306093697, -0.319136491991);//q22
    glVertex2f(-0.6269242733611, -0.3102758533167);//r22
    glVertex2f(-0.6485142846929, -0.2890819889818);//s22
    glVertex2f(-0.6649543850649, -0.2768014320774);//t22
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6916943073566, -0.260163258207);//e23
    glVertex2f(-0.71, -0.25);//f23
    glVertex2f(-0.7709558165106, -0.2157474982364);//g23
    glVertex2f(-0.7071440402363, -0.257984449724);//h23
    glVertex2f(-0.6772349419692, -0.2785840935635);//i23
    glVertex2f(-0.6627755765819, -0.290468503471);//j23
    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24
    glVertex2f(-0.6347897722405, -0.3228362034847);//c24
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glEnd();

    //left nicher daal up
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6910431099364, -0.2424369936892);//v22
    glVertex2f(-0.7021922027749, -0.2247081019832);//w22
    glVertex2f(-0.71425759275, -0.2121203631656);//z22
    glVertex2f(-0.7306879344673, -0.2022621581352);//a23
    glVertex2f(-0.715105610387, -0.2138163984396);//b23
    glVertex2f(-0.7064899861296, -0.2243903573086);//c23
    glVertex2f(-0.6968504105225, -0.2405065227767);//q24
    glVertex2f(-0.691101129232, -0.2568566320869);//d23
    glVertex2f(-0.6916943073566, -0.260163258207);//e23

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6910431099364, -0.2424369936892);//v22
    glVertex2f(-0.7021922027749, -0.2247081019832);//w22
    glVertex2f(-0.71425759275, -0.2121203631656);//z22
    glVertex2f(-0.7306879344673, -0.2022621581352);//a23
    glVertex2f(-0.715105610387, -0.2138163984396);//b23
    glVertex2f(-0.7064899861296, -0.2243903573086);//c23
    glVertex2f(-0.6968504105225, -0.2405065227767);//q24
    glVertex2f(-0.691101129232, -0.2568566320869);//d23
    glVertex2f(-0.6916943073566, -0.260163258207);//e23




    glEnd();

    //left nicher daal down
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6647659033553, -0.306039918654);//l23
    glVertex2f(-0.6775495218403, -0.3073914906524);//m23
    glVertex2f(-0.6964617045839, -0.3035778074158);//n23
    glVertex2f(-0.722770868287, -0.2940109278682);//o23
    glVertex2f(-0.7473368274368, -0.2889244548788);//p23
    glVertex2f(-0.7661847457755, -0.2893640043484);//q23
    glVertex2f(-0.7781253322054, -0.2917234098578);//r23
    glVertex2f(-0.7955776397213, -0.3017667189);//s23
    glVertex2f(-0.7768081769212, -0.2943577204262);//r24
    glVertex2f(-0.7621548243843, -0.2923819874999);//t23
    glVertex2f(-0.7438792948158, -0.2940284316052);//u23
    glVertex2f(-0.7193472776472, -0.3017667189);//v23
    glVertex2f(-0.6954738381208, -0.3123039611737);//w23
    glVertex2f(-0.6775270659941, -0.3168382455172);//z23
    glVertex2f(-0.6590586038649, -0.3155190696508);//a24
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6647659033553, -0.306039918654);//l23
    glVertex2f(-0.6775495218403, -0.3073914906524);//m23
    glVertex2f(-0.6964617045839, -0.3035778074158);//n23
    glVertex2f(-0.722770868287, -0.2940109278682);//o23
    glVertex2f(-0.7473368274368, -0.2889244548788);//p23
    glVertex2f(-0.7661847457755, -0.2893640043484);//q23
    glVertex2f(-0.7781253322054, -0.2917234098578);//r23
    glVertex2f(-0.7955776397213, -0.3017667189);//s23
    glVertex2f(-0.7768081769212, -0.2943577204262);//r24
    glVertex2f(-0.7621548243843, -0.2923819874999);//t23
    glVertex2f(-0.7438792948158, -0.2940284316052);//u23
    glVertex2f(-0.7193472776472, -0.3017667189);//v23
    glVertex2f(-0.6954738381208, -0.3123039611737);//w23
    glVertex2f(-0.6775270659941, -0.3168382455172);//z23
    glVertex2f(-0.6590586038649, -0.3155190696508);//a24
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24


    glEnd();

    //top daal
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.59, -0.26);//r19
    glVertex2f(-0.5969217410789, -0.2447988003275);//s19
    glVertex2f(-0.6022657522227, -0.2293833835666);//t19
    glVertex2f(-0.6092540744876, -0.2152012001465);//u19
    glVertex2f(-0.6172700912033, -0.2012245556166);//v19
    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21
    glVertex2f(-0.6382736778887, -0.1796518099154);//c21
    glVertex2f(-0.6438883611052, -0.1739176653538);//d21
    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21
    glVertex2f(-0.6626699448768, -0.1789381225684);//f22
    glVertex2f(-0.6503392737369, -0.1844302637166);//g22
    glVertex2f(-0.6417292191306, -0.1909476111094);//h22
    glVertex2f(-0.6308356579529, -0.2075962612112);//i22
    glVertex2f(-0.6199420967752, -0.2289723057863);//j22
    glVertex2f(-0.6108417734709, -0.2548261431784);//k22
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22


    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.59, -0.26);//r19
    glVertex2f(-0.5969217410789, -0.2447988003275);//s19
    glVertex2f(-0.6022657522227, -0.2293833835666);//t19
    glVertex2f(-0.6092540744876, -0.2152012001465);//u19
    glVertex2f(-0.6172700912033, -0.2012245556166);//v19
    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21
    glVertex2f(-0.6382736778887, -0.1796518099154);//c21
    glVertex2f(-0.6438883611052, -0.1739176653538);//d21
    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21
    glVertex2f(-0.6626699448768, -0.1789381225684);//f22
    glVertex2f(-0.6503392737369, -0.1844302637166);//g22
    glVertex2f(-0.6417292191306, -0.1909476111094);//h22
    glVertex2f(-0.6308356579529, -0.2075962612112);//i22
    glVertex2f(-0.6199420967752, -0.2289723057863);//j22
    glVertex2f(-0.6108417734709, -0.2548261431784);//k22
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22

    glEnd();

    //top daal right
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6194988242484, -0.1849652026938);//z19
    glVertex2f(-0.6043468925912, -0.1558857378971);//a20
    glVertex2f(-0.5908785088959, -0.1272654225446);//b20
    glVertex2f(-0.5838711112742, -0.1086050072283);//c20
    glVertex2f(-0.5814570748408, -0.0896461573997);//d20
    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20
    glVertex2f(-0.5896545762834, -0.0916160787636);//u20
    glVertex2f(-0.5911004425358, -0.1026408089375);//v20
    glVertex2f(-0.6023059059912, -0.1281242016345);//w20
    glVertex2f(-0.6218251003974, -0.1644515912238);//z20
    glVertex2f(-0.6290544316589, -0.1754763213977);//a21
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6194988242484, -0.1849652026938);//z19
    glVertex2f(-0.6043468925912, -0.1558857378971);//a20
    glVertex2f(-0.5908785088959, -0.1272654225446);//b20
    glVertex2f(-0.5838711112742, -0.1086050072283);//c20
    glVertex2f(-0.5814570748408, -0.0896461573997);//d20
    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20
    glVertex2f(-0.5896545762834, -0.0916160787636);//u20
    glVertex2f(-0.5911004425358, -0.1026408089375);//v20
    glVertex2f(-0.6023059059912, -0.1281242016345);//w20
    glVertex2f(-0.6218251003974, -0.1644515912238);//z20
    glVertex2f(-0.6290544316589, -0.1754763213977);//a21
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5639904503049, -0.0737234838913);//f20
    glVertex2f(-0.543567589491, -0.0473364247866);//g20
    glVertex2f(-0.543567589491, -0.0473364247866);//h20
    glVertex2f(-0.5587491851403, -0.0641446199697);//i20
    glVertex2f(-0.5717619814111, -0.0735427506097);//j20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5639904503049, -0.0737234838913);//f20
    glVertex2f(-0.543567589491, -0.0473364247866);//g20
    glVertex2f(-0.543567589491, -0.0473364247866);//h20
    glVertex2f(-0.5587491851403, -0.0641446199697);//i20
    glVertex2f(-0.5717619814111, -0.0735427506097);//j20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20


    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5845940444004, -0.0742656837359);//l20
    glVertex2f(-0.5920041089435, -0.0654097529405);//m20
    glVertex2f(-0.5956187745742, -0.0536620896404);//n20
    glVertex2f(-0.596883907545, -0.037757560865);//o20
    glVertex2f(-0.5947151081665, -0.0214915655265);//p20
    glVertex2f(-0.5989968131683, -0.0350444554008);//q20
    glVertex2f(-0.5986523558595, -0.0520950921872);//r20
    glVertex2f(-0.5967031742635, -0.0641446199697);//s20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5845940444004, -0.0742656837359);//l20
    glVertex2f(-0.5920041089435, -0.0654097529405);//m20
    glVertex2f(-0.5956187745742, -0.0536620896404);//n20
    glVertex2f(-0.596883907545, -0.037757560865);//o20
    glVertex2f(-0.5947151081665, -0.0214915655265);//p20
    glVertex2f(-0.5989968131683, -0.0350444554008);//q20
    glVertex2f(-0.5986523558595, -0.0520950921872);//r20
    glVertex2f(-0.5967031742635, -0.0641446199697);//s20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20


    glEnd();

    //top daal top1
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6565604206257, -0.1453562961332);//f21
    glVertex2f(-0.6656054767175, -0.1317064842128);//g21
    glVertex2f(-0.6759661773317, -0.1207701891201);//h21
    glVertex2f(-0.684188955597, -0.1132874608987);//i21
    glVertex2f(-0.6943852006459, -0.1067092382865);//j21
    glVertex2f(-0.68, -0.12);//k21
    glVertex2f(-0.6684834491103, -0.1379557956944);//l21
    glVertex2f(-0.6614940875849, -0.1518522909627);//m21
    glVertex2f(-0.656971559539, -0.1664066084922);//n21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6565604206257, -0.1453562961332);//f21
    glVertex2f(-0.6656054767175, -0.1317064842128);//g21
    glVertex2f(-0.6759661773317, -0.1207701891201);//h21
    glVertex2f(-0.684188955597, -0.1132874608987);//i21
    glVertex2f(-0.6943852006459, -0.1067092382865);//j21
    glVertex2f(-0.68, -0.12);//k21
    glVertex2f(-0.6684834491103, -0.1379557956944);//l21
    glVertex2f(-0.6614940875849, -0.1518522909627);//m21
    glVertex2f(-0.656971559539, -0.1664066084922);//n21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21

    glEnd();


}


void waterfall()//F47
{

    glPushMatrix();
    glScalef(0.5,1.2,1.0);
    glTranslatef(0.1f, -0.1f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(153,204,255);
    glVertex2f(0.1349744290931, 0.3208738313581);
    glVertex2f(0.1418331837972, 0.3208524860652);
    glVertex2f(0.1423394920046, 0.3873965155746);
    glVertex2f(0.135124841831, 0.3873721417564);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

}


void Fountain()//F48
{

    //border

    glBegin(GL_POLYGON);
    glColor3ub(28,163,236);


    glVertex2f(0.0523562861658, 0.2476434939835); //a14
    glVertex2f(0.0324222507317, 0.2384881849969); //j14
    glVertex2f(0.1486274339599, 0.1732298427639); //p14
    glVertex2f(0.269855896002, 0.2418813198872); //Q14
    glVertex2f(0.2510867691315, 0.2492509080094);    //J15
    glVertex2f(0.2032832352019, 0.223610321721);  //V15
    glVertex2f(0.093889520929, 0.2240125155838);    //P15

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(28,163,236);


    glVertex2f(0.0809510306663, 0.3264676497324); //a14
    glVertex2f(0.0630529593538, 0.3158875462336); //j14
    glVertex2f(0.11, 0.3); //p14
    glVertex2f(0.1121864243235, 0.2612067545737); //Q14
    glVertex2f(0.1858866217781, 0.2605727743806);    //J15
    glVertex2f(0.19, 0.3);  //V15
    glVertex2f(0.24, 0.32);    //P15
    glVertex2f(0.2203096556183,0.3266695675172);    //P15

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(28,163,236);


    glVertex2f(0.1484576960699, 0.3984241447819); //a14
    glVertex2f(0.0679257725531, 0.3831508489425); //j14
    glVertex2f(0.1197624129777, 0.3771340960361); //p14
    glVertex2f(0.120688067271, 0.3563068744369); //Q14
    glVertex2f(0.1794671148953, 0.3567697015836);    //J15
    glVertex2f(0.179929942042, 0.3762084417428);  //V15
    glVertex2f(0.2303781010267, 0.3873162932624);    //P15


    glEnd();



    //ground
    //bottom left
    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);

    glVertex2f(0.0226193961984, 0.1645379198803);    //T14
    glVertex2f(0.1106868245775, 0.1033203172265);  //I15
    glVertex2f(0.1497808412925, 0.1029382910046);    //G15
    glVertex2f(0.15, 0.16); //v14
    glVertex2f(0.0125238617257, 0.2390730360938); //v14

    glEnd();

    //bottom left border

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.0125238617257, 0.2390730360938);    //T14
    glVertex2f(0.15, 0.16);  //I15
    glVertex2f(0.1486274339599, 0.1732298427639);    //G15
    glVertex2f(0.0324222507317, 0.2384881849969); //v14
    glVertex2f(0.0523562861658, 0.2476434939835); //v14
    glVertex2f(0.0460897089614, 0.251208960324); //v14

    glEnd();

    //bottom right
    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);

    glVertex2f(0.1497808412925, 0.1029382910046);    //G15
    glVertex2f(0.1766299965589, 0.1026759214091);  //I15
    glVertex2f(0.1981098571392, 0.1076162893426);    //G15
    glVertex2f(0.2816665147965, 0.1675451003615); //v14
    glVertex2f(0.2855328897009, 0.2429394109983); //v14
    glVertex2f(0.15, 0.16); //v14

    glEnd();

    //bottom right border
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.2855328897009, 0.2429394109983);    //P15
    glVertex2f(0.15, 0.16);  //V15
    glVertex2f(0.1486274339599, 0.1732298427639);//S15
    glVertex2f(0.269855896002, 0.2418813198872);    //T15
    glVertex2f(0.2510867691315, 0.2492509080094); //U15
    glVertex2f(0.25705089846, 0.2524895269178); //T14

    glEnd();

    //2nd floor
    //left side
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);

    glVertex2f(0.0460897089614, 0.251208960324);    //Q14
    glVertex2f(0.093889520929, 0.2240125155838);  //R14
    glVertex2f(0.0914235729976, 0.29861158597);//V14
    glVertex2f(0.0420050067357, 0.3155649096876);    //P14
    glEnd();

    //left side middle left wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.093889520929, 0.2240125155838);  //R14
    glVertex2f(0.1121864243235, 0.2612067545737);//B15
    glVertex2f(0.11, 0.3);    //A15
    glVertex2f(0.0914235729976, 0.29861158597);//V14
    glEnd();

    //left side border

    glBegin(GL_POLYGON);
    glColor3ub(136,140,141);
    glVertex2f(0.0420050067357, 0.3155649096876);  //P14
    glVertex2f(0.1121864243235, 0.2612067545737);//V14
    glVertex2f(0.11, 0.3);    //A15
    glVertex2f(0.0630529593538, 0.3158875462336);//Z14
    glVertex2f(0.0809510306663, 0.3264676497324);//W14
    glVertex2f(0.072269562536, 0.3298460454098);//J14
    glEnd();

    //middle floor

    glBegin(GL_QUADS);
    glColor3ub(102,178,255);
    glVertex2f(0.093889520929, 0.2240125155838);  //R14
    glVertex2f(0.2035102784564, 0.223416102322);//S14
    glVertex2f(0.1858866217781, 0.2605727743806);    //C15
    glVertex2f(0.1121864243235, 0.2612067545737);//B15
    glEnd();

    //right side

    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(0.2035102784564, 0.223416102322);//S14
    glVertex2f(0.25705089846, 0.2524895269178); //T14
    glVertex2f(0.2595868192327, 0.3181064769096);//U14
    glVertex2f(0.2083107816742, 0.2982421429704);    //H15
    glEnd();

    //right side middle left wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.2035102784564, 0.223416102322);//S14
    glVertex2f(0.1858866217781, 0.2605727743806);    //C15
    glVertex2f(0.19, 0.3);    //D15
    glVertex2f(0.2083107816742, 0.2982421429704);//H15
    glEnd();

    //right side border
    glBegin(GL_POLYGON);
    glColor3ub(136,140,141);
    glVertex2f(0.2595868192327, 0.3181064769096);//U14
    glVertex2f(0.2083107816742, 0.2982421429704);    //H15
    glVertex2f(0.19, 0.3);    //D15
    glVertex2f(0.24, 0.32);//F15
    glVertex2f(0.2203096556183, 0.3266695675172);//G15
    glVertex2f(0.2274502255224, 0.328924484329);//G14
    glEnd();


    //3rd floor starts here
    //left side
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);

    glVertex2f(0.072269562536, 0.3298460454098);    //J14
    glVertex2f(0.1057197643293, 0.3165840498598);  //l14
    glVertex2f(0.1031006356983, 0.3780597503294);//C14
    glVertex2f(0.0679257725531, 0.3831508489425);    //A14
    glEnd();

    //left side middle left wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.1057197643293, 0.3165840498598);  //l14
    glVertex2f(0.120688067271, 0.3563068744369);//L14
    glVertex2f(0.1197624129777, 0.3771340960361);    //K14
    glVertex2f(0.1031006356983, 0.3780597503294);//C14
    glEnd();

    //middle floor

    glBegin(GL_QUADS);
    glColor3ub(102,178,255);
    glVertex2f(0.1057197643293, 0.3165840498598);  //l14
    glVertex2f(0.1912886414304, 0.317505036721);//O14
    glVertex2f(0.1794671148953, 0.3567697015836);    //M14
    glVertex2f(0.120688067271, 0.3563068744369);//L14
    glEnd();

    //Right side
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);

    glVertex2f(0.1912886414304, 0.317505036721);//O14
    glVertex2f(0.2274502255224, 0.328924484329);//G14
    glVertex2f(0.2303781010267, 0.3873162932624);//E14
    glVertex2f(0.197054546468, 0.3794482317693);    //A14
    glEnd();

    //right side middle right wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.1912886414304, 0.317505036721);//O14
    glVertex2f(0.2303781010267, 0.3873162932624);//E14
    glVertex2f(0.179929942042, 0.3762084417428);    //N14
    glVertex2f(0.1794671148953, 0.3567697015836);    //M14
    glEnd();


    //top

    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);
    glVertex2f(0.1197624129777, 0.3771340960361);    //K14
    glVertex2f(0.1031006356983, 0.3780597503294);//C14
    glVertex2f(0.0679257725531, 0.3831508489425);    //A14
    glVertex2f(0.1484576960699, 0.3984241447819);    //D14
    glVertex2f(0.2303781010267, 0.3873162932624);//E14
    glVertex2f(0.197054546468, 0.3794482317693);//F14
    glVertex2f(0.179929942042, 0.3762084417428);    //N14
    glEnd();


    //bottom traingle


    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(0.1981098571392, 0.1076162893426);    //N15
    glVertex2f(0.1106868245775, 0.1033203172265);//L15
    glVertex2f(0.1484750949575, 0.0801595731801);    //E15
    glEnd();

    glPushMatrix();
    glTranslatef(0.0,watermove,0.0);
    waterfall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f,watermove2,0.0f);
    waterfall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.035f,watermove3,0.0f);
    waterfall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05f,watermove4,0.0f);
    waterfall();
    glPopMatrix();

}


void fountainwater(int value) //A1
{

    watermove -= 0.002;
    watermove2 -=0.002;
    watermove3 -=0.002;
    watermove4 -=0.002;

    if(watermove < -0.03)
    {
        watermove = 0.05;
    }

     if(watermove2 < -0.03)
    {
        watermove2 = 0.053;
    }

     if(watermove3 < -0.03)
    {
        watermove3 = 0.048;
    }

     if(watermove4 < -0.03)
    {
        watermove4 = 0.045;
    }


    glutPostRedisplay();
    glutTimerFunc(15, fountainwater, 0);


}

void update_speed_boat(int value) //A2
{
    move_speed_boat -= boatstartstop; //assume as moving speed
    if(move_speed_boat<-90) //boundary for the positive x negative for last part of the box
    {
        move_speed_boat =60;//reappear the box
    }
    glutPostRedisplay();
    glutTimerFunc(35, update_speed_boat, 0);
}



void updateFlow(int value) //A3
{
    move_flow -=0.001;
    if (move_flow < -0.1)
    {
        move_flow = 0.001;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateFlow, 0);
}

void update(int value) //A4
{
    cloudPosition+=cloudSpeed;
    if(cloudPosition>1.0)
    {
        cloudPosition=-1.7;
    }
    sunPosition+=sunSpeed;
    if(sunPosition>=0.08)
    {
        sunPosition=0.08;
        p = true;
    }
    glutPostRedisplay();
    glutTimerFunc(80, update, 0);
}

void updateFroghopper(int value) //A5
{

    if(f==false){
        benchPosition += stopstart;
        if(benchPosition > 0.1)
        {
            //benchPosition=(-0.5);
            f=true;
        }
    }
    else if(f==true){
        benchPosition -= stopstart;
        if(benchPosition < (-0.45))
        {
            //benchPosition=(0.5);
            f=false;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(benchSpeed, updateFroghopper, 0);

}


void updateGlow(int value) //A6
{
    // Increase glowAlpha gradually
    glowAlpha += 0.01f;
    if (glowAlpha > 1.0f)
        glowAlpha = 0.0f;

    // Redraw
    glutPostRedisplay();

    // Call updateGlow again after 50 milliseconds
    glutTimerFunc(50, updateGlow, 0);
}


// Definition of update function
void Bat_update(int value) //A7
{
    glutPostRedisplay();
    glutTimerFunc(16, Bat_update, 0); // 60 frames per second

    // Update the rotation count
    rotationCount++;
}

void chairupdate(int value) //A8
{


   chairmove += chairmovespeed;
   chairmove2 += chairmove2speed;

    if(chairmove > .25)
    {
        chairmove = 0.02;
    }

    if(chairmove2 > .12)
    {
        chairmove2 = -0.13;
    }


    glutPostRedisplay();
    glutTimerFunc(20, chairupdate, 0);


}

void blackshipmove(int value) //A9
{
    blackshipupdate -= blackshipstartstop; //assume as moving speed
    if(blackshipupdate<-40) //boundary for the positive x negative for last part of the box
    {
        blackshipupdate =40;//reappear the box
    }
    glutPostRedisplay();
    glutTimerFunc(20, blackshipmove, 0);
}

void GhostUpdate(int value)//A10
{

    ghostmovement-=speed;// speedMultiplier;
    ghostmovement3rd -= speed;// speedMultiplier;
    if(ghostmovement<(-1.4))
    {
        ghostmovement = 1.8;
        ghostmovement3rd = 1.8f;
    }
    glutPostRedisplay();
    glutTimerFunc(resumeGhostMovement,GhostUpdate,0);

}


void Bardfly(int value) //A11
{

    bardposition += 0.005;
    if(bardposition > 1.3)
    {
        bardposition = -1.1;
    }
    glutPostRedisplay();
    glutTimerFunc(20, Bardfly, 0);
}


void windMove(int value)//A12
{

    angle -= angle_speed;

    glutPostRedisplay();
    glutTimerFunc(20, windMove, 0);

}

void TrainMove(int value) //A13
{

    trainmovent += trainstartstop;
    if(trainmovent > 1.6)
    {
        trainmovent = -2.0;
    }
    glutPostRedisplay();
    glutTimerFunc(trainspeed, TrainMove, 0);
}


void update_star(int value) //A14
{
    glutPostRedisplay();
    glutTimerFunc(25, update_star, 0); // 60 frames per second
}


void mouseClick(int button, int state, int x, int y) //A15
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        fountainRunning = true;  // Start the fountain on left mouse click
        fountainwater(0);        // Start the timer function
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        fountainRunning = false; // Stop the fountain on right mouse click
    }
}


void ship2()
{


    // Draw your scene here using OpenGL functions
        // Base Line
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(-7.5361338242086, 4.68160920905);
    glVertex2f(-5.9114381559027,0.7001945951846);
    glVertex2f(8.0228373829087, 0.7001945951846);
    glVertex2f(8.4408858318646, 3.6962084793681);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(165,42,42);
    glVertex2f(-6.2894634356413, 1.4943545306619);
    glVertex2f(-6.1083014376502, 1.0939117134655);
    glVertex2f(8.0673884661971, 1.1016139011283);
    glVertex2f(8.154664161649, 1.4725356067989);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(211,211,211);
    glVertex2f(-3.7521939293472, 6.3786860268347);
    glVertex2f(-3.7447742018042, 4.4607806803594);
    glVertex2f(8.0198139848403, 3.7238835807652);
    glVertex2f(8.0455695423341, 5.1599337396419);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(-7.4101178577108, 5.3684022751914);
    glVertex2f(-7.4069735012713, 4.6738823080316);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(-7.4101178577108, 5.3684022751914);
    glVertex2f(-3.3167267950182, 5.0722846238477);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glVertex2f(-3.3167267950182, 5.0722846238477);
    glVertex2f(-3.2993081096451, 4.4277932650408);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(5.6, 7.0832325579927);
    glVertex2f(5.6, 5.4353160798914);
    glVertex2f(6.3, 5.378556402866);
    glVertex2f(6.3, 7.0832325579927);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    glVertex2f(7.0, 7.5478002987359);
    glVertex2f(7.0, 5.2973123087423);
    glVertex2f(7.7, 5.2157995919706);
    glVertex2f(7.7, 7.5478002987359);
    glEnd();

    circle_c(0.4,2.8372947931585, 4.7063083271131);
    glEnd();
    circle_c(0.4,4.4288537924416, 4.7100329947702);
    glEnd();
    circle_c(0.4,6.034437199091, 4.6992098303546);
    glEnd();


    circle_c(0.75,-4.0, 3.0);
    glEnd();
    circle_black(0.5,-4.0, 3.0);
    glEnd();


    circle_c(0.75,-2,3.0);
    glEnd();
    circle_black(0.5,-2, 3);
    glEnd();



}

void sky2()
{
    ///sky
    glBegin(GL_QUADS);            //// Each set of 4 vertices form a quad
    glColor3ub(244,164,96); //// sky-blue
    glVertex2f(-1.0f, 0.4f);    //// x, y
    glColor3ub(244,164,96);
    glVertex2f(1.0f, 0.4f);    //// x, y
    glVertex2f(1.0f, 1.0f);    //// x, y
    glColor3ub(222,184,135);
    glVertex2f(-1.0f, 1.0f);    //// x, y
    glEnd();
}

void sky3()
{
    ///sky
    glBegin(GL_QUADS);            //// Each set of 4 vertices form a quad
    glColor3ub(64,64,64); //// sky-blue
    glVertex2f(-1.0f, 0.4f);    //// x, y
    glColor3ub(64,64,64);
    glVertex2f(1.0f, 0.4f);    //// x, y
    glVertex2f(1.0f, 1.0f);    //// x, y
    glColor3ub(32,32,32);
    glVertex2f(-1.0f, 1.0f);    //// x, y
    glEnd();
}






void Moon() //F49
{

    glColor3ub(224,255,255);
    glPushMatrix();
    glTranslatef(-1.0,0.005,0);
    circle1(0.8, 0.9, 0.05);
    glPopMatrix();
}

void buildings2()
{

    ///1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(192,192,192); //// sky-blue
    glVertex2f(-0.86f, 0.4f);    //// x, y
    glVertex2f(-0.76f, 0.4f);    //// x, y
    glVertex2f(-0.76f, 0.65f);    //// x, y
    glVertex2f(-0.86f, 0.65f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(128,128,128); //// sky-blue
    glVertex2f(-0.76f, 0.4f);    //// x, y
    glVertex2f(-0.73f, 0.4f);    //// x, y
    glVertex2f(-0.73f, 0.62f);    //// x, y
    glVertex2f(-0.76f, 0.65f);    //// x, y
    glEnd();

    ///windows
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.84f, 0.43f);    //// x, y
    glVertex2f(-0.81f, 0.43f);    //// x, y
    glVertex2f(-0.81f, 0.48f);    //// x, y
    glVertex2f(-0.84f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.8f, 0.43f);    //// x, y
    glVertex2f(-0.77f, 0.43f);    //// x, y
    glVertex2f(-0.77f, 0.48f);    //// x, y
    glVertex2f(-0.8f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.84f, 0.5f);    //// x, y
    glVertex2f(-0.81f, 0.5f);    //// x, y
    glVertex2f(-0.81f, 0.55f);    //// x, y
    glVertex2f(-0.84f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.8f, 0.5f);    //// x, y
    glVertex2f(-0.77f, 0.5f);    //// x, y
    glVertex2f(-0.77f, 0.55f);    //// x, y
    glVertex2f(-0.8f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.84f, 0.57f);    //// x, y
    glVertex2f(-0.81f, 0.57f);    //// x, y
    glVertex2f(-0.81f, 0.62f);    //// x, y
    glVertex2f(-0.84f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.8f, 0.57f);    //// x, y
    glVertex2f(-0.77f, 0.57f);    //// x, y
    glVertex2f(-0.77f, 0.62f);    //// x, y
    glVertex2f(-0.8f, 0.62f);    //// x, y
    glEnd();

    ///2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(112,128,144); //// sky-blue
    glVertex2f(-0.72f, 0.4f);    //// x, y
    glVertex2f(-0.62f, 0.4f);    //// x, y
    glVertex2f(-0.62f, 0.71f);    //// x, y
    glVertex2f(-0.72f, 0.71f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(192.0f, 192.0f, 192.0f); //// sky-blue
    glVertex2f(-0.62f, 0.4f);   //// x, y
    glVertex2f(-0.59f, 0.4f);    //// x, y
    glVertex2f(-0.59f, 0.65f);    //// x, y
    glVertex2f(-0.62f, 0.71f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.7f, 0.43f);    //// x, y
    glVertex2f(-0.67f, 0.43f);    //// x, y
    glVertex2f(-0.67f, 0.48f);    //// x, y
    glVertex2f(-0.7f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.66f, 0.43f);    //// x, y
    glVertex2f(-0.63f, 0.43f);    //// x, y
    glVertex2f(-0.63f, 0.48f);    //// x, y
    glVertex2f(-0.66f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.7f, 0.5f);    //// x, y
    glVertex2f(-0.67f, 0.5f);    //// x, y
    glVertex2f(-0.67f, 0.55f);    //// x, y
    glVertex2f(-0.7f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.66f, 0.5f);    //// x, y
    glVertex2f(-0.63f, 0.5f);    //// x, y
    glVertex2f(-0.63f, 0.55f);    //// x, y
    glVertex2f(-0.66f, 0.55f);    //// x, y
    glEnd();

    ///p3
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.7f, 0.57f);    //// x, y
    glVertex2f(-0.67f, 0.57f);    //// x, y
    glVertex2f(-0.67f, 0.62f);    //// x, y
    glVertex2f(-0.7f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.66f, 0.57f);    //// x, y
    glVertex2f(-0.63f, 0.57f);    //// x, y
    glVertex2f(-0.63f, 0.62f);    //// x, y
    glVertex2f(-0.66f, 0.62f);    //// x, y
    glEnd();

    ///p4
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.7f, 0.64f);    //// x, y
    glVertex2f(-0.67f, 0.64f);    //// x, y
    glVertex2f(-0.67f, 0.69f);    //// x, y
    glVertex2f(-0.7f, 0.69f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.66f, 0.64f);    //// x, y
    glVertex2f(-0.63f, 0.64f);    //// x, y
    glVertex2f(-0.63f, 0.69f);    //// x, y
    glVertex2f(-0.66f, 0.69f);    //// x, y
    glEnd();

    ///////////////
    ///4
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(255, 153, 153); //// sky-blue
    glVertex2f(-0.58f, 0.4f);    //// x, y
    glVertex2f(-0.48f, 0.4f);    //// x, y
    glVertex2f(-0.48f, 0.5f);    //// x, y
    glVertex2f(-0.58f, 0.5f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.0f, 0.0f); //// sky-blue
    glVertex2f(-0.48f, 0.4f);    //// x, y
    glVertex2f(-0.47f, 0.4f);    //// x, y
    glVertex2f(-0.47f, 0.48f);    //// x, y
    glVertex2f(-0.48f, 0.5f);    //// x, y
    glEnd();

    ///windows
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.56f, 0.43f);    //// x, y
    glVertex2f(-0.53f, 0.43f);    //// x, y
    glVertex2f(-0.53f, 0.48f);    //// x, y
    glVertex2f(-0.56f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.52f, 0.43f);    //// x, y
    glVertex2f(-0.49f, 0.43f);    //// x, y
    glVertex2f(-0.49f, 0.48f);    //// x, y
    glVertex2f(-0.52f, 0.48f);    //// x, y
    glEnd();

    ///5
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(138, 43, 226); //// sky-blue
    glVertex2f(-0.45f, 0.4f);    //// x, y
    glVertex2f(-0.35f, 0.4f);    //// x, y
    glVertex2f(-0.35f, 0.72f);    //// x, y
    glVertex2f(-0.45f, 0.72f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.3f, 0.3f, 0.3f); //// sky-blue
    glVertex2f(-0.35f, 0.4f);   //// x, y
    glVertex2f(-0.33f, 0.4f);    //// x, y
    glVertex2f(-0.33f, 0.67f);    //// x, y
    glVertex2f(-0.35f, 0.72f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.43f, 0.43f);    //// x, y
    glVertex2f(-0.4f, 0.43f);    //// x, y
    glVertex2f(-0.4f, 0.48f);    //// x, y
    glVertex2f(-0.43f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.39f, 0.43f);    //// x, y
    glVertex2f(-0.36f, 0.43f);    //// x, y
    glVertex2f(-0.36f, 0.48f);    //// x, y
    glVertex2f(-0.39f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.43f, 0.5f);    //// x, y
    glVertex2f(-0.4f, 0.5f);    //// x, y
    glVertex2f(-0.4f, 0.55f);    //// x, y
    glVertex2f(-0.43f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.39f, 0.5f);    //// x, y
    glVertex2f(-0.36f, 0.5f);    //// x, y
    glVertex2f(-0.36f, 0.55f);    //// x, y
    glVertex2f(-0.39f, 0.55f);    //// x, y
    glEnd();

    ///p3
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.43f, 0.57f);    //// x, y
    glVertex2f(-0.4f, 0.57f);    //// x, y
    glVertex2f(-0.4f, 0.62f);    //// x, y
    glVertex2f(-0.43f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.39f, 0.57f);    //// x, y
    glVertex2f(-0.36f, 0.57f);    //// x, y
    glVertex2f(-0.36f, 0.62f);    //// x, y
    glVertex2f(-0.39f, 0.62f);    //// x, y
    glEnd();

    ///p4
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.43f, 0.64f);    //// x, y
    glVertex2f(-0.4f, 0.64f);    //// x, y
    glVertex2f(-0.4f, 0.69f);    //// x, y
    glVertex2f(-0.43f, 0.69f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.39f, 0.64f);    //// x, y
    glVertex2f(-0.36f, 0.64f);    //// x, y
    glVertex2f(-0.36f, 0.69f);    //// x, y
    glVertex2f(-0.39f, 0.69f);    //// x, y
    glEnd();

    ///6
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(255.0f, 69.0f, 0.0f); //// sky-blue
    glVertex2f(-0.3f, 0.4f);    //// x, y
    glVertex2f(-0.2f, 0.4f);    //// x, y
    glVertex2f(-0.2f, 0.6f);    //// x, y
    glVertex2f(-0.3f, 0.6f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(153.0f, 76.0f, 0.0f); //// sky-blue
    glVertex2f(-0.2f, 0.4f);    //// x, y
    glVertex2f(-0.18f, 0.4f);    //// x, y
    glVertex2f(-0.18f, 0.57f);    //// x, y
    glVertex2f(-0.2f, 0.6f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.28f, 0.43f);    //// x, y
    glVertex2f(-0.25f, 0.43f);    //// x, y
    glVertex2f(-0.25f, 0.48f);    //// x, y
    glVertex2f(-0.28f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.24f, 0.43f);    //// x, y
    glVertex2f(-0.21f, 0.43f);    //// x, y
    glVertex2f(-0.21f, 0.48f);    //// x, y
    glVertex2f(-0.24f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.28f, 0.5f);    //// x, y
    glVertex2f(-0.25f, 0.5f);    //// x, y
    glVertex2f(-0.25f, 0.55f);    //// x, y
    glVertex2f(-0.28f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(-0.24f, 0.5f);    //// x, y
    glVertex2f(-0.21f, 0.5f);    //// x, y
    glVertex2f(-0.21f, 0.55f);    //// x, y
    glVertex2f(-0.24f, 0.55f);    //// x, y
    glEnd();

    ///9
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3ub(255.0f, 215.0f, 0.0f); //// sky-blue
    glVertex2f(0.08f, 0.4f);    //// x, y
    glVertex2f(0.18f, 0.4f);    //// x, y
    glVertex2f(0.18f, 0.6f);    //// x, y
    glVertex2f(0.08f, 0.6f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.5f, 0.0f); //// sky-blue
    glVertex2f(0.07f, 0.4f);    //// x, y
    glVertex2f(0.08f, 0.4f);    //// x, y
    glVertex2f(0.08f, 0.6f);    //// x, y
    glVertex2f(0.07f, 0.55f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.09f, 0.43f);    //// x, y
    glVertex2f(0.12f, 0.43f);    //// x, y
    glVertex2f(0.12f, 0.48f);    //// x, y
    glVertex2f(0.09f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.13f, 0.43f);    //// x, y
    glVertex2f(0.16f, 0.43f);    //// x, y
    glVertex2f(0.16f, 0.48f);    //// x, y
    glVertex2f(0.13f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.09f, 0.5f);    //// x, y
    glVertex2f(0.12f, 0.5f);    //// x, y
    glVertex2f(0.12f, 0.55f);    //// x, y
    glVertex2f(0.09f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.13f, 0.5f);    //// x, y
    glVertex2f(0.16f, 0.5f);    //// x, y
    glVertex2f(0.16f, 0.55f);    //// x, y
    glVertex2f(0.13f, 0.55f);    //// x, y
    glEnd();

    ///10
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.7f, 0.7f, 0.7f); //// sky-blue
    glVertex2f(0.22f, 0.4f);    //// x, y
    glVertex2f(0.32f, 0.4f);    //// x, y
    glVertex2f(0.32f, 0.65f);    //// x, y
    glVertex2f(0.22f, 0.65f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(0.5f, 0.5f, 0.5f); //// sky-blue
    glVertex2f(0.2f, 0.4f);    //// x, y
    glVertex2f(0.22f, 0.4f);    //// x, y
    glVertex2f(0.22f, 0.65f);    //// x, y
    glVertex2f(0.2f, 0.62f);    //// x, y
    glEnd();

    ///windows
    ///p1
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.24f, 0.43f);    //// x, y
    glVertex2f(0.27f, 0.43f);    //// x, y
    glVertex2f(0.27f, 0.48f);    //// x, y
    glVertex2f(0.24f, 0.48f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.28f, 0.43f);    //// x, y
    glVertex2f(0.31f, 0.43f);    //// x, y
    glVertex2f(0.31f, 0.48f);    //// x, y
    glVertex2f(0.28f, 0.48f);    //// x, y
    glEnd();

    ///p2
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.24f, 0.5f);    //// x, y
    glVertex2f(0.27f, 0.5f);    //// x, y
    glVertex2f(0.27f, 0.55f);    //// x, y
    glVertex2f(0.24f, 0.55f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.28f, 0.5f);    //// x, y
    glVertex2f(0.31f, 0.5f);    //// x, y
    glVertex2f(0.31f, 0.55f);    //// x, y
    glVertex2f(0.28f, 0.55f);    //// x, y
    glEnd();

    ///p3
    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.24f, 0.57f);    //// x, y
    glVertex2f(0.27f, 0.57f);    //// x, y
    glVertex2f(0.27f, 0.62f);    //// x, y
    glVertex2f(0.24f, 0.62f);    //// x, y
    glEnd();

    glBegin(GL_QUADS);              //// Each set of 4 vertices form a quad
    glColor3f(176,196,222); //// sky-blue
    glVertex2f(0.28f, 0.57f);    //// x, y
    glVertex2f(0.31f, 0.57f);    //// x, y
    glVertex2f(0.31f, 0.62f);    //// x, y
    glVertex2f(0.28f, 0.62f);    //// x, y
    glEnd();


}

void body2()
{
    //middle
    glBegin(GL_QUADS);
    glColor3ub(58,73,80);
    glVertex2f(-7.0f,-10.0f);
    glVertex2f(-7.0f,10.0f);
    glVertex2f(8.0f,10.0f);
    glVertex2f(8.0f,-10.0f);
    glEnd();

    //shed
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-7.0f,10.0f);
    glVertex2f(-7.0f,11.0f);
    glVertex2f(8.0f,11.0f);
    glVertex2f(8.0f,10.0f);
    glEnd();


    //left line
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-2.0f, 10.0f);
    glVertex2f(-2.0f, -10.0f);
    glEnd();

    //middle line
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(3.0f, 10.0f);
    glVertex2f(3.0f, -10.0f);
    glEnd();


    //left tola
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-7.0f,-10.0f);
    glVertex2f(-7.0f,-9.0f);
    glVertex2f(-2.0f,-9.0f);
    glVertex2f(-2.0f,-10.0f);
    glEnd();

    //right tola
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(3.0f,-10.0f);
    glVertex2f(3.0f,-9.0f);
    glVertex2f(8.0f,-9.0f);
    glVertex2f(8.0f,-10.0f);
    glEnd();


    //left 5th window
    glBegin(GL_QUADS);
    glColor3ub(207, 216, 220);
    glVertex2f(-5.5f,7.0f);
    glVertex2f(-5.5f,9.0f);
    glVertex2f(-3.0f,9.0f);
    glVertex2f(-3.0f,7.0f);
    glEnd();


    //left 4th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,3.0f);
glVertex2f(-5.5f,5.0f);
glVertex2f(-3.0f,5.0f);
glVertex2f(-3.0f,3.0f);
glEnd();

//left 3th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,-1.0f);
glVertex2f(-5.5f,1.0f);
glVertex2f(-3.0f,1.0f);
glVertex2f(-3.0f,-1.0f);
glEnd();

//left 2th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,-5.0f);
glVertex2f(-5.5f,-3.0f);
glVertex2f(-3.0f,-3.0f);
glVertex2f(-3.0f,-5.0f);
glEnd();

//left 1st window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(-5.5f,-8.2f);
glVertex2f(-5.5f,-6.5f);
glVertex2f(-3.0f,-6.5f);
glVertex2f(-3.0f,-8.2f);
glEnd();

 //Right 5th window
    glBegin(GL_QUADS);
    glColor3ub(207, 216, 220);
    glVertex2f(4.5f,7.0f);
    glVertex2f(4.5f,9.0f);
    glVertex2f(7.0f,9.0f);
    glVertex2f(7.0f,7.0f);
    glEnd();

//Right 4th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,3.0f);
glVertex2f(4.5f,5.0f);
glVertex2f(7.0f,5.0f);
glVertex2f(7.0f,3.0f);
glEnd();

//Right 3th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,-1.0f);
glVertex2f(4.5f,1.0f);
glVertex2f(7.0f,1.0f);
glVertex2f(7.0f,-1.0f);
glEnd();

//right 2th window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,-4.7f);
glVertex2f(4.5f,-3.0f);
glVertex2f(7.0f,-3.0f);
glVertex2f(7.0f,-4.7f);
glEnd();

//right 1st window
glBegin(GL_QUADS);
glColor3ub(207, 216, 220);
glVertex2f(4.5f,-8.2f);
glVertex2f(4.5f,-6.5f);
glVertex2f(7.0f,-6.5f);
glVertex2f(7.0f,-8.2f);
glEnd();


    //middle 5th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,7.0f);
glVertex2f(-0.7f,9.0f);
glVertex2f(2.0f,9.0f);
glVertex2f(2.0f,7.0f);
glEnd();

//middle 4th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,3.0f);
glVertex2f(-0.7f,5.0f);
glVertex2f(2.0f,5.0f);
glVertex2f(2.0f,3.0f);
glEnd();

//middle 3th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,-1.0f);
glVertex2f(-0.7f,1.0f);
glVertex2f(2.0f,1.0f);
glVertex2f(2.0f,-1.0f);
glEnd();

//middle 2th window
glBegin(GL_QUADS);
glColor3ub(236, 239, 241);
glVertex2f(-0.7f,-4.7f);
glVertex2f(-0.7f,-3.0f);
glVertex2f(2.0f,-3.0f);
glVertex2f(2.0f,-4.7f);
glEnd();

}


void Tree2()
{
    //tree
glBegin(GL_QUADS);
glColor3ub(123.00f,51.0f,0.0f);
glVertex2f(-15.0f,-8.0f);
glVertex2f(-15.0f,-2.0f);
glVertex2f(-14.0f,-2.0f);
glVertex2f(-14.0f,-8.0f);
glEnd();

circle_tree(2.0,-16.0,-2.7);
glEnd();

glColor3ub(0, 204,0);
circle_tree(2.0,-14.0,-1.5);
glEnd();

circle_tree(2.0,-13.0,-2.7);
glEnd();

}

void sea2()
{
    ///sea
    glBegin(GL_QUADS);            /// Each set of 4 vertices form a quad
    glColor3ub(65,105,225); /// blue
    glVertex2f(-1.0f, -0.1f);    /// x, y
    glVertex2f(1.0f, -0.1f);    /// x, y
    glColor3ub(0,0,128);
    glVertex2f(1.0f, 0.4f);    /// x, y
    glVertex2f(-1.0f, 0.4f);    /// x, y
    glEnd();

    ///bank river
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-1.0,0.4);
    glVertex2f(1.0, 0.4);
    glEnd();
    float x=0.1,y=0.1;
    ///flow
    glPushMatrix();
    glTranslatef(move_flow, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5,0.3);
    glVertex2f(0.6, 0.3);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.3-x);
    glVertex2f(0.6-x, 0.3-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x,0.3-x-x);
    glVertex2f(0.6-x-x, 0.3-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x, 0.3-x-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x,0.3-x-x-x+0.05);
    glVertex2f(0.6-x-x-x-2*x, 0.3-x-x-x+0.05);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x+0.15);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12, 0.3-x-x-x+0.15);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x-0.05);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x-0.05);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x,0.3-x-x-x+0.1);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x, 0.3-x-x-x+0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x,0.3-x-x-x-0.08);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x, 0.3-x-x-x-0.08);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x, 0.3-x-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17,0.3);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17, 0.3);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.3+0.06);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.3+0.06);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.2);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.2);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.2);
    glVertex2f(0.6-x,0.2);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x,0.1);
    glVertex2f(0.6-x+2*x,0.1);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x,0.1+y);
    glVertex2f(0.6-x+2*x+x,0.1+y);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.1+y+y);
    glVertex2f(0.6-x+2*x+x+x,0.1+y+y);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2.0);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.0);
    glVertex2f(0.6-x+2*x+x+x,0.0);
    glEnd();
    glPopMatrix();
}



void window2()
{
    glBegin(GL_QUADS);
    glColor3ub(255,215,0);
    glVertex2f(0.015,-0.04);
    glVertex2f(-0.015, -0.04);
    glColor3ub(160,160,160);
    glVertex2f(-0.015, -0.00);
    glVertex2f(0.015, -0.00);
    glEnd();
    glTranslatef(-0.0005,0,0);
    HalfCircle(0.015,160,160,160);
    glLoadIdentity();
}

void light_house2()
{

    glBegin(GL_QUADS);
    glColor3ub(173,216,230);
    glVertex2f(-0.14,0.00);
    glColor3ub(160,160,160);
    glVertex2f(-0.22, 0.00);
    glVertex2f(-0.22, 0.47);
    glColor3ub(192,192,192);
    glVertex2f(-0.14, 0.47);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(50);
    glColor3ub(190,190,190);
    glVertex2f(-0.13,0.47);
    glVertex2f(-0.23, 0.47);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(50);
    glColor3ub(190,190,190);
    glVertex2f(-0.12,0.26);
    glVertex2f(-0.24, 0.26);
    glEnd();


    glBegin(GL_LINES);
    glLineWidth(40);
    glColor3ub(190,190,190);
    glVertex2f(-0.11,0.00);
    glVertex2f(-0.25, 0.00);
    glEnd();

    glScalef(0.55,0.55,0);
    glTranslatef(-0.33,0.63,0);
    window2();
    glLoadIdentity();

    glScalef(0.55,0.55,0);
    glTranslatef(-0.33,0.32,0);
    window2();
    glLoadIdentity();

    glScalef(0.55,0.55,0);
    glTranslatef(-0.33,0.12,0);
    window2();
    glLoadIdentity();

}



void ground2()
{
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad

    glColor3ub(0,102,0); // Red
    glVertex2f(-1.0f, -1.0f);    // x, y
    glColor3ub(6,100,31);
    glVertex2f(1.0f, -1.0f);    // x, y
    glColor3ub(76.0f, 153.0f, 0.0f); // Red
    glVertex2f(1.0f, -0.1f);    // x, y
    glColor3ub(102.0f, 204.0f, 0.0f); // Red
    glVertex2f(-1.0f, -0.1f);    // x, y




    glEnd();
}



void Lampost2()
{
    circle_lamp(0.0145239316937, 0.1477264524784, -0.0772219536772, glowAlpha); // left
    circle_lamp(0.0197921878293, 0.192787594241, -0.0553003171441, glowAlpha); // middle
    circle_lamp(0.0145239316937, 0.2379955904464, -0.0770311098337, glowAlpha); // right

    // Lamp stand
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Red
    glVertex2f(0.1890898766711, -0.1517335194932);    //T12
    glVertex2f(0.1959794679766, -0.1516306897722);    //U12
    glVertex2f(0.1956233509927, -0.0748883028168);    //Z12
    glVertex2f(0.1888341164192, -0.074693633317);    //V12
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1475994640695, -0.0917453302057);
    glVertex2f(0.1475576020546, -0.1039184550827);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1475576020546, -0.1039184550827);
    glVertex2f(0.2380067980133, -0.1041399677207);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.2380067980133, -0.1041399677207);
    glVertex2f(0.2381165549024, -0.0915545377846);
    glEnd();
}

void set_lampPost2()
{
    glPushMatrix();
    glTranslatef(-1.13f, 0.15f, 0.0f);
    Lampost2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15f, 0.15f, 0.0f);
    Lampost2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.73f, 0.15f, 0.0f);
    Lampost2();
    glPopMatrix();
}

void Bench2(){

    glPushMatrix();
    glScalef(0.028f,0.05f,1.0f);

    glLineWidth(2.5);

    //middle
    glBegin(GL_QUADS);
    glColor3f(0.749f,0.376f,0.024f);
    glVertex2f(14.0f,-7.0f);
    glVertex2f(14.0f,-5.0f);
    glVertex2f(18.0f,-5.0f);
    glVertex2f(18.0f,-7.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.749f,0.376f,0.024f);
    glVertex2f(16.0f,-8.0f);
    glVertex2f(14.0f,-7.0f);
    glVertex2f(18.0f,-7.0f);
    glVertex2f(20.0f,-8.0f);
    glEnd();

    //leg
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(14.0f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(16.0f, -8.0f);    // x, y
    glVertex2f(16.0f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(19.8f, -8.0f);    // x, y
    glVertex2f(19.8f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.3f, -8.0f);    // x, y
    glVertex2f(18.3f, -9.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(16.0f, -8.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(18.0f, -7.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.0f, -7.0f);    // x, y
    glVertex2f(20.0f, -8.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -7.0f);    // x, y
    glVertex2f(14.0f, -5.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(14.0f, -5.0f);    // x, y
    glVertex2f(18.0f, -5.0f);    // x, y
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.0f, -5.0f);    // x, y
    glVertex2f(18.0f, -7.0f);    // x, y
    glEnd();

    glPopMatrix();
    glLoadIdentity();



}


void fench2()
{
    float L = 0.05;
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.95f,-0.01f);
    glVertex2f(-0.95f,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.9f,-0.01f);
    glVertex2f(-0.9f,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f,-0.01f);
    glVertex2f(-0.85f,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)
    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+L,-0.01f);
    glVertex2f(-0.85f+L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+2*L,-0.01f);
    glVertex2f(-0.85f+2*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+3*L,-0.01f);
    glVertex2f(-0.85f+3*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+4*L,-0.01f);
    glVertex2f(-0.85f+4*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+5*L,-0.01f);
    glVertex2f(-0.85f+5*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+6*L,-0.01f);
    glVertex2f(-0.85f+6*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+7*L,-0.01f);
    glVertex2f(-0.85f+7*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+8*L,-0.01f);
    glVertex2f(-0.85f+8*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+9*L,-0.01f);
    glVertex2f(-0.85f+9*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+10*L,-0.01f);
    glVertex2f(-0.85f+10*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+11*L,-0.01f);
    glVertex2f(-0.85f+11*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+12*L,-0.01f);
    glVertex2f(-0.85f+12*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+13*L,-0.01f);
    glVertex2f(-0.85f+13*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+14*L,-0.01f);
    glVertex2f(-0.85f+14*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+15*L,-0.01f);
    glVertex2f(-0.85f+15*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+16*L,-0.01f);
    glVertex2f(-0.85f+16*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+17*L,-0.01f);
    glVertex2f(-0.85f+17*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+18*L,-0.01f);
    glVertex2f(-0.85f+18*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+19*L,-0.01f);
    glVertex2f(-0.85f+19*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+20*L,-0.01f);
    glVertex2f(-0.85f+20*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+21*L,-0.01f);
    glVertex2f(-0.85f+21*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+22*L,-0.01f);
    glVertex2f(-0.85f+22*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+23*L,-0.01f);
    glVertex2f(-0.85f+23*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+24*L,-0.01f);
    glVertex2f(-0.85f+24*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+25*L,-0.01f);
    glVertex2f(-0.85f+25*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+26*L,-0.01f);
    glVertex2f(-0.85f+26*L,-0.1f);
    glEnd();glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+27*L,-0.01f);
    glVertex2f(-0.85f+27*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+28*L,-0.01f);
    glVertex2f(-0.85f+28*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+29*L,-0.01f);
    glVertex2f(-0.85f+29*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+30*L,-0.01f);
    glVertex2f(-0.85f+30*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+31*L,-0.01f);
    glVertex2f(-0.85f+31*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+32*L,-0.01f);
    glVertex2f(-0.85f+32*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+33*L,-0.01f);
    glVertex2f(-0.85f+33*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+34*L,-0.01f);
    glVertex2f(-0.85f+34*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+35*L,-0.01f);
    glVertex2f(-0.85f+35*L,-0.1f);
    glEnd();
    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(4.0f);
    glVertex2f(-0.85f+36*L,-0.01f);
    glVertex2f(-0.85f+36*L,-0.1f);
    glEnd();

    glColor3ub(57,43,23); // Clear the color buffer (background)

    glBegin(GL_LINES);// Draw a Red 1x1 Square centered at origin
    glLineWidth(2.0f);
    glVertex2f(-1.0,-0.01f);
    glVertex2f(1.0f,-0.01f);
    glEnd();

}


void HauntedHouse2(){
    glBegin(GL_TRIANGLES);
    glColor3ub(5,1,74);

    // Left shade
    glVertex2f(-0.9052998158133, -0.156396506655);
    glColor3ub(25,25,112);
    glVertex2f(-0.9433887865386, -0.2688496583202);
    glVertex2f(-0.8920444844303, -0.2565818747899);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,1,74);
    glVertex2f(-0.9433887865386, -0.2688496583202);
    glVertex2f(-1.0050566439034, -0.3468413602815);
    glVertex2f(-0.954271349603, -0.3486551207923);
    glColor3ub(25,25,112);
    glVertex2f(-0.8621887122427, -0.3479586320914);
    glVertex2f(-0.8218668323198, -0.3450275997708);
    glVertex2f(-0.8920444844303, -0.2565818747899);
    glEnd();

    // Right shade
    glBegin(GL_TRIANGLES);
    glColor3ub(5,1,74);
    glVertex2f(-0.7311788067834, -0.0983561703117);
    glColor3ub(25,25,112);
    glVertex2f(-0.7632572096799, -0.195342654441);
    glVertex2f(-0.7015390021384, -0.2072115405067);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(5,1,74);
    glVertex2f(-0.7632572096799, -0.195342654441);
    glVertex2f(-0.8454457189593, -0.2688496583202);
    glVertex2f(-0.7985865378978, -0.2732520214242);
    glColor3ub(25,25,112);
    glVertex2f(-0.679238608755, -0.271139668696);
    glVertex2f(-0.6404907812469, -0.2688496583202);
    glVertex2f(-0.7015390021384, -0.2072115405067);
    glEnd();

    // Wall
    glBegin(GL_POLYGON);
    glColor3ub(0,0,205);
    glVertex2f(-0.954271349603, -0.3486551207923);
    glVertex2f(-0.9237096973566, -0.5117130189388 - 0.1);
    glColor3ub(51,0,102);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.8558556696574, -0.383242726495 - 0.05);
    glVertex2f(-0.8621887122427, -0.3479586320914);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51,0,102);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.7850104042242, -0.5113849740625 - 0.1);
    glVertex2f(-0.8106196511913, -0.3868616079723 - 0.05);
    glVertex2f(-0.8558556696574, -0.383242726495 - 0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51,0,102);
    glVertex2f(-0.7985865378978, -0.2732520214242);
    glVertex2f(-0.8106196511913, -0.3868616079723 - 0.1);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.7325330296947, -0.5113849740625 - 0.1);
    glVertex2f(-0.7045868414933, -0.3778134814697);
    glColor3ub(0,0,205);
    glVertex2f(-0.679238608755, -0.271139668696);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51,0,102);
    glVertex2f(-0.7325330296947, -0.5113849740625 - 0.1);
    glVertex2f(-0.6321916761987, -0.5125383229532 - 0.1);
    glVertex2f(-0.6327678690856, -0.4297725922336);
    glVertex2f(-0.5951020420498, -0.4303211236952);
    glVertex2f(-0.6321916761987, -0.3781731771798);
    glVertex2f(-0.7045868414933, -0.3778134814697);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51,0,102);
    glVertex2f(-0.8328743831907, -0.5108082996171 - 0.1);
    glVertex2f(-0.7325330296947, -0.5113849740625 - 0.1);
    glVertex2f(-0.7321867242007, -0.4680063641405 - 0.1);
    glVertex2f(-0.8333257562177, -0.4696920146741 - 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51,0,102);
    glVertex2f(-0.7996127455453, -0.4309220524009 - 0.1);
    glVertex2f(-0.8333257562177, -0.4696920146741 - 0.1);
    glVertex2f(-0.7321867242007, -0.4680063641405 - 0.1);
    glVertex2f(-0.7574714822049, -0.4292364018673 - 0.1);
    glEnd();

    ////door
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(240,230,140); // Red
    glVertex2f(-0.8328743831907, -0.5108082996171-0.1); //j2
    glVertex2f(-0.7325330296947, -0.5113849740625-0.1);//e2   // x, y
    glVertex2f(-0.7321867242007, -0.4680063641405-0.1); //f2
    glVertex2f(-0.8333257562177, -0.4696920146741-0.1); //i2
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(240,230,140); // Red
    glVertex2f(-0.7996127455453, -0.4309220524009-0.1); //h2
    glVertex2f(-0.8333257562177, -0.4696920146741-0.1);//i2   // x, y
    glVertex2f(-0.7321867242007, -0.4680063641405-0.1); //f2
    glVertex2f(-0.7574714822049, -0.4292364018673-0.1); //g2
    glEnd();


    circle_lamp(0.03,-0.8901412862041-0.025, -0.370843479522-0.025,glowAlpha);
    glEnd();
    circle_lamp(0.035,-0.7496272346364, -0.3146200253607-0.005,glowAlpha);
    glEnd();


}

void Chair2(){

    //Lower Part
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.9455132503274, -0.1881016149557);
	glVertex2f(-0.9117827691956, -0.1892810024078);
	glVertex2f(-0.9108392592338, -0.1803176577714);
	glVertex2f(-0.9467113974835, -0.1799542142943);
	glEnd();

	//Upper Part
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.9467113974835, -0.1799542142943);
	glVertex2f(-0.9429185979327, -0.1798459027905);
	glVertex2f(-0.9448056178561, -0.1425772593022);
	glVertex2f(-0.9525895750404, -0.1399826069074);
	glEnd();


    //Seat
    glBegin(GL_POLYGON);
	glColor3f(92,92,92);
	glVertex2f(-0.9429185979327, -0.1798459027905);
	glVertex2f(-0.9108392592338, -0.1803176577714);
	glVertex2f(-0.907460644422, -0.1733532615283);
	glVertex2f(-0.9068604661657, -0.1632702668225);
	glVertex2f(-0.944371607184, -0.1636303737763);
	glEnd();

	//stand
	glBegin(GL_POLYGON);
	glColor3f(92,92,92);
	glVertex2f(-0.931124723411, -0.1810252902427);
    glVertex2f(-0.9268637380383, -0.180909977323);
    glVertex2f(-0.9251416185163, -0.0275102435472);
    glVertex2f(-0.9311792933833, -0.0278620514147);
	glEnd();


	//glutSwapBuffers();

}

void ride2()
{
    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.925, 0); //k3
    glVertex2f(-0.925, -0.028);//a3
    glColor3ub(204,204, 0);
    glVertex2f(-0.67, -0.028); //d3
    glColor3ub(204,204, 0);
    glVertex2f(-0.67, 0); //z3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.9310733313146, -0.0220430556755); //h3
    glVertex2f(-0.9310558673343, -0.028);//g3
    glVertex2f(-0.666, -0.028); //b4
    glVertex2f(-0.6659185882569, -0.0220430556755); //c4
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.925, -0.028);//a3
    glVertex2f(-0.8871775329089, -0.0754764506258); //z2
    glColor3ub(204,204, 0);
    glVertex2f(-0.7076831338211, -0.0754764506258); //e3
    glColor3ub(204,204, 0);
    glVertex2f(-0.67, -0.028); //d3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.8871775329089, -0.0754764506258); //z2
    glVertex2f(-0.8871775329089, -0.0875701527496);//w2
    glVertex2f(-0.7076831338211, -0.0875947606018); //f3
    glVertex2f(-0.7076831338211, -0.0754764506258); //e3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(219.0f, 189.0f, 38.0f);
    glVertex2f(-0.8871775329089, -0.0875701527496);//w2
    glVertex2f(-0.8638515621642, -0.0999611737789); //v2
    glColor3ub(204,204, 0);
    glVertex2f(-0.7311788067834, -0.0999611737789); //o1
    glVertex2f(-0.7076831338211, -0.0875947606018); //f3
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.8638515621642, -0.0999611737789);//v2
    glColor3ub(204,204, 0);
    glVertex2f(-0.85, -0.2); //u2
    glVertex2f(-0.75, -0.2); //u5
    glVertex2f(-0.7311788067834, -0.0999611737789); //o1
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255.0f, 255.0f, 0.0f);
    glVertex2f(-0.85, -0.2);//u2
    glVertex2f(-0.8651011820348, -0.281799069355); //t2
    glColor3ub(204,204, 0);
    glVertex2f(-0.7333179038519, -0.281799069355); //r5
    glColor3ub(204,204, 0);
    glVertex2f(-0.75, -0.2); //u5
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.85, -0.2); //u2
    glVertex2f(-0.75, -0.2); //u5
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255.0f, 0.0f, 0.0f);
    glVertex2f(-0.97, -0.28);//s2
    glVertex2f(-0.9774863264877, -0.3); //v5
    glVertex2f(-0.62, -0.3); //z5
    glVertex2f(-0.6262041464756, -0.28); //w5
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(153.0f, 0.0f, 0.0f);
    glVertex2f(-0.8000975214123, 0.0570655431202);//a6
    glVertex2f(-0.87, 0);//n3
    glVertex2f(-0.7277590432943, -0.0000107017145);//k1
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192);//white
    glVertex2f(-0.8000975214123, 0.0570655431202);//a6
    glVertex2f(-0.835, 0);//o3
    glVertex2f(-0.82,0);//q3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192);//white
    glVertex2f(-0.8000975214123, 0.0570655431202);//a6
    glVertex2f(-0.78, 0);//r3
    glVertex2f(-0.7656735622151, 0.0000750589451);//t3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 96.0f);//pink
    glVertex2f(-0.885, 0);//l3
    glVertex2f(-0.8775590270233, -0.0101782141455);//m3
    glVertex2f(-0.87, 0);//n3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 96.0f, 0.0f);//yellow
    glVertex2f(-0.835, 0);//o3
    glVertex2f(-0.8274072532665, -0.0101782141455);//p3
    glVertex2f(-0.82, 0);//q3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 96.0f);//pink
    glVertex2f(-0.78, 0);//r3
    glVertex2f(-0.7731646935298, -0.0101128796429);//s3
    glVertex2f(-0.7656735622151, 0.0000750589451);//t3
    glEnd();

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 96.0f, 0.0f);//yellow
    glVertex2f(-0.7277590432943, -0.0000107017145);//u3
    glVertex2f(-0.72, -0.01);//v3
    glVertex2f(-0.7136851108911, 0);//w3
    glEnd();

    glPushMatrix();
    glTranslatef(chairmove, 0.0f, 0.0f);
    Chair2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.13, 0.0f, 0.0f);
    glTranslatef(chairmove2, 0.0f, 0.0f);
    Chair2();
    glPopMatrix();


}





void horse2() //ghorar body
{


    //Horse Head
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(161,61,45); // Red
    glVertex2f(0.6230289295598, -0.07153140419);    // x, y
    glVertex2f(0.6204933293862, -0.0845218808048);    // x, y
    glVertex2f(0.5952168105742, -0.1214119352872);    // x, y
    glVertex2f(0.6152677031054, -0.1300933856185);    // x, y
    glVertex2f(0.6353763352827, -0.1138653666684);    // x, y
    glVertex2f(0.6630081138722, -0.0945747376603);   // x, y
    glVertex2f(0.6477565923213, -0.0799660124065);    // x, y
    glVertex2f(0.63, -0.08);
    glEnd();

    // Horse Ear
    glBegin(GL_TRIANGLES);
    glColor3ub(0.0f, 0.0f, 0.0f);
    glVertex2f(0.6204933293862, -0.0745218808048f);    // x, y
    glVertex2f(0.63, -0.07f);    // x, y
    glVertex2f(0.6230289295598, -0.06153140419f);    // x, y
    glEnd();

    //Horse Body
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(161,61,45); // Red
    glVertex2f(0.6353763352827, -0.1138653666684);    // s6
    glVertex2f(0.6427847787164, -0.1322100837424);    // t6
    glVertex2f(0.6364346843446, -0.1614910744567);    // u6
    glVertex2f(0.6371402503859, -0.1741912632002);    // v6
    glVertex2f(0.6652170320805, -0.1823792364382);    // a7
    glVertex2f(0.7469470057857, -0.1818270068861);   // b7
    glVertex2f(0.7734540242846, -0.1790658591258);    // e7
    glVertex2f(0.7733144963582, -0.142793574362);       // o6
    glVertex2f(0.7695884174202, -0.1348874949609);      // h7
    glVertex2f(0.7581448264701, -0.126565555412);    // n6
    glVertex2f(0.7330972320037, -0.1258599893707);    // m6
    glVertex2f(0.7147525149297, -0.1293878195772);    // l6
    glVertex2f(0.7034634582688, -0.1290350365565);    // k6
    glVertex2f(0.6886465714014, -0.12550720635);   //j6
    glVertex2f(0.6630081138722, -0.0945747376603); //i6
    glEnd();

    //Horse Front Leg
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(44,45,45); // Red

    glVertex2f(0.6342368822203, -0.2248317806397);    // w6
    glVertex2f(0.6485590055079, -0.2244737275575);    // Z6
    glVertex2f(0.6652170320805, -0.1823792364382);    // A7
    glVertex2f(0.6371402503859, -0.1741912632002);    // v6
    glEnd();

    //Horse Front Leg Horseshoe
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // Red

    glVertex2f(0.6306563513984, -0.2309186830369);    // L7
    glVertex2f(0.6478766558479, -0.2307468511194);    // J7
    glVertex2f(0.6485590055079, -0.2244737275575);    // Z6
    glVertex2f(0.6342368822203, -0.2248317806397);    // w6
    glEnd();


    //Horse Back Leg
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(44,45,45); // Red

    glVertex2f(0.7717292657813, -0.2245769480091);    // C7
    glVertex2f(0.7835450174936, -0.2241156744753);    // D7
    glVertex2f(0.7734540242846, -0.1790658591258);    // E7
    glVertex2f(0.7469470057857, -0.1818270068861);    // B7
    glEnd();

    //Horse Back Leg Horseshoe
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // Red

    glVertex2f(0.7692518015035, -0.2298319430705);    // K7
    glVertex2f(0.7855341793726, -0.2297248716381);    // L7
    glVertex2f(0.7835450174936, -0.2241156744753);    // D7
    glVertex2f(0.7717292657813, -0.2245769480091);    // C7
    glEnd();


    //Horse Lengur

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // Red

    glVertex2f(0.7733144963582, -0.142793574362);    // O6
    glVertex2f(0.8, -0.15);                             // P6
    glVertex2f(0.803274420096, -0.1702301862928);    // R6
    glVertex2f(0.8353037341156, -0.1531110701789);    // F7
    glVertex2f(0.8043788792001, -0.1282607403361);    // G7
    glVertex2f(0.7695884174202, -0.1348874949609);    // H7
    glEnd();

}

void Carousel2(){
    //Horse Building Structure
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(184, 173, 173); // Red

    glVertex2f(0.6469362786402, -0.2307682123178);    // H8
    glVertex2f(0.7742691404413, -0.2298197125607);    // K8
    glVertex2f(0.7708206462465, -0.0131777323474);    // l8
    glVertex2f(0.6440323872888, -0.0149066631513);    // G8
    glEnd();
    //Triangle
    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
    glColor3ub(185,96,236); // Red
    glVertex2f(0.5072739941155, 0.0355885447244);    // N7
    glColor3ub(153,0,153);
    glVertex2f(0.9111285277335, 0.0365501031378);    //v7                      // T7
    glVertex2f(0.7063165856844, 0.15962958005);    // V7
    glEnd();


    //Triangle Base

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(56,172,236); // Red
    glVertex2f(0.4512152034121, 0.007414334689);    // W7
    glVertex2f(0.962155655219, 0.0098746783722);    //E8
    glColor3ub(0,0,153); // Red
    glVertex2f(0.9611295652291, 0.0375116615512);    // U7
    glVertex2f(0.452465164553, 0.0365501031378);    // M7
    glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(188,207,236); // Red
    glVertex2f(0.4538499988523, -0.0154829734193);    // F8
    glVertex2f(0.9540873114671, -0.0126014220794);    //J8                    // T7
    glVertex2f(0.962155655219, 0.0098746783722);    //E8
    glVertex2f(0.4512152034121, 0.007414334689);    // W7
    glEnd();

    //Leg Basement

    //First Basement
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(52.0f, 61.0f, 235.0f); // Red
    glVertex2f(0.4569623148533, -0.2858343211071);    //p8
    glVertex2f(0.9647104079067, -0.2798019186316);    //n8
    glColor3ub(51,0,102);
    glVertex2f(0.9629772196723, -0.2285125058642);    // m8
    glVertex2f(0.4538499988523, -0.2321756341833);    // l8
    glEnd();


    //Bottom Basement

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3ub(56,172,236); // Red
    glVertex2f(0.4359129315107, -0.3051218849393);    //R8
    glVertex2f(0.9848799046873, -0.3014903503868);    //S8                    // T7
    glVertex2f(0.9862766869929, -0.2792028553237);    //O8
    glVertex2f(0.4340971642345, -0.2857537006596);    //Q8
    glEnd();

}

void Ferris_Stucut2() {
    // Bottom Rectangle
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.3096608460677f, -0.3065404744871f);
    glVertex2f(-0.0371610716596f, -0.3060380409959f);
    glColor3ub(102,0,0);
    glVertex2f(-0.0439667166987f, -0.2871604321096f);
    glVertex2f(-0.308290638259f, -0.2873792054854f);
    glEnd();

    // Left Piller
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.265462072651f, -0.2868300240855f);
    glVertex2f(-0.2430138070153f, -0.286997961871f);
    glColor3ub(102,0,0);
    glVertex2f(-0.1798456047657f, -0.0587666146482f);
    glVertex2f(-0.1857520627791f, -0.057459481894f);
    glEnd();

    // Right Piller
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.1042949131319f, -0.2874730134383f);
    glVertex2f(-0.0810640372311f, -0.2874730134383f);
    glColor3ub(102,0,0);
    glVertex2f(-0.1678730123114f, -0.0580330565503f);
    glVertex2f(-0.1729344011929f, -0.0588904606151f);
    glEnd();
}

void Ferris_Wheel_Box2(float angle, float centerX, float centerY) {
    glPushMatrix();
    glTranslatef(centerX, centerY, 0.0f);
    glRotatef(angle + glutGet(GLUT_ELAPSED_TIME) * 0.05f, 0.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-0.0070925788264, 0.0100271080899);
    glVertex2f(-0.0065262479132, -0.065861234269);
    glColor3ub(102,0,0);
    glVertex2f(-0.0699553101834, -0.065861234269);
    glVertex2f(-0.0705216410965, 0.0094607771768);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.0407381118577, -0.0060621666345);
    glVertex2f(-0.0387660340241, -0.0054821437423);
    glVertex2f(-0.0432081038632, 0.0177307806438);
    glVertex2f(-0.0444809600007, 0.017057184183);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.0665573247046, -0.0437743286571);
    glVertex2f(-0.0122214568576, -0.043575970705);
    glVertex2f(-0.0127558879576, -0.0063964883908);
    glVertex2f(-0.0665573247046, -0.0058301574777);
    glEnd();

    glPopMatrix();
}

void Ferris_Wheel3() {
    // Draw the central circle without rotation
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float theta = (i * pi) / 50;
        float r = 0.0324787890821;
        float x = -0.1763900029793 + r * cos(theta);
        float y = -0.05882803763165 + r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw Ferris Wheel boxes and stands at different angles
    for (int i = 0; i < 6; ++i) {
        float angle = i * 60.0f; // Adjust the number of boxes as needed
        float centerX = -0.1763900029793;
        float centerY = -0.05882803763165;

        // Box
        Ferris_Wheel_Box2(angle, centerX, centerY);


    }
}



void Froghopper2()                                                                   //C6
{
    //Stand
    glPushMatrix();
    glScalef(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.2975812230974f,-0.2706178068053f-0.5);    // x, y
    glColor3ub(178,34,34);
    glVertex2f(0.3626871800881f,-0.2697379965757f-0.5);    // x, y // lowerpoint
    glVertex2f(0.3500357081808, 0.1359212367917);    // x, y
    glColor3ub(128,0,0);
    glVertex2f(0.3099537246946, 0.1361314569848);    // x, y upper point
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.0,benchPosition,0.0);

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(184,134,11); // Red
    glVertex2f(0.2395137479435f, -0.1861560247634f);    // x, y
    glVertex2f(0.4185551296679f, -0.1830766889597f);    // x, y
    glColor3ub(255,215,0); // Red
    glVertex2f(0.4172354143235f, -0.1544828564976f);    // x, y
    glVertex2f(0.2395421009271f, -0.1591253399728f);    // x, y
    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255,215,0); // Red
    glVertex2f(0.2295641457125f, -0.2284237649445f);    // x, y
    glVertex2f(0.4216344654715f, -0.2121104265367f);// x, y
    glColor3ub(184,134,11); // Red
    glVertex2f(0.4185551296679f, -0.1830766889597f);    // x, y
    glVertex2f(0.2395137479435f, -0.1861560247634f);    // x, y
    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 120.0f, 0.0f); // Red
    glVertex2f(0.2295641457125f, -0.2284237649445f);    // x, y
    glVertex2f(0.4277931370787f, -0.2248676748659f);    // x, y
    glVertex2f(0.4216344654715f, -0.2121104265367f);    // x, y
    glVertex2f(0.2375858385045f, -0.2165110616948f);    // x, y
    glEnd();

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(255.0f, 230.0f, 0.0f); // Red
    glVertex2f(0.2295641457125f, -0.2495633923737f);
    glVertex2f(0.4281485245931f, -0.244438634209f);
    glColor3ub(184,134,11); // Red
    glVertex2f(0.4277931370787f, -0.2248676748659f);
    glVertex2f(0.2295641457125f, -0.2284237649445f);
    glEnd();

    glPopMatrix();


}


void Bat3() {
    glPushMatrix();  // Save the current matrix state

    // Calculate the rotation angle based on time
    float rotationAngle = sin(glutGet(GLUT_ELAPSED_TIME) * 0.10 * angularFrequency) * 45.0f;

    // Apply rotation around the center
    glTranslatef(centerX, centerY, 0.0f);
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-centerX, -centerY, 0.0f);

    // Move the bat upward after a certain number of rotations
    if (rotationCount >= 10) {
        centerY += translationSpeed;
    }

    // Existing bat drawing code here...

    // head left
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4794296974, 0.483162683194);  //W14
    glVertex2f(0.4879352209436, 0.4836758369816);    //R15
    glVertex2f(0.4877632543751, 0.4883756675795);   //A15
    glVertex2f(0.4826481127162, 0.4945217960749);   //Z14
    glEnd();

    // head right
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4879352209436, 0.4836758369816);    //R15
    glVertex2f(0.4956926190924, 0.4841438549962);  //C15
    glVertex2f(0.4928847697259, 0.4941800516436);   //B14
    glVertex2f(0.4877632543751, 0.4883756675795);   //A15
    glEnd();

    // left wing first segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4275296599459, 0.4616867617925);    //G15
    glVertex2f(0.4568344911265, 0.4612808462672);  //J15
    glVertex2f(0.474867028814, 0.4544893710342);   //K15
    glVertex2f(0.4794296974, 0.483162683194);   //W14
    glVertex2f(0.4646628506548, 0.4865704170582); //v14
    glEnd();

    // left wing second segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.4018090927138, 0.496225663007);    //T14
    glVertex2f(0.4227955183753, 0.483085081692);  //I15
    glVertex2f(0.4275296599459, 0.4616867617925);    //G15
    glVertex2f(0.4646628506548, 0.4865704170582); //v14
    glVertex2f(0.4597405684064, 0.496225663007); //u14
    glEnd();

    // middle stomach segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.474867028814, 0.4544893710342);   //K15
    glVertex2f(0.4882157904787, 0.4383303437558);  //L15
    glVertex2f(0.5032038737515, 0.4554261262387);    //M15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glVertex2f(0.4794296974, 0.483162683194);   //W14
    glEnd();

    // right wing first segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.5032038737515, 0.4554261262387);    //M15
    glVertex2f(0.52, 0.46);  //N15
    glVertex2f(0.5420792147401 , 0.4629201678751 );    //O15
    glVertex2f(0.5479339347685, 0.4619834126706); //P15
    glVertex2f(0.5514467667856, 0.4795475727558); //Q15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glEnd();

    // right wing second segment
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.5514467667856, 0.4795475727558); //Q15
    glVertex2f(0.5738691757898, 0.4963182108585); //E15
    glVertex2f(0.5178143888124, 0.4979308554635);//F15
    glVertex2f(0.5074567992113, 0.4854484638614); //D15
    glEnd();

    glPopMatrix();  // Restore the previous matrix state
}



void TentHouse2(){

    //Whole Border
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(153,0,0); // Red
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.5352946604884, -0.2137213219901);    // x, y
    glVertex2f(-0.5341626405179, -0.4044666870249);    // x, y
    glVertex2f(-0.2426674981056, -0.4039006770396);    // x, y
    glVertex2f(-0.245497548032, -0.2165513719164);
    glEnd();


    //Left White part top
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192); // White
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.4887871675063, -0.2320600455263);    // x, y
    glVertex2f(-0.440631330625, -0.2320024348871);
    glEnd();


    //Left White part top
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192); // White
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.4887871675063, -0.2320600455263);    // x, y
    glVertex2f(-0.440631330625, -0.2320024348871);
    glEnd();

    //Left White part down
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192); // White
    glVertex2f(-0.4887871675063, -0.2320600455263);    // x, y
    glVertex2f(-0.4866178017555, -0.3993725971575);
    glVertex2f(-0.4396389729784, -0.3999386071427);
    glVertex2f(-0.440631330625, -0.2320024348871);
    glEnd();


    //Right White part top
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192); // White
    glVertex2f(-0.391172070257, -0.1028416617228);    // x, y
    glVertex2f(-0.337876042845, -0.2321057353565);    // x, y
    glVertex2f(-0.2924763768091, -0.2301356115628);
    glEnd();

    //Right White part down
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(192,192,192); // White
    glVertex2f(-0.2924763768091, -0.2301356115628);    // x, y
    glVertex2f(-0.2924763768091, -0.3991556327941);
    glVertex2f(-0.34, -0.4003490456219);
    glVertex2f(-0.337876042845, -0.2321057353565);
    glEnd();

    //Middle Black Door
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(0.0f, 0.0f, 0.0f); // White
    glVertex2f(-0.4396389729784, -0.3999386071427);    // x, y
    glVertex2f(-0.34, -0.4003490456219);
    glVertex2f(-0.366623684879, -0.3246592791023);
    glVertex2f(-0.3711517647611, -0.2827745401926);

    glVertex2f(-0.3768683954017, -0.2325145418793);
    glVertex2f(-0.4023856124878, -0.2325145418793);
    glVertex2f(-0.386623684879, -0.3246592791023);

    glEnd();

    //Middle Door Left Brown
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(153,153,0); // White
    glVertex2f(-0.4079424138035, -0.2839065601631);    // x, y
    glVertex2f(-0.4583173024922, -0.3110750394559);
    glVertex2f(-0.4396389729784, -0.3999386071427);
    glEnd();

    //Middle Door Right Brown
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(153,153,0); // White
    glVertex2f(-0.3711517647611, -0.2827745401926);    // x, y
    glVertex2f(-0.321908896043, -0.3127730694117);
    glVertex2f(-0.34, -0.4003490456219);
    glEnd();


    //Top Flag

    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
    glColor3ub(235.0f, 204.0f, 52.0f); // yellow
    glVertex2f(-0.391172070257, -0.0686145571218);    // x, y
    glVertex2f(-0.391172070257, -0.0920908404058);
    glVertex2f(-0.346852357889, -0.0923102449225);
    glVertex2f(-0.36, -0.08);
    glVertex2f(-0.3455359307889, -0.0686145571218);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-0.3911489791823, -0.0646577053519);
    glVertex2f(-0.391172070257, -0.1028416617228);
    glEnd();


}


void Ghost2(){


        //Broom Brush
    glPushMatrix();
    glTranslatef(-0.01f, 0.023f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(150, 105, 25);

    glVertex2f(-0.3727039192255, 0.2223922836999);//H12
    glVertex2f(-0.376718712988, 0.2175986659684); //j12
    glVertex2f(-0.3730002622554, 0.2175986659684);//k12
    glVertex2f(-0.376718712988, 0.2148502458616); //l12
    glVertex2f(-0.3694434832937, 0.2116168104419); //M12
    glVertex2f(-0.3742936364233, 0.2091917338771); //N12
    glVertex2f(-0.35, 0.21);   //O12
    glVertex2f(-0.3388875185773, 0.2046649242895); //P12
    glVertex2f(-0.3173851730362, 0.1854259835422); //Q12
    glVertex2f(-0.2894159566556, 0.1728155854053); //R12
    glVertex2f(-0.2908710025945, 0.175887349054);//F13
    glVertex2f(-0.2635484732979, 0.1556783776808); //S13
    glVertex2f(-0.2847274752971, 0.1783124256188); //R13
    glVertex2f(-0.2803623374804, 0.1783124256188); //Q13
    glVertex2f(-0.250453059848, 0.1640853097721);//P13
    glVertex2f(-0.2680752828855, 0.1808991739546); //O13
    glVertex2f(-0.251261418703, 0.1718455547794); //N13
    glVertex2f(-0.2536864952678, 0.1754023337411); //P12
    glVertex2f(-0.2383276770241, 0.1681271040467); //Q12
    glVertex2f(-0.2685602981985, 0.1909228237557); //R12
    glVertex2f(-0.2583749766264, 0.187366044794);//F13
    glVertex2f(-0.2669435804886, 0.1946412744884); //S13
    glVertex2f(-0.2417227842148, 0.188012731878); //R13
    glVertex2f(-0.2517464340159, 0.1952879615723); //Q13
    glVertex2f(-0.2300824167038, 0.1914078390687);//P13
    glVertex2f(-0.25, 0.2); //O13
    glVertex2f(-0.2412377689018, 0.2015931606408); //N13
    glVertex2f(-0.2554648847486, 0.2048265960605); //P12
    glVertex2f(-0.2564349153745, 0.2078983597092); //Q12
    glVertex2f(-0.2441478607796, 0.210323436274); //R12
    glVertex2f(-0.2548181976647, 0.2164669635715);//F13
    glVertex2f(-0.2452795631765, 0.221963803785); //S13
    glVertex2f(-0.26225509913, 0.2213171167011); //R13
    glVertex2f(-0.2498063727641, 0.2255205827467); //Q13
    glVertex2f(-0.2706620312213, 0.2260055980597);//P13
    glVertex2f(-0.2941044380142, 0.2310174229602); //O13
    glVertex2f(-0.3146367529295, 0.2303707358763); //N13
    glVertex2f(-0.3461627482717, 0.222125475556);//P13
    glVertex2f(-0.3523062755692, 0.222125475556); //O13
    glVertex2f(-0.3645933301641, 0.2308557511892); //N13

    glEnd();
    glPopMatrix();

    //dandi
    glPushMatrix();
    glTranslatef(-0.01f, 0.023f, 0.0f);
    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3ub(150, 105, 25);
    glVertex2f(-0.6515749481072, 0.2945418174205);
    glVertex2f(-0.3727039192255, 0.2223922836999);
    glEnd();
    glPopMatrix();

    //Ghost Hat
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.5324120085967, 0.4132103872745); //U22
    glVertex2f(-0.4727072133115, 0.4146601452409); //F23
    glVertex2f(-0.4645636637043, 0.4225128537907);//G23
    glVertex2f(-0.4299535778738, 0.4236762180203); //H23
    glVertex2f(-0.414829842889, 0.4318197676275); //l23
    glVertex2f(-0.4, 0.44); //J23
    glVertex2f(-0.3662849321763, 0.4365047130341);//E23
    glVertex2f(-0.3944944633464, 0.4512287122303); //D23
    glVertex2f(-0.4015367157788, 0.4512455791154); //C23
    glVertex2f(-0.4358439504053, 0.438275770903); //B23
    glVertex2f(-0.4723213381552, 0.449694008614);//A23
    glVertex2f(-0.4832902700612, 0.4492170985311); //Z22
    glVertex2f(-0.5030820385003, 0.4461171829924); //W22
    glVertex2f(-0.5202508014836, 0.4346713410036); //V22


    glEnd();


    //Ghost Face
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.5355119241354, 0.4031952755342); //Q22
    glVertex2f(-0.4601691638938, 0.3730884872031); //S23
    glVertex2f(-0.4101763859706, 0.375396602492);//R23
    glVertex2f(-0.3915625582971 , 0.387030244788); //Q23
    glVertex2f(-0.407558816454, 0.3852851984436); //P23
    glVertex2f(-0.3866182603213, 0.4091341651503); //O23
    glVertex2f(-0.4, 0.4);//N23
    glVertex2f(-0.4171565713482, 0.3989547281414); //M23
    glVertex2f(-0.4107580680854, 0.4021539797727); //L23
    glVertex2f(-0.4407146969976, 0.4027356618875); //K23
    glVertex2f(-0.4727072133115, 0.4146601452409);//F23
    glVertex2f(-0.5324120085967, 0.4132103872745); //U22
    glEnd();

    //Ghost face down
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.5355119241354, 0.4031952755342); //Q22
    glVertex2f(-0.5355119241354, 0.3919878885868); //P22
    glVertex2f(-0.5414733001712, 0.3853111474266);//O22
    glVertex2f(-0.5438578505856, 0.3733883953549); //N22
    glVertex2f(-0.531458188431 , 0.3795882264322); //M22
    glVertex2f(-0.5338427388453, 0.3707653898991); //L22
    glVertex2f(-0.5309812783481, 0.3669501092362);//K22
    glVertex2f(-0.5347391611688, 0.3602242211769); //H22
    glVertex2f(-0.5249995708677, 0.3576111603644); //J22
    glVertex2f(-0.5169228374474, 0.3609368741258); //l22
    glVertex2f(-0.508608553044, 0.3595115682281);//G22
    glVertex2f(-0.4976812078282, 0.3535727936543); //F22
    glVertex2f(-0.4540933856379, 0.3602728675073); //W23
    glVertex2f(-0.4354795579644, 0.3620179138517); //V23
    glVertex2f(-0.4488582466047, 0.3643446423108);//U23
    glVertex2f(-0.4343161937348, 0.3675438939422); //T23
    glVertex2f(-0.4601691638938, 0.3730884872031); //S23
    glEnd();

    //Hat sharp Phase

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);

    glVertex2f(-0.5324120085967, 0.4132103872745); //U22
    glVertex2f(-0.5557806026573, 0.4055798259486); //T22
    glVertex2f(-0.5691340849776, 0.4031952755342);//S22
    glVertex2f(-0.5665110795219 ,0.4005722700784); //R22
    glVertex2f(-0.5355119241354, 0.4031952755342); //Q22

    glEnd();

    //Hand

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.6460918890339, 0.2978225035081); //C22
    glVertex2f(-0.6110612242307, 0.2915125800089); //U27
    glVertex2f(-0.599820883082, 0.2935131465918);//V27
    glVertex2f(-0.5937079006987, 0.2875827089398); //W27
    glVertex2f(-0.5724377946139, 0.2837079221724); //B22
    glVertex2f(-0.494633281804, 0.3092503837857); //A22
    glVertex2f(-0.4976812078282, 0.3535727936543);//F22
    glVertex2f(-0.553033249933, 0.3190037068883);//E22
    glVertex2f(-0.5984636743787, 0.3037756630716); //D22

    glEnd();


    //upper body

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4976812078282, 0.3535727936543);//F22
    glVertex2f(-0.494633281804, 0.3092503837857); //A22
    glVertex2f(-0.4513333862673, 0.2777595506682);//Z21
    glVertex2f(-0.3869091013787, 0.2826183051817); //G24
    glVertex2f(-0.3496814460316, 0.2677854112543); //F24
    glVertex2f(-0.3162347244307, 0.2733113913449); //E24
    glVertex2f(-0.3141988370289, 0.309084841405);//D24
    glVertex2f(-0.3240874329805, 0.3093756824624);//C24
    glVertex2f(-0.3575341545814, 0.310539046692); //B24
    glVertex2f(-0.3810922802307, 0.3244994174472); //A24
    glVertex2f(-0.441005538055, 0.3532926821297); //Z23
    glVertex2f(-0.4540933856379, 0.3602728675073); //W23
    glEnd();


    //Lower body

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4513333862673, 0.2777595506682);//Z21
    glVertex2f(-0.5455369079553, 0.240253621215); //J24
    glVertex2f(-0.5499682908322, 0.2285421093261);//K24
    glVertex2f(-0.4952090595676, 0.1839117532087); //L24
    glVertex2f(-0.4898280946456, 0.1750489874548); //M24
    glVertex2f(-0.4759513199637, 0.1746003427975); //Z24
    glVertex2f(-0.4614130867907, 0.171575045721);//B25
    glVertex2f(-0.4453488505378, 0.1695886232068); //T25
    glVertex2f(-0.4355608248445, 0.1691535998426); //U25
    glVertex2f(-0.4277304042899, 0.170349914094); //V25
    glVertex2f(-0.4287092068592, 0.1738301010072);//W25
    glVertex2f(-0.4145709475244, 0.170349914094); //Z25
    glVertex2f(-0.38066742649, 0.1732509037213); //A26
    glVertex2f(-0.3327028268984, 0.1993955420233); //B26
    glVertex2f(-0.3565533852501 , 0.2024354865511);//C26
    glVertex2f(-0.3725063115439, 0.2100170752848); //D26
    glVertex2f(-0.3723483617786, 0.2191781616713); //E26
    glVertex2f(-0.4012531688257, 0.2324459419552); //F26
    glVertex2f(-0.4039383148355, 0.2392377818624); //G26
    glVertex2f(-0.3927238815003, 0.2521896626158);//H26
    glVertex2f(-0.3882228158251, 0.2608278988578); //I24
    glVertex2f(-0.3844244876449, 0.2703237193083); //H24
    glVertex2f(-0.3869091013787, 0.2826183051817); //G24
    glEnd();

    //Front Leg
    glPushMatrix();
    glTranslatef(0.0f, 0.01f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4812655120916, 0.1745573497223);//G12
    glVertex2f(-0.4815753934812, 0.1600962182062); //U12
    glVertex2f(-0.4850873825637, 0.1514195392966);//V12
    glVertex2f(-0.4869466709015, 0.1450153239109); //W12
    glVertex2f(-0.4884960778497, 0.1394374588975); //Z12
    glVertex2f(-0.4912850103563, 0.1355122946289); //A13
    glVertex2f(-0.5036802659416, 0.1343760628669);//J12
    glVertex2f(-0.4997551016729, 0.1316904241567); //C13
    glVertex2f(-0.4866367895119, 0.1301410172086); //D13
    glVertex2f(-0.4818852748709, 0.1312772489706); //E13
    glVertex2f(-0.4672175557617, 0.1444988549281);//F13
    glVertex2f(-0.4697999006753, 0.1484240191968); //G13
    glVertex2f(-0.4677340247444, 0.1485273129933); //H13
    glVertex2f(-0.4641187418654, 0.1461515556728); //l13
    glVertex2f(-0.4579211140728, 0.149973426145);//j13
    glVertex2f(-0.4698755125084, 0.1703358813453); //L12
    glVertex2f(-0.4675590640932, 0.164888060828); //H12

    glEnd();
    glPopMatrix();


    //Back Leg
    glPushMatrix();
    glTranslatef(0.01f, 0.01f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(-0.4543189400492, 0.1701417715099);//l12
    glVertex2f(-0.4563717071246, 0.1582369298684); //j12
    glVertex2f(-0.4558552381419, 0.1504898951277);//k12
    glVertex2f(-0.456061825735, 0.1446021487247); //l12
    glVertex2f(-0.458540876852, 0.1352024132392); //M12
    glVertex2f(-0.4613298093587, 0.1279718474812); //N12
    glVertex2f(-0.466701086779, 0.1230137452471);   //O12
    glVertex2f(-0.475067884299, 0.1209478693162); //P12
    glVertex2f(-0.4712460138269, 0.1183655244026); //Q12
    glVertex2f(-0.4543058311937, 0.1179523492165); //R12
    glVertex2f(-0.4672175557617, 0.1444988549281);//F13
    glVertex2f(-0.4416006942189, 0.1303476048017); //S12
    glVertex2f(-0.442943513574, 0.1341694752738); //T12
    glVertex2f(-0.4372623547641, 0.1324134807326); //Q13
    glVertex2f(-0.4308581393784, 0.1384045209321);//P13
    glVertex2f(-0.4438731577428, 0.1519360082793); //O13
    glVertex2f(-0.4450513861298, 0.1646182269369); //N13
    glEnd();

    glPopMatrix();




    }


void blackship2()
{

    glPushMatrix();
    glScaled(0.5,0.2,0);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f); //ship body front
    glVertex2d(0.0f,0.0f);
    glVertex2d(-3.0f,7.0f);
    glVertex2d(10.0f,7.0f);
    glVertex2d(8.0f,0.0f);

    glColor3f(0.0f,1.0f,0.0f); //green box front
    glVertex2d(2.0f,7.0f);
    glVertex2d(2.0f,9.0f);
    glVertex2d(8.0f,9.0f);
    glVertex2d(8.0f,7.0f);

    glColor3f(0.0f,0.0f,1.0f); //blue box front
    glVertex2d(3.0f,9.0f);
    glVertex2d(3.0f,11.0f);
    glVertex2d(7.0f,11.0f);
    glVertex2d(7.0f,9.0f);

    glColor3f(1.0f,0.0f,0.0f); //red stand front
    glVertex2d(4.0f,9.0f);
    glVertex2d(4.0f,15.0f);
    glVertex2d(6.0f,15.0f);
    glVertex2d(6.0f,9.0f);

    glEnd();
    glPopMatrix();
}


///////////////////////////////


/////////////////////////////////////////////////////////

void wheerligig2()
{
    glPushMatrix();
    glPushMatrix();
    glTranslated(13,-5,1);
    glScaled(0.4,0.25,0);
    glColor3f(0.184,0.31,0.31);
    glBegin(GL_QUADS);
    glVertex2d(0,-10);
    glVertex2d(1,-10);
    glVertex2d(1,30);
    glVertex2d(0,30);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslated(13.25,2.5,1);
    glScaled(0.35,0.2,0);
    glRotated(angle,0,0,1);
    glPushMatrix();
    glTranslatef(10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();



    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();


    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,13,0);
    glRotated(-angle,0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,-3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-2.5);
    glColor3f(0.545,0,0);
    glVertex2d(1.5,-7.5);
    glColor3f(0.545,0,0);
    glVertex2d(-1.5,-7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-3.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-4.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-5.5);
    glColor3f(0,0,0);
    glVertex2d(-1.5,-6.5);
    glColor3f(0,0,0);
    glVertex2d(1.5,-6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

    glColor3f(1,0,0);
    glBegin(GL_LINES);

    glVertex2d(0,0);
    glVertex2d(10,13);
    glVertex2d(0,0);
    glVertex2d(10,-13);
    glVertex2d(0,0);       //4 cross lines
    glVertex2d(-10,-13);
    glVertex2d(0,0);
    glVertex2d(-10,13);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,0);
    glColor3f(0.545,0,0);
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
}


void TrainLineStand2(){

    //left stand;
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-1, 0.15);
    glVertex2f(-0.3401491747484, 0.289164780547);
    glVertex2f(-0.5377171099902, 0.2720197377969);
    glVertex2f(-0.9997158107161, 0.1721983055444);
    glEnd();

    //right stand;
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(1.0026810730535, 0.1620790406772);
    glVertex2f(0.56011358327, 0.2724813880009);
    glVertex2f(0.5267765560807, 0.2724673694045);
    glVertex2f(0.9989775639092, 0.1398579858116);
    glEnd();

    //middle stand;
    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-0.6441776006153, 0.237546840868);
    glVertex2f(0.6660538061076, 0.2333537928378);
    glVertex2f(0.6218413507372, 0.2457700866546);
    glVertex2f(-0.5998366919368, 0.2484565151401);
    glEnd();

}


void TrainPart2(){

    //4rd part

    //Wheel
    glBegin(GL_POLYGON);
    glColor3ub(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.4181430288752)+x,(0.2894196624232+y));
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.371613308143)+x,(0.2894196624232+y));
        }
    glEnd();

    //body
    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2f(-0.4602711712901, 0.2895573360912);
    glVertex2f(-0.3401491747484, 0.289164780547);
    glVertex2f(-0.3405417302927, 0.4045761105575);
    glVertex2f(-0.4602711712901, 0.4041835550133);
    glEnd();

    //window;
    glBegin(GL_QUADS);
    glColor3ub(240,230,140);
    glVertex2f(-0.4444807563549, 0.3467918795839);
    glVertex2f(-0.35477913555, 0.3463841449438);
    glVertex2f(-0.35518687019, 0.3928658939064);
    glVertex2f(-0.4444807563549, 0.3930697612264);
    glEnd();

    //roof
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.4664292636764, 0.4042190946974);
    glVertex2f(-0.3321551175367, 0.4046504975766);
    glVertex2f(-0.3405417302927, 0.4045761105575);
    glVertex2f(-0.4662135622368, 0.4105822871651);
    glEnd();


}



void TrainlineCross2(){

    glBegin(GL_QUADS);
    glColor3ub(0,51,51);
    glVertex2f(-1, 0.2557167785128);
    glVertex2f(-0.9754293048045, 0.2559914983469);
    glVertex2f(-0.9754293048045, 0.3308351580175);
    glVertex2f(-0.9999374245239, 0.3309822446475);
    glEnd();
}


void TrainLine2(){

    TrainLineStand2();
    TrainlineCross2();

    glPushMatrix();
    glTranslatef(0.08, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.24, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.32, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.40, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.56, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.64, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.72, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.80, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.88, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.96, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.04, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.12, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.20, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.28, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.36, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.44, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.52, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.60, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.68, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.76, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.84, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.92, 0.0f, 0.0f);
    TrainlineCross2();
    glPopMatrix();


    //upper line
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9999980648384, 0.2973152032047);
    glVertex2f(0.9993365381334, 0.2966981573604);
    glVertex2f(0.9989458922249, 0.310761410068);
    glVertex2f(-0.9999950657936, 0.3109950845453);
    glEnd();

    //Lower Line;
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.9998269964605, 0.2718254153711);
    glVertex2f(0.9999385462274, 0.2726663393647);
    glVertex2f(0.9999385462274, 0.2837025492797);
    glVertex2f(-0.9997272625358, 0.2838398841969);
    glEnd();

}


void Train2(){

    // joint train part;
    glBegin(GL_QUADS);
    glColor3ub(255,229,204);
    glVertex2f(-0.3402231651472, 0.310917957778);
    glVertex2f(-0.1610147523435, 0.3108970084688);
    glVertex2f(-0.1609295978501, 0.3353789253159);
    glVertex2f(-0.3403063732809, 0.3353811490888);
    glEnd();

    //4rd part;
    TrainPart2();

    //3nd part;
    glPushMatrix();
    glTranslatef(0.15, 0.0f, 0.0f);
    TrainPart2();
    glPopMatrix();

    //2st part

    //Wheel;
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.1184279303271)+x,(0.2894196624232+y));
        }
    glEnd();

    //body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.1610904547415, 0.2891325690472);
    glVertex2f(-0.070441741507, 0.2885268983575);
    glVertex2f(-0.0710474121967, 0.4052194512518);
    glVertex2f(-0.1606866742816, 0.4052194512518);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3ub(240,230,140);
    glVertex2f(-0.1450919680854, 0.3468529025678);
    glVertex2f(-0.0856103973306, 0.3466934345497);
    glVertex2f(-0.0859293333668, 0.3930188938105);
    glVertex2f(-0.1449325000673, 0.3930188938105);
    glEnd();


    //1st part

    //Wheel
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.0416272514535)+x,(0.2894196624232+y));
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
	for(int i=0;i<360;i++)
        {
            float pi=3.1416;
            float theta=(i*pi)/50;
            float r=0.020;
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f((-0.0014289931996)+x,(0.2894196624232+y));
        }
    glEnd();

    //body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.070441741507, 0.2885268983575);
    glVertex2f(0.0199086787311, 0.2888198246858);
    glVertex2f(0.020236893377, 0.3465856023667);
    glVertex2f(-0.0707430913649, 0.3465869709834);
    glEnd();

    //upper body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.0256704631673, 0.3475450809554);
    glVertex2f(0.0042924418657, 0.3473263736193);
    glVertex2f(0.0042924418657, 0.3812260107004);
    glVertex2f(-0.0258891705033, 0.3812260107004);
    glEnd();
    //upper top roof
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.0321678925792, 0.3810613944403);
    glVertex2f(0.0112403848194, 0.3812956117644);
    glVertex2f(0.0110061674953, 0.3869168275426);
    glVertex2f(-0.0322459650206, 0.3870729724253);
    glEnd();

}



void leafless_tree2()
{

    //gacher gora
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);
    glVertex2f(-0.629419862086, -0.4953445671983);//k24
    glVertex2f(-0.6371391079331, -0.5143070624314);//l24
    glVertex2f(-0.6505638833194, -0.5275640281254);//m24
    glVertex2f(-0.6663457537908, -0.5353027647459);//n24
    glVertex2f(-0.6749605988491, -0.5382318120657);//o24
    glVertex2f(-0.6842367068845, -0.5397854892693);//r15
    glVertex2f(-0.674788301948, -0.5428838283972);//s15
    glVertex2f(-0.6489437667729, -0.5421946407925);//v15
    glVertex2f(-0.6347006479162, -0.5355112836743);//w15

    glVertex2f(-0.6382613589006, -0.5477081416299);//z15
    glVertex2f(-0.6623829250639, -0.5694175511769);//a16
    glVertex2f(-0.6427410783309, -0.5625256751302);//b16
    glVertex2f(-0.63, -0.55);//c16
    glVertex2f(-0.6125722184429, -0.5345464950871);//d16
    glVertex2f(-0.6010452282486, -0.5285831856004);//e16

    glVertex2f(-0.5969101026206, -0.5413331562867);//f16
    glVertex2f(-0.5884675544634, -0.5563229866882);//g16
    glVertex2f(-0.5827817567249, -0.5618364875256);//h16
    glVertex2f(-0.5863999916494, -0.5461574695194);//i16
    glVertex2f(-0.5863999916494, -0.5308230453155);//j16

    glVertex2f(-0.5754113918399, -0.5410031944066);//m16
    glVertex2f(-0.5641736913989, -0.5477081416299);//p16
    glVertex2f(-0.5474474060663, -0.5523615281652);//q16
    glVertex2f(-0.5372953748169, -0.5525324548626);//r16
    glVertex2f(-0.5468982978086, -0.5481883054067);//s16
    glVertex2f(-0.5569372215499, -0.5397824841762);//v16
    glVertex2f(-0.5657243635094, -0.5311676391179);//w16
    glVertex2f(-0.5729608333584, -0.5175561839257);//z16
    glVertex2f(-0.5770090305441, -0.5060598715996);//a17
    glVertex2f(-0.5779574434922, -0.4956744774775);//b17

    glEnd();

    //kando
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5779574434922, -0.4956744774775);//b17
    glVertex2f(-0.5775341257166, -0.4834062407073);//c17
    glVertex2f(-0.5769934966787, -0.4717827163905);//d17
    glVertex2f(-0.5778044402356, -0.4558341597698);//e17
    glVertex2f(-0.5786153837926, -0.4331277401741);//f17
    glVertex2f(-0.5769934966787, -0.4247479900853);//g17
    glVertex2f(-0.5742903514887, -0.4125838367305);//h17
    glVertex2f(-0.5805075854256, -0.383389868679);//j18
    glVertex2f(-0.5842919886915, -0.3701444572482);//k18
    glVertex2f(-0.5845623032105, -0.3541959006275);//l18
    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24
    glVertex2f(-0.62, -0.36);//e24
    glVertex2f(-0.6218657068319, -0.385552384831);//f24
    glVertex2f(-0.6261907391358, -0.4071775463506);//g24
    glVertex2f(-0.6279095748551, -0.4283884999593);//h24
    glVertex2f(-0.6272383360858, -0.4485256630387);//i24
    glVertex2f(-0.6278126262498, -0.4755671196564);//j24
    glVertex2f(-0.629419862086, -0.4953445671983);//k24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5779574434922, -0.4956744774775);//b17
    glVertex2f(-0.5775341257166, -0.4834062407073);//c17
    glVertex2f(-0.5769934966787, -0.4717827163905);//d17
    glVertex2f(-0.5778044402356, -0.4558341597698);//e17
    glVertex2f(-0.5786153837926, -0.4331277401741);//f17
    glVertex2f(-0.5769934966787, -0.4247479900853);//g17
    glVertex2f(-0.5742903514887, -0.4125838367305);//h17
    glVertex2f(-0.5805075854256, -0.383389868679);//j18
    glVertex2f(-0.5842919886915, -0.3701444572482);//k18
    glVertex2f(-0.5845623032105, -0.3541959006275);//l18
    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24
    glVertex2f(-0.62, -0.36);//e24
    glVertex2f(-0.6218657068319, -0.385552384831);//f24
    glVertex2f(-0.6261907391358, -0.4071775463506);//g24
    glVertex2f(-0.6279095748551, -0.4283884999593);//h24
    glVertex2f(-0.6272383360858, -0.4485256630387);//i24
    glVertex2f(-0.6278126262498, -0.4755671196564);//j24
    glVertex2f(-0.629419862086, -0.4953445671983);//k24


    glEnd();

    //right nicher daal
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);
    glVertex2f(-0.5742903514887, -0.4125838367305);//h17
    glVertex2f(-0.57, -0.4);//i17
    glVertex2f(-0.5542232194806, -0.3826965358376);//j17
    glVertex2f(-0.5388170165041, -0.3662278361042);//k17
    glVertex2f(-0.5225253995635, -0.3547174545701);//l17
    glVertex2f(-0.5127021164438, -0.3490035629226);//m17
    glVertex2f(-0.5035775407305, -0.3463945633069);//n17
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17
    glVertex2f(-0.5064108654158, -0.337894589251);//c18
    glVertex2f(-0.5145566738861, -0.3412591623148);//d18
    glVertex2f(-0.5247716963228, -0.3473569496866);//e18
    glVertex2f(-0.53, -0.35);//f18
    glVertex2f(-0.5409420100181, -0.3564882824984);//g18
    glVertex2f(-0.5616606967795, -0.3726028166461);//h18
    glVertex2f(-0.5765155595475, -0.3842717996158);//i18
    glVertex2f(-0.5805075854256, -0.383389868679);//j18

    glEnd();

    //nicher daal#1
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5035775407305, -0.3463945633069);//n17
    glVertex2f(-0.4908362742112, -0.3409682973457);//o17
    glVertex2f(-0.4762728946815, -0.3333431316486);//p17
    glVertex2f(-0.4716209260509, -0.329615132874);//q17
    glVertex2f(-0.4841396780074, -0.3353054746723);//r17
    glVertex2f(-0.5014153329261, -0.3417239443968);//s17
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5035775407305, -0.3463945633069);//n17
    glVertex2f(-0.4908362742112, -0.3409682973457);//o17
    glVertex2f(-0.4762728946815, -0.3333431316486);//p17
    glVertex2f(-0.4716209260509, -0.329615132874);//q17
    glVertex2f(-0.4841396780074, -0.3353054746723);//r17
    glVertex2f(-0.5014153329261, -0.3417239443968);//s17
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17

    glEnd();

    //nicher daal#2
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5051712858659, -0.3414362451076);//t17
    glVertex2f(-0.4987362206542, -0.3321753134787);//u17
    glVertex2f(-0.493077220391, -0.3186417255983);//v17
    glVertex2f(-0.4913457815259, -0.3095288894661);//w17
    glVertex2f(-0.4914369098872, -0.2995958980819);//z17
    glVertex2f(-0.4951731727014, -0.3174570569011);//a18
    glVertex2f(-0.5020989281619, -0.3319464663514);//b18
    glVertex2f(-0.5064108654158, -0.337894589251);//c18

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5051712858659, -0.3414362451076);//t17
    glVertex2f(-0.4987362206542, -0.3321753134787);//u17
    glVertex2f(-0.493077220391, -0.3186417255983);//v17
    glVertex2f(-0.4913457815259, -0.3095288894661);//w17
    glVertex2f(-0.4914369098872, -0.2995958980819);//z17
    glVertex2f(-0.4951731727014, -0.3174570569011);//a18
    glVertex2f(-0.5020989281619, -0.3319464663514);//b18
    glVertex2f(-0.5064108654158, -0.337894589251);//c18

    glEnd();

    //daal 2
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.5784633950618, -0.306215395255);//n18
    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5817135361927, -0.2676026561615);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22
    glVertex2f(-0.601477651402, -0.2967217859033);//m22
    glVertex2f(-0.6021585196228, -0.3080110729981);//n22
    glVertex2f(-0.6047716706036, -0.3162223795766);//o22
    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5823997870586, -0.3309488519939);//m18
    glVertex2f(-0.5784633950618, -0.306215395255);//n18
    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5817135361927, -0.2676026561615);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22
    glVertex2f(-0.601477651402, -0.2967217859033);//m22
    glVertex2f(-0.6021585196228, -0.3080110729981);//n22
    glVertex2f(-0.6047716706036, -0.3162223795766);//o22
    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glEnd();

    /////////

    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5543691583961, -0.2560190688682);//p18
    glVertex2f(-0.5443383215231, -0.230296562445);//q18
    glVertex2f(-0.5384463743403, -0.2068294920212);//r18
    glVertex2f(-0.5331714313819, -0.1696755459664);//s18
    glVertex2f(-0.5298274947868, -0.1431832072954);//t18
    glVertex2f(-0.5398224464164, -0.1835509394005);//u18
    glVertex2f(-0.5464234004575, -0.2104604556683);//v18
    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19
    glVertex2f(-0.5594913081571, -0.2317677261959);//l19
    glVertex2f(-0.5637576830347, -0.2450081999537);//m19
    glVertex2f(-0.5703779199136, -0.2550121134597);//n19
    glVertex2f(-0.5759683421669, -0.2638390959649);//o19
    glVertex2f(-0.5817058807953, -0.2667814234666);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5669182399929, -0.2807156614505);//o18
    glVertex2f(-0.5543691583961, -0.2560190688682);//p18
    glVertex2f(-0.5443383215231, -0.230296562445);//q18
    glVertex2f(-0.5384463743403, -0.2068294920212);//r18
    glVertex2f(-0.5331714313819, -0.1696755459664);//s18
    glVertex2f(-0.5298274947868, -0.1431832072954);//t18
    glVertex2f(-0.5398224464164, -0.1835509394005);//u18
    glVertex2f(-0.5464234004575, -0.2104604556683);//v18
    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19
    glVertex2f(-0.5594913081571, -0.2317677261959);//l19
    glVertex2f(-0.5637576830347, -0.2450081999537);//m19
    glVertex2f(-0.5703779199136, -0.2550121134597);//n19
    glVertex2f(-0.5759683421669, -0.2638390959649);//o19
    glVertex2f(-0.5817058807953, -0.2667814234666);//p19
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5526765644741, -0.2120102962617);//z18
    glVertex2f(-0.5562884122295, -0.2070472401577);//a19
    glVertex2f(-0.5624544661448, -0.1907793532322);//b19
    glVertex2f(-0.5656292438359, -0.1831144162457);//c19
    glVertex2f(-0.5678166053575, -0.1713822044479);//d19
    glVertex2f(-0.5679160308812, -0.1543804398936);//e19
    glVertex2f(-0.5665214378762, -0.1414509219098);//f19
    glVertex2f(-0.5698012537886, -0.1550949561053);//g19
    glVertex2f(-0.5704572169711, -0.1739866957607);//h19
    glVertex2f(-0.5682269421507, -0.1874995373198);//i19
    glVertex2f(-0.5636351998733, -0.2066536622482);//j19
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5489766167145, -0.2130136719253);//w18
    glVertex2f(-0.5526765644741, -0.2120102962617);//z18
    glVertex2f(-0.5562884122295, -0.2070472401577);//a19
    glVertex2f(-0.5624544661448, -0.1907793532322);//b19
    glVertex2f(-0.5656292438359, -0.1831144162457);//c19
    glVertex2f(-0.5678166053575, -0.1713822044479);//d19
    glVertex2f(-0.5679160308812, -0.1543804398936);//e19
    glVertex2f(-0.5665214378762, -0.1414509219098);//f19
    glVertex2f(-0.5698012537886, -0.1550949561053);//g19
    glVertex2f(-0.5704572169711, -0.1739866957607);//h19
    glVertex2f(-0.5682269421507, -0.1874995373198);//i19
    glVertex2f(-0.5636351998733, -0.2066536622482);//j19
    glVertex2f(-0.5596384245322, -0.2229407436907);//k19


    glEnd();

    //left nicher daal
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6166306093697, -0.319136491991);//q22
    glVertex2f(-0.6269242733611, -0.3102758533167);//r22
    glVertex2f(-0.6485142846929, -0.2890819889818);//s22
    glVertex2f(-0.6649543850649, -0.2768014320774);//t22
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6916943073566, -0.260163258207);//e23
    glVertex2f(-0.71, -0.25);//f23
    glVertex2f(-0.7709558165106, -0.2157474982364);//g23
    glVertex2f(-0.7071440402363, -0.257984449724);//h23
    glVertex2f(-0.6772349419692, -0.2785840935635);//i23
    glVertex2f(-0.6627755765819, -0.290468503471);//j23
    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24
    glVertex2f(-0.6347897722405, -0.3228362034847);//c24
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6093832974858, -0.3218880926033);//p22
    glVertex2f(-0.6166306093697, -0.319136491991);//q22
    glVertex2f(-0.6269242733611, -0.3102758533167);//r22
    glVertex2f(-0.6485142846929, -0.2890819889818);//s22
    glVertex2f(-0.6649543850649, -0.2768014320774);//t22
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6916943073566, -0.260163258207);//e23
    glVertex2f(-0.71, -0.25);//f23
    glVertex2f(-0.7709558165106, -0.2157474982364);//g23
    glVertex2f(-0.7071440402363, -0.257984449724);//h23
    glVertex2f(-0.6772349419692, -0.2785840935635);//i23
    glVertex2f(-0.6627755765819, -0.290468503471);//j23
    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24
    glVertex2f(-0.6347897722405, -0.3228362034847);//c24
    glVertex2f(-0.6267313681738, -0.3398692311207);//d24

    glEnd();

    //left nicher daal up
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6910431099364, -0.2424369936892);//v22
    glVertex2f(-0.7021922027749, -0.2247081019832);//w22
    glVertex2f(-0.71425759275, -0.2121203631656);//z22
    glVertex2f(-0.7306879344673, -0.2022621581352);//a23
    glVertex2f(-0.715105610387, -0.2138163984396);//b23
    glVertex2f(-0.7064899861296, -0.2243903573086);//c23
    glVertex2f(-0.6968504105225, -0.2405065227767);//q24
    glVertex2f(-0.691101129232, -0.2568566320869);//d23
    glVertex2f(-0.6916943073566, -0.260163258207);//e23

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6819269203384, -0.2656514765027);//u22
    glVertex2f(-0.6910431099364, -0.2424369936892);//v22
    glVertex2f(-0.7021922027749, -0.2247081019832);//w22
    glVertex2f(-0.71425759275, -0.2121203631656);//z22
    glVertex2f(-0.7306879344673, -0.2022621581352);//a23
    glVertex2f(-0.715105610387, -0.2138163984396);//b23
    glVertex2f(-0.7064899861296, -0.2243903573086);//c23
    glVertex2f(-0.6968504105225, -0.2405065227767);//q24
    glVertex2f(-0.691101129232, -0.2568566320869);//d23
    glVertex2f(-0.6916943073566, -0.260163258207);//e23




    glEnd();

    //left nicher daal down
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6647659033553, -0.306039918654);//l23
    glVertex2f(-0.6775495218403, -0.3073914906524);//m23
    glVertex2f(-0.6964617045839, -0.3035778074158);//n23
    glVertex2f(-0.722770868287, -0.2940109278682);//o23
    glVertex2f(-0.7473368274368, -0.2889244548788);//p23
    glVertex2f(-0.7661847457755, -0.2893640043484);//q23
    glVertex2f(-0.7781253322054, -0.2917234098578);//r23
    glVertex2f(-0.7955776397213, -0.3017667189);//s23
    glVertex2f(-0.7768081769212, -0.2943577204262);//r24
    glVertex2f(-0.7621548243843, -0.2923819874999);//t23
    glVertex2f(-0.7438792948158, -0.2940284316052);//u23
    glVertex2f(-0.7193472776472, -0.3017667189);//v23
    glVertex2f(-0.6954738381208, -0.3123039611737);//w23
    glVertex2f(-0.6775270659941, -0.3168382455172);//z23
    glVertex2f(-0.6590586038649, -0.3155190696508);//a24
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6518815341667, -0.3007683253907);//k23
    glVertex2f(-0.6647659033553, -0.306039918654);//l23
    glVertex2f(-0.6775495218403, -0.3073914906524);//m23
    glVertex2f(-0.6964617045839, -0.3035778074158);//n23
    glVertex2f(-0.722770868287, -0.2940109278682);//o23
    glVertex2f(-0.7473368274368, -0.2889244548788);//p23
    glVertex2f(-0.7661847457755, -0.2893640043484);//q23
    glVertex2f(-0.7781253322054, -0.2917234098578);//r23
    glVertex2f(-0.7955776397213, -0.3017667189);//s23
    glVertex2f(-0.7768081769212, -0.2943577204262);//r24
    glVertex2f(-0.7621548243843, -0.2923819874999);//t23
    glVertex2f(-0.7438792948158, -0.2940284316052);//u23
    glVertex2f(-0.7193472776472, -0.3017667189);//v23
    glVertex2f(-0.6954738381208, -0.3123039611737);//w23
    glVertex2f(-0.6775270659941, -0.3168382455172);//z23
    glVertex2f(-0.6590586038649, -0.3155190696508);//a24
    glVertex2f(-0.6443547412253, -0.3092854858244);//b24


    glEnd();

    //top daal
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.59, -0.26);//r19
    glVertex2f(-0.5969217410789, -0.2447988003275);//s19
    glVertex2f(-0.6022657522227, -0.2293833835666);//t19
    glVertex2f(-0.6092540744876, -0.2152012001465);//u19
    glVertex2f(-0.6172700912033, -0.2012245556166);//v19
    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21
    glVertex2f(-0.6382736778887, -0.1796518099154);//c21
    glVertex2f(-0.6438883611052, -0.1739176653538);//d21
    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21
    glVertex2f(-0.6626699448768, -0.1789381225684);//f22
    glVertex2f(-0.6503392737369, -0.1844302637166);//g22
    glVertex2f(-0.6417292191306, -0.1909476111094);//h22
    glVertex2f(-0.6308356579529, -0.2075962612112);//i22
    glVertex2f(-0.6199420967752, -0.2289723057863);//j22
    glVertex2f(-0.6108417734709, -0.2548261431784);//k22
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22


    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5854028376984, -0.2672073738574);//q19
    glVertex2f(-0.59, -0.26);//r19
    glVertex2f(-0.5969217410789, -0.2447988003275);//s19
    glVertex2f(-0.6022657522227, -0.2293833835666);//t19
    glVertex2f(-0.6092540744876, -0.2152012001465);//u19
    glVertex2f(-0.6172700912033, -0.2012245556166);//v19
    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21
    glVertex2f(-0.6382736778887, -0.1796518099154);//c21
    glVertex2f(-0.6438883611052, -0.1739176653538);//d21
    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21
    glVertex2f(-0.6626699448768, -0.1789381225684);//f22
    glVertex2f(-0.6503392737369, -0.1844302637166);//g22
    glVertex2f(-0.6417292191306, -0.1909476111094);//h22
    glVertex2f(-0.6308356579529, -0.2075962612112);//i22
    glVertex2f(-0.6199420967752, -0.2289723057863);//j22
    glVertex2f(-0.6108417734709, -0.2548261431784);//k22
    glVertex2f(-0.6046399098355, -0.2786705606788);//l22

    glEnd();

    //top daal right
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6194988242484, -0.1849652026938);//z19
    glVertex2f(-0.6043468925912, -0.1558857378971);//a20
    glVertex2f(-0.5908785088959, -0.1272654225446);//b20
    glVertex2f(-0.5838711112742, -0.1086050072283);//c20
    glVertex2f(-0.5814570748408, -0.0896461573997);//d20
    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20
    glVertex2f(-0.5896545762834, -0.0916160787636);//u20
    glVertex2f(-0.5911004425358, -0.1026408089375);//v20
    glVertex2f(-0.6023059059912, -0.1281242016345);//w20
    glVertex2f(-0.6218251003974, -0.1644515912238);//z20
    glVertex2f(-0.6290544316589, -0.1754763213977);//a21
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6207642523358, -0.19176976667);//w19
    glVertex2f(-0.6194988242484, -0.1849652026938);//z19
    glVertex2f(-0.6043468925912, -0.1558857378971);//a20
    glVertex2f(-0.5908785088959, -0.1272654225446);//b20
    glVertex2f(-0.5838711112742, -0.1086050072283);//c20
    glVertex2f(-0.5814570748408, -0.0896461573997);//d20
    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20
    glVertex2f(-0.5896545762834, -0.0916160787636);//u20
    glVertex2f(-0.5911004425358, -0.1026408089375);//v20
    glVertex2f(-0.6023059059912, -0.1281242016345);//w20
    glVertex2f(-0.6218251003974, -0.1644515912238);//z20
    glVertex2f(-0.6290544316589, -0.1754763213977);//a21
    glVertex2f(-0.6333920304159, -0.1796331868731);//b21


    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5639904503049, -0.0737234838913);//f20
    glVertex2f(-0.543567589491, -0.0473364247866);//g20
    glVertex2f(-0.543567589491, -0.0473364247866);//h20
    glVertex2f(-0.5587491851403, -0.0641446199697);//i20
    glVertex2f(-0.5717619814111, -0.0735427506097);//j20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5799359269317, -0.0826923383864);//e20
    glVertex2f(-0.5639904503049, -0.0737234838913);//f20
    glVertex2f(-0.543567589491, -0.0473364247866);//g20
    glVertex2f(-0.543567589491, -0.0473364247866);//h20
    glVertex2f(-0.5587491851403, -0.0641446199697);//i20
    glVertex2f(-0.5717619814111, -0.0735427506097);//j20
    glVertex2f(-0.5797142457988, -0.0767959496774);//k20


    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.5845940444004, -0.0742656837359);//l20
    glVertex2f(-0.5920041089435, -0.0654097529405);//m20
    glVertex2f(-0.5956187745742, -0.0536620896404);//n20
    glVertex2f(-0.596883907545, -0.037757560865);//o20
    glVertex2f(-0.5947151081665, -0.0214915655265);//p20
    glVertex2f(-0.5989968131683, -0.0350444554008);//q20
    glVertex2f(-0.5986523558595, -0.0520950921872);//r20
    glVertex2f(-0.5967031742635, -0.0641446199697);//s20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.5845940444004, -0.0742656837359);//l20
    glVertex2f(-0.5920041089435, -0.0654097529405);//m20
    glVertex2f(-0.5956187745742, -0.0536620896404);//n20
    glVertex2f(-0.596883907545, -0.037757560865);//o20
    glVertex2f(-0.5947151081665, -0.0214915655265);//p20
    glVertex2f(-0.5989968131683, -0.0350444554008);//q20
    glVertex2f(-0.5986523558595, -0.0520950921872);//r20
    glVertex2f(-0.5967031742635, -0.0641446199697);//s20
    glVertex2f(-0.586889745945, -0.0798673494123);//t20


    glEnd();

    //top daal top1
    glBegin(GL_POLYGON);
    glColor3ub(153.00f,76.0f,0.0f);

    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6565604206257, -0.1453562961332);//f21
    glVertex2f(-0.6656054767175, -0.1317064842128);//g21
    glVertex2f(-0.6759661773317, -0.1207701891201);//h21
    glVertex2f(-0.684188955597, -0.1132874608987);//i21
    glVertex2f(-0.6943852006459, -0.1067092382865);//j21
    glVertex2f(-0.68, -0.12);//k21
    glVertex2f(-0.6684834491103, -0.1379557956944);//l21
    glVertex2f(-0.6614940875849, -0.1518522909627);//m21
    glVertex2f(-0.656971559539, -0.1664066084922);//n21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21

    glColor3ub(123.00f,51.0f,0.0f);
    glVertex2f(-0.6487862762515, -0.1624493762308);//e21
    glVertex2f(-0.6565604206257, -0.1453562961332);//f21
    glVertex2f(-0.6656054767175, -0.1317064842128);//g21
    glVertex2f(-0.6759661773317, -0.1207701891201);//h21
    glVertex2f(-0.684188955597, -0.1132874608987);//i21
    glVertex2f(-0.6943852006459, -0.1067092382865);//j21
    glVertex2f(-0.68, -0.12);//k21
    glVertex2f(-0.6684834491103, -0.1379557956944);//l21
    glVertex2f(-0.6614940875849, -0.1518522909627);//m21
    glVertex2f(-0.656971559539, -0.1664066084922);//n21
    glVertex2f(-0.6557150342633, -0.1722452065234);//o21

    glEnd();


}


void Fountain2(){

    //border

    glBegin(GL_POLYGON);
    glColor3ub(28,163,236);


    glVertex2f(0.0523562861658, 0.2476434939835); //a14
    glVertex2f(0.0324222507317, 0.2384881849969); //j14
    glVertex2f(0.1486274339599, 0.1732298427639); //p14
    glVertex2f(0.269855896002, 0.2418813198872); //Q14
    glVertex2f(0.2510867691315, 0.2492509080094);    //J15
    glVertex2f(0.2032832352019, 0.223610321721);  //V15
    glVertex2f(0.093889520929, 0.2240125155838);    //P15

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(28,163,236);


    glVertex2f(0.0809510306663, 0.3264676497324); //a14
    glVertex2f(0.0630529593538, 0.3158875462336); //j14
    glVertex2f(0.11, 0.3); //p14
    glVertex2f(0.1121864243235, 0.2612067545737); //Q14
    glVertex2f(0.1858866217781, 0.2605727743806);    //J15
    glVertex2f(0.19, 0.3);  //V15
    glVertex2f(0.24, 0.32);    //P15
    glVertex2f(0.2203096556183,0.3266695675172);    //P15

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(28,163,236);


    glVertex2f(0.1484576960699, 0.3984241447819); //a14
    glVertex2f(0.0679257725531, 0.3831508489425); //j14
    glVertex2f(0.1197624129777, 0.3771340960361); //p14
    glVertex2f(0.120688067271, 0.3563068744369); //Q14
    glVertex2f(0.1794671148953, 0.3567697015836);    //J15
    glVertex2f(0.179929942042, 0.3762084417428);  //V15
    glVertex2f(0.2303781010267, 0.3873162932624);    //P15


    glEnd();



    //ground
    //bottom left
    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);

    glVertex2f(0.0226193961984, 0.1645379198803);    //T14
    glVertex2f(0.1106868245775, 0.1033203172265);  //I15
    glVertex2f(0.1497808412925, 0.1029382910046);    //G15
    glVertex2f(0.15, 0.16); //v14
    glVertex2f(0.0125238617257, 0.2390730360938); //v14

    glEnd();

    //bottom left border

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.0125238617257, 0.2390730360938);    //T14
    glVertex2f(0.15, 0.16);  //I15
    glVertex2f(0.1486274339599, 0.1732298427639);    //G15
    glVertex2f(0.0324222507317, 0.2384881849969); //v14
    glVertex2f(0.0523562861658, 0.2476434939835); //v14
    glVertex2f(0.0460897089614, 0.251208960324); //v14

    glEnd();

    //bottom right
    glBegin(GL_POLYGON);
    glColor3ub(96,96,96);

    glVertex2f(0.1497808412925, 0.1029382910046);    //G15
    glVertex2f(0.1766299965589, 0.1026759214091);  //I15
    glVertex2f(0.1981098571392, 0.1076162893426);    //G15
    glVertex2f(0.2816665147965, 0.1675451003615); //v14
    glVertex2f(0.2855328897009, 0.2429394109983); //v14
    glVertex2f(0.15, 0.16); //v14

    glEnd();

    //bottom right border
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(0.2855328897009, 0.2429394109983);    //P15
    glVertex2f(0.15, 0.16);  //V15
    glVertex2f(0.1486274339599, 0.1732298427639);//S15
    glVertex2f(0.269855896002, 0.2418813198872);    //T15
    glVertex2f(0.2510867691315, 0.2492509080094); //U15
    glVertex2f(0.25705089846, 0.2524895269178); //T14

    glEnd();

    //2nd floor
    //left side
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);

    glVertex2f(0.0460897089614, 0.251208960324);    //Q14
    glVertex2f(0.093889520929, 0.2240125155838);  //R14
    glVertex2f(0.0914235729976, 0.29861158597);//V14
    glVertex2f(0.0420050067357, 0.3155649096876);    //P14
    glEnd();

    //left side middle left wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.093889520929, 0.2240125155838);  //R14
    glVertex2f(0.1121864243235, 0.2612067545737);//B15
    glVertex2f(0.11, 0.3);    //A15
    glVertex2f(0.0914235729976, 0.29861158597);//V14
    glEnd();

    //left side border

    glBegin(GL_POLYGON);
    glColor3ub(136,140,141);
    glVertex2f(0.0420050067357, 0.3155649096876);  //P14
    glVertex2f(0.1121864243235, 0.2612067545737);//V14
    glVertex2f(0.11, 0.3);    //A15
    glVertex2f(0.0630529593538, 0.3158875462336);//Z14
    glVertex2f(0.0809510306663, 0.3264676497324);//W14
    glVertex2f(0.072269562536, 0.3298460454098);//J14
    glEnd();

    //middle floor

    glBegin(GL_QUADS);
    glColor3ub(102,178,255);
    glVertex2f(0.093889520929, 0.2240125155838);  //R14
    glVertex2f(0.2035102784564, 0.223416102322);//S14
    glVertex2f(0.1858866217781, 0.2605727743806);    //C15
    glVertex2f(0.1121864243235, 0.2612067545737);//B15
    glEnd();

    //right side

    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(0.2035102784564, 0.223416102322);//S14
    glVertex2f(0.25705089846, 0.2524895269178); //T14
    glVertex2f(0.2595868192327, 0.3181064769096);//U14
    glVertex2f(0.2083107816742, 0.2982421429704);    //H15
    glEnd();

    //right side middle left wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.2035102784564, 0.223416102322);//S14
    glVertex2f(0.1858866217781, 0.2605727743806);    //C15
    glVertex2f(0.19, 0.3);    //D15
    glVertex2f(0.2083107816742, 0.2982421429704);//H15
    glEnd();

    //right side border
    glBegin(GL_POLYGON);
    glColor3ub(136,140,141);
    glVertex2f(0.2595868192327, 0.3181064769096);//U14
    glVertex2f(0.2083107816742, 0.2982421429704);    //H15
    glVertex2f(0.19, 0.3);    //D15
    glVertex2f(0.24, 0.32);//F15
    glVertex2f(0.2203096556183, 0.3266695675172);//G15
    glVertex2f(0.2274502255224, 0.328924484329);//G14
    glEnd();


    //3rd floor starts here
    //left side
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);

    glVertex2f(0.072269562536, 0.3298460454098);    //J14
    glVertex2f(0.1057197643293, 0.3165840498598);  //l14
    glVertex2f(0.1031006356983, 0.3780597503294);//C14
    glVertex2f(0.0679257725531, 0.3831508489425);    //A14
    glEnd();

    //left side middle left wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.1057197643293, 0.3165840498598);  //l14
    glVertex2f(0.120688067271, 0.3563068744369);//L14
    glVertex2f(0.1197624129777, 0.3771340960361);    //K14
    glVertex2f(0.1031006356983, 0.3780597503294);//C14
    glEnd();

    //middle floor

    glBegin(GL_QUADS);
    glColor3ub(102,178,255);
    glVertex2f(0.1057197643293, 0.3165840498598);  //l14
    glVertex2f(0.1912886414304, 0.317505036721);//O14
    glVertex2f(0.1794671148953, 0.3567697015836);    //M14
    glVertex2f(0.120688067271, 0.3563068744369);//L14
    glEnd();

    //Right side
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);

    glVertex2f(0.1912886414304, 0.317505036721);//O14
    glVertex2f(0.2274502255224, 0.328924484329);//G14
    glVertex2f(0.2303781010267, 0.3873162932624);//E14
    glVertex2f(0.197054546468, 0.3794482317693);    //A14
    glEnd();

    //right side middle right wall
    glBegin(GL_QUADS);
    glColor3ub(136,140,141);
    glVertex2f(0.1912886414304, 0.317505036721);//O14
    glVertex2f(0.2303781010267, 0.3873162932624);//E14
    glVertex2f(0.179929942042, 0.3762084417428);    //N14
    glVertex2f(0.1794671148953, 0.3567697015836);    //M14
    glEnd();


    //top

    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);
    glVertex2f(0.1197624129777, 0.3771340960361);    //K14
    glVertex2f(0.1031006356983, 0.3780597503294);//C14
    glVertex2f(0.0679257725531, 0.3831508489425);    //A14
    glVertex2f(0.1484576960699, 0.3984241447819);    //D14
    glVertex2f(0.2303781010267, 0.3873162932624);//E14
    glVertex2f(0.197054546468, 0.3794482317693);//F14
    glVertex2f(0.179929942042, 0.3762084417428);    //N14
    glEnd();


    //bottom traingle


    glBegin(GL_TRIANGLES);
    glColor3ub(96,96,96);
    glVertex2f(0.1981098571392, 0.1076162893426);    //N15
    glVertex2f(0.1106868245775, 0.1033203172265);//L15
    glVertex2f(0.1484750949575, 0.0801595731801);    //E15
    glEnd();

    glPushMatrix();
    glTranslatef(0.0,watermove,0.0);
    waterfall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f,watermove2,0.0f);
    waterfall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.035f,watermove3,0.0f);
    waterfall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05f,watermove4,0.0f);
    waterfall();
    glPopMatrix();

}

void Star() //F50
{


    // Gradually increase or decrease scale
    if (increasingScale) {
        scale += 0.0001f; // You can adjust the step size
        if (scale >= 2.0f) {
            increasingScale = false;
        }
    } else {
        scale -= 0.0001f; // You can adjust the step size
        if (scale <= 0.5f) {
            increasingScale = true;
        }
    }

    float centerX = 0.1473149928274;
    float centerY = 0.2641583056878;



    glPushMatrix(); // Save the current matrix

    glBegin(GL_TRIANGLES);
    glColor3ub(239, 239, 232);

    glVertex2f((0.1391971175598 - centerX) * scale + centerX, (0.2450741778656 - centerY) * scale + centerY);    // E14
    glVertex2f((0.1473149928274 - centerX) * scale + centerX, (0.2641583056878 - centerY) * scale + centerY); // C14
    glVertex2f((0.1088618994542 - centerX) * scale + centerX, (0.2643007245521 - centerY) * scale + centerY);    // D14
    glEnd();

    // Add other triangles and polygons for the complete star shape

    glBegin(GL_TRIANGLES);
    glColor3ub(239, 239, 232);
    glVertex2f((0.1473149928274 - centerX) * scale + centerX, (0.2641583056878 - centerY) * scale + centerY); // C14
    glVertex2f((0.1585660831107 - centerX) * scale + centerX, (0.2950631992507 - centerY) * scale + centerY); // B14
    glVertex2f((0.1708141054444 - centerX) * scale + centerX, (0.2643007245521 - centerY) * scale + centerY); // K14
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(239, 239, 232);
    glVertex2f((0.1708141054444 - centerX) * scale + centerX, (0.2643007245521 - centerY) * scale + centerY); // K14
    glVertex2f((0.206988496988 - centerX) * scale + centerX, (0.2631613736374 - centerY) * scale + centerY); // J14
    glVertex2f((0.1779350486616 - centerX) * scale + centerX, (0.2450741778656 - centerY) * scale + centerY); // I14
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(239, 239, 232);
    glVertex2f((0.1779350486616 - centerX) * scale + centerX, (0.2450741778656 - centerY) * scale + centerY); // I14
    glVertex2f((0.1886164634875 - centerX) * scale + centerX, (0.2144541220314 - centerY) * scale + centerY); // H14
    glVertex2f((0.1585660831107 - centerX) * scale + centerX, (0.2332534121249 - centerY) * scale + centerY);    // G14
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(239, 239, 232);
    glVertex2f((0.1585660831107 - centerX) * scale + centerX, (0.2332534121249 - centerY) * scale + centerY); // G14
    glVertex2f((0.1279460272765 - centerX) * scale + centerX, (0.2145965408957 - centerY) * scale + centerY); // F14
    glVertex2f((0.1391971175598 - centerX) * scale + centerX, (0.2450741778656 - centerY) * scale + centerY); // E14
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(239, 239, 232);
    glVertex2f((0.1473149928274 - centerX) * scale + centerX, (0.2641583056878 - centerY) * scale + centerY); // C14
    glVertex2f((0.1391971175598 - centerX) * scale + centerX, (0.2450741778656 - centerY) * scale + centerY);    // E14
    glVertex2f((0.1585660831107 - centerX) * scale + centerX, (0.2332534121249 - centerY) * scale + centerY);    // G14
    glVertex2f((0.1779350486616 - centerX) * scale + centerX, (0.2450741778656 - centerY) * scale + centerY); // I14
    glVertex2f((0.1708141054444 - centerX) * scale + centerX, (0.2643007245521 - centerY) * scale + centerY); // K14

    glEnd();

    glPopMatrix(); // Restore the original matrix
}

void displayDay() //F51
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //// Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         //// Clear the color buffer (background)

    ground();

    if (p==false)

        sky();
    else
        sky2();

    sun();
    Cloud();
    glPushMatrix();
    glScalef(0.009f,0.015,1.0f);
    glTranslatef(-5.0f,37.0f,0.0f);
    body();
    glPopMatrix();
    glLoadIdentity();

    buildings();
    sea();

    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.0f);
    TrainLine();
    glTranslatef(trainmovent, 0.0f, 0.0f);
    Train();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.020f, 0.05f, 1.0f);
    glTranslatef(move_speed_boat,0.5f,0.0f);
    ship();
    glPopMatrix();
    glLoadIdentity();

    light_house();

    glPushMatrix();
    glScalef(0.030f, 0.05f, 1.0f);
    glTranslatef(0.0f, -2.0f, 0.0f);
    glTranslatef(blackshipupdate, 0.0f, 0.0f);
    blackship();
    glPopMatrix();
	glLoadIdentity();

    fench();

    //1st bench
    glPushMatrix();
    glTranslatef(-1.35,0.25f,0.0f);
    Bench();
    glPopMatrix();

    //2nd bench
    glPushMatrix();
    glTranslatef(0.2,0.25f,0.0f);
    Bench();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.03f, -0.32f, 0.0f);

    Carousel();

    glPushMatrix();
    glTranslatef(-0.15, 0.0f, 0.0f);
    horse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.005f, 0.0f);
    horse();
    glPopMatrix();

    glPopMatrix();

    set_lampPost();

     //tree 1
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(10.0f,0.0f,0.0f);
    Tree();
    glPopMatrix();
    glLoadIdentity();

    //tree 2
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(50.0f,0.0f,0.0f);
    Tree();
    glPopMatrix();
    glLoadIdentity();

    //tree 3
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(95.0f,0.0f,0.0f);
    Tree();
    glPopMatrix();
    glLoadIdentity();

    //tree 4
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(-35.0f,0.0f,0.0f);
    Tree();
    glPopMatrix();
    glLoadIdentity();

    Ferris_Stucut();
    Ferris_Wheel2();

    glPushMatrix();
    glTranslatef(-0.10f, -0.7f, 0.0f);
    Fountain();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.5f,1.75f,1.0f);
    glTranslatef(0.35f, 0.043f, 0.0f);
    ride();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glScalef(1.5f,1.75f,1.0f);
    glTranslatef(0.35f, 0.043f, 0.0f);
    HauntedHouse();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glScalef(1.85f,1.95f,1.0f);
    glTranslatef(0.4f, 0.003f, 0.0f);
    leafless_tree();
    glPopMatrix();
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.55f, 0.55f, 0.0f);
    Froghopper();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5f,2.0f,1.0f);
    glTranslatef(0.65f, -0.15f, 0.0f);
    TentHouse();
    glPopMatrix();
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(bardposition,0.0f,0.0f);
    Bard();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.03f,0.05f,1.0f);
    glTranslatef(0.0f,2.0f,0.0f);
    wheerligig();
    glPopMatrix();
    glLoadIdentity();


    glFlush();


    glutSwapBuffers();  /// Render now
}


void displayNight() //F52
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //// Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         //// Clear the color buffer (background)

    ground2();

    sky3();

//4
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(0.0f,2.5f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();
//3
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(-2.0f,2.7f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();

//1
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(-3.0f,2.2f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();
//2
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(-1.7f,2.0f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();
//5
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(0.7f,1.95f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();

//6
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(1.8f,1.8f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();

    //7
    glPushMatrix();
    glScalef(0.3f,0.3f,1.0f);
    glTranslatef(3.0f,2.7f,0.0f);
    Star();
    glPopMatrix();
    glLoadIdentity();



    Moon();
//    Cloud2();
    glPushMatrix();
    glScalef(0.009f,0.015,1.0f);
    glTranslatef(-5.0f,37.0f,0.0f);
    body2();
    glPopMatrix();
    glLoadIdentity();

    buildings2();
    sea2();

    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.0f);
    TrainLine2();
    glTranslatef(trainmovent, 0.0f, 0.0f);
    Train2();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.020f, 0.05f, 1.0f);
    glTranslatef(move_speed_boat,0.5f,0.0f);
    ship2();
    glPopMatrix();
    glLoadIdentity();

    light_house2();

    glPushMatrix();
    glScalef(0.030f, 0.05f, 1.0f);
    glTranslatef(0.0f, -2.0f, 0.0f);
    glTranslatef(blackshipupdate, 0.0f, 0.0f);
    blackship2();
    glPopMatrix();
	glLoadIdentity();

    fench2();

    //1st bench
    glPushMatrix();
    glTranslatef(-1.35,0.25f,0.0f);
    Bench2();
    glPopMatrix();

    //2nd bench
    glPushMatrix();
    glTranslatef(0.2,0.25f,0.0f);
    Bench2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.03f, -0.32f, 0.0f);

    Carousel2();

    glPushMatrix();
    glTranslatef(-0.15, 0.0f, 0.0f);
    horse2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.005f, 0.0f);
    horse2();
    glPopMatrix();

    glPopMatrix();

    set_lampPost2();

     //tree 1
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(10.0f,0.0f,0.0f);
    Tree2();
    glPopMatrix();
    glLoadIdentity();

    //tree 2
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(50.0f,0.0f,0.0f);
    Tree2();
    glPopMatrix();
    glLoadIdentity();

    //tree 3
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(95.0f,0.0f,0.0f);
    Tree2();
    glPopMatrix();
    glLoadIdentity();

    //tree 4
    glPushMatrix();
    glScalef(0.01f,0.025,1.0f);
    glTranslatef(-35.0f,0.0f,0.0f);
    Tree2();
    glPopMatrix();
    glLoadIdentity();

    Ferris_Stucut2();
    Ferris_Wheel3();

    glPushMatrix();
    glTranslatef(-0.10f, -0.7f, 0.0f);
    Fountain2();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.5f,1.75f,1.0f);
    glTranslatef(0.35f, 0.043f, 0.0f);
    ride2();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glScalef(1.5f,1.75f,1.0f);
    glTranslatef(0.35f, 0.043f, 0.0f);
    HauntedHouse2();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glScalef(1.85f,1.95f,1.0f);
    glTranslatef(0.4f, 0.003f, 0.0f);
    leafless_tree2();
    glPopMatrix();
    glLoadIdentity();


    glPushMatrix();
    glTranslatef(0.55f, 0.55f, 0.0f);
    Froghopper2();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5f,2.0f,1.0f);
    glTranslatef(0.65f, -0.15f, 0.0f);
    TentHouse2();
    glPopMatrix();
    glLoadIdentity();

    //1st voot
    glPushMatrix();
    glTranslatef(-0.25f, 0.45f, 0.0f);
    glTranslatef(ghostmovement,0.0f,0.0f);
    Ghost2();
    glPopMatrix();

    //2nd Voot
    glPushMatrix();
    glTranslatef(0.15f, 0.25f, 0.0f);
    glTranslatef(ghostmovement,0.0f,0.0f);
    Ghost2();
    glPopMatrix();

    //3rd voot;
    glPushMatrix();
    glTranslatef(ghostmovement3rd,0.0f,0.0f);
    Ghost2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(bardposition,0.0f,0.0f);
    //Bard();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.03f,0.05f,1.0f);
    glTranslatef(0.0f,2.0f,0.0f);
    wheerligig2();
    glPopMatrix();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(-1.13f,-1.38f,0.0f);
    Bat3();
    glPopMatrix();


    glFlush();


    glutSwapBuffers();  /// Render now
}

void updateday()
{
     glutDisplayFunc(displayDay);
}
void updatenight()
{
    glutDisplayFunc(displayNight);
}

void sound() //F53
{
    PlaySound("Ghost Incoming.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void stopsound() //F54
{

    PlaySound(NULL, 0, 0);
}




void handleKeypress(unsigned char key, int x, int y) //A16
{
	switch (key) {

	  ///////////////Frog Hopper/////////////////////////
        case 'i': //increase speed;
        benchSpeed -= 10;
        if(benchSpeed < 10){
            benchSpeed = 10;
        }


        break;
        case 'l'://decrease speed;
        benchSpeed += 10;
         if(benchSpeed > 1000){
            benchSpeed = 1000;
        }
        break;

        case 'a': // Stop;
            stopstart=0.0f;
            break;
        case 'q': // Start
            stopstart=0.02f;
            break;

        ////////////////Blackship////////////////
        case 's': //Stop
            blackshipstartstop = 0.0f;
            break;
        case 'w': //Start
            blackshipstartstop = 0.05f;
            break;

        ////////////////White Ship///////////////////
        case 'd': // Stop
            boatstartstop = 0.0f;
            break;
        case 'e': // Start
            boatstartstop = 0.5f;
            break;

    /////////////////////Train////////////////////////
        case 'f': //stop;
            trainstartstop = 0.0f;
            break;
        case 'r': //start;
            trainstartstop = 0.02f;
            break;
        case 'y': //increase
            trainspeed-=10;
            if(trainspeed<10){
                trainspeed = 10;
            }
            break;
        case 'h':// decrease
             trainspeed+=5;
                if(trainspeed>1000){
                trainspeed = 1000;
            }
            break;

        /////////Ride/////////////
        case 't': // Start
            chairmovespeed = 0.0005;
            chairmove2speed = 0.0005;
            break;
        case 'g': // Stop
            chairmovespeed = 0.0;
            chairmove2speed = 0.0;
            break;

        ////////////ghost/////////////
        case 'z':
            resumeGhostMovement -= 10; // increase ghost movement
            if(resumeGhostMovement<10)
            {
                resumeGhostMovement=10;
            }
            break;
        case 'x':
            resumeGhostMovement += 10; // dicrease ghost movement
            if(resumeGhostMovement>1000)
            {
                resumeGhostMovement=1000;
            }  // Resume ghost movement
            break;
        case 'c':
            speed = 0.0f;     // ghost stop

            break;
        case 'v':
            speed = 0.02f;   //start
            break;
            /////lamp//////

        case 'm':
            isColorOn = !isColorOn;
            break;

            //////nagordola//////
        case 'j':       //start
            angle_speed = 0.3f;
            break;

        case 'k':
            angle_speed = 0.0f; //stop
            break;

            ///////day_night///////
        case 'b':

            updateday();
            stopsound();
            sunPosition=-0.5;
            p = false;
            stopstart=0.0f;
            blackshipstartstop = 0.0f;
            chairmovespeed = 0.0f;
            chairmove2speed = 0.0f;
            speed = 0.0f;
            isColorOn = !isColorOn;
            angle_speed = 0.0f;

            break;

        case 'n':

            updatenight();
            sound();
            stopstart=0.02f;
            blackshipstartstop = 0.05f;
            chairmovespeed = 0.0005;
            chairmove2speed = 0.0005;
            speed = 0.02f;
            isColorOn = !isColorOn;
            angle_speed = 0.3f;
            sky3();


            break;

        glutPostRedisplay();
	}
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Haunted Theme Park");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutDisplayFunc(updateday);
    glutTimerFunc(80, update, 0);
    glutTimerFunc(benchSpeed, updateFroghopper, 0);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(30, updateFlow, 0);
    glutTimerFunc(10, update_speed_boat, 0);
    glutTimerFunc(20, blackshipmove, 0);
    glutTimerFunc(20, Bardfly, 0);
    glutTimerFunc(20, windMove, 0);
    glutTimerFunc(trainspeed, TrainMove, 0);
    glutTimerFunc(15, fountainwater, 0);
    glutTimerFunc(resumeGhostMovement,GhostUpdate,0);
    glutTimerFunc(20, chairupdate, 0);
    glutTimerFunc(50, updateGlow, 0);
    glutMouseFunc(mouseClick);
    glutTimerFunc(16, Bat_update, 0);
    glutTimerFunc(25, update_star, 0);
    glutMainLoop();
    return 0;
}
