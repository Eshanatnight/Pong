#pragma once
#include <iostream>

enum Direction
{
	STOP = 0,
	LEFT = 1,
	UPLEFT = 2,
	DOWNLEFT = 3,
	RIGHT = 4,
	UPRIGHT = 5,
	DOWNRIGHT = 6
};

class Ball
{
private:
	int m_x, m_y;
	int m_Originalx, m_Originaly;
	Direction m_direction;

public:
	Ball(int posX, int posY);
	void Reset();
	void changeDirection(Direction d);
	 int getX() const;
	 int getY() const;
	 Direction getDirection() const;
	void randomDirection();
	void Move();

	friend std::ostream& operator<<(std::ostream& o, const Ball& ball);
};
