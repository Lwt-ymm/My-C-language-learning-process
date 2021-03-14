#include<iostream>

using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
private:
	CPU* m_cpu;
	VideoCard* m_videocard;
	Memory* m_memory;
public:
	Computer(CPU* cpu, VideoCard* videocard, Memory* memory);
	~Computer();
	void work()
	{
		m_cpu->calculate();
		m_videocard->display();
		m_memory->storage();
	}

};

Computer::Computer(CPU* cpu, VideoCard* videocard, Memory* memory)
{
	m_cpu = cpu;
	m_videocard = videocard;
	m_memory = memory;

}

Computer::~Computer()
{
	if (m_cpu != NULL)
	{
		delete m_cpu;
		m_cpu = NULL;
	}
	if (m_videocard != NULL)
	{
		delete m_videocard;
		m_videocard = NULL;
	}
	if (m_memory != NULL)
	{
		delete m_memory;
		m_memory = NULL;
	}
}

class InterCpu :public CPU
{
public:
	void calculate()
	{
		cout << "InterCPu" << endl;
	}
};

class InterVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "InterVideoCard" << endl;
	}
};

class InterMemory :public Memory
{
public:
	void storage()
	{
		cout << "InterMemory" << endl;
	}
};

class LenovoCpu :public CPU
{
public:
	void calculate()
	{
		cout << "LenovoCPu" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "LenovoVideoCard" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "LenovoMemory" << endl;
	}
};

void test1()
{
	CPU* intercpu = new InterCpu;
	VideoCard* intervideoCard = new InterVideoCard;
	Memory* intermemory = new InterMemory;

	Computer* c1 = new Computer(intercpu, intervideoCard, intermemory);
	c1->work();
	delete c1;
}

int main()
{
	test1();
	return 0;
}
//class Drink
//{
//public:
//	virtual void Boil() = 0;
//	virtual void Brew() = 0;
//	virtual void PourInCup() = 0;
//	virtual void AddSomething() = 0;
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		AddSomething();
//	}
//};
//
//class Coffee :public Drink
//{
//	void Boil()
//	{
//		cout << "��ˮ" << endl;
//	}
//	void Brew()
//	{
//		cout << "���ݿ���" << endl;
//	}
//	void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//	void AddSomething()
//	{
//		cout << "�����Ǻ�ţ��" << endl;
//	}
//};
//
//void makeDrink(Drink* drink)
//{
//	drink->makeDrink();
//}
//
//int main()
//{
//	Coffee* coffee = new Coffee;
//	makeDrink(coffee);
//	return 0;
//}

//class Calculator
//{
//public:
//	int m_num1, m_num2;
//	
//	virtual int getResult()
//	{
//		return 0;
//	}
//};
//
//class Add :public Calculator
//{
//public:
//	Add(int a, int b)
//	{
//		m_num1 = a;
//		m_num2 = b;
//	}
//private:
//	int getResult()
//	{
//		return m_num1 + m_num2;
//	}
//};
//
//class subtract :public Calculator
//{
//	int getResult()
//	{
//		return m_num1 - m_num2;
//	}
//};
//
//class multiply :public Calculator
//{
//	int getResult()
//	{
//		return m_num1 * m_num2;
//	}
//};
//
//class divide :public Calculator
//{
//	int getResult()
//	{
//		return m_num1 / m_num2;
//	}
//};
//
//int main()
//{
//	Calculator* calculator = new Add(10,10);
//	cout << calculator->getResult() << endl;
//	delete calculator;
//	return 0;
//}

//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//
//void test(Animal& animal)
//{
//	animal.speak();
//}
//
//int main()
//{
//	Cat cat;
//	Dog dog;
//	test(cat);
//	test(dog);
//	return 0;
//}

//class Animal
//{
//public:
//	int m_age;
//};
//
//class Sheep :virtual public Animal {};
//
//class Tuo :virtual public Animal {};
//
//class SheepTuo :public Sheep, public Tuo {};
//
//int main()
//{
//	SheepTuo st;
//	st.Sheep::m_age = 10;
//	st.Tuo::m_age = 20;
//	cout << st.Sheep::m_age << endl;
//	cout << st.Tuo::m_age << endl;
//	cout << st.m_age << endl;
//	return 0;
//}

//class Father
//{
//public:
//	void printf()
//	{
//		cout << "����" << endl;
//	}
//};
//
//class Son :public Father
//{
//public:
//	void print()
//	{
//		cout << "����" << endl;
//	}
//};
//
//int main()
//{
//	Son s;
//	s.print();
//	s.printf();
//	return 0;
//}