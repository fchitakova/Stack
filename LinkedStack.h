#pragma once

#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack
{
private:
	template <class T>
	class Node
	{
	public:
		T data;
		Node<T>*previous;
		Node<T>*next;
		Node(const T & d,Node<T>*prev=NULL,Node<T>*n=NULL):data(d),previous(prev),next(n){}
	};

public:
	Stack();
	Stack(const Stack<T>&other);
	Stack&operator=(const Stack&other);
	~Stack();

	bool isEmpty()const { return !top; }
	size_t Size()const { return size; }
	void push_back(const T&element);
	T peek()const { return top->data; }
	void pop_back();

private:
	void copyFrom(const Stack<T>&rhs);
	void clear();

private:
	Node<T>*top;
	size_t size;
};




template<class T>
Stack<T>::Stack()
{
	top = NULL;
	size = 0;
}

template<class T>
 Stack<T>::Stack(const Stack<T> & other):top(NULL)
{
	 copyFrom(other);
}

 template<class T>
 Stack<T> & Stack<T>::operator=(const Stack & other)
 {
	  if (this != &other)
	 {
		  copyFrom(other);
	 }
	  return *this;
 }

 template<class T>
 Stack<T>::~Stack()
 {
	 clear();
 }

template<class T>
void Stack<T>::push_back(const T & element)
{
	if (isEmpty())
	{
		top = new Node<T>(element);
	}
	else
	{
		    Node<T>*temp = top;
			
			top = new Node<T>(element, NULL, temp);

			temp->previous = top;
	}
	
	
	++size;
}

template<class T>
void Stack<T>::pop_back()
{
	if (!isEmpty())
	{
		if (top->next)
		{
			Node<T>*temp = top->next;
			delete top;
			top = temp;
			temp->previous = NULL;

		}
		else
		{
			delete top;
			top = NULL;
		}

		--size;
	}
}

template<class T>
void Stack<T>::copyFrom(const Stack<T> & rhs)
{
	if (!isEmpty())
		clear();
	if (rhs.isEmpty())
		return;

	Node<T>*endOfrhs = rhs.top;

	size_t elemsToCopy= rhs.size;

	while (endOfrhs->next)
	{
		endOfrhs = endOfrhs->next;
	}

	while (elemsToCopy > 0)
	{
		push_back(endOfrhs->data);
		endOfrhs = endOfrhs->previous;
		--elemsToCopy;
	}

}

template<class T>
void Stack<T>::clear()
{
	while (size > 0)
	{
		pop_back();
	}
}



#endif
