#pragma once
#include<iostream>

using namespace std;

template <class T>
class MyArray
{
private:
	T* pAddress;//ָ��ָ��������ٵ�����
	int m_capacity;//��������
	int m_size;//�����С

public:
	MyArray(int capacity);
	//�������죬��ֹǳ����
	MyArray(const MyArray& arr);
	//��=�����أ���ֹǳ����
	MyArray& operator=(const MyArray& arr);
	//β�巨
	void pushBack(const T& val);
	//βɾ��
	void popBack();
	//ͨ���±귽ʽ��������Ԫ��
	T& operator[](int i);
	//��ȡ��ǰ����
	int getCapacity();
	//��ȡ��ǰ��С
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
		cout << "�����������޷����" << endl;
		return;
	}

	this->pAddress[this->m_size] = val;
	this->m_size++;
	cout << "��ӳɹ�" << endl;
}

template <class T>
void MyArray<T>::popBack()
{
	if (this->m_size == 0)
	{
		cout << "����Ϊ��" << endl;
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