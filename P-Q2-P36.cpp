#include <iostream>
#include <string>
class date {
private:
	int day, month, year;
public:
	date();
	date(int, int, int);
	void setdate(int, int, int);
	void printdate() const;
};
date::date()
{
	day = month = 1;
	year = 2013;
}
date::date(int y, int m, int d)
{
	day = d;
	month = m;
	year = y;
}
void date::setdate(int y, int m, int d)
{
	day = d;
	month = m;
	year = y;
}
void date::printdate() const
{
	std::cout << year << "\\" << month << "\\" << day << std::endl;
}
class person {
private:
	static int count;
public:
	std::string name;
	date personsDate;
	person();
	void printp();
	void getcount() const;
	~person();
};
person::person()
{
	name = '\0';
	count++;
}
void person::printp()
{
	std::cout << "name : " << name << std::endl;
	std::cout << "date : ";
	personsDate.printdate();
}
void person::getcount() const
{
	std::cout << "count : " << count << std::endl;
}
person::~person()
{
	std::cout << "count : " << --count << std::endl;
}
int person::count = 0;
int main()
{
	person Ahmad;
	Ahmad.name = "Ahmad";
	Ahmad.personsDate.setdate(1990, 1, 1);
	Ahmad.printp();
	Ahmad.getcount();
	std::cout << "------------------------------------" << std::endl;
	person Ali;
	Ali.name = "Ali";
	Ali.personsDate.setdate(1980, 2, 1);
	Ali.printp();
	Ali.getcount();
	std::cout << "------------------------------------" << std::endl;
}