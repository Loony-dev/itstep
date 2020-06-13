#include <iostream>

class Point
{
	double x;
	double y;

public:
	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}

	void setX(double x)
	{
		this->x = x;
	}

	void setY(double y)
	{
		this->y = y;
	}

	Point()
	{
		x = y = double();
		std::cout << "Constructor " << this << std::endl;
	}

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		std::cout << "Constructor " << this << std::endl;
	}

	~Point()
	{
		std::cout << "Destructor " << this << std::endl;
	}

	void print() const
	{
		std::cout << x << "\t" << y << std::endl;
	}
};

void main()
{
	using namespace std;
	setlocale(LC_ALL, "");

	Point A;

	A.setX(2);
	A.setY(A.getX() * 5);
	cout << A.getX() << "\t" << A.getY() << endl;

	cout << "-----------------------------" << endl;

	Point B(4, 5);
	B.print();
}

//void main()
//{
//	using namespace std;
//	setlocale(LC_ALL, "");
//
//	Point A;
//
//	A.x = 1;
//	A.y = 2;
//
//	cout << A.x << "\t" << A.y << endl;
//
//	Point* pA = &A;
//	cout << pA->x << "\t" << pA->y << endl;
//	cout << (*pA).x << "\t" << (*pA).y << endl;
//}