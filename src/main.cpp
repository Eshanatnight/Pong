#include "Ball.h"
#include "Paddle.h"

int main()
{
	Paddle P1(0, 0);
	Paddle P2(10, 0);
	std::cout << P1 << P2 << std::endl;
	P1.moveUp();
	P2.moveDown();
	std::cout << P1 << P2 << std::endl;
	return 0;
}