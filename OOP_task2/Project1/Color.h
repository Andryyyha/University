#pragma once
#include"Decor.h"
#include<string>

class Color : public Decor
{
public:
	Color();
	std::string getColor();//�������/�������
	void setColor(std::string color);
	void setColor();
protected:
	std::string color;//���� ������
};