#include <iostream>
using namespace std;

//1. Develop a class that describes the essence of "Point on the plane".
//A point is defined by its coordinates and symbolic designation.
//The class must be universal(the maximum functionality of interaction with fields is described).
//2. When using the previous class, develop a class "line segment".
//The class must be generic.Provide for the possibility :
//a.calculating the length of a segment using the "!" operation;
//b.defining a line segment that combines the midpoints of two line segments(using the "&&" operation.

//1. Разработать класс, который описывает суть «Точка на плоскости».
//Точка определяется своими координатами и символьным обозначением.
//Класс должен быть универсальным(описан максально функционал взаимодействия с полями).
//2. При использовании предыдущего класса разработать класс «отрезок на плоскости».
//Класс должен быть универсальным.Предусмотреть возможность :
//a.вычисления длины отрезка с использованием операции «!»;
//b.определение отрезка, который сочетает средние точки двух отрезков(с использованием операции «&& ».


class Point {
	friend class Line;
private:
	double x;
	double y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point()
		:x{0},y{0}
	{}

	double getX() {
		return x;
	}
	void setX(double x) {
		this->x = x;
	}
	double getY() {
		return y;
	}
	void setY(double y) {
		this->y = y;
	}
	void Show() {
		cout << '(' << x << ';' << y << ')';
	}
};

class Line {
private:
	Point a;
	Point b;
public:
	double operator * (Line len) {
		return sqrt(pow(len.b.x - len.a.x, 2) + (pow(len.b.y - len.a.y, 2)));
	};

	Point findMid(Line ab) {
		return Point(((ab.a.x + ab.b.x) / 2), (ab.a.y + ab.b.y) / 2);
	}

	Line(Point a, Point b) {
		this->a = a;
		this->b = b;
	}
	Line()
		:a{0,0}, b{0,0}
	{}
	Point  getA() {
		return a;
	}
	void setA(Point a) {
		this->a = a;
	}
	Point getB() {
		return b;
	}
	void setB(Point b) {
		this->b = b;
	}
	void Show() {
		cout << '(' << a.x << ';' << a.y << ')'<<'('<<b.x<<';'<<b.y<<')';
	}
	void ShowLen(Line ab) {
		double temp= ab * ab;
		cout << temp;
	}
};
 
Line operator && (Line& ab, Line& cd) {
	Point temp1 = ab.findMid(ab);
	Point temp2 = cd.findMid(cd);
	return Line (temp1, temp2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Point a(2,9);
	cout << "Координаты точки А: ";
	a.Show();
	cout << endl;
	Point b(5,1); 
	cout << "Координаты точки B: ";
	b.Show();
	cout << endl;
	Line ab(a, b);
	cout << "Длинна отрезка АВ: ";
	ab.ShowLen(ab);
	cout << endl;
	cout << "Координаты средины отрезка АВ: ";
	ab.findMid(ab).Show();
	cout << endl;

	Point c(6, 11);
	cout << "Координаты точки C: ";
	c.Show();
	cout << endl;
	Point d(12, 3);
	cout << "Координаты точки D: ";
	d.Show();
	cout << endl;
	Line cd(c, d);
	cout << "Длинна отрезка CD: ";
	cd.ShowLen(cd);
	cout << endl;
	cout << "Координаты средины отрезка CD: ";
	cd.findMid(cd).Show();
	cout << endl;

	cout << "Координаты отрезка, который сочетает средние точки двух отрезков: ";
	Line ef = ab && cd;
	ef.Show();
	cout << endl;
	cout << "Длинна отрезка, который сочетает средние точки двух отрезков: ";
	ef.ShowLen(ef);
	cout << endl;
	cout << endl;
}

