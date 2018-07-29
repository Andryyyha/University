#pragma once
#include"Figure.h"
#include"Color.h"
#include"Style.h"

class Square : virtual public Figure, public Color, public Style
{
public:
	Square(int length);//����������� ��������
	Square(int length, std::string color, std::string coloring);//����������� ��������
	Square();
	int getLength();//�������/�������
	void setLength(int length);
	int getPerimeter();//���������� �������
	int getArea();//���������� ���������
	void print();
private:
	int length;
	int width;
	int perimeter;
	int area;
};
