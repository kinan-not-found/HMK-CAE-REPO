#include <iostream>
#include <math.h>
class compute {
private:
	float x1, x2;
public:
	void calculate(int, int, int);
	void print();
	friend void fr(compute);
};
void compute::calculate(int a, int b, int c)
{
	float delta;
	delta = b * b - 4.0 * a * c;
	if (delta < 0)
	{
		x1 = x2 = 0;
	}
	else
	{
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
	}
}
void compute::print()
{
	std::cout << "x1 = " << x1 << std::endl;
	std::cout << "x2 = " << x2 << std::endl;
}
void fr(compute eq)
{
	float z;
	z = (eq.x1 + eq.x2) / 15;
	std::cout << "z = (x1 + x2) / 15 = " << z << std::endl;
}
int main()
{
	int a, b, c;
	compute ob;
	std::cout << "ax^2 + bx + c = 0" << std::endl;
	std::cout << "Enter a, b, and c : ";
	std::cin >> a >> b >> c;
	ob.calculate(a, b, c);
	ob.print();
	fr(ob);
}