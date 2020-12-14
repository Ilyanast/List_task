#pragma once

#include "bidirectional_list.h"

template <typename T>
class Queue {
	UnidirectionalList<T>* list;

public:
	Queue(UnidirectionalList<T>* list);
	T& Pop();
	void PushBack(T data_);
	bool isEmpty();
};

template<typename T>
Queue<T>::Queue(UnidirectionalList<T>* list) : list(list)
{
}

template<typename T>
T& Queue<T>::Pop()
{
	T first = list->GetFirst();
	list->Erase(0);
	return first;
}

template<typename T>
void Queue<T>::PushBack(T data_)
{
	list->PushBack(data_);
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return !list->getSize();
}
