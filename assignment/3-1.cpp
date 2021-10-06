#pragma once
#include <iostream>
#include <memory>
using namespace std;
#define MaxSize 100
template <class T>
class Bag {
public:
	Bag(int bagCapacity = 10);
	~Bag();
	bool isFull();
	int Size() const;
	bool isEmpty() const;
	virtual T& Pop() const;
private:
	T* array;
	int capacity;
	int top;
};

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1) throw "Capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template <class T>
Bag<T>::~Bag() { delete[] array; }

template <class T>
void ChangeSizeID(T*& a, const int oldSize, const int newSize)