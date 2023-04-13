#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <Windows.h>
#include<memory>
using namespace std;


class Human
{//������ ������ ������������� �����������
public:

	Human(string Name) 
	{
		this->name = name;
		this->age = 0;
		this->weight = 0;
	}

	Human(string Name, int Age):Human(Name)
	{
		this->age = age;
	}

	Human(string Name, int Age, int Weight):Human(Name, Age)
	{
		this->weight = weight;
	}
	int age;
	int weight;
	string name;
	//void print()
	//{
	//	cout << "���" << " " << name << endl << "�������" << " " << age << endl << "���" << " " << weight;
	//}
};


class Point
{
private:
	int x;
	int y;

public:

	//����������� ������������� �������
	friend void ChangeX(Point& value);

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int valueX, int valueY) 
	{
		x = valueX;
		y = valueY;
	}

	int GetY()
	{
		return y;
	}

	int SetY(int y)
	{
		this->y = y;
		return 0;
	}

	int GetX() 
	{
		return x;
	}

	int SetX(int valueX) 
	{
		x = valueX;
		return 0;
	}



	//���������� �������� ���������
	bool operator == (const Point & other)
	{
		return this->x == other.x && this->y == other.y;
	}

	//���������� �������� �����������
	bool operator != (const Point & other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	//���������� ��������� ��������
	Point operator + (const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	//���������� ��������� ����������/���������� / �������
	Point& operator ++ ()
	{
		this->x++;//--
		this->y++;//--
		return *this;
	}

	//���������� ��������� ����������/���������� / ��������
	Point& operator ++(int value)
	{
		Point temp(*this);
		this->x++;//--
		this->y++;//--
		return temp;
	}



	void Print() 
	{
		cout << "X =\t" << x << " Y =\t" << y<<endl;
	}
};

class CoffeeGrinder
{
public:
	void Start() 
	{
		if (CheckVoltage()) 
		{
			cout << "VjuHHHH!!!!!!"<<endl;
		}
		else
		{	
			cout << "Beep Beep"<<endl;
		}
	}

private:
	bool CheckVoltage() {
		return false;
	}
};


class MyClass
{
public:

	//����������� ������ ��� ������
	void PrintMessage();

	//����������� �� ���������
	MyClass()
	{

	}

	MyClass(int size)
	{
		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++) 
		{
			data[i] = i;
		}
		cout << "������ " << data << " �������� ����������� " <<this<< endl;

	};
	//����������� �����������
	MyClass(const MyClass &other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout <<"�������� ����������� ����������� " << this << endl;

	};

	//���������� ��������� ������������
	MyClass & operator = (const MyClass &other)
	{
		cout << "�������� �������� = " << this << endl;

		if (this->data != nullptr) 
		{
			delete[] this->data;
		}

		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}

		return *this;
	}

	//����������
	~MyClass()
	{
		delete[] data;
		cout << "������ " << data << " �������� ����������"<< this << endl;
	};

private:
	int* data;
	int Size;
};

//����� ������������ ��� ������
void MyClass::PrintMessage()
{
	cout << "Hello!";
}


class TestClass
{
public:
	//���������� ��������� ��������������
	int& operator [](int index)
	{
		return arr[index];
	}

private:
	int arr[5]{ 5, 22, 543, 123, 12 };
};



class Saler;
class Apple;

class Saler
{
public:
	void TakeApple(Apple &apple);

private:

};

class Apple
{
public:
	

	//����������� �������������� ������
	friend Saler;
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;
		id = Count;
	};

	//��������� ID ��� ������� ������
	int GenID()
	{
		return id;
	}

	//�������� STATIC ������
	static int GetCount()
	{
		return Count;
	}

	//����������� �������������� ������ ������ SALER
	//friend void Saler::TakeApple(Apple& apple);
private:
	int weight;
	string color;
	int id;
	//�������� STATIC-����������
	static int Count;
};

//������ � ��������� �������
class Image
{
public:
	void GetImageINFO()
	{
		for (int i = 0; i < length; i++)
		{
			cout<<pixels[i].GetINFO()<<endl;
		}
	}

private:
	//��������� �����
	class Pixel
	{
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		};

		string GetINFO()
		{
			return "Pixel r - " + to_string(r) + " g - " + to_string(g) + " b " + to_string(b);
		}

	private:
		int r;
		int g;
		int b;
	};

	//������ ������ ������� �������� ������
	static const int length = 5;
	Pixel pixels[length]{
		Pixel(4, 6, 2),
		Pixel(23, 123, 32),
		Pixel(442, 423, 324),
		Pixel(465, 324, 342),
		Pixel(423, 656, 23),
	};
	
};


//������ ���������
class Cap
{
public:
	string GetColor()
	{
		return color;
	}

private:
	string color = "red";
};

//������ ����������
class People
{
public:
	void think()
	{
		brain.think();
	}

	void InspectTheCap()
	{
		cout << "��� ����� " << cap.GetColor() << " �����";
	}

private:
	class Brain
	{
	public:
		void think()
		{
			cout << "� �����!" << endl;
		}


	};
	Brain brain;
	Cap cap;
};



//������������� STATIC ����������
int Apple::Count = 0;

//������������� �������
void ChangeX(Point& value)
{
	value.x = -1;
}

void Foo()
{
	cout << "����� ������������" << endl;
	MyClass a(5);
	cout << "����� �����������" << endl;
}

//������ ������������
class Peoples
{
public:
	string name;
};
class Student : public Peoples
{
public:
	string group;

	void learn()
	{
		cout << "� �����!" << endl;
	}
};
class Professor : public Peoples
{
public:
	string subject;
};
class ExtramuralStudent : public Student
{
public:
	void learn()
	{
		cout << "� ����� �� ������� �����������" << endl;
	}
};

//������ ������������� ������� ��� ������������
class A
{
public:
	string msgOne = "��������� ����";

private:
	string msgTwo = "��������� ���";
protected:
	string msgThree = "��������� ���";
};
class B : public A
{
public:
	void PrintMsg()
	{
		cout << msgOne << endl;
	}

};

//����������� �����
class Weapon
{
public:
	//����� ����������� �������
	virtual void Shoot() = 0;
};


//�����������, VIRTUAL, OVERRIDE
class Gun : public Weapon
{
public:
	virtual void Shoot() override
	{
		cout << "BANG" << endl;
	}

};
class SubmachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "BANG BANG BANG BANG" << endl;
	}

};
class Knife: public Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUHH" << endl;
	}

};
class Player
{
public:
	void Shoot(Weapon *weapon) 
	{
		weapon->Shoot();
	}

};

//������ ������ ������������ �����������
class PA
{
public:
	PA() 
	{
		cout << "�������� ������������ ������ ������������ ������ PA" << endl;
	};
	virtual ~PA()
	{
		
		cout << "����������� ������������ ������ ������������ ������ PA" << endl;
		
	};

};
class PB : public PA
{
public:
	PB()
	{
		cout << "�������� ������������ ������ ������������ ������ PB" << endl;
	};
	~PB() override
	{

		cout << "����������� ������������ ������ ������������ ������ PB" << endl;

	};

};


//����� ������������ ������ �������� ������
class Msg
{
public:
	Msg(string msg)
	{
		this->msg = msg;
	};
	
	virtual string GetMsg() 
	{
		return msg;
	}

private:
	string msg;
};
class BracketsMsg: public Msg
{
public:
	BracketsMsg(string msg):Msg(msg)
	{

	};
	string GetMsg() override
	{
		return "[" + Msg::GetMsg() + "]";
	}

};
class Printer
{
public:
	void Print(Msg *msg) 
	{
		cout << msg->GetMsg() << endl;
	}


};

//������ �������������� ������������/���������� ������
class Car
{
public:
	void USE()
	{
		cout << "� ���!" << endl;
	}
};
class Airplain
{
public:
	void USE()
	{
		cout << "� ����!" << endl;
	}
};
class Flyingcar :public Car, public Airplain
{
public:

};

//������ ����������
class IBicycle
{
public:
	void virtual TwistTheWhell() = 0;
	void virtual Ride() = 0;
};
class SimpleBicycle:public IBicycle
{
public:
	void TwistTheWhell() override
	{
		cout << "����� TwistTheWhell SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "����� Ride SimpleBicycle" << endl;
	}

};
class SportBicycle :public IBicycle
{
public:
	void TwistTheWhell() override
	{
		cout << "����� TwistTheWhell SportBicycle" << endl;
	}
	void Ride() override
	{
		cout << "����� Ride SportBicycle" << endl;
	}

};
class Bicyclist
{
public:
	
	void RideOn(IBicycle& bicycle)
	{
		cout << "������ ����" << endl;
		bicycle.TwistTheWhell();
		cout << "�������" << endl;
		bicycle.Ride();
	}
};

//������ ������������ ������������/������������
class Character
{
public:
	Character()
	{
		cout << "����������� ������ Character" << endl;
	};
	
	int HP;
};
class Orc: public virtual Character
{
public:
	Orc()
	{
		cout << "����������� ������ Orc" << endl;
	};

};
class Warrior : public virtual Character
{
public:
	Warrior()
	{
		cout << "����������� ������ Warrior" << endl;
	};

};
class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "����������� ������ OrcWarrior" << endl;
	};

};

//������ � ������ �� ����� ������� ������
class Points
{
public:
	Points()
	{
		x = y = z = 0;
	};
	void Print()
	{
		cout << "X " << x << "\tY " << y << "\tZ " << z << endl;
	}
	Points(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	int x;
	int y;
	int z;
};

//���� ����� EXCEPTION
class Myexception:public exception
{
public:
	Myexception(const char *msg, int data) :exception(msg)
	{
		this->data = data;
	};
	int GetData() 
	{
		return data;
	}

private:
	int data;
};


//������������� ��� ENUM
class PC
{
public:
	enum PCState
	{
		ON,
		OFF,
		SLEEP
	};
	PCState GetSatate() 
	{
		return State;
	}

	void SetState(PCState State)
	{
		this->State = State;
	}

private:
	PCState State;
};



//��������� ����������
void Test(int value)
{
	if (value <0)
	{
		throw exception("���������� < 0!");
	}
	if (value==1)
	{
		throw Myexception("���������� = 1!",value);
	}
	
	//if (value == 1)
	//{
	//	throw 1;
	//}
	cout << "���������� = " << value << endl;
}

//������������� ������������ ����
namespace firstNS
{
	void Foo()
	{
		cout << "First NS" << endl;
	}
}
namespace secondNS
{
	void Foo()
	{
		cout << "Second NS" << endl;
	}
}

//������ �������
template<typename T>
class Pattern
{
public:
	Pattern(T value)
	{
		this->value = value;
	};
	void DataTypeSize()
	{
		cout << "Value " << sizeof(value) << endl;
	}

private:
	T value;
};

//����� ���������
template<typename T>
class SmartPointer
{
public:
	SmartPointer(T*ptr)
	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	};
	~SmartPointer() 
	{
		delete ptr;
		cout << "Distructor" << endl;
	};

	T& operator*()
	{
		return *ptr;
	}

private:
	T* ptr;
};


int main() 
{
	setlocale(LC_ALL, "ru");
	//Human firstguman;
	//firstguman.age = 22;
	//firstguman.name = "����";
	//firstguman.weight = 75;
	//firstguman.print();

	//Point a;
	//a.SetX(5);
	//a.GetX();
	//a.SetY(11);
	//a.GetY();
	//a.Print();

	//CoffeeGrinder c;
	//c.Start();
	
	//Point a(5,44);
	//a.Print();
	//Point b(23, 77);
	//b.Print();

	//Foo();

	//Point a;
	//a.SetY(5);
	//a.Print();

	//�������� �����������
	//MyClass a(10);
	//MyClass b(a);

	//�������� ������������
	//MyClass a(10);
	//MyClass b(3);
	//MyClass c(1);
	//c = a = b;

	//�������� ���������/�����������
	//Point a(4, 2);
	//Point b(7, 6);
	//bool result = a == b;

	//�������� ��������
	//Point a(4, 2);
	//Point b(2, 6);
	//Point c = a + b;

	//�������� ���������� ����������, ����������
	//Point a(2, 2);
	//Point b;
	//b = a++;

	//���������� ��������� ��������������
	//TestClass a;
	//cout << a[1] << endl;

	//����� ������������� ������� ��� ������ Point
	//Point a(33, 12);
	//a.Print();
	//ChangeX(a);
	//a.Print();

	//����� ������ ��� ������
	//MyClass a;
	//a.PrintMessage();

	//��������� ��� �������������� ������ ������ / �������������� ������
	//Apple apple(200,"Green");
	//Saler human;
	//human.TakeApple(apple);

	//������ �� sttic ����������
	//Apple apple1(200, "Red");
	//Apple apple2(150, "Green");
	//cout << Apple::Count << endl;

	//��������� id ��� ������� ������
	//Apple apple1(200, "Red");
	//Apple apple2(150, "Green");
	//cout << apple1.GenID() << endl;
	//cout << apple2.GenID() << endl;

	//������ �� static �������
	//Apple apple1(200, "Red");
	//Apple apple2(150, "Green");
	//Apple apple3(100, "Yellow");
	//cout << Apple::GetCount() << endl;

	//������ �� ��������� �������
	//Image img;
	//img.GetImageINFO();

	//��������� � ����������
	//People a;
	//a.think();
	//a.InspectTheCap();

	//������ ������������
	//Student st;
	//st.learn();
	//ExtramuralStudent extrast;
	//extrast.learn();

	//������ ������������
	//Gun gun;
	//SubmachineGun machineGun;
	//Knife knife;
	//Player player;
	//player.Shoot(&knife);

	//������ ������ ������������ �����������
	//PA *a = new PB;
	//delete a;

	//������ ������ ������ ������������ ������ �������� ������
	//BracketsMsg b("������!");
	//Printer p;
	//p.Print(&b);

	//������ �������������� ������������
	//Flyingcar fc;
	//fc.drive();
	//fc.fly();
	
	//������ ������ ���������� ������� 
	//Flyingcar fc;
	//((Car)fc).USE();
	//((Airplain)fc).USE();

	//������ ����������
	//SimpleBicycle sb;
	//SportBicycle sport;
	//Bicyclist bb;
	//bb.RideOn(sb);
	//cout << endl << endl;
	//bb.RideOn(sport);
	
	//������ ������������ ������������/������������
	//OrcWarrior orc;
	
	//������ ������ � ����
	//string path = "me_file.txt";
	//ofstream fout;
	//fout.open(path, ofstream::app);
	//if (!fout.is_open())
	//{
	//	cout << "������ �������� �����!";
	//}
	//else 
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		cout << "������� ������\n";
	//		int a;
	//		cin >> a;
	//		fout << a;
	//		fout << "\n";
	//	}
	//}
	//fout.close();
	
	//������ ������ �� �����
	
	/*string path = "me_file.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "������! ���� �� ������" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();*/
	
	//������ � ������ �� ����� ������� ������
	//string path = "me_file.txt";
	//ofstream fout;
	//Points points (3024, 422, 430);
	//fout.open(path, ofstream::app);
	//if (!fout.is_open())
	//{
	//	cout << "������ �������� �����!";
	//}
	//else
	//{
	//	cout << "���� ������!" << endl;
	//	fout.write((char*)&points, sizeof(Points));
	//}
	//fout.close();
	// 
	//string path = "me_file.txt";
	//ifstream fin;
	//fin.open(path);

	//if (!fin.is_open())
	//{
	//	cout << "������! ���� �� ������" << endl;
	//}
	//else
	//{
	//	cout << "���� ������!" << endl;
	//	Points pnt;
	//	while (fin.read((char*)&pnt, sizeof(Points)))
	//	{
	//		pnt.Print();
	//	}
	//}
	//fin.close();

	//������ � ������ � ���� FSTREAM

	//string path = "me_file.txt";
	//fstream fs;
	//fs.open(path, fstream::in | fstream::out | fstream::app);

	//	if (!fs.is_open())
	//	{
	//		cout << "������ �������� �����!";
	//	}
	//	else
	//	{
	//		string msg;
	//		int value;
	//		cout << "���� ������!" << endl;
	//		cout << "������� 1 ��� ������ ���������� � ����!" << endl;
	//		cout << "������� 2 ��� ���������� ���� ��������� �� �����!" << endl;
	//		cin >> value;

	//		if (value == 1)
	//		{
	//			cout << "������� ���� ���������" << endl;
	//			SetConsoleCP(1251);
	//			cin >> msg;
	//			fs << msg << "\n";
	//			SetConsoleCP(866);
	//		}
	//		if (value == 2)
	//		{
	//			cout << "������ ������ �� �����" << endl;
	//			while (!fs.eof())
	//			{
	//				msg = "";
	//				fs >> msg;
	//				cout << msg << endl;

	//			}
	//			
	//		}
	//	}
	//	fs.close();

//������ � ������������ TRY CATCH
	//string path = "me_fe.txt";
	//ifstream fs;

	//fs.exceptions(ifstream::badbit | ifstream::failbit);

	//try
	//{
	//	cout << "������� �������� �����" << endl;
	//	fs.open(path);
	//	cout << "���� ������!" << endl;

	//}
	//catch (const ifstream::failure& ex)
	//{
	//	cout << ex.what() << endl;
	//	cout << ex.code() << endl;
	//	cout << "������ �������� �����!" << endl;
	//}

//��������� ����������/��������� ������ catch
	//try
	//{
	//	Test(1);
	//}
	//catch (const std::exception& ex)
	//{
	//	cout << "���� 1. ������! " << ex.what() << endl;
	//}
	//catch (const char* ex)
	//{
	//	cout << "���� 2. ������! " << ex << endl;
	//}
	//catch (...)
	//{
	//	cout << "���� 3. ���-�� ����� �� ��� " << endl;
	//}

//��������� ���������� � ������� ������ ������
	//try
	//{
	//	Test(1);
	//}
	//catch (Myexception& ex)
	//{
	//	cout << "���� 1. ������! " << ex.what() << endl;
	//	cout << "��������� ������ " << ex.GetData() << endl;
	//}
	//catch (exception& ex)
	//{
	//	cout << "���� 2. ������! " << ex.what() << endl;
	//}
	
//������������� ��� ENUM
	//PC pc;
	//pc.SetState(PC::PCState::OFF);
	//switch (pc.GetSatate())
	//{
	//case PC::PCState::OFF:
	//		cout << "��������" << endl;
	//		break;
	//case PC::PCState::ON:
	//	cout << "�������" << endl;
	//	break;
	//case PC::PCState::SLEEP:
	//	cout << "����" << endl;
	//	break;
	//}

//������������� ������������ ����
	//firstNS::Foo();
	//secondNS::Foo();

//������� �������
	//double a = 12;
	//Pattern<double> c(a);
	//c.DataTypeSize();

//������ � ����� ����������
	//SmartPointer<int> pointer = new int(23);
	//cout << *pointer << endl;

//����� ��������� � ������
	//int SIZE;
	//cin >> SIZE;
	//shared_ptr<int[]> ptr(new int[SIZE]);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	ptr[i] = rand() % 10;
	//	cout << ptr[i] << endl;
	//}



		return 0;
}

//������������� ����� ������
void Saler::TakeApple(Apple& apple)
{
	cout << "Take apple" << " weight " << apple.weight << " color " << apple.color << endl;
}
