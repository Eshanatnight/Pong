// #include "Ball.h"
#include "include/Ball.h"

Ball::Ball(int posX, int posY)
	: m_Originalx(posX), m_Originaly(posY), m_x(posX), m_y(posY), m_direction(STOP)
{}


void Ball::Reset()
{
	m_x = m_Originalx;
	m_y = m_Originaly;
	m_direction = STOP;
}

void Ball::changeDirection(Direction d)
{
	m_direction = d;
}

inline int Ball::getX() const
{
	return m_x;
}

inline int Ball::getY() const
{
	return m_y;
}

inline Direction Ball::getDirection() const
{
	return m_direction;
}

void Ball::randomDirection()
{
	m_direction = (Direction)((rand() % 6) + 1);
}

void Ball::Move()
{
	switch (m_direction)
	{
	case STOP:
		break;

	case LEFT:
		m_x--;
		break;

	case UPLEFT:
	{
		m_x--;
		m_y--;
		break;
	}

	case DOWNLEFT:
	{
		m_x--;
		m_y++;
		break;
	}

	case RIGHT:
		m_x++;
		break;

	case UPRIGHT:
	{
		m_x++;
		m_y--;
		break;
	}

	case DOWNRIGHT:
	{
		m_x++;
		m_y++;
		break;
	}

	default:
		break;
	}
}


// ostream operator overload for debug purposes
std::ostream &operator<<(std::ostream &o, const Ball &ball)
{
	o << "Ball: [ X = " << ball.m_x << " , Y = " << ball.m_y << " ] [ Direction: " << ball.m_direction << " ]\n";
	return o;
}
