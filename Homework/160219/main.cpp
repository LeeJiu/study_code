#include "B.h"

int main(void)
{
	B * b = new B();
	A * a = b;

	a->Print();

	return 0;
}