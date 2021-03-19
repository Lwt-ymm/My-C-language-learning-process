#pragma once
#include<iostream>

using namespace std;

template <class T>
class MyArray
{
private:
	T* pAddress;//指针指向堆区开辟的数组
	int m_capacity;//数组容量
	int m_size;//数组大小

public:
	MyArray(int capacity);
	//拷贝构造，防止浅拷贝
	MyArray(const MyArray& arr);
	//‘=’重载，防止浅拷贝
	MyArray& operator=(const MyArray& arr);
	//尾插法
	void pushBack(const T& val);
	//尾删法
	void popBack();
	//通过下标方式访问数组元素
	T& operator[](int i);
	//获取当前容量
	int getCapacity();
	//获取当前大小
	int getSize();

	~MyArray();
};

template <class T>
MyArray<T>::MyArray(int capacity)
{
	this->m_capacity = capacity;
	this->m_size = 0;
	this->pAddress = new T[this->m_capacity];
}

template <class T>
MyArray<T>::MyArray(const MyArray& arr)
{
	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->pAddress = new T[arr.m_capacity];

	for (int i = 0; i < arr.m_size; i++)
	{
		this->pAddress[i] = arr.pAddress[i];
	}
}

template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& arr)
{
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
		this->m_capacity = 0;
		this->m_size = 0;
	}

	this->m_capacity = arr.capacity;
	this->m_size = 0;
	this->pAddress = new T[this->m_capacity];
	for (int i = 0; i < arr.m_size; i++)
	{
		this->pAddress[i] = arr.pAddress[i];
	}

	return *this;
}

template <class T>
void MyArray<T>::pushBack(const T& val)
{
	if (this->m_capacity == this->m_size)
	{
		cout << "容量已满，无法添加" << endl;
		return;
	}

	this->pAddress[this->m_size] = val;
	this->m_size++;
	cout << "添加成功" << endl;
}

template <class T>
void MyArray<T>::popBack()
{
	if (this->m_size == 0)
	{
		cout << "容量为空" << endl;
		return;
	}

	this->m_size--;
}

template <class T>
T& MyArray<T>::operator[](int i)
{
	return this->pAddress[i];
}

template <class T>
int MyArray<T>::getCapacity()
{
	return this->m_capacity;
}

template <class T>
int MyArray<T>::getSize()
{
	return this->m_size;
}

template <class T>
MyArray<T>::~MyArray()
{
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
}