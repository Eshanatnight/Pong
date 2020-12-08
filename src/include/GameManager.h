#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <ctime>
#include <conio.h>

class GameManager
{
public:
	GameManager(int Width, int Height);
	~GameManager();

	void scoreUp(const Paddle* player);

private:
	int m_width, m_height;
	int m_score1, m_score2;

	char m_up1, m_down1, m_down2, m_up2;
	bool m_quit;
	Ball* ball;
	Paddle* Player1;
	Paddle* Player2;
};
