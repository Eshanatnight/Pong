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
	~Ball();
	void Reset();
	void changeDirection(Direction d);
	inline int getX() const;
	inline int getY() const;
	inline Direction getDirection() const;
	void randomDirection();
	void Move();

	friend std::ostream& operator<<(std::ostream& o, const Ball& ball);
};

Ball::Ball(int posX, int posY)
	: m_Originalx(posX), m_Originaly(posY), m_x(posX), m_y(posY), m_direction(STOP)
{
}

Ball::~Ball()
{
}

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

int main()
{
	return 0;
}

std::ostream& operator<<(std::ostream& o, const Ball& ball)
{
	o << "Ball: [ X = " << ball.m_x << " , Y = " << ball.m_y << " ] [ Direction: " << ball.m_direction << " ]\n";
}