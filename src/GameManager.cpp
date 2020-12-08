#include "GameManager.h"

GameManager::GameManager(int Width, int Height)
	: m_quit(false), m_height(Height), m_width(Width), m_up1('w'), m_up2('i'), m_down1('s'), m_down2('k'), m_score1(0), m_score2(0)
{
	srand(time(NULL));
	ball = new Ball(Width / 2, Height / 2);
	Player1 = new Paddle(1, Height / 2 - 3);
	Player2 = new Paddle(Width - 2, Height / 2 - 3);
}

GameManager::~GameManager()
{
	delete ball, Player1, Player2;
}

void GameManager::scoreUp(const Paddle* player)
{
	if (player == Player1)
		m_score1++;
	else if (player == Player2)
		m_score2++;

	else
		std::cout << "Error [ GameManager.cpp, line 25 ]\n";

	this->ball->Reset();
    this->Player1->Reset();
    this->Player2->Reset();

}
