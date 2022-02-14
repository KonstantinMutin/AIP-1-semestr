#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Lib(6_figure_Grafik).h"

float pos_x = 0, pos_y = 0;

int countBird = 0;

bool OpenDoor = false;

bool isGetSky[3] = { false, false, false };

bool isGetBird[5] = { false, false, false, false, false };

bool isWindowOff = false;

bool isWindowOn = false;

bool isCloseDoor = false;

bool isOpenDoor = false;

bool isCat = false;

bool isCatHome = false;

void renderScene(void);
void processKeys(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Lesson - Basic Forms");
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(processKeys);
	glutMainLoop();
	return 0;
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawTerrain(0, 0, 0);

	if(!isGetSky[0]) {
		drawSky(.05, .05, .03);
		drawMoon(-.2, .8);
	}
	if (!isGetSky[1]) {
		drawSky(.97, .81, .09);
		drawSolar(.7, .7);
	}
	if (!isGetSky[2]) {
		drawSky(.12, .8, .98);
		drawSolar(-.2, .8);
	}

	drawWood(-.3, -.05);
	drawDeskG(0, 0);
	drawDeskV(.1, 0);
	drawHome();

	if (!isWindowOff)
		drawWindow(.7, .7, .69);

	if (isWindowOn)
		drawWindow(1, .9, .08);
	
	if(!isCloseDoor)
		drawCloseDoor();

	drawCatHome(.27, .04, 1, 1, 1);
	drawCar(0, -0.3);
	

	if (!isGetBird[0])
	{
		drawBird(-.3, -.5, 0, 0, 0);
	}

	if (isGetBird[0] && !isGetBird[1])
	{
		drawBird(.4, -.7, .5, .1, .08);
	}

	if (isGetBird[1] && !isGetBird[2])
	{
		drawBird(-.7, -.4, .15, .3, -.47);
	}

	if (isGetBird[2] && !isGetBird[3])
	{
		drawBird(.8, -.5, -.34, .65, .015);
	}

	if (isGetBird[3] && !isGetBird[4])
	{
		drawBird(-.8, -.6, .2, -.4, -.5);
	}

	if (!isCat)
	{
		drawCat(pos_x, pos_y);
	}

	if (isOpenDoor)
		drawOpenDoor();

	if (isCatHome)
		drawCatHome(.39, .04, 1, 1, 1);

	if (countBird == 5)
		OpenDoor = true;

	glEnd();

	glutSwapBuffers();
}

void processKeys(unsigned char key, int x, int y) {

	if (key == 100) {
		pos_x = pos_x + 0.015;
	}

	if (key == 97) {
		pos_x = pos_x - 0.015;
	}

	if (key == 119) {
		pos_y = pos_y + 0.015;
	}

	if (key == 115) {
		pos_y = pos_y - 0.015;
	}

	if (key == 13)
		exit(0);

	// ËÎÃÈÊÀ ÏÐÎÃÐÀÌÌÛ
	if ((pos_x >= -0.5) && (pos_x <= -0.4) &&
		(pos_y >= -0.3) && (pos_y <= -0.1))

	{
		isGetBird[0] = true;
		countBird++;
	}

	if ((pos_x >= 0.2) && (pos_x <= 0.3) &&
		(pos_y >= -0.5) && (pos_y <= -0.4))

	{
		isGetBird[1] = true;
		isGetSky[2] = true;
		countBird++;
	}

	if ((pos_x >= -0.9) && (pos_x <= -0.8) &&
		(pos_y >= -0.2) && (pos_y <= -0.1))

	{
		isGetBird[2] = true;
		countBird++;
	}

	if ((pos_x >= 0.6) && (pos_x <= 0.7) &&
		(pos_y >= -0.3) && (pos_y <= -0.2))
	{
		isGetBird[3] = true;
		isGetSky[1] = true;
		isWindowOff = true;
		isWindowOn = true;
		countBird++;
	}

	if ((pos_x >= -0.95) && (pos_x <= -0.9) &&
		(pos_y >= -0.35) && (pos_y <= -0.25))
	{
		isGetBird[4] = true;
		countBird++;
	}

	if ((pos_x >= 0.1) && (pos_x <= 0.2) &&
		(pos_y >= -0.05) && (pos_y <= 0) && (OpenDoor == true))
	{
		isCloseDoor = true;
		isOpenDoor = true;
	}

	if ((pos_x >= 0.5) && (pos_x <= 0.6) &&
		(pos_y >= 0) && (pos_y <= 0.1) && (isOpenDoor == true))
	{
		isCat = true;
		isOpenDoor = false;
		isCloseDoor = false;
		isCatHome = true;
	}

	glutPostRedisplay();
}