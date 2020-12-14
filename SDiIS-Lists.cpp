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


	UnidirectionalList<int>::Node<int> head_ = a.GetHead();
	UnidirectionalList<int>::Node<int> element = a.FindNodeByData(1);
	a.Erase(1);


	BidirectionalList<int> b;
	b.PushBack(1);
	b.PushBack(2);
	b.PushBack(3);
	b.PushFront(0);
	b.Insert(4, 3);
	b.Insert(5, 3);

	b.Erase(3);

	UnidirectionalList<int>* list = new BidirectionalList<int>();

	Queue<int> queue(list);
	queue.PushBack(1);
	queue.PushBack(2);
	queue.PushBack(3);
	while (!queue.isEmpty())
	{
		cout << queue.Pop() << " ";
	}
	cout << endl;

	delete list;
}
