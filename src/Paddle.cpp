#include "Paddle.h"

Paddle::Paddle()
	: m_x(0), m_y(0), m_Originalx(0), m_Originaly(0)
{
}

Paddle::Paddle(int posX, int posY)
	: m_Originalx(posX), m_Originaly(posY), m_x(posX), m_y(posY)
{}

void Paddle::Reset()
{
	m_x = m_Originalx;
	m_y = m_Originaly;
}

 int Paddle::getX() const
{
	return m_x;
}

 int Paddle::getY() const
{
	return m_y;
}

void Paddle::moveUp()
{
	m_y--;
}

void Paddle::moveDown()
{
	m_y++;
}

// ostream operator overload for debug purposes
std::ostream& operator<<(std::ostream& o, const Paddle& paddle)
{
	o << "Paddle: [ X = " << paddle.m_x << " , Y = " << paddle.m_y << " ]\n";
	return o;
}