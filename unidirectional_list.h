#pragma once

#include <memory>

using namespace std;

template<typename T>
class UnidirectionalList
{
public:
	template<typename T>
	class Node
	{
	public:
		shared_ptr<Node<T>> next_el_;
		T data_;

		Node(T data_) {
			this->data_ = data_;
		}
	};

	virtual void PushBack(T data_);
	virtual void PushFront(T data_);
	virtual void Insert(T data_, int index_);
	virtual T& GetFirst();

	virtual void Erase(int index_);

	int getSize() { return size_; };

	Node<T>& GetHead();
	Node<T>& FindNodeByData(T data_);

	UnidirectionalList();

protected:
	int size_;
	shared_ptr<Node<T>> head_;

};

template<typename T>
void UnidirectionalList<T>::PushBack(T data_)
{
	shared_ptr<Node<T>> current_el = head_;

	while (current_el.get()->next_el_.get()) {
		current_el = current_el.get()->next_el_;
	}

	current_el.get()->next_el_ = make_shared<Node<T>>(data_);
	size_++;
}

template<typename T>
void UnidirectionalList<T>::PushFront(T data_)
{
	shared_ptr<Node<T>> new_element = make_shared<Node<T>>(data_);
	new_element.get()->next_el_ = head_.get()->next_el_;
	head_.get()->next_el_ = new_element;
	size_++;
}

template<typename T>
void UnidirectionalList<T>::Insert(T data_, int index_)
{
	shared_ptr<Node<T>> current_el = head_;

	for (int i = 0; i < index_; i++) {
		current_el = current_el.get()->next_el_;
	}

	shared_ptr<Node<T>> new_element = make_shared<Node<T>>(data_);

	new_element.get()->next_el_ = current_el.get()->next_el_;
	current_el.get()->next_el_ = new_element;
	size_++;
}

template<typename T>
T& UnidirectionalList<T>::GetFirst()
{
	return head_.get()->next_el_.get()->data_;
}

template<typename T>
UnidirectionalList<T>::Node<T>& UnidirectionalList<T>::GetHead()
{
	return *(head_.get()->next_el_.get());
}

template<typename T>
UnidirectionalList<T>::Node<T>& UnidirectionalList<T>::FindNodeByData(T data_)
{
	shared_ptr<Node<T>> current_el = head_.get()->next_el_;

	while (current_el.get()->next_el_)
	{
		if (current_el.get()->data_ == data_) {
			return *(current_el.get());
		}
		current_el = current_el.get()->next_el_;
	};
}

template<typename T>
void UnidirectionalList<T>::Erase(int index_)
{
	shared_ptr<Node<T>> current_el = head_;

	for (int i = 0; i < index_; i++) {
		current_el = current_el.get()->next_el_;
	}

	current_el.get()->next_el_ = current_el.get()->next_el_.get()->next_el_;
	size_--;
}


template<typename T>
UnidirectionalList<T>::UnidirectionalList()
{
	size_ = 0;
	head_ = make_shared<Node<T>>(T());
}
