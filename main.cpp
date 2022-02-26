#include <iostream>
#include <time.h>
#include <curses.h>

using namespace std;
enum eDir {STOP = 0, LEFT =1,  UPLEFT = 2, DOWNLEFT =3, RIGHT = 4, UPRIGHT=5,DOWNRIGHT = 6};


class cBall 
{
private:
	int x, y; //stores position of the ball on screen
	int originalX, originalY;
	eDir direction;

public:
	cBall(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = originalX; y = originalY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;

	}
	void randomDirection()
	{
		direction = (eDir)(rand() % 6 + 1);
	}
	inline int getX() {return x;}
	inline int getY() {return y;}
	inline eDir getDirection(){return direction;}

	void Move()
	{
		switch(direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		
		case UPLEFT:
			x--;
			y--;
			break;
		case DOWNLEFT:
			x--;
			y++;
			break;
		case UPRIGHT:
			x++;
			y--;
			break;
		case DOWNRIGHT:
			x++;
			y++;
			break;
		default:
			break;
		}

	}

	friend ostream &operator<<(ostream &o, cBall c)
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction <<  "]";
		return o;
	}
};
class cPaddle
{
private:
	int  x ,y ;
	int originalX,originalY;
public:

	cPaddle(int posX, int posY) 
	{
		x = y =0;
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;

	}
	inline void Reset() {x = originalX; y = originalY;}
	inline int getX(){return x;}
	inline int getY(){return y;}
	inline void moveUP(){y--;}
	inline void moveDown(){y++;}

	friend ostream &operator<<(ostream &o, cPaddle c)
	{
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}


};

class cGameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2; // keys to be used to controll the player on the screen
	bool quit;
	cBall * ball;
	cPaddle *player1;
	cPaddle  *player2;
public:
	cGameManager(int w, int h) // constructer
	{
		srand(time(NULL));
		quit = false;
		up1 = 'w'; up2 = 'i';
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0;
		width = w; height = h;
		ball = new cBall(w/2, h/2); // place ball in the middle of the area

		player1 = new cPaddle(1,h/2-3);
		player2 = new cPaddle(w-2,h/2-3);

	}
	
	~cGameManager() // deconstructer
	{
		delete ball, player1, player2;
	}



};

int main()
{
	cPaddle p1(0,0);
	cPaddle p2(10, 0);
	cout << p1 << endl;
	cout << p2 << endl;
	p1.moveUP();
	p2.moveDown();
	cout << p1 << endl;
	cout << p2 << endl;

	return 0;
	

}