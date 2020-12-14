#pragma once

#include "bidirectional_list.h"

template <typename T>
class Queue {
	BidirectionalList<T> list;

public:
	T& Pop();
	void PushBack(T data_);
	bool isEmpty();
};

template<typename T>
T& Queue<T>::Pop()
{
	T temp_el_ = list[0];
	list.Erase(0);
	return temp_el_;
}

template<typename T>
void Queue<T>::PushBack(T data_)
{
	list.PushBack(data_);
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return list.getSize();
}
