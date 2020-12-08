#pragma once
#include <iostream>

class Paddle
{
public:
	Paddle();
	Paddle(int posX, int posY);

	void Reset();
	 int getX() const;
	 int getY() const;
	void moveUp();
	void moveDown();

	friend std::ostream& operator<<(std::ostream& o, const Paddle& paddle);

private:
	int m_x, m_y;
	int m_Originalx, m_Originaly;
};
