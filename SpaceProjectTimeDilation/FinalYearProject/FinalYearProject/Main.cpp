#include <Windows.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Model.h"
#include <cmath>
#include <vector>
#include "Scene.h"



using namespace std;

//Structs
struct point3D {
	float x;
	float y;
	float z;
};


struct camera {
	point3D pos;
	point3D lookAt;
	point3D up;
};

//Enum for menu
enum MENU_TYPE
{
	showNames,
	showPosition,
	showTextureName,
	Neither
};


material redShinyMaterial = {
	{ 0.80, 0.05, 0.05, 1.0 },
	{ 0.80, 0.05, 0.05, 1.0 },
	{ 1.0, 1.0, 1.0, 1.0 },
	100.0
};

lighting whiteLighting = {
	{ 0.2, 0.2, 0.2, 1.0 },
	{ 0.7, 0.7, 0.7, 1.0 },
	{ 0.5, 0.5, 0.5, 1.0 }
};


//Global Variables

MENU_TYPE show = Neither;

float light0_pos[] = { 1.0, 1.0, 1.0, 0.0 };
void menu(int);

int mousex = 0;
int mousey = 0;
bool choice = false;
//Planet positions, using the position struct in the struct Header file

//Scene
Scene *sceneGraph = new Scene();

//FPS
float fps;
int frame = 0, time, timebase = 0;



//World objects using pointers

Player ** player;

//Game Objects
//vector<GameObject> *sceneGraph = new vector<GameObject>;

int planetNum = 5;
int playerNum = 1;
int sunNum = 1;

//Cam position
camera cam = { 0, 20, 94, 0, 0, 0, 0, 1, 0 };

//Player Position
fposition playerPos = { cam.pos.x, cam.pos.y - 10, cam.pos.z - 20 };



//Call update methods to update planet + player positions
void go()
{

	

	for (int i = 0; i < playerNum; i++)
	{
		//for each player call update method
		player[i]->update();

	}


	glutPostRedisplay();
}

void setMaterial(material *mat) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat->ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat->diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat->specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat->shininess);
}

void setLight(lighting * light) {
	glLightfv(GL_LIGHT0, GL_AMBIENT, light->ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light->diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light->specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
}



void key(unsigned char key, int x, int y) {
	if (key == 'a')
	{
		cam.pos.x -= 0.5;
		player[0]->MovePlayerPos("-", "x");


	}
	else if (key == 'd')
	{
		cam.pos.x += 0.5;
		player[0]->MovePlayerPos("+", "x");

	}
	else if (key == 'w')
	{
		cam.pos.y += 0.5;
		player[0]->MovePlayerPos("+", "y");
	}
	else if (key == 's')
	{
		cam.pos.y -= 0.5;
		player[0]->MovePlayerPos("-", "y");
	}
	else if (key == 'z')
	{
		cam.pos.z += 0.5;
		player[0]->MovePlayerPos("+", "z");
	}
	else if (key == 'x')
	{
		cam.pos.z -= 0.5;
		player[0]->MovePlayerPos("-", "z");
	}


	


	glutPostRedisplay();
}

//outputs text in specific position depending on parameter values ( X, Y and Z pos)
void outputText(float x, float y, float z, string text)
{
	glRasterPos3f(x, y, z);  // where to start drawing
	for (int i = 0; i < text.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
}
//outputs text in specific position depending on parameter values (only X and Y pos)
//used for Gui
void outputGui(float x, float y, string text)
{
	glRasterPos2f(x, y);
	for (int i = 0; i < text.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
	}
}


// Menu handling function definition
void menu(int item)
{

	switch (item)
	{
	case showPosition:
	{
						 cout << "derp" << endl;

	}
	case showNames:
	{

	}
	case showTextureName:
	{

	}

	case Neither:
	{
					choice = false;
					show = (MENU_TYPE)item;
	}
		break;
	default:
	{       /* Nothing */       }
		break;
	}

	glutPostRedisplay();

	return;
}

void MenuHandling()
{
	// Create a menu
	glutCreateMenu(menu);

	// Add menu items
	glutAddMenuEntry("Show planet names", showNames);
	glutAddMenuEntry("Show planet texture names", showTextureName);
	glutAddMenuEntry("Show planet position ", showPosition);
	glutAddMenuEntry("Neither", Neither);

	// Associate a mouse button with menu
	glutAttachMenu(GLUT_RIGHT_BUTTON);


}

void drawHUD()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	
	if (time - timebase > 1000)
	{
		fps = (frame * 1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	float dilation = time / sqrt(1 - (pow(0.95f, 2) / 89875243264));

	stringstream gui;
	stringstream gui1;
	stringstream gui2;
	glColor3f(0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	gui << "FPS " << fps << endl;
	gui1 << "Cam pos  " << "x: " << cam.pos.x << " y: " << cam.pos.y << " z: " << cam.pos.z << endl;
	gui2 << "Dilation: " << dilation << endl;
	outputGui(2, 95, gui.str());
	outputGui(2, 90, gui1.str());
	outputGui(38, 95, gui2.str());
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

}

/* WORKING CALCULATION OF TIME DILATION
#define c 299792
#define c2 89875243264

int main(int argc, char* argv[])
{
	double t, t1, v;

	if (argc<3)
	{
		printf("\nUsage: td [Time in rest frame] [Velocity]\n");
		return -1;
	}

	t = strtod(argv[1], NULL);
	v = strtod(argv[2], NULL);

	if (v >= c)
	{
		printf("\nError: The velocity must be less than the speed of light\n");
		return -1;
	}

	t1 = t / sqrt(1 - (pow(v, 2) / c2));

	printf("\nInput:\n");
	printf("\nTime in rest frame: %.12f s\nVelocity: %.12f km/s (%.12f c)\n", t, v, v / c);

	printf("\nResult:\n");
	printf("\nDilated time: %.12f s\n", t1);

	return 0;
}
*/

void display() {



	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // reset the matrix

	
	gluLookAt(cam.pos.x, cam.pos.y, cam.pos.z,
		cam.lookAt.x, cam.lookAt.y, cam.lookAt.z,
		cam.up.x, cam.up.y, cam.up.z);
	setMaterial(&redShinyMaterial);
	//drawAxes();



	glColor3f(1.0, 0, 0);


	//Draw Player
	for (int i = 0; i < playerNum; i++)
	{
		player[i]->draw();
	}
	
	sceneGraph->draw();
	

	MenuHandling();
	drawHUD();

	glutSwapBuffers();
	glFlush();

}



void passiveMouseFunc(int x, int y)
{

	if (x > mousex)
	{
		cam.lookAt.x += 0.5;
		player[0]->Pitch("+", "x");
	}
	if (x < mousex)
	{
		cam.lookAt.x -= 0.5;
		player[0]->Pitch("-", "x");
	}
	if (y > mousey)
	{
		cam.lookAt.y -= 0.5;
		player[0]->Pitch("-", "y");
	}
	if (y < mousey)
	{
		cam.lookAt.y += 0.5;
		player[0]->Pitch("+", "y");
	}


	mousex = x;
	mousey = y;



	if (x >= 495)
	{

		glutWarpPointer(5, y);
	}
	if (y >= 495)
	{
		glutWarpPointer(x, 5);
	}
	if (x <= 5)
	{
		glutWarpPointer(490, y);
	}
	if (y <= 5)
	{
		glutWarpPointer(x, 490);
	}




}




void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	gluPerspective(45.0, 1, 0.5, 10000.0);

	glEnable(GL_TEXTURE_2D);
	player = new Player *[playerNum];
	
	player[0] = new Player("PlayerShip01.txt", "Penguins.raw", 1, "player", playerPos, 0.05);
	player[0]->read_file("PlayerShip01.txt");
	player[0]->loadTexture("Textures/Ship/ShipTexture.raw");
	
	sceneGraph->initialize();
	
	
	

	setLight(&whiteLighting);
}



void clearHeap()
{
	

	//Remove models from heap.
	for (int i = 0; i < playerNum; i++)
	{
		delete player[i];
		player[i] = NULL;
	}

	
	delete[] player;
	

}

int main(int argc, char** argv) {


	glutInit(&argc, argv);

	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Solar System");
	glutDisplayFunc(display);
	glutIdleFunc(go);
	glutKeyboardFunc(key);
	glutPassiveMotionFunc(passiveMouseFunc);

	init();
	glutMainLoop();
	clearHeap();


}