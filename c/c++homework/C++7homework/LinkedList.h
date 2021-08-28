#ifndef NODE_H_
#define NODE_H_
#include"Node.h"
#endif
#ifndef LINKEDLIST_H_
#include"Node.h"
template<class T>
class LinkedList{
    public:
        LinkedList();
        LinkedList(const LinkedList<T> &L);
        ~LinkedList();
        LinkedList<T>& operator=(const LinkedList<T>&L);

        int getSize() const;
        bool isEmpty() const;

        void reset (int pos=0);
        void next();
        bool endOfList() const;
        int currentPosition (void) const;

        void insertFront(const T &item);
        void insertRear(const T &item);
        void insertAt(const T&item);
        void insertAfter(const T& item);

        T deleteFront();
        void deleteCurrent();

        T& data();
        const T& data() const;

        void clear();
    private:
        Node<T> *front,*rear;
        Node<T> *prevPtr,*currPtr;
        int size;
        int position;

        Node<T> * newNode(const T &item,Node<T> *ptrNext=NULL);
        void freeNode(Node<T> *p);
        void copy(const LinkedList<T> &L);
};
#endif