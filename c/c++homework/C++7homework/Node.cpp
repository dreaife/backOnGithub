#include<iostream>
#include"Node.h"

using namespace std;

template <class T>
Node<T>::Node(const T& data, Node<T> * next):data(data), next(next){}
 
template <class T>
void Node<T>::insertAfter(Node<T> *p)
{
	p->next = next;
	next = p;	
} 
 
template <class T>
Node<T> * Node<T>::deleteAfter()
{
	Node<T> * tempPtr = next;
	if(next == 0)
		return 0;
	next = tempPtr->next;
	return tempPtr;
}
 
template <class T>
Node<T> *  Node<T>::nextNode()
{
	return next;
}

