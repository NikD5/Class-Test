#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <Windows.h>
#include<memory>
using namespace std;


class Human
{//ПРИМЕР РАБОТЫ ДЕЛЕГИРУЮЩЕГО КОНТРУКТОРА
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
	//	cout << "Имя" << " " << name << endl << "Возраст" << " " << age << endl << "Вес" << " " << weight;
	//}
};


class Point
{
private:
	int x;
	int y;

public:

	//ОПРЕДЕЛЕНИЕ ДРУЖЕСТВЕННОЙ ФУНКЦИИ
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



	//ПЕРЕГРУЗКА ОПЕРАТОР РАВЕНСТВА
	bool operator == (const Point & other)
	{
		return this->x == other.x && this->y == other.y;
	}

	//ПЕРЕГРУЗКА ОПЕРАТОР НЕРАВЕНСТВА
	bool operator != (const Point & other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	//ПЕРЕГРУЗКА ОПЕРАТОРА СЛОЖЕНИЯ
	Point operator + (const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	//ПЕРЕГРУЗКА ОПЕРАТОРА ИНКРЕМЕНТА/ДЕКРЕМЕНТА / ПРЕФИКС
	Point& operator ++ ()
	{
		this->x++;//--
		this->y++;//--
		return *this;
	}

	//ПЕРЕГРУЗКА ОПЕРАТОРА ИНКРЕМЕНТА/ДЕКРЕМЕНТА / ПОСТФИКС
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

	//ОПРЕДЕЛЕНИЕ МЕТОДА ВНЕ КЛАССА
	void PrintMessage();

	//КОНСТРУКТОР ПО УМОЛЧАНИЮ
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
		cout << "Объект " << data << " Вызвался конструктор " <<this<< endl;

	};
	//КОНСТРУКТОР КОПИРОВАНИЯ
	MyClass(const MyClass &other)
	{
		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout <<"Вызвался конструктор копирования " << this << endl;

	};

	//ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ
	MyClass & operator = (const MyClass &other)
	{
		cout << "Вызвался оператор = " << this << endl;

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

	//ДИСТРУКТОР
	~MyClass()
	{
		delete[] data;
		cout << "Объект " << data << " Вызвался диструктор"<< this << endl;
	};

private:
	int* data;
	int Size;
};

//МЕТОД ОПРЕДЕЛЕННЫЙ ВНЕ КЛАССА
void MyClass::PrintMessage()
{
	cout << "Hello!";
}


class TestClass
{
public:
	//ПЕРЕГРУЗКА ОПЕРАТОРА ИНДЕКСИРОВАНИЯ
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
	

	//ОПРЕДЕЛЕНИЕ ДРУЖЕСТВЕННОГО КЛАССА
	friend Saler;
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;
		id = Count;
	};

	//ГЕНЕРАТОР ID ДЛЯ КАЖДОГО ЯБЛОКА
	int GenID()
	{
		return id;
	}

	//СОЗДАНИЕ STATIC МЕТОДА
	static int GetCount()
	{
		return Count;
	}

	//ОПРЕДЕЛЕНИЕ ДРУЖЕСТВЕННОГО МЕТОДА КЛАССА SALER
	//friend void Saler::TakeApple(Apple& apple);
private:
	int weight;
	string color;
	int id;
	//СОЗДАНИЕ STATIC-ПЕРЕМЕННОЙ
	static int Count;
};

//РАБОТА С ВЛОЖЕННЫМ КЛАССОМ
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
	//ВЛОЖЕННЫЙ КЛАСС
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

	//пример работы массива объектов класса
	static const int length = 5;
	Pixel pixels[length]{
		Pixel(4, 6, 2),
		Pixel(23, 123, 32),
		Pixel(442, 423, 324),
		Pixel(465, 324, 342),
		Pixel(423, 656, 23),
	};
	
};


//ПРИМЕР АГРЕГАЦИИ
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

//ПРИМЕР КОМПОЗИЦИИ
class People
{
public:
	void think()
	{
		brain.think();
	}

	void InspectTheCap()
	{
		cout << "Моя кепка " << cap.GetColor() << " цвета";
	}

private:
	class Brain
	{
	public:
		void think()
		{
			cout << "Я думаю!" << endl;
		}


	};
	Brain brain;
	Cap cap;
};



//ИНИЦИАЛИЗАЦИЯ STATIC ПЕРЕМЕННОЙ
int Apple::Count = 0;

//ДРУЖЕСТВЕННАЯ ФУНКЦИЯ
void ChangeX(Point& value)
{
	value.x = -1;
}

void Foo()
{
	cout << "Вызов конструктора" << endl;
	MyClass a(5);
	cout << "Вызов диструктора" << endl;
}

//ПРИМЕР НАСЛЕДОВАНИЯ
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
		cout << "Я учусь!" << endl;
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
		cout << "Я учусь на заочном направлении" << endl;
	}
};

//ПРИМЕР МОДИФИКАТОРОВ ДОСТУПА ПРИ НАСЛЕДОВАНИИ
class A
{
public:
	string msgOne = "Сообщение один";

private:
	string msgTwo = "Сообщение два";
protected:
	string msgThree = "Сообщение три";
};
class B : public A
{
public:
	void PrintMsg()
	{
		cout << msgOne << endl;
	}

};

//АБСТРАКТНЫЙ КЛАСС
class Weapon
{
public:
	//ЧИСТО ВИРТУАЛЬНАЯ ФУНКЦИЯ
	virtual void Shoot() = 0;
};


//ПОЛИМОРФИЗМ, VIRTUAL, OVERRIDE
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

//ПРИМЕР РАБОТЫ ВИРТУАЛЬНОГО ДИСТРУКТОРА
class PA
{
public:
	PA() 
	{
		cout << "выделена динамическая память конструктору класса PA" << endl;
	};
	virtual ~PA()
	{
		
		cout << "освобождена динамическая память конструктору класса PA" << endl;
		
	};

};
class PB : public PA
{
public:
	PB()
	{
		cout << "выделена динамическая память конструктору класса PB" << endl;
	};
	~PB() override
	{

		cout << "освобождена динамическая память конструктору класса PB" << endl;

	};

};


//ВЫЗОВ ВИРТУАЛЬНОГО МЕТОДА БАЗОВОГО КЛАССА
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

//ПРИМЕР МНОЖЕСТВЕННОГО НАСЛЕДОВАНИЯ/ОДИНАКОВЫЕ МЕТОДЫ
class Car
{
public:
	void USE()
	{
		cout << "Я еду!" << endl;
	}
};
class Airplain
{
public:
	void USE()
	{
		cout << "Я лечу!" << endl;
	}
};
class Flyingcar :public Car, public Airplain
{
public:

};

//ПРИМЕР ИНТЕРФЕЙСА
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
		cout << "метод TwistTheWhell SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "метод Ride SimpleBicycle" << endl;
	}

};
class SportBicycle :public IBicycle
{
public:
	void TwistTheWhell() override
	{
		cout << "метод TwistTheWhell SportBicycle" << endl;
	}
	void Ride() override
	{
		cout << "метод Ride SportBicycle" << endl;
	}

};
class Bicyclist
{
public:
	
	void RideOn(IBicycle& bicycle)
	{
		cout << "крутим руль" << endl;
		bicycle.TwistTheWhell();
		cout << "поехали" << endl;
		bicycle.Ride();
	}
};

//ПРИМЕР РОМБОВИДНОГО НАСЛЕДОВАНИЯ/ВИРТУАЛЬНОГО
class Character
{
public:
	Character()
	{
		cout << "конструктор класса Character" << endl;
	};
	
	int HP;
};
class Orc: public virtual Character
{
public:
	Orc()
	{
		cout << "конструктор класса Orc" << endl;
	};

};
class Warrior : public virtual Character
{
public:
	Warrior()
	{
		cout << "конструктор класса Warrior" << endl;
	};

};
class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "конструктор класса OrcWarrior" << endl;
	};

};

//ЗАПИСЬ И ЧТЕНИЕ ИЗ ФАЙЛА ОБЪЕКТА КЛАССА
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

//СВОЙ КЛАСС EXCEPTION
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


//ПЕРЕЧЕСЛЯЕМЫЙ ТИП ENUM
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



//ГЕНЕРАЦИЯ ИСКЛЮЧЕНИЯ
void Test(int value)
{
	if (value <0)
	{
		throw exception("Переменная < 0!");
	}
	if (value==1)
	{
		throw Myexception("Переменная = 1!",value);
	}
	
	//if (value == 1)
	//{
	//	throw 1;
	//}
	cout << "Переменная = " << value << endl;
}

//ИСПОЛЬЗОВАНИЕ ПРОСТРАНСТВА ИМЕН
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

//ШАБЛОН КЛАССОВ
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

//УМНЫЙ УКАЗАТЕЛЬ
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
	//firstguman.name = "Вася";
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

	//оператор копирования
	//MyClass a(10);
	//MyClass b(a);

	//оператор присваивания
	//MyClass a(10);
	//MyClass b(3);
	//MyClass c(1);
	//c = a = b;

	//оператор равенства/неравенства
	//Point a(4, 2);
	//Point b(7, 6);
	//bool result = a == b;

	//оператор сложения
	//Point a(4, 2);
	//Point b(2, 6);
	//Point c = a + b;

	//оператор перегрузки инкремента, декремента
	//Point a(2, 2);
	//Point b;
	//b = a++;

	//перегрузка оператора индексирования
	//TestClass a;
	//cout << a[1] << endl;

	//вызов дружественной функции для класса Point
	//Point a(33, 12);
	//a.Print();
	//ChangeX(a);
	//a.Print();

	//вызов метода вне класса
	//MyClass a;
	//a.PrintMessage();

	//параметры для дружественного метода класса / дружественного класса
	//Apple apple(200,"Green");
	//Saler human;
	//human.TakeApple(apple);

	//работа со sttic переменной
	//Apple apple1(200, "Red");
	//Apple apple2(150, "Green");
	//cout << Apple::Count << endl;

	//генератор id для каждого яблока
	//Apple apple1(200, "Red");
	//Apple apple2(150, "Green");
	//cout << apple1.GenID() << endl;
	//cout << apple2.GenID() << endl;

	//работа со static методом
	//Apple apple1(200, "Red");
	//Apple apple2(150, "Green");
	//Apple apple3(100, "Yellow");
	//cout << Apple::GetCount() << endl;

	//работа со вложенным классом
	//Image img;
	//img.GetImageINFO();

	//агрегация и композиция
	//People a;
	//a.think();
	//a.InspectTheCap();

	//пример наследования
	//Student st;
	//st.learn();
	//ExtramuralStudent extrast;
	//extrast.learn();

	//работа полиморфизма
	//Gun gun;
	//SubmachineGun machineGun;
	//Knife knife;
	//Player player;
	//player.Shoot(&knife);

	//пример работы виртуального диструктора
	//PA *a = new PB;
	//delete a;

	//пример работы вызова виртуального метода базового класса
	//BracketsMsg b("Привет!");
	//Printer p;
	//p.Print(&b);

	//пример множественного наследования
	//Flyingcar fc;
	//fc.drive();
	//fc.fly();
	
	//пример вызова одинаковых методов 
	//Flyingcar fc;
	//((Car)fc).USE();
	//((Airplain)fc).USE();

	//пример интерфейса
	//SimpleBicycle sb;
	//SportBicycle sport;
	//Bicyclist bb;
	//bb.RideOn(sb);
	//cout << endl << endl;
	//bb.RideOn(sport);
	
	//Пример ромбовидного наследования/виртуального
	//OrcWarrior orc;
	
	//ПРИМЕР ЗАПИСИ В ФАЙЛ
	//string path = "me_file.txt";
	//ofstream fout;
	//fout.open(path, ofstream::app);
	//if (!fout.is_open())
	//{
	//	cout << "Ошибка открытия файла!";
	//}
	//else 
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		cout << "Введите данные\n";
	//		int a;
	//		cin >> a;
	//		fout << a;
	//		fout << "\n";
	//	}
	//}
	//fout.close();
	
	//ПРИМЕР ЧТЕНИЯ ИЗ ФАЙЛА
	
	/*string path = "me_file.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Ошибка! Файл не найден" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();*/
	
	//ЗАПИСЬ И ЧТЕНИЕ ИЗ ФАЙЛА ОБЪЕКТА КЛАССА
	//string path = "me_file.txt";
	//ofstream fout;
	//Points points (3024, 422, 430);
	//fout.open(path, ofstream::app);
	//if (!fout.is_open())
	//{
	//	cout << "Ошибка открытия файла!";
	//}
	//else
	//{
	//	cout << "Файл открыт!" << endl;
	//	fout.write((char*)&points, sizeof(Points));
	//}
	//fout.close();
	// 
	//string path = "me_file.txt";
	//ifstream fin;
	//fin.open(path);

	//if (!fin.is_open())
	//{
	//	cout << "Ошибка! Файл не найден" << endl;
	//}
	//else
	//{
	//	cout << "Файл открыт!" << endl;
	//	Points pnt;
	//	while (fin.read((char*)&pnt, sizeof(Points)))
	//	{
	//		pnt.Print();
	//	}
	//}
	//fin.close();

	//ЧТЕНИЕ И ЗАПИСЬ В ФАЙЛ FSTREAM

	//string path = "me_file.txt";
	//fstream fs;
	//fs.open(path, fstream::in | fstream::out | fstream::app);

	//	if (!fs.is_open())
	//	{
	//		cout << "Ошибка открытия файла!";
	//	}
	//	else
	//	{
	//		string msg;
	//		int value;
	//		cout << "Файл открыт!" << endl;
	//		cout << "Введите 1 для записи информации в файл!" << endl;
	//		cout << "Введите 2 для считывания всех сообщений из файла!" << endl;
	//		cin >> value;

	//		if (value == 1)
	//		{
	//			cout << "Введите ваше сообщение" << endl;
	//			SetConsoleCP(1251);
	//			cin >> msg;
	//			fs << msg << "\n";
	//			SetConsoleCP(866);
	//		}
	//		if (value == 2)
	//		{
	//			cout << "Чтение данных из файла" << endl;
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

//РАБОТА С ИСКЛЮЧЕНИЯМИ TRY CATCH
	//string path = "me_fe.txt";
	//ifstream fs;

	//fs.exceptions(ifstream::badbit | ifstream::failbit);

	//try
	//{
	//	cout << "Попытка открытия файла" << endl;
	//	fs.open(path);
	//	cout << "Файл открыт!" << endl;

	//}
	//catch (const ifstream::failure& ex)
	//{
	//	cout << ex.what() << endl;
	//	cout << ex.code() << endl;
	//	cout << "Ошибка открытия файла!" << endl;
	//}

//ГЕНЕРАЦИЯ ИСКЛЮЧЕНИЯ/несколько блоков catch
	//try
	//{
	//	Test(1);
	//}
	//catch (const std::exception& ex)
	//{
	//	cout << "Блок 1. Ошибка! " << ex.what() << endl;
	//}
	//catch (const char* ex)
	//{
	//	cout << "Блок 2. Ошибка! " << ex << endl;
	//}
	//catch (...)
	//{
	//	cout << "Блок 3. Что-то пошло не так " << endl;
	//}

//ОБРАБОТКА ИСКЛЮЧЕНИЙ С ПОМОЩЬЮ СВОЕГО КЛАССА
	//try
	//{
	//	Test(1);
	//}
	//catch (Myexception& ex)
	//{
	//	cout << "Блок 1. Ошибка! " << ex.what() << endl;
	//	cout << "Состояние данных " << ex.GetData() << endl;
	//}
	//catch (exception& ex)
	//{
	//	cout << "Блок 2. Ошибка! " << ex.what() << endl;
	//}
	
//ПЕРЕЧЕСЛЯЕМЫЙ ТИП ENUM
	//PC pc;
	//pc.SetState(PC::PCState::OFF);
	//switch (pc.GetSatate())
	//{
	//case PC::PCState::OFF:
	//		cout << "Выключен" << endl;
	//		break;
	//case PC::PCState::ON:
	//	cout << "Включен" << endl;
	//	break;
	//case PC::PCState::SLEEP:
	//	cout << "Спит" << endl;
	//	break;
	//}

//ИСПОЛЬЗОВАНИЕ ПРОСТРАНСТВА ИМЕН
	//firstNS::Foo();
	//secondNS::Foo();

//ШАБЛОНЫ КЛАССОВ
	//double a = 12;
	//Pattern<double> c(a);
	//c.DataTypeSize();

//РАБОТА С УМНЫМ УКАЗАТЕЛЕМ
	//SmartPointer<int> pointer = new int(23);
	//cout << *pointer << endl;

//УМНЫЕ УКАЗАТЕЛИ И МАССИВ
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

//ДРУЖЕСТВЕННЫЙ МЕТОД КЛАССА
void Saler::TakeApple(Apple& apple)
{
	cout << "Take apple" << " weight " << apple.weight << " color " << apple.color << endl;
}
