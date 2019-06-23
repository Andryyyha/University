#pragma once
#include<string>
#include<vector>
#include<list>
#include<time.h>


struct Time
{
	int hour;
	int min;
};

class Request //����� ������
{
public:
	Request();
	Request(int from, int to, int hb, int mb, int he, int me);
	int getFrom(); //������ ��� �������� ������ �����������
	int getTo(); //������ ��� �������� ������ ��������
	int getHB(); //������ ��� �������� ���� ������ ����������
	int getMB(); //������ ��� �������� ����� ������ ����������
	int getHE(); //������ ��� �������� ���� ��������� ����������
	int getME(); //������ ��� �������� ������ ��������� ����������
private:
	int from; //������
	int to; //����
	Time tb; //����� ������ ���������
	Time te; //����� ����� ����������
};

class Courier //����� ������
{
public:
	Courier();
private:
};

class Office //����� ������� �����
{
public:
	Office(int number); //����������� 
	int getNumber(); //������� ������ �����
	bool getStatus(); //�������� ������� ������� � �����
	void setCourier(Courier c); //������������ ������� � ����� � ������ �������� ���
private:
	std::vector<Courier> cour; //������ �������� � �����
	int number; //������ �����
	bool courAvailable; //����������� �������
};

class Controller //����� ���������
{
public:
	Controller();
	int random(int mix, int max); //������� ������������ ���������� ��� �������������
	void createRequest(Request request); //��������� ������ � ����� ������
	void Work(int n, int m, int gen); //����� ����������� �������������
	bool availableCour(int n, int from); //������� ������� ������� � ���������� �����
	void generate(int gen, int n, int i); //�������� ������ � ������� ����
	int getDim(); //���������� ����������� ������� ������
	Request getRequest(int i); //���������� ���������� ������ ��  �������
	int getTransfer();  //���������� ���������� ����� �����������  �� ������ ��������
	float getemptyTransfer(); //���������� ������� ����� ������ ���������
	float getavgTime(); //���������� ������� ����� ���������� ������
private:
	float emptyTransfer = 0; //������ �������
	int emptyCount = 0; //��������� ������  ���������
	int avgCount = 0; //���������� ���� ���������� ������ �� ������ ������ ���������
	float avgTransfer = 0; //��������� ����� ���� ���������� ������
	std::vector<Request> requests; //������ ���� ������
	std::vector<Office> offices; //������ ���� ������
};

