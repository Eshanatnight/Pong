#include "Ball.h"

int main()
{
	Ball b(0, 0);
	std::cout << b << std::endl;
	b.randomDirection();
	std::cout << b << std::endl;
	b.Move();
	std::cout << b << std::endl;
	b.randomDirection();
	b.Move();
	std::cout << b << std::endl;
	b.randomDirection();
	b.Move();
	std::cout << b << std::endl;
	return 0;
}


