#include<iostream>
#include<malloc.h>
#include<queue>
#include<windows.h>
using namespace std;
typedef struct treeList{
    char data;
    struct treeList *lchild,*rchild;
}tree,*treeP;
void creatTree(treeP &pz){
    char temp;
    cin>>temp;
    if(temp!='#'){
        pz=(treeP)malloc(sizeof(tree));
        pz->data=temp;
        creatTree(pz->lchild);
        creatTree(pz->rchild);
    }else pz=NULL;
}
void frontTreeVisit(treeP p){
    if(p!=NULL){
        cout<<p->data;
        frontTreeVisit(p->lchild);
        frontTreeVisit(p->rchild);
    }
}
void inTreeVisit(treeP p){
    if(p!=NULL){
        inTreeVisit(p->lchild);
        cout<<p->data;
        inTreeVisit(p->rchild);
    }
}
void backTreeVisit(treeP p){
    if(p!=NULL){
       backTreeVisit(p->lchild);
       backTreeVisit(p->rchild);
       cout<<p->data;
    }
}
void levelTreeVisit(treeP p){
        queue<treeP> dp;
        treeP pp=p;
        if(p!=NULL) dp.push(pp);
        while(dp.empty()==0){
            treeP temp=dp.front();
            dp.pop();
            cout<<temp->data;
            if(temp->lchild!=NULL) dp.push(temp->lchild);
            if(temp->rchild!=NULL) dp.push(temp->rchild);
        }
}
void deleteTree(treeP &p){
    if(p!=NULL){
        deleteTree(p->lchild);
        deleteTree(p->rchild);
        free(p);
    }
}
void menu(){
	cout<<"???????????§Ö??????"<<endl;
	cout<<" 1.??????????"<<endl;
	cout<<" 2.?????????????"<<endl;
	cout<<" 3.?????????????"<<endl;
	cout<<" 4.?????????????"<<endl; 
	cout<<" 5.?????????????"<<endl;
	cout<<" 6.???"<<endl;
}
int main(){
    int cho=0,k=0;
    treeP tp;
    tp->data='#';tp->lchild=NULL;tp->rchild=NULL;
    menu();
    while(cin>>cho&&cho!=6){
        switch (cho)
        {
        case 1:
            cout<<"???????????????????????????????#???????:"<<endl;
            if(k==1) deleteTree(tp);
            creatTree(tp);k=1;
            cout<<"?????????????"<<endl;
            break;
        case 2:
            if(tp->data=='#'){
                cout<<"?????????"<<endl;
                break;
            }else{
                cout<<"????????????????"<<endl;
                frontTreeVisit(tp);
                cout<<endl;
            }break;
        case 3:
            if(tp->data=='#'){
                cout<<"?????????"<<endl;
                break;
            }else{
                cout<<"????????????????"<<endl;
                inTreeVisit(tp);
                cout<<endl;
            }break;
        case 4:
            if(tp->data=='#'){
                cout<<"?????????"<<endl;
                break;
            }else{
                cout<<"???????????????"<<endl;
                backTreeVisit(tp);
                cout<<endl;
            }break;
        case 5:
            if(tp->data=='#'){
                cout<<"?????????"<<endl;
            }else{
                cout<<"???????¦Á??????"<<endl;
                levelTreeVisit(tp);
                cout<<endl;
            }break;
        default:
            cout<<"???????????????????"<<endl;
            break;
        }
        cout<<endl<<"====================================================="<<endl;
        menu();
    }
    if(k==1) deleteTree(tp);
    system("pause");
    return 0;
}