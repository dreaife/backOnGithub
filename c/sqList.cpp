#include<stdio.h>
#define maxSize 12500
struct elem_sq{
	int i,j;
	int e;
};
typedef struct sqList{
	struct elem_sq a[maxSize+1];
	int nu,mu,tu;
}sq;
void initSqList(sq &A){
	scanf("%d %d %d",&A.nu,&A.mu,&A.tu);
	for(int i=1;i<=A.tu;i++){
		scanf("%d %d %d",&A.a[i].i,&A.a[i].j,&A.a[i].e);
	}
}
void printSqList(sq A){
	printf("该矩阵为：\n");
	for(int i=1;i<=A.tu;i++){
		printf("%d	%d	%d\n",A.a[i].i,A.a[i].j,A.a[i].e);
	}
	printf("\n");
}
void tranSqList(sq &T,sq A){
	T.nu=A.mu;T.mu=A.nu;T.tu=A.tu;
	int q=1;
	for (int col=1;col<=A.mu;col++){
		for (int k=1;k<=A.tu;k++){
			if(A.a[k].j==col){
				T.a[q].i=A.a[k].j; T.a[q].j=A.a[k].i; T.a[q].e=A.a[k].e;
				q++;
			}
		}
	}
}
void QuicktranSqList(sq &T,sq A){
	T.nu=A.mu;T.mu=A.nu;T.tu=A.tu;
	int col=1,cp[A.mu]={0},num[A.mu]={0};
	int k=1;
	if(T.tu){
		for(k;k<=A.tu;k++) ++num[A.a[k].j];
		cp[1]=1;
		for(k=2;k<=A.mu;k++) cp[k]=cp[k-1]+num[k-1];
		for(k=1;k<A.tu;k++){
			T.a[cp[A.a[k].j]].i=A.a[k].j; T.a[cp[A.a[k].j]].j=A.a[k].i; T.a[cp[A.a[k].j]].e=A.a[k].e;
			cp[A.a[k].j]++;
		}
	}
}
int main(){
	sq jz,jzT;
//	initSqList(jz);
//	矩阵定义
	jz.nu=3;jz.mu=4;jz.tu=4;
	jz.a[1].i=1;	jz.a[1].j=3;	jz.a[1].e=2;
	jz.a[2].i=2;	jz.a[2].j=2;	jz.a[2].e=5;
	jz.a[3].i=3;	jz.a[3].j=1;	jz.a[3].e=8;
	jz.a[4].i=3;	jz.a[4].j=4;	jz.a[4].e=1;
	printSqList(jz);
	tranSqList(jzT,jz);
	printf("转置后");
	printSqList(jzT);
	QuicktranSqList(jzT,jz);
	printf("快速转置后");
	printSqList(jzT);
	return 0;
}
