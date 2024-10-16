		#include "Vector.h"
	#include<iostream>
	#include<Windows.h>
	using namespace std;

	Vector::Vector()
	{
		arr = nullptr;
		size = 0;
	}
	Vector::Vector(int s)
	{
		cout << "Constructor by 1 params" << endl;
		size = s;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = i + 1;
		}

	}
	Vector::~Vector()
	{
		cout << "Destructor\n";
		delete[]arr;
		size = 0;
	
	}
	Vector::Vector(const Vector& obj)
	{
		cout << "Copy constructor\n";
		this->size = obj.size;
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}
	void Vector::InputRand()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand()%41 - 20; // [-20 +20]
		}
	}
	void Vector::Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << "\n---------------------------------------------------\n";
	}

	void Vector::PushBack(int a)
	{
		int* temp = new int[size + 1];  // ������ ����� ������ (��� ������ +1)

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i]; // �������� ������� �������� ������� ������� � ����� ������
		}
		temp[size] = a; // ������������� ���������� �������� ���������� ������

		delete[] arr; // �������� ������� �������!

		arr = temp; // �������������� ��������� � ������� �� ����� ���. ������
		size++;

	}

	int Vector::PopBack()
	{
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = arr[i];
		}
		int el = arr[size - 1]; // ������� ��������� ������� ������� ������� �� ��������

		delete[] arr;
		arr = temp;
		size--;

		return el;
	}

	Vector Vector::operator- (int a)
	{
		Vector rez(size - a); // 5 - 2 = 3
		for (int i = 0; i < rez.size; i++)
		{
			rez.arr[i] = this->arr[i];
		}
		return rez;
	}

	Vector& Vector::operator++()
	{
		int* temp = new int[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = 0;
		delete[] arr;
		arr = temp;
		size++;
		return *this;
	}

	Vector& Vector::operator++(int)
	{
		int* tarr = new int[size + 1];

		Vector v(*this);
		for (int i = 0; i < size; i++) {
			tarr[i] = arr[i];
		}
		tarr[size] = 0;
		delete[] arr;
		arr = tarr;
		size++;

		return v;

	}

	Vector& Vector::operator--(int)
	{
		int* tarr = new int[size - 1];
		Vector v(*this);
		for (int i = 0; i < size; i++) {
			tarr[i] = arr[i];
		}
		delete[] arr;
		arr = tarr;
		size--;
		return v;
	
	}


	Vector& Vector::operator--()
	{
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		size--;
		return *this;
	}

	Vector& Vector::operator=(const Vector& obj)
	{
		if (this == &obj) {
			return *this;
		}
		if (arr != nullptr) {
			delete[] arr;
		}
		size = obj.size;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
		return *this;

	}

	Vector& Vector::operator*=(int a)
	{
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
			temp[i] = temp[i] * a;
		}
		delete[] arr;
		arr = temp;
		return *this;
	}


