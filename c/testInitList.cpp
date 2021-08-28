#include<stdio.h>
#include<stdlib.h>
#define Stack_SIZE	10
#define StackaddN 10

typedef struct stackList{
	int *top;
	int *base;
	int Length;
}  Smode;

int initStack(Smode &Slist){
	Slist.base=(int*)malloc(Stack_SIZE*sizeof(stackList));
	if(!*Slist.base){
		printf("�����ʼ������\n");
		return 0;
	}
	Slist.top=Slist.base;
	Slist.Length=Stack_SIZE;
	return 0;
}

int checkStack(Smode Slist){
	if (Slist.top-Slist.base==Slist.Length){
			printf("��������\n");
			return 1;
		}
	else
		return 0;
}

void push(Smode &Slist,int a){
	int ck;
	ck=checkStack(Slist);
	if(ck==1){
		Slist.base=(int*)realloc(Slist.base,(Slist.Length+StackaddN)*sizeof(stackList));
		Slist.top=Slist.base+Slist.Length;
		Slist.Length+=StackaddN;
		printf("������������\n"); 
	}
		*Slist.top=a;
		Slist.top++;
}

void pop(Smode &Slist,int &a){
		a=*--Slist.top;
}

void breakList(Smode &Slist){
	free(Slist.base);
}

void printfStack(Smode Slist){
	int i=1;
	int sl=Slist.top-Slist.base;
	Slist.top=Slist.base;	
	while (i<=sl){
		printf("%d\n",*Slist.top);
		i++;
		Slist.top++;
	}
}

int EmptyStack(Smode Slist){
	if(Slist.top==Slist.base) return 1;
	else return 0;
}


int main(){
	int k=0,shu=0,kk=0,i=0;
	for(i=1;;i==0){
		Smode jinzhi;
		initStack(jinzhi);
		k=0,shu=0,kk=0,i=0;
		printf("������������еĲ�����\n");
		printf("1��10����ת2����\n2��2����ת10����\n0���˳�����\n");
		scanf("%d",&k);
		switch (k){
		case 1:{
			printf("��������Ҫת������:\n");
			scanf("%d",&shu);
			int aa=0; 
			while(shu/2!=0){
				aa=shu%2;
				push(jinzhi,aa);
				shu=shu/2;
			}
			if(shu==1) push(jinzhi,1);
			shu=0;
			while(kk!=1){
				pop(jinzhi,aa);
				shu=shu*10+aa;
				kk=EmptyStack(jinzhi);
			}
			printf("ת�������Ϊ%d\n",shu);
			break;
		}
		case 2:{
			int k1=0;
			printf("��������Ҫת������:\n");
			scanf("%d",&shu);
			while(shu/10!=0){
				push(jinzhi,shu%10);
				shu=shu/10;
			}
			if(shu==1) push(jinzhi,1);
			shu=0;
			while(kk!=1){
				pop(jinzhi,k1);
				shu=shu*2+k1;
				kk=EmptyStack(jinzhi);
			}
			printf("ת�������Ϊ%d\n",shu);
			break;
		}
		default:{
			return 0;
		}
	}
	breakList(jinzhi);
	}
	return 0;
}
