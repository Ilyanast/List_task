#pragma once

#include "unidirectional_list.h"

template<typename T>
class BidirectionalList : public UnidirectionalList<T>
{

public:
	template<typename T>
	class Node
	{
	public:
		shared_ptr<Node<T>> next_el_;
		weak_ptr<Node<T>> prev_el_;
		T data_;

		Node(T data_) {
			this->data_ = data_;
		}
	};

	void PushBack(T data_);
	void PushFront(T data_);
	void Insert(T data_, int index_);
	T& GetFirst();

	void Erase(int index_);

	BidirectionalList();

protected:

	shared_ptr<Node<T>> head_;
	using UnidirectionalList<T>::size_;
};

template<typename T>
BidirectionalList<T>::BidirectionalList()
{
	head_ = make_shared<Node<T>>(T());
}

template<typename T>
void BidirectionalList<T>::PushBack(T data_)
{
	shared_ptr<Node<T>> current_el = head_;

	while (current_el.get()->next_el_.get()) {
		current_el = current_el.get()->next_el_;
	}

	shared_ptr<Node<T>> new_element = make_shared<Node<T>>(data_);

	current_el.get()->next_el_ = new_element;
	new_element.get()->prev_el_ = current_el;
	size_++;
}

template<typename T>
T& BidirectionalList<T>::GetFirst()
{
	return head_.get()->next_el_.get()->data_;
}

template<typename T>
void BidirectionalList<T>::PushFront(T data_)
{
	shared_ptr<Node<T>> new_element = make_shared<Node<T>>(data_);
	new_element.get()->next_el_ = head_.get()->next_el_;
	new_element.get()->prev_el_ = head_;
	head_.get()->next_el_ = new_element;
	size_++;
}

template<typename T>
void BidirectionalList<T>::Insert(T data_, int index_)
{
	shared_ptr<Node<T>> current_el;


	current_el = head_.get()->next_el_;

	for (int i = 0; i < index_; i++) {
		current_el = current_el.get()->next_el_;
	}


	shared_ptr<Node<T>> new_element = make_shared<Node<T>>(data_);

	current_el.get()->prev_el_.lock().get()->next_el_ = new_element;
	new_element.get()->prev_el_ = current_el.get()->prev_el_;
	new_element.get()->next_el_ = current_el;
	current_el.get()->prev_el_ = new_element;
	size_++;
}

template<typename T>
void BidirectionalList<T>::Erase(int index_)
{
	shared_ptr<Node<T>> current_el;

	current_el = head_.get()->next_el_;

	for (int i = 0; i < index_; i++) {
		current_el = current_el.get()->next_el_;
	}

	if (current_el.get()->next_el_.get()) {
		current_el.get()->next_el_.get()->prev_el_ = current_el.get()->prev_el_;
	}

	current_el.get()->prev_el_.lock().get()->next_el_ = current_el.get()->next_el_;
	size_--;
}