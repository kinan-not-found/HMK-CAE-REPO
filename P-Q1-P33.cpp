#include <iostream>
class myclass2;
class myclass1 {
private:
	double avarage1;
public:
	myclass1();
	void setAvarage1(double*, int);
	~myclass1();
	friend void fCompare(myclass1, myclass2);
};
class myclass2 {
private:
	double avarage2;
public:
	myclass2();
	void setAvarage2(double*, int);
	~myclass2();
	friend void fCompare(myclass1, myclass2);
};
myclass1::myclass1()
{
	avarage1 = 0.0;
}
void myclass1::setAvarage1(double* array, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += *(array + i);
	avarage1 = sum / size;
	std::cout << "avarage1 = " << avarage1 << std::endl;
}
myclass1::~myclass1()
{
	std::cout << "distructing..." << std::endl;
}
myclass2::myclass2()
{
	avarage2 = 0.0;
}
void myclass2::setAvarage2(double* array, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += *(array + i);
	avarage2 = sum / size;
	std::cout << "avarage2 = " << avarage2 << std::endl;
}
myclass2::~myclass2()
{
	std::cout << "distructing..." << std::endl;
}
void fCompare(myclass1 ob1, myclass2 ob2)
{
	if (ob1.avarage1 >= ob2.avarage2)
		std::cout << "max = " << ob1.avarage1 << std::endl;
	else
		std::cout << "max = " << ob2.avarage2 << std::endl;
}
int main()
{
	double a[5], b[5];
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "a[" << i << "] = ";
		std::cin >> a[i];
	}
	std::cout << "==========================================================" << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "b[" << i << "] = ";
		std::cin >> b[i];
	}
	myclass1 ob1;
	myclass2 ob2;
	ob1.setAvarage1(a, 5);
	ob2.setAvarage2(b, 5);
	fCompare(ob1, ob2);
}