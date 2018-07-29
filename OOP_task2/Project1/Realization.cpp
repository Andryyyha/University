#include"Figure.h"
#include"Color.h"
#include"Style.h"
#include"Circle.h"
#include"Dot.h"
#include"Square.h"
#include"Liast.h"
#include<list>
#include<iostream>

//���������� ������� ���� �������

Figure::Figure()
{

}

Color::Color()
{

}

std::string Color::getColor()
{
	return color;
}

void Color::setColor(std::string color)
{
	this->color = color;
}

void Color::setColor()
{
	int k;
	std::cout << "������� ����\n 1 - ������ \n 2 - �����\n 3 - �������\n";
	std::cin >> k;
	switch (k)
	{
	case 1:
		this->color = "������";
		break;
	case 2:
		this->color = "�����";
		break;
	case 3:
		this->color = "�������";
		break;
	default:
		std::cout << "����������� ������� ������\n";
		break;
	}
}

Style::Style()
{

}


std::string Style::getColoring()
{
	return coloring;
}

void Style::setColoring()
{
	int k;
	std::cout << "������� ����\n 1 - �������� \n 2 - ���������\n 3 - ���������\n";
	std::cin >> k;
	switch (k)
	{
	case 1:
		this->coloring = "��������";
		break;
	case 2:
		this->coloring = "���������";
		break;
	case 3:
		this->coloring = "���������";
		break;
	default:
		std::cout << "����������� ������� ������";
		break;
	}
}


void Style::setColoring(std::string coloring)
{
	this->coloring = coloring;
}

Decor::Decor()
{

}

Circle::Circle(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
	std::cout << "��� ���� � ������� � ����� " << x << "," << y << " � �������� " << radius << std::endl;
}

Circle::Circle(int x, int y, int radius, std::string color, std::string coloring)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->color = color;
	this->coloring = coloring;
	std::cout << "��� " << color << " " << coloring << " ���� � ������� � ����� " << x << "," << y << " � �������� " << radius << std::endl;
}

Circle::Circle()
{

}

int Circle::getX()
{
	return x;
}

void Circle::setX(int x)
{
	this->x = x;
}

int Circle::getY()
{
	return y;
}

void Circle::setY(int y)
{
	this->y = y;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(int radius)
{
	this->radius = radius;
}

double Circle::getPerimeter()
{
	int radius = this->radius;
	return 2 * 3.14 * radius;
}

double Circle::getArea()
{
	int radius = this->radius;
	return 3.14 * (radius * radius);
}

void Circle::print()
{
	std::cout << "��� " << this->color << " " << this->coloring << " ���� � ������� � ����� " << this->x << "," << this->y << " � �������� " << this->radius << std::endl;
}

Dot::Dot(int x, int y)
{
	this->x = x;
	this->y = y;
	std::cout << "��� ����� � ������������ " << x << "," << y << std::endl;
}

Dot::Dot(int x, int y, std::string color)
{
	this->x = x;
	this->y = y;
	this->color = color;
	std::cout << "��� " << color << " ����� � ������������ " << x << "," << y << std::endl;
}

Dot::Dot()
{

}

int Dot::getX()
{
	return x;
}

void Dot::setX(int x)
{
	this->x = x;
}

int Dot::getY()
{
	return y;
}

void Dot::setY(int y)
{
	this->y = y;
}

void Dot::print()
{
	std::cout << "��� " << this->color << " ����� � ������������ " << this->x << "," << this->y << std::endl;
}

Square::Square(int length)
{
	this->length = length;
	this->width = width;
	std::cout << "��� ������� � �������� " << length << std::endl;
}

Square::Square(int length, std::string color, std::string coloring)
{
	this->length = length;
	this->width = width;
	this->color = color;
	this->coloring = coloring;
	std::cout << "��� " << coloring << " " << color << " ������� � �������� " << length << std::endl;
}

Square::Square()
{

}

int Square::getLength()
{
	return length;
}

void Square::setLength(int length)
{
	this->length = length;
}
int Square::getPerimeter()
{
	int length = this->length;
	return (length + length) * 2;
}

int Square::getArea()
{
	int length = this->length;
	return length * length;
}

void Square::print()
{
	std::cout << "��� " << this->coloring << " " << this->color << " ������� � �������� " << this->length << std::endl;  
}


void List::push(Circle *x)
{
		node *r = new node;
		
		r->inf = x;

		r->next = NULL;

		if (!head && !tail) {

			r->prev = NULL;

			head = r;

		}

		else {

			tail->next = r;

			r->prev = tail;

		}

		tail = r;
		r->inf1 = nullptr;
		r->inf2 = nullptr;
}

void List::push(Square *x)
{
	node *r = new node;

	r->inf1 = x;

	r->next = NULL;

	if (!head && !tail) {

		r->prev = NULL;

		head = r;

	}

	else {

		tail->next = r;

		r->prev = tail;

	}

	tail = r;
	r->inf = nullptr;
	r->inf2 = nullptr;
}

void List::push(Dot *x)
{
	node *r = new node;

	r->inf2 = x;

	r->next = NULL;

	if (!head && !tail) {

		r->prev = NULL;

		head = r;

	}

	else {

		tail->next = r;

		r->prev = tail;

	}

	tail = r;
	r->inf = nullptr;
	r->inf1 = nullptr;
}

void List::print()

{

	node *r = head;

	while (r != NULL) {
		if (r->inf != nullptr)
		{
			r->inf->print();
			cout << '\n';
			r = r->next;
		}
		else if (r->inf1 != nullptr)
		{
			r->inf1->print();
			cout << '\n';
			r = r->next;
		}
		else
		{
			r->inf2->print();
			cout << '\n';
			r = r->next;
		}
	}



}

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "���������� �������� ���������\n �����\n ������\n �������\n";
	std::cout << "��������� �������� �����(������� ���y��)\n ��������\n ���������\n ����������\n";
	Circle *new1 = new Circle(0, 0, 4, "�������", "��������");
	Circle *new2 = new Circle(0, 0, 8, "�����","���������");
	Dot *new3 = new Dot(4, 6, "������");
	Square *new4 = new Square(4,"�������","��������");
	Circle *test = new Circle(0,0,2,"","");
	List *tmp = new List();
	tmp->push(new1);
	tmp->push(new2);
	tmp->push(new3);
	tmp->push(new4);
	cout << "������\n";
	tmp->print();
	system("pause");
	return 0;
}