#include<iostream>
#include"Node.h"
#include"LinkedList.h"

using namespace std;

int main(){
    LinkedList<int> L;
    for(int i=0;i<10;i++){
        int item;
        cin>>item;
        L.insertFront(item);
    }
    cout<<"List:";
    L.reset();
    while(!L.endOfList()){
        cout<<L.data()<<" ";
        L.next();
    }
    cout<<endl;
    
    int key;
    cout<<"Please enter some integer needed to be deleted:";
    cin>>key;
    L.reset();
    while(!L.endOfList()){
        if(L.data()==key)
            L.deleteCurrent();
        L.next();
    }
    cout<<"List:";
    L.reset();
    while(!L.endOfList()){
        cout<<L.data()<<" ";
        L.next();
    }
    cout<<endl;
    return 0;
}