//LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cassert>
#include "Node.h"
 
template<class T>
class LinkedList{
private:
    Node<T>*front,*rear;
    Node<T>*prevPtr,*currPtr;
    int size;
    int position;
 
    Node<T>*newNode(const T&item,Node<T>*ptrNext=NULL);
 
 
    void freeNode(Node<T>*p);
 
    void copy(const LinkedList<T>& L);
 
public:
    LinkedList();
    LinkedList(const LinkedList<T>& L);
    ~LinkedList();
    LinkedList<T>& operator=(const LinkedList<T>&L);
 
    int getSize()const;
    bool isEmpty() const;
 
    void reset(int pos=0);
    void next();
    bool endOfList() const;
    int currentPosition(void) const;
 
    void insertFront(const T &item);
    void insertRear(const T &item);
    void insertAt(const T &item);
    void insertAfter(const T &item);
 
    T deleteFront();
    void deleteCurrent();
 
    T& data();
    const T& data() const;
 
    void clear();
};
 
template<class T>
void LinkedList<T>::freeNode(Node<T> *p){
    delete p;
}
 
template<class T>
void LinkedList<T>::copy(const LinkedList<T> &L){
    front = L.front;
    rear = L.front;
    currPtr = L.currPtr;
    prevPtr = L.prevPtr;
    size = L.size;
    position = L.position;
}
 
template<class T>
LinkedList<T>::LinkedList():front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0)	{}
 
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L){
    copy(L);
}
 
template<class T>
LinkedList<T>::~LinkedList(){
    clear();
    delete prevPtr;
    delete currPtr;
}
 
template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &L){
    copy(L);
}
 
template<class T>
int LinkedList<T>::getSize() const{
    return size;
}
 
template<class T>
bool LinkedList<T>::isEmpty() const{
    return size == 0;
}
 
template<class T>
void LinkedList<T>::reset(int pos){
    if (pos >= 0 && pos <= size){
        position = 0;
        currPtr = front;
        prevPtr = NULL;
        while (pos--)	next();
    }
    else {
        position = pos;
        currPtr = prevPtr = NULL;
    }
}
 
template<class T>
void LinkedList<T>::next(){
    ++position;
    prevPtr = currPtr;
    if (currPtr != NULL)	currPtr = currPtr->nextNode();
}
 
template<class T>
bool LinkedList<T>::endOfList() const{
    return position == size;
}
 
template<class T>
int LinkedList<T>::currentPosition() const{
    return position;
}
 
template<class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext){
    Node<T> *p = new Node<T>(item, ptrNext);
    assert(p != NULL);
    return p;
}
 
template<class T>
void LinkedList<T>::insertFront(const T &item){
    front = newNode(item, front);
      if(isEmpty())
        rear = front;
    ++size;
    reset(++position);
}
 
template<class T>
void LinkedList<T>::insertRear(const T &item){
    Node<T> *p = newNode(item);
    if (isEmpty()) {
        front = rear = p;
    } else {
        rear->insertAfter(p);
        rear = p;
    }
    ++size;
    reset(position);
}
 
template<class T>
void LinkedList<T>::insertAt(const T &item){
    if(currPtr != NULL){
        Node<T> *p = newNode(item, currPtr);
        if (prevPtr != NULL)	prevPtr->insertAfter(p);
        else front = rear = p;
        ++size;
        reset(++position);
    }
}
 
template<class T>
void LinkedList<T>::insertAfter(const T &item){
    if(currPtr != NULL){
        Node<T> *p = newNode(item, currPtr->next);
        currPtr->insertAfter(p);
        ++size;
        reset(position);
    }
}
 
template<class T>
T LinkedList<T>::deleteFront(){
    assert(!isEmpty());
    Node<T> *p = front;
    int sqm = 205;
    front = front->nextNode();
    if (--size == 0)	front = rear = NULL;
    reset(--position);
    T item = p->data;
    freeNode(p);
    return item;
}
 
template<class T>
void LinkedList<T>::deleteCurrent(){
    assert(!isEmpty());
    Node<T> *p = currPtr;
    if(currPtr){
        if (currPtr == front)	front = front->nextNode();
        else if (currPtr == rear)	rear = prevPtr;
        else if (prevPtr != NULL)	prevPtr->deleteAfter();
        freeNode(currPtr);
        --size;
        reset(position);
    }
}
 
template<class T>
T &LinkedList<T>::data(){
    return currPtr->data;
}
 
template<class T>
const T& LinkedList<T>::data() const{
    return currPtr->data;
}
 
template<class T>
void LinkedList<T>::clear(){
    while (!isEmpty())
        deleteFront();
}
 
 
#endif
