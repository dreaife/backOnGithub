#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node,*PNode;

int main()
{ 
	PNode creatNodeList();					//�������� 
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
		printf("��ѡ��������еĲ�����\n");
		printf("1.��������\n"); 
		printf("2.ɾ��Ԫ��\n"); 
		printf("3.����Ԫ��\n");
		printf("4.����Ԫ��\n");
		printf("0.��������\n");
		scanf("%d",&k);
		switch(k){
			case 1:{
				PList=creatNodeList();
				while(PList==NULL){
					printf("�����������Ϊ��,���������룺\n");
					PList=creatNodeList();
				}
				printf("�����������Ϊ��\n"); 
				printNodeList(PList);
				printf("\n");
				system("pause");
				break;
			} 
			case 2:{
				if (PList==NULL){
					printf("������������\n");
					break;
				}
				printf("����������ɾ�������ݵ�λ��:");
				scanf("%d",&n);
				NodeLong=checkNodeList(PList);
				while(n<=0||n>NodeLong) {
					printf("�������λ������ȷ�������������ڵ�λ��\n");
					printf("����������ɾ�������ݵ�λ��:");
					scanf("%d",&n);
				}
				if (n==1)
					DeleteFront(PList);
				else	
					deleteNodeinList(PList,n);
				printf("\nɾ���������Ϊ��\n");
				printNodeList(PList);
				printf("\n");
				system("pause");
				break;
			}
			case 3:{
				if (PList==NULL){
					printf("������������\n");
					break;
				}
				printf("�����������������ݵ�λ��:");
				scanf("%d",&n);
				NodeLong=checkNodeList(PList);
				while(n<=0||n>NodeLong) {
					printf("�������λ������ȷ�������������ڵ�λ��\n");
					printf("�����������������ݵ�λ��:");
					scanf("%d",&n);
				}
				if (n==1)
					AddFront(PList);
				else 
					newNodeinList(PList,n);	
				printf("����������Ϊ��\n");
				printNodeList(PList);
				printf("\n");
				system("pause");
				break;
			}
			case 4:{
				if (PList==NULL){
					printf("������������\n");
					break;
				}
				printf("������������ҵ����ݵ�λ��:");
				scanf("%d",&n);
				NodeLong=checkNodeList(PList);
				while(n<=0||n>NodeLong) {
					printf("�������λ������ȷ�������������ڵ�λ��\n");
					printf("������������ҵ����ݵ�λ��:");
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
 
 PNode creatNodeList()		//�������� 
 {
	int n=0;
	printf("������������������ݣ�\n"); 
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
 
 void printNodeList(PNode p0)	//������� 
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
 
 void deleteNodeinList (PNode p0 ,int n)	//ɾ�������n���ڵ� (n>1) 
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
 
 void newNodeinList (PNode p0 ,int n) 	//�ڵ�n���ڵ�ǰ���� (n>1) 
 {
 	PNode p,pplus;
 	p=p0;
 	if (p0!=NULL)
 		for(int i=0;;i++){
 			if (i==n-2) {
 				pplus=(PNode)malloc(sizeof(Node));
 				printf("������Ҫ��������ݣ�"); 
 				scanf("%d",&pplus->data);
 				pplus->next=p->next;
 				p->next=pplus;
 				break;
			 } 
 			p=p->next;
 			if (p==NULL) break;
		 }
 }
 
 int DeleteFront(PNode &HL)		//ɾ�������һλ 
{
	if(HL==NULL)
	{
		printf("����Ϊ��");
		exit(1);
	}
	PNode p=HL;
	HL=HL->next;
	int temp=p->data;
	delete(p);
	return temp;
}

 int AddFront(PNode &HL)		//���������һλ
{
	if(HL==NULL)
	{
		printf("����Ϊ��");
		exit(1);
	}
	PNode p=HL,pplus;	
	pplus=(PNode)malloc(sizeof(Node));
	printf("������Ҫ��������ݣ�"); 
	scanf("%d",&pplus->data);
	pplus->next=HL;
	HL=pplus;
	return pplus->data;
}

int  checkNodeList (PNode p)		//��������� 
{
	int n=0;
	while(p->next!=NULL){
		p=p->next;
		n++;
	}
	return (n);
}

void findNodeList (PNode p ,int k)		//����Ԫ�� 
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
