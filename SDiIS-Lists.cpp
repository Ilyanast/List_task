#include <iostream>

#include <list>
#include "unidirectional_list.h"
#include "bidirectional_list.h"
#include "queue.h"

using namespace std;

int main()
{	
	UnidirectionalList<int> a;
	
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushFront(0);
	a.Insert(1, 1);

	for (int i = 0; i < a.getSize(); i++) {
		cout << a[i] << endl;
	}

	cout << "-------------" << endl;

	UnidirectionalList<int>::Node<int> head_ = a.GetHead();
	UnidirectionalList<int>::Node<int> element = a.FindNodeByData(1);
	a.Erase(1);

	for (int i = 0; i < a.getSize(); i++) {
		cout << a[i] << endl;
	}

	cout << "-------------" << endl;

	BidirectionalList<int> b;
	b.PushBack(1);
	b.PushBack(2);
	b.PushBack(3);
	b.PushFront(0);
	b.Insert(4, 3);
	b.Insert(5, 3);

	for (int i = 0; i < b.getSize(); i++) {
		cout << b[i] << endl;
	}

	cout << "-------------" << endl;

	b.Erase(3);

	for (int i = 0; i < b.getSize(); i++) {
		cout << b[i] << endl;
	}

	BidirectionalList<int>::Node<int> tail_ = b.GetTail();

	Queue<int> queue;
	queue.PushBack(1);
	queue.Pop();
}
