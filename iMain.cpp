#include "iGraphics.h"
#include<iostream>
#define screenWidth 1360
#define screenHeight 768
#define backgroundSpeed 10
#define backgroundWidth 68
#define enemyNumber 10
//#define rockNumber 7
#define collisionWidth 150
#define enemyWidth 400
using namespace std;

int mposx, mposy;
char str[50] = "Enter your name: ";
char str1[100];
;
int indexNumber = 0;
int menuIndex = 0;

bool musicOn = true;
char characterFrontRun[8][30] = { "front\\1 (1).bmp", "front\\1 (2).bmp", "front\\1 (3).bmp", "front\\1 (4).bmp", "front\\1 (5).bmp", "front\\1 (6).bmp", "front\\1 (7).bmp", "front\\1 (8).bmp" };
char characterBackRun[8][30] = { "backwards\\1 (1).bmp", "backwards\\1 (2).bmp", "backwards\\1 (3).bmp", "backwards\\1 (4).bmp", "backwards\\1 (5).bmp", "backwards\\1 (6).bmp", "backwards\\1 (7).bmp", "backwards\\1 (8).bmp", };
char characterShootFront[3][30] = { "shoot_front\\3 (1).bmp", "shoot_front\\3 (2).bmp", "shoot_front\\3 (3).bmp" };
char characterShootBack[3][30] = { "shoot_back\\3 (1).bmp", "shoot_back\\3 (2).bmp", "shoot_back\\3 (3).bmp" };
char characterStand[2][30] = { "idle\\2 (1).bmp", "idle\\2 (2).bmp" };
char enemyBackwards[8][30] = { "Enemy_back\\1 (1).bmp", "Enemy_back\\1 (2).bmp", "Enemy_back\\1 (3).bmp", "Enemy_back\\1 (4).bmp", "Enemy_back\\1 (5).bmp", "Enemy_back\\1 (6).bmp", "Enemy_back\\1 (7).bmp", "Enemy_back\\1 (8).bmp" };
char enemyfront[8][30] = { "Enemy_front\\1 (1).bmp", "Enemy_front\\1 (2).bmp", "Enemy_front\\1 (3).bmp", "Enemy_front\\1 (4).bmp", "Enemy_front\\1 (5).bmp", "Enemy_front\\1 (6).bmp", "Enemy_front\\1 (7).bmp", "Enemy_front\\1 (8).bmp" };
char enemyAttackFront[6][30] = { "Enemy attack front\\1 (1).bmp", "Enemy attack front\\1 (2).bmp", "Enemy attack front\\1 (3).bmp", "Enemy attack front\\1 (4).bmp", "Enemy attack front\\1 (5).bmp", "Enemy attack front\\1 (6).bmp", };
char enemyAttackBack[6][30] = { "Enemy attack back\\1 (1).bmp", "Enemy attack back\\1 (2).bmp", "Enemy attack back\\1 (3).bmp", "Enemy attack back\\1 (4).bmp", "Enemy attack back\\1 (5).bmp", "Enemy attack back\\1 (6).bmp", };
char lifeBar[10][30] = { "Life bar\\1.bmp", "Life bar\\2.bmp", "Life bar\\3.bmp", "Life bar\\4.bmp", "Life bar\\5.bmp", "Life bar\\6.bmp", "Life bar\\7.bmp", "Life bar\\8.bmp", "Life bar\\9.bmp", "Life bar\\10.bmp" };
char lifeBarIndicator[30] = "Buttons\\life bar.bmp";
char image[12][30] = { "BC\\2 (1).bmp", "BC\\2 (2).bmp", "BC\\2 (3).bmp", "BC\\2 (4).bmp", "BC\\2 (5).bmp", "BC\\2 (6).bmp", "BC\\2 (7).bmp", "BC\\2 (8).bmp", "BC\\2 (9).bmp", "BC\\2 (10).bmp", "BC\\2 (11).bmp", "BC\\2 (12).bmp" };
//char fallingCharacter[2][30] = { "fallingCharacter\\1 (1).bmp", "fallingCharacter\\1 (2).bmp" };
//char rockImg[30] = "rock.bmp";
//char lifeBar1[10][30] = { "Life bar\\1.bmp", "Life bar\\2.bmp", "Life bar\\3.bmp", "Life bar\\4.bmp", "Life bar\\5.bmp", "Life bar\\6.bmp", "Life bar\\7.bmp", "Life bar\\8.bmp", "Life bar\\9.bmp", "Life bar\\10.bmp" };
//char lifeBarIndicator1[30] = "Life indicator\\life bar.bmp";
//char lifeBar2[10][30] = { "Life bar\\1.bmp", "Life bar\\2.bmp", "Life bar\\3.bmp", "Life bar\\4.bmp", "Life bar\\5.bmp", "Life bar\\6.bmp", "Life bar\\7.bmp", "Life bar\\8.bmp", "Life bar\\9.bmp", "Life bar\\10.bmp" };
//char lifeBarIndicator2[30] = "Life indicator\\life bar.bmp";
char bulletImg[30] = "Bullet\\Bullet.bmp";

int characterShootFrontIndex = 0;
int characterShootBackIndex = 0;
int characterFrontRunIndex = 0;
int characterBackRunIndex = 0;
int characterStandIndex = 0;
int characterCoordinateX = 300;
int characterCoordinateY = 0;
int enemyAttackIndex = 0;
int lifeBarIndex = 0;
int lowCoordinate = screenWidth;
int highCoordinate = 0;
int bulletCoordinateX = 0;
int bulletCoordinateY = 295;
int bullet2CoordinateX = 0;
int bullet2CoordinateY = 290;
char score[100] = "100";
char *buffer = score;
int scoring;

bool standPosition = true;
int standCounter = 0;

bool jump = false;
bool frontRun = false;
bool backRun = false;
bool shootFront = false;
bool shootBack = false;
bool enemyFront = true;
bool enemyBack = true;
bool shot = false;
bool shot2 = false;
bool enemyStart = false;
bool characterAlive = true;
//int fallingCharacterX = 600;
//int fallingCharacterY = 350;
int windIndex = 0;
int position[12];

/*typedef struct rock
{
	int cX;
	int cY;
	bool rockshow = true;
	bool rockup = true;
}rock;
rock r[rockNumber];*/

int lifeBarIndex1 = 0;
int lifeBarIndex2 = 0;
typedef struct enemys2
{
	int ex = 0;
	int ey = 0;
	int enemyIndex;
	bool enemyShow;
	bool enemyBack;
}enemys2;

enemys2 enemy2[enemyNumber];

typedef struct enemys
{
	int ex;
	int ey;
	int enemyIndex;
	bool enemyShow;
	bool enemyFront;
}enemys;

enemys enemy1[enemyNumber];
int lowIndex = 0;
int highIndex = 0;


void iDraw()
{
	iClear();
	int menu[12] = { iLoadImage("Menu\\1.jpg"), iLoadImage("Menu\\2.jpg"), iLoadImage("Menu\\3.jpg"), iLoadImage("Menu\\4.jpg"), iLoadImage("Menu\\5.jpg"), iLoadImage("Menu\\6.jpg"), iLoadImage("Menu\\7.jpg"), iLoadImage("Menu\\8.jpg"), iLoadImage("Menu\\9.jpg"), iLoadImage("Menu\\10.jpg"), iLoadImage("Menu\\11.jpg"), iLoadImage("Menu\\12.jpg") };
	int buttons[8] = { iLoadImage("Buttons\\play.jpg"), iLoadImage("Buttons\\Settings.jpg"), iLoadImage("Buttons\\Highscore.jpg"), iLoadImage("Buttons\\sound.jpg"), iLoadImage("Buttons\\back.jpg"), iLoadImage("Buttons\\exit.jpg"), iLoadImage("Buttons\\enter.jpg"), iLoadImage("Buttons\\credits.jpg") };
	int pic[3] = { iLoadImage("Pic\\1.jpg"), iLoadImage("Pic\\2.jpg"), iLoadImage("Pic\\3.jpg") };
	iShowImage(0, 0, 1366, 768, menu[menuIndex]);

	if (menuIndex == 0)
	{
		
		iText(600, 300, str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 250, str1, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(950, 150, 50, 50, buttons[6]);
	}
	if (menuIndex == 1)
	{
		
		iText(500, 100, "Welcome to the Kingdom of Asmodeus", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 70, str1, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(100, 568, 150, 100, buttons[0]);
		iShowImage(100, 368, 150, 100, buttons[1]);
		iShowImage(100, 168, 150, 100, buttons[7]);
		iShowImage(1250, 50, 50, 50, buttons[5]);
	}
	if (menuIndex == 2)
	{
		
		iText(200, 630, "Level 1: Survive", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 600, "Run Left - left button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 570, "Run Right - right button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 540, "Front Shoot - F button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 510, "Back Shoot - G button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 480, "Music On/Off - Home button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 450, "Exit - End button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 390, "Tips For Level 1:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 370, "If the gun jams then you can survive the enemy by going to the opposite of them", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 350, "as they chase you front of them", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 420, "Menu back - Space button", GLUT_BITMAP_TIMES_ROMAN_24);
		/*iText(600, 630, "Level 2: Avoid Obstacles", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 600, "Move Left - left button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 570, "Move Right - right button", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 540, "Tips For Level 2: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 520, "Try to find the pattern where rock comes rarely and stick to those path ", GLUT_BITMAP_TIMES_ROMAN_24);*/
		iShowImage(400, 200, 100, 100, buttons[3]);
		iShowImage(50, 630, 80, 80, buttons[4]);
	}
	if (menuIndex == 3)
	{
		
		iText(100, 250, "From the beginning the demons and the demon hunters were always at each other's throat.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1040, 50, "press space to continue", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 100, "press r to skip", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if (menuIndex == 4)
	{
		
		iText(100, 250, "A famous demon hunter named Levithan is in search of the greatest devil there ever lived to slay and stumbles upon a castle.", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1040, 50, "press space to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (menuIndex == 5)
	{
		
		iText(100, 250, "There he is to meet the demon lord named Asmodeus. Will he succeed in his jouney?!", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1040, 50, "press space to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (menuIndex == 6)
	{
		
		iShowBMP(94, 657, lifeBar[lifeBarIndex]);
		iShowBMP2(20, 545, lifeBarIndicator, 255);
		
		sprintf_s(score, "%d", scoring);
		
		iText(160, 590, buffer, GLUT_BITMAP_TIMES_ROMAN_24);
		if (standPosition)
		{
			
			if (shootFront)
			{
				for (int i = 0; i < 3; i++)
				{
					iShowBMP2(characterCoordinateX, characterCoordinateY, characterShootFront[i], 255);
				}
				shootFront = false;
			}

			else if (shootBack)
			{
				for (int i = 0; i < 3; i++)
				{
					iShowBMP2(characterCoordinateX, characterCoordinateY, characterShootBack[i], 255);
				}
				shootBack = false;
			}
			else
			{
				iShowBMP2(characterCoordinateX, characterCoordinateY, characterStand[characterStandIndex], 255);
			}
		}
		else
		{
			if (frontRun)//for front running.
			{
				iShowBMP2(characterCoordinateX, characterCoordinateY, characterFrontRun[characterFrontRunIndex], 255);

				if (shootFront)
				{
					for (int i = 0; i < 3; i++)
					{
						iShowBMP2(characterCoordinateX, characterCoordinateY, characterShootFront[i], 255);
					}
					shootFront = false;
				}

			}
			else if (backRun)//for backwards running.
			{
				iShowBMP2(characterCoordinateX, characterCoordinateY, characterBackRun[characterBackRunIndex], 255);

				if (shootBack)
				{
					for (int i = 0; i < 3; i++)
					{
						iShowBMP2(characterCoordinateX, characterCoordinateY, characterShootBack[i], 255);
					}
					shootBack = false;
				}
			}
			
			standCounter++;
			if (standCounter >=1)
			{
				characterFrontRunIndex = 0;
				characterBackRunIndex = 0;
				standPosition = true;
				standCounter = 0;
			}

		}
		for (int i = 0; i < enemyNumber; i++)
		{

			if (enemy1[i].enemyShow)
			{
				if (enemy1[i].enemyFront)
				{
					iShowBMP2(enemy1[i].ex, enemy1[i].ey, enemyfront[enemy1[i].enemyIndex], 255);
				}
				else
				{
					iShowBMP2(enemy1[i].ex, enemy1[i].ey, enemyAttackFront[enemyAttackIndex], 255);
					enemyAttackIndex++;
					if (enemyAttackIndex >= 6)
					{
						enemyAttackIndex = 0;
					}
				}
			}

			if (enemy2[i].enemyShow)
			{

				if (enemy2[i].enemyBack)
				{
					iShowBMP2(enemy2[i].ex, enemy2[i].ey, enemyBackwards[enemy2[i].enemyIndex], 255);
				}
				else
				{
					iShowBMP2(enemy2[i].ex, enemy2[i].ey, enemyAttackBack[enemyAttackIndex], 255);
					enemyAttackIndex++;
					if (enemyAttackIndex >= 6)
					{
						enemyAttackIndex = 0;
					}
				}
			}
		}

		if (menuIndex == 7)
		{
			
			iText(1040, 50, "press space to continue", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	/*if (menuIndex == 8)
	{
		
		iText(250, 450, "Reaching the castle of Asmodeus and confronting his nemesis the hero jumps from  ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(250, 430, "the cliff taking Asmodeus with him", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1040, 50, "press space to continue", GLUT_BITMAP_TIMES_ROMAN_24);
	}*/
	if (menuIndex == 10)
	{
		
		iText(980, 50, "press space to go back to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (menuIndex == 11)
	{
		
		iText(500, 680, "Created By:", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(80, 220, 300, 400, pic[1]);
		iText(80, 200, "Shihab Sarar", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(80, 180, "ID:20210104156", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(50, 630, 80, 80, buttons[4]);
		iShowImage(480, 220, 300, 400, pic[0]);
		iText(480, 200, "Maisha Alam Mim", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(480, 180, "ID:20210104133", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(880, 220, 300, 400, pic[2]);
		iText(880, 200, "Tasnim Abhsal", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(880, 180, "ID:20210104134", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	/*if (menuIndex == 9)
	{
		
		for (int i = 0; i < 12; i++)
		{
			iShowBMP(0, position[i], image[i]);

		}
		for (int i = 0; i < 12; i++)
		{

			position[i] += 64;



		}
		for (int i = 0; i < 12; i++)
		{

			if (position[i] > screenHeight)
			{
				position[i] = 64;
			}
		}
		iShowBMP2(fallingCharacterX, fallingCharacterY, fallingCharacter[windIndex], 255);

		for (int i = 0; i < rockNumber; i++)
		{
			iShowBMP2(r[i].cX, r[i].cY, rockImg, 255);
		}
		iShowBMP(96, 662, lifeBar1[lifeBarIndex1]);
		iShowBMP2(20, 545, lifeBarIndicator1, 255);
		iShowBMP(842, 662, lifeBar2[lifeBarIndex2]);
		iShowBMP2(766, 545, lifeBarIndicator2, 255);
		

		if (menuIndex == 7)
		{
			
			iText(1040, 50, "press space to continue", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}*/



}

void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (menuIndex == 1 && 30 <= mx && mx >= 80 && 490 <= my && my >= 590)
		{
			menuIndex = 3;
		}
		if (menuIndex == 1 && 30 <= mx && mx >= 80 && 290 <= my && my >= 390)
		{
			menuIndex = 2;
		}
		if (menuIndex == 1 && 30 <= mx && mx >= 80 && 90 <= my && my >= 190)
		{
			menuIndex = 11;
		}
		if (menuIndex == 2 && 300 <= mx && mx >= 400 && 150 <= my && my >= 250)
		{

			if (musicOn)
			{
				musicOn = false;
				PlaySound(0, 0, 0);
			}
			else
			{
				musicOn = true;
				PlaySound("music\\PLAY SOUND 1.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		if (menuIndex == 2 && -20 <= mx && mx >= 60 && 570 <= my && my >= 650)
		{
			menuIndex = 1;
		}
		if (menuIndex == 1 && 1100 <= mx && mx >= 1150 && 20 <= my && my >= 70)
		{
			exit(0);
		}
		if (menuIndex == 0 && 850 <= mx && mx >= 900 && 80 <= my && my >= 130)
		{
			menuIndex = 1;
		}
		if (menuIndex == 11 && -20 <= mx && mx >= 60 && 570 <= my && my >= 650)
		{
			menuIndex = 1;
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{
		if (menuIndex == 0 ||  menuIndex==10 ||menuIndex ==7)
		{
			menuIndex = 1;
		}
		if (menuIndex == 3 || menuIndex == 4 || menuIndex == 5|| menuIndex== 10)
		{
			menuIndex++;
		}
	}
	if (key == 'r')
	{
		if (menuIndex == 3)
		{
			menuIndex = 6;
		}
	}
	if (key == 'q')
	{
		if (menuIndex == 3 || menuIndex == 4 || menuIndex == 5)
		{
			menuIndex--;
		}
	}
	if (key != '\b' && menuIndex == 0)
	{
		str1[indexNumber] = key;
		indexNumber++;
		str1[indexNumber] = '\0';
	}

	else
	{
		if (indexNumber <= 0)
		{
			indexNumber = 0;
		}
		else if (key == '\b')
		{
			indexNumber--;
			str1[indexNumber] = '\0';
		}
	}
	if (key == 'f')
	{
		for (int i = 0; i<3; i++)
		{
			characterShootFrontIndex++;
			if (characterShootFrontIndex > 3)
			{
				characterShootFrontIndex = 0;

			}
		}
		shootFront = true;
		shootBack = false;
		shot = true;
		standPosition = true;
		
	}
	else if (key == 'g')
	{
		for (int i = 0; i<3; i++)
		{
			characterShootBackIndex++;
			if (characterShootBackIndex > 3)
			{
				characterShootBackIndex = 0;

			}
		}
		shootBack = true;
		shootFront = false;
		shot2 = true;
		standPosition = true;
		
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_HOME)
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("music\\PLAY SOUND 1.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

	else if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	else if (key == GLUT_KEY_RIGHT)
	{
		characterCoordinateX += 150;

		characterFrontRunIndex++;
		if (characterFrontRunIndex >= 8)
		{
			characterFrontRunIndex = 0;
		}
		standPosition = false;
		backRun = false;
		frontRun = true;
		//fallingCharacterX += 40;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		characterCoordinateX -= 150;

		characterBackRunIndex++;
		if (characterBackRunIndex >= 8)
		{
			characterBackRunIndex = 0;
		}
		standPosition = false;
		frontRun = false;
		backRun = true;
		//fallingCharacterX -= 40;
	}


}


/*void idleAndWind()
{
	if (menuIndex == 6)
	{
		characterStandIndex++;
		if (characterStandIndex == 2)
		{
			characterStandIndex = 0;
		}
	}
	if (menuIndex == 9)
	{
		windIndex++;
		if (windIndex > 1)
		{
			windIndex = 0;
		}
	}
}*/
void changemovement()
{
	

	for (int i = 0; i < enemyNumber; i++)
	{
		if (enemy1[i].enemyFront && enemy1[i].enemyShow)
		{
			enemy1[i].ex -= 40;
			if (enemy1[i].ex <= 0)
			{
				enemy1[i].ex = screenWidth + rand() % 100000;
			}
			enemy1[i].enemyIndex++;
			if (enemy1[i].enemyIndex >= 8)
			{
				enemy1[i].enemyIndex = 0;
			}
		}
	}
	for (int i = 0; i < enemyNumber; i++)
	{
		if (enemy2[i].enemyBack && enemy1[i].enemyShow)
		{
			enemy2[i].ex += 40;
			if (enemy2[i].ex >= screenWidth)
			{
				enemy2[i].ex = 0 - rand() % 100000;
			}
			enemy2[i].enemyIndex++;
			if (enemy2[i].enemyIndex >= enemyNumber)
			{
				enemy2[i].enemyIndex = 0;
			}
		}

	}
}


void setEnemy1()
{
	for (int i = 0; i < enemyNumber; i++)
	{
		enemy1[i].ex = screenWidth + rand() % 100000;
		enemy1[i].enemyIndex = rand() % 30000;
		enemy1[i].enemyShow = true;
		enemy1[i].enemyFront = true;
	}
}

void setEnemy2()
{
	for (int i = 0; i < enemyNumber; i++)
	{
		enemy2[i].ex = 0 - rand() % 100000;
		enemy2[i].enemyIndex = rand() % 30000;
		enemy2[i].enemyShow = true;
		enemy2[i].enemyBack = true;
	}
}


void enemyAttack()
{
	for (int i = 0; i < enemyNumber; i++)
	{
		if (enemy1[i].ex < characterCoordinateX + collisionWidth)
		{
			enemy1[i].enemyFront = false;

		}
		else
		{
			enemy1[i].enemyFront = true;
		}
	}
	for (int i = 0; i < enemyNumber; i++)
	{
		if (enemy2[i].ex > characterCoordinateX - collisionWidth)
		{
			enemy2[i].enemyBack = false;

		}
		else
		{
			enemy2[i].enemyBack = true;
		}
	}
}

void lifeIndicator()
{
	if (menuIndex == 6)
	{
		for (int i = 0; i < enemyNumber; i++)
		{
			if (enemy1[i].ex < characterCoordinateX + collisionWidth && enemy1[i].enemyShow &&!(enemy1[i].ex < characterCoordinateX))
			{
				lifeBarIndex++;
				scoring -= 25;
				if (lifeBarIndex >= 10)
				{
					menuIndex = 7;
					characterAlive = false;
				}
			}
		}
	}
	
	
}
void lifeIndicator3()
{
	if (menuIndex == 6)
	{
		for (int i = 0; i < enemyNumber; i++)
		{
			if (enemy2[i].ex + collisionWidth> characterCoordinateX && enemy2[i].enemyShow &&!(enemy2[i].ex > characterCoordinateX))
			{
				
					lifeBarIndex++;
					scoring -= 25;

					if (lifeBarIndex >= 10)
					{
						menuIndex = 7;
						characterAlive = false;
					}
			}
		}
	}

}
void levelTransition()
{
	if (characterAlive && menuIndex==6)
	{
		menuIndex = 10;
		characterAlive = false;
	}
	
	
}

void bullet()
{
	if (shot)
	{
		bulletCoordinateX = characterCoordinateX + 320;
		for (int i = 0; i < screenWidth; i++)
		{
			bulletCoordinateX += 40;
			if (enemy1[i].ex < bulletCoordinateX && !(characterCoordinateX < enemy2[i].ex))
			{
				enemy1[i].enemyShow = false;
				scoring += 50;
				break;
			}
		}
		shot = false;
	}
	if (shot2)
	{
		bullet2CoordinateX = characterCoordinateX - 76;
		for (int i = 0; i < screenWidth; i++)
		{
			bullet2CoordinateX -= 40;
			if (enemy2[i].ex + 200 > bullet2CoordinateX && !(characterCoordinateX > enemy2[i].ex + 200))
			{
				enemy2[i].enemyShow = false;
				scoring += 50;
				break;
			}
			
		}
		shot2 = false;
	}
}

/*void setRock()
{


	for (int i = 0; i < rockNumber; i++)
	{
		r[i].cX = rand() % screenWidth;
		r[i].cY = 0 - rand() % 1000;

		r[i].rockshow = true;
		r[i].rockup = true;

	}
}
void rockMovement()
{
	for (int i = 0; i < rockNumber; i++)
	{
		if (r[i].rockup && r[i].rockshow)
		{
			r[i].cY += 64;
			if (r[i].cY >= screenWidth)
			{
				r[i].cY = 0 - rand() % 1000;

			}

		}

	}

}*/

/*void positionf()
{
	int i, j;
	for (i = 0, j = 0; i < 12; i++)
	{
		position[i] = j;
		j += 64;
	}
}
void lifeIndicator1()
{
	if (menuIndex == 9)
	{
		for (int i = 0; i < rockNumber; i++)
		{
			if (r[i].cY + 100 > fallingCharacterY && r[i].cX > fallingCharacterX && r[i].cX < fallingCharacterX + 200 && r[i].cY < fallingCharacterY)
			{
				lifeBarIndex1++;
				if (lifeBarIndex1 >= 10)
				{
					menuIndex = 7;
				}
			}
		}
	}

}
void lifeIndicator2()
{
	if (menuIndex == 9)
	{
		lifeBarIndex2++;
		if (lifeBarIndex2 >= 10)
		{
			menuIndex = 10;
		}
	}
}*/



int main()
{
	iSetTimer(25, enemyAttack);
	iSetTimer(25, changemovement);
	iSetTimer(1000, lifeIndicator);
	//iSetTimer(25, lifeIndicator1);
	//iSetTimer(4000, lifeIndicator2);
	iSetTimer(1000, lifeIndicator3);
	iSetTimer(40000, levelTransition);
	iSetTimer(25, bullet);
	//positionf();
	//setRock();
	//iSetTimer(40, rockMovement);
	//iSetTimer(500, idleAndWind);
	
	setEnemy1();
	setEnemy2();

	if (musicOn)
	{
		PlaySound("music\\PLAY SOUND 1.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	//for Idle animation.

	iInitialize(screenWidth, screenHeight, "Kingdom of Asmodeus");

	iStart();
	return 0;
}