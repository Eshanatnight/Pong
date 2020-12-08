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

	ball->Reset();
	Player1->Reset();
	Player2->Reset();
}

void GameManager::Draw()
{
	system("cls");
	for (int i = 0; i < m_width + 2; i++)
		std::cout << "\xB2";
	std::cout << std::endl;

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (j == 0)
				std::cout << "\xB2";

			if (ball->getX() == j && ball->getY() == i)
				std::cout << "O";

			else if (Player1->getX() == j && Player1->getY() == i)
				std::cout << "\xDB";

			else if (Player2->getX() == j && Player2->getY() == i)
				std::cout << "\xDB";

			else if (Player1->getX() == j && Player1->getY() + 1 == i)
				std::cout << "\xDB";

			else if (Player1->getX() == j && Player1->getY() + 2 == i)
				std::cout << "\xDB";

			else if (Player1->getX() == j && Player1->getY() + 3 == i)
				std::cout << "\xDB";

			else if (Player2->getX() == j && Player2->getY() + 1 == i)
				std::cout << "\xDB";

			else if (Player2->getX() == j && Player2->getY() + 2 == i)
				std::cout << "\xDB";

			else if (Player2->getX() == j && Player2->getY() + 3 == i)
				std::cout << "\xDB";

			else
				std::cout << " ";

			if (j == m_width - 1)
				std::cout << "\xB2";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < m_width + 2; i++)
		std::cout << "\xB2";
	std::cout << std::endl;

	std::cout << "[ Score 1: " << m_score1 << " ]\t\t[ Score 2: " << m_score2 << " ]" << std::endl;
}

void GameManager::Input()
{
	ball->Move();

	if (_kbhit())
	{
		char current = _getch();
		if (current == m_up1)
			if (Player1->getY() > 0)
				Player1->moveUp();

		if (current == m_up2)
			if (Player2->getY() > 0)
				Player2->moveUp();

		if (current == m_down1)
			if (Player1->getY() + 4, m_height)
				Player1->moveDown();

		if (current == m_down2)
			if (Player2->getY() + 4, m_height)
				Player2->moveDown();

		if (ball->getDirection() == STOP)
			ball->randomDirection();

		if (current == 'q')
			m_quit = true;
	}
}

void GameManager::Logic()
{
	/* Left paddle */
	for (int i = 0; i < 4; i++)
		if (ball->getX() == Player1->getX() + 1)
			if (ball->getY() == Player1->getY() + i)
				ball->changeDirection((Direction)((rand() % 3) + 4));

	/* right paddle */
	for (int i = 0; i < 4; i++)
		if (ball->getX() == Player2->getX() - 1)
			if (ball->getY() == Player2->getY() + i)
				ball->changeDirection((Direction)((rand() % 3) + 1));

	/* Bottom Wall */
	if (ball->getY() == m_height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

	/* Top Wall */
	if (ball->getY() == m_height - 1)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

	/* Right Wall */
	if (ball->getX() == m_width - 1)
		scoreUp(Player1);

	/* Left Wall */
	if (ball->getX() == 0)
		scoreUp(Player2);
}

void GameManager::Run()
{
	while (!m_quit)
	{
		Draw();
		Input();
		Logic();
	}
}