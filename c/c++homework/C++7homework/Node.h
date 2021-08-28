#ifndef NODE_H_
 
template<class T>
class Node
{
	private :
		Node<T> * next; 
	public :
		T data;
		Node(const T& data, Node<T> *next);
		void insertAfter(Node<T> *p);
		Node<T> * deleteAfter();
		Node<T> * nextNode();	
};

#endif
