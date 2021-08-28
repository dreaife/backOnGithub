#include<stdio.h>
#include<stdlib.h>
#define Queue_Size	15

typedef struct queueList{
	int *base;
	int front;
	int rear;
}  Qmode;

int initQueue(Qmode &Qlist){
	Qlist.base=(int*)malloc(Queue_Size*sizeof(queueList));
	if(!*Qlist.base){
		printf("�����ʼ������\n");
		return 0;
	}
	Qlist.front=Qlist.rear=0;
	return 0;
}

void pushQ(Qmode &Qlist,int a){
	if((Qlist.rear+1)%Queue_Size==Qlist.front)	printf("��������\n������������%d\n",a);
	else{
		Qlist.base[Qlist.rear]=a;
		Qlist.rear=(Qlist.rear+1)%Queue_Size;
	}
}

void popQ(Qmode &Qlist){
		int a=Qlist.base[Qlist.front];
		printf("%d\n",a);
		Qlist.front=(Qlist.front+1)%Queue_Size;
}

void breakQueue(Qmode &Qlist){
	free(Qlist.base);
}

void printfQueue(Qmode Qlist){
	int i=Qlist.front,n=0;
	while(i!=Qlist.rear){
		if((Qlist.rear+1)%Queue_Size==Qlist.front)	if(n+1==Queue_Size)	break;
		printf("%d	",Qlist.base[i]);
		i++;
		if(i%Queue_Size==0)	i=0;
		n++;
	}printf("\n"); 
}

int EmptyQueue(Qmode Qlist){
	if(Qlist.rear==Qlist.front){
		if((Qlist.rear+1)%Queue_Size==Qlist.front)	return 0;
		else	return 1;
	}
	else return 0;
}


int main(){
	Qmode xhuan;
	initQueue(xhuan);
	int m=0;
	printf("����������е����飺\n������ֹͣ����������0��");
	for(int i=0;i<Queue_Size;i++){
		scanf("%d",&m);
		if(m==0) break;
		pushQ(xhuan,m);
	}
	printf("������Ķ���Ϊ:\n");
	printfQueue(xhuan);
	printf("\n");
	printf("�����ͷ���ݣ�\n");
	for(int i=0;i<3;i++) popQ(xhuan);
	printf("�����к�Ķ���Ϊ:\n");
	printfQueue(xhuan);
	printf("����������е����飺\n������ֹͣ����������0��");
	for(int i=0;i<Queue_Size;i++){
		scanf("%d",&m);
		if(m==0) break;
		pushQ(xhuan,m);
	}
	printf("�ٴ������Ķ���Ϊ:\n");
	printfQueue(xhuan);
	breakQueue(xhuan);
	return 0;
}
