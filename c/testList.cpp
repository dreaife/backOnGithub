#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node,*PNode;

int main()
{ 
	PNode creatNodeList();					//函数声明 
	void printNodeList(PNode p0);
	void deleteNodeinList (PNode p0 ,int n);
	void newNodeinList (PNode p0 ,int n);
	int DeleteFront(PNode &HL);
	int AddFront(PNode &HL);
	int  checkNodeList (PNode p); 
	void findNodeList (PNode p ,int k); 
	 
	int n=0,NodeLong=0;
	PNode PList;
	int k;

	do{system("cls");
		printf("请选择您想进行的操作：\n");
		printf("1.输入链表\n"); 
		printf("2.删除元素\n"); 
		printf("3.插入元素\n");
		printf("4.查找元素\n");
		printf("0.结束程序\n");
		scanf("%d",&k);
		switch(k){
			case 1:{
				PList=creatNodeList();
				while(PList==NULL){
					printf("您输入的链表为空,请重新输入：\n");
					PList=creatNodeList();
				}
				printf("您输入的链表为：\n"); 
				printNodeList(PList);
				printf("\n");
				system("pause");
				break;
			} 
			case 2:{
				if (PList==NULL){
					printf("请先输入链表\n");
					break;
				}
				printf("请输入您想删除的数据的位数:");
				scanf("%d",&n);
				NodeLong=checkNodeList(PList);
				while(n<=0||n>NodeLong) {
					printf("您输入的位数不正确，请输入链表内的位数\n");
					printf("请输入您想删除的数据的位数:");
					scanf("%d",&n);
				}
				if (n==1)
					DeleteFront(PList);
				else	
					deleteNodeinList(PList,n);
				printf("\n删除后的链表为：\n");
				printNodeList(PList);
				printf("\n");
				system("pause");
				break;
			}
			case 3:{
				if (PList==NULL){
					printf("请先输入链表\n");
					break;
				}
				printf("请输入您想插入的数据的位数:");
				scanf("%d",&n);
				NodeLong=checkNodeList(PList);
				while(n<=0||n>NodeLong) {
					printf("您输入的位数不正确，请输入链表内的位数\n");
					printf("请输入您想插入的数据的位数:");
					scanf("%d",&n);
				}
				if (n==1)
					AddFront(PList);
				else 
					newNodeinList(PList,n);	
				printf("插入后的链表为：\n");
				printNodeList(PList);
				printf("\n");
				system("pause");
				break;
			}
			case 4:{
				if (PList==NULL){
					printf("请先输入链表\n");
					break;
				}
				printf("请输入您想查找的数据的位数:");
				scanf("%d",&n);
				NodeLong=checkNodeList(PList);
				while(n<=0||n>NodeLong) {
					printf("您输入的位数不正确，请输入链表内的位数\n");
					printf("请输入您想查找的数据的位数:");
					scanf("%d",&n);
				}
				findNodeList(PList,n);
				printf("\n");
				system("pause");
				break;
			}
			default: return 0;
		}
		
	}while (k>=1||k<=4);
	return 0;
 } 
 
 PNode creatNodeList()		//建立链表 
 {
	int n=0;
	printf("请输入您想输入的数据：\n"); 
	PNode P1=(PNode)malloc(sizeof(Node)),P2,P0;
	P0 =NULL;
	P2=P1;
	scanf("%d",&P1->data);
	while (P2->data!=0){
		if (n==0) P0=P1;
		PNode P1=(PNode)malloc(sizeof(Node));
		scanf("%d",&P1->data);
		P2->next=P1;
		P2=P1;
		n+=1;
	}
	P2->next=NULL;
	return (P0);
 }
 
 void printNodeList(PNode p0)	//输出链表 
 {
 	PNode p;
 	p=p0;
	if (p0!=NULL)
		do
		{
			printf("%d	",p->data);
			p=p->next;
		}while(p->data!=0);
 }
 
 void deleteNodeinList (PNode p0 ,int n)	//删除链表第n个节点 (n>1) 
 {
 	PNode p,ptr;
 	p=p0;
 	if (p0!=NULL)
 			for(int i=0;;i++){
	 			if (i==n-2) {
	 				p->next=p->next->next;
	 				break;
				 } 
	 			p=p->next;
	 			if (p==NULL) break;
		 	}
 }
 
 void newNodeinList (PNode p0 ,int n) 	//在第n个节点前插入 (n>1) 
 {
 	PNode p,pplus;
 	p=p0;
 	if (p0!=NULL)
 		for(int i=0;;i++){
 			if (i==n-2) {
 				pplus=(PNode)malloc(sizeof(Node));
 				printf("请输入要插入的数据："); 
 				scanf("%d",&pplus->data);
 				pplus->next=p->next;
 				p->next=pplus;
 				break;
			 } 
 			p=p->next;
 			if (p==NULL) break;
		 }
 }
 
 int DeleteFront(PNode &HL)		//删除链表第一位 
{
	if(HL==NULL)
	{
		printf("链表为空");
		exit(1);
	}
	PNode p=HL;
	HL=HL->next;
	int temp=p->data;
	delete(p);
	return temp;
}

 int AddFront(PNode &HL)		//插入链表第一位
{
	if(HL==NULL)
	{
		printf("链表为空");
		exit(1);
	}
	PNode p=HL,pplus;	
	pplus=(PNode)malloc(sizeof(Node));
	printf("请输入要插入的数据："); 
	scanf("%d",&pplus->data);
	pplus->next=HL;
	HL=pplus;
	return pplus->data;
}

int  checkNodeList (PNode p)		//检查链表长度 
{
	int n=0;
	while(p->next!=NULL){
		p=p->next;
		n++;
	}
	return (n);
}

void findNodeList (PNode p ,int k)		//查找元素 
{
	int i=1;
	while(p->next!=NULL){
		if (i==k) {
			printf("%d\n",p->data);
			break;
		}
		else{
			p=p->next;
			i++;
		}
	}
}
