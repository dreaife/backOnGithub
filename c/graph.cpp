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
    cout<<"请问您输入的是:(无向图请输入1，有向图请输入2)";
    cin>>k;
    cout<<"请输入该矩阵的结点数和边数:"<<endl;
    cin>>A.vNums>>A.arcNums;
    cout<<"请按次序输入各结点:"<<endl;
    for(int m=0;m<A.vNums;m++) cin>>A.data[m].aa;
    for(int m=0;m<A.arcNums;m++){
        cout<<"请按头尾顺序依次输入相连的两结点:";
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
    cout<<"请输入您想进行的操作"<<endl;
    cout<<" 1.图的初始化和创建"<<endl;
    cout<<" 2.图的深度优先遍历"<<endl;
    cout<<" 3.图的广度优先遍历"<<endl;
    cout<<" 4.图的邻接矩阵表示"<<endl;
    cout<<" 5.退出"<<endl;
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
            //图的初始化和创建
            if(k==1) deleteGraph(A);
            creatGraph(A);k=1;
            cout<<"图创建完成"<<endl;
            break;
        case 2:
            //深度遍历
            if(k==1){
                int m=0;
                cout<<"请输入该图深度优先遍历的起点:";
                cin>>m;m--;
                memset(visited,0,maxSize);
                cout<<"该图的深度遍历为:";
                dfs(A,m);
                cout<<endl;
            }else
                cout<<"输入错误，请重新输入"<<endl;
            break;
        case 3:
            //广度遍历
            if(k==1){
                memset(visited,0,maxSize);
                cout<<"该图的广度遍历为:";
                bfs(A);
                cout<<endl;
            }else
                cout<<"输入错误，请重新输入"<<endl;
            break;
        case 4:
            //图的邻接矩阵表示
            if(k==1){
                cout<<"该图的邻接矩阵表示为:"<<endl;
                change(A);
                cout<<endl;
            }else
                cout<<"输入错误，请重新输入"<<endl;
            break;
        default:
            cout<<"输入错误，请重新输入"<<endl;
            break;
        }
        cout<<endl<<"====================================================="<<endl;
        menu();
    }
    if(k=1) deleteGraph(A);
    return 0;
}