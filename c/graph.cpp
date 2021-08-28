#include<bits/stdc++.h>
#define maxSize 110
using namespace std;
typedef struct arcNode{
    int nums;
    struct arcNode* nextNode;
}*arc;
typedef struct vNode{
    char aa;
    arc pArc;
}vNode,graph[maxSize];
typedef struct{
    graph data;
    int vNums,arcNums;
}Agraph;
int visited[maxSize];
void initGraph(Agraph &A){
    for(int i=0;i<maxSize;i++) A.data[i].pArc=NULL;
}
void creatGraph(Agraph &A){
    int k=0;
    cout<<"�������������:(����ͼ������1������ͼ������2)";
    cin>>k;
    cout<<"������þ���Ľ�����ͱ���:"<<endl;
    cin>>A.vNums>>A.arcNums;
    cout<<"�밴������������:"<<endl;
    for(int m=0;m<A.vNums;m++) cin>>A.data[m].aa;
    for(int m=0;m<A.arcNums;m++){
        cout<<"�밴ͷβ˳���������������������:";
        int i,j;
        char a,b;
        cin>>a>>b;
        for(int m=0;m<A.vNums;m++){
            if(a==A.data[m].aa)
                i=m;
            if(b==A.data[m].aa)
                j=m;
        }
        arc p=new arcNode;
        p->nums=i;
        p->nextNode=A.data[j].pArc;
        A.data[j].pArc=p;
        if(k==1){
            arc q=new arcNode;
            q->nums=j;
            q->nextNode=A.data[i].pArc;
            A.data[i].pArc=q;
        }
    }
}
void dfs(Agraph A,int k){
    cout<<A.data[k].aa;
    visited[k]++;
    if(A.data[k].pArc&&!visited[A.data[k].pArc->nums]){
        arc p=new arcNode;
        p=A.data[k].pArc;
        while(p){
            if(!visited[(p->nums)])
                dfs(A,p->nums);
            p=p->nextNode;
        }
        delete(p);
    }
}
void bfs(Agraph A){
    queue<int> sums;
    for(int i=0;i<A.vNums;i++){
        if(!visited[i]) sums.push(i);
        while(sums.size()){
            int temp=sums.front();
            if(!visited[temp]) cout<<A.data[temp].aa;
            sums.pop();
            visited[temp]++;
            arc p=new arcNode;
            p=A.data[temp].pArc;
            while(p!=NULL){
                if(!visited[p->nums]) sums.push(p->nums);
                p=p->nextNode;
            }
            delete(p);
        }
    }
}
void deleteGraph(Agraph &A){
    queue<arc> sums;
    for(int i=0;i<A.vNums;i++){
        sums.push(A.data[i].pArc);
        while(sums.back()->nextNode) sums.push(sums.back()->nextNode);
        while(!sums.empty()){
            delete(sums.front());
            sums.pop();
        }
        A.data[i].pArc=NULL;
        A.data[i].aa='\0';
    }
    A.arcNums=0;A.vNums=0;
}
void change(Agraph &A){
    int len=A.vNums;
    int a[len];
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++) a[j]=0;
        arc p=A.data[i].pArc;
        while(p){
            a[p->nums]++;
            p=p->nextNode;
        }
        delete(p);
        for(int j=0;j<len;j++) cout<<a[j]<<' ';
        cout<<endl;
    }
}
void menu(){
    cout<<"������������еĲ���"<<endl;
    cout<<" 1.ͼ�ĳ�ʼ���ʹ���"<<endl;
    cout<<" 2.ͼ��������ȱ���"<<endl;
    cout<<" 3.ͼ�Ĺ�����ȱ���"<<endl;
    cout<<" 4.ͼ���ڽӾ����ʾ"<<endl;
    cout<<" 5.�˳�"<<endl;
}
int main(){
    int cho=0,k=0;
    Agraph A;
    initGraph(A);
    menu();
    while(cin>>cho&&cho!=5){
        switch (cho)
        {
        case 1:
            //ͼ�ĳ�ʼ���ʹ���
            if(k==1) deleteGraph(A);
            creatGraph(A);k=1;
            cout<<"ͼ�������"<<endl;
            break;
        case 2:
            //��ȱ���
            if(k==1){
                int m=0;
                cout<<"�������ͼ������ȱ��������:";
                cin>>m;m--;
                memset(visited,0,maxSize);
                cout<<"��ͼ����ȱ���Ϊ:";
                dfs(A,m);
                cout<<endl;
            }else
                cout<<"�����������������"<<endl;
            break;
        case 3:
            //��ȱ���
            if(k==1){
                memset(visited,0,maxSize);
                cout<<"��ͼ�Ĺ�ȱ���Ϊ:";
                bfs(A);
                cout<<endl;
            }else
                cout<<"�����������������"<<endl;
            break;
        case 4:
            //ͼ���ڽӾ����ʾ
            if(k==1){
                cout<<"��ͼ���ڽӾ����ʾΪ:"<<endl;
                change(A);
                cout<<endl;
            }else
                cout<<"�����������������"<<endl;
            break;
        default:
            cout<<"�����������������"<<endl;
            break;
        }
        cout<<endl<<"====================================================="<<endl;
        menu();
    }
    if(k=1) deleteGraph(A);
    return 0;
}