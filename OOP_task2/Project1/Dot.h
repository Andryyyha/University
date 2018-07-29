#pragma once
#include"Figure.h"
#include"Color.h"
#include"Style.h"

class Dot : virtual public Figure, public Color, public Style
{
public:
	Dot(int x, int y);//������� �����������
	Dot(int x, int y, std::string color);//����������� ����� �� �������
	Dot();
	int getX();//�������/�������
	void setX(int x);
	int getY();
	void setY(int y);
	void print();
private:
	int x;//���������� �����
	int y;
};
