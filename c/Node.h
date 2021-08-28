//Node.h
#ifndef NODE_H
#define NODE_H
 
template<class T>
class Node
{
	private :
		Node<T> * next; //指向后继的指针 
	public :
		T data;// 数据域
		Node(const T& data, Node<T> *next);
		void insertAfter(Node<T> *p);
		Node<T> * deleteAfter();
		Node<T> * nextNode();	
};
 
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
 
#endif

