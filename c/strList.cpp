#include<stdio.h>
#include<stdlib.h>
#define strSize 100

typedef struct strList{
	char str[strSize];
	int length;
} Smode;

void clearStr(Smode &S){
	int i=0;
	while(i!=S.length){
		S.str[i]=NULL;
		S.str[i]='\0';
		i++;
	}
	S.length=0;
}

void pushStr(Smode &S,char T[]){
	clearStr(S);
	int i=0;
	while(T[i]!='\0'){
		S.str[i]=T[i];
		i++; 
	}
	S.length=i;
}

void copyStr(Smode &S,Smode ss){
	clearStr(S);
	int i=0;
	while(ss.str[i]!='\0'){
		S.str[i]=ss.str[i];
		i++;
	}
	S.length=ss.length;
}

int lengthStr(Smode S){
	return S.length;
}

int empStr(Smode &S){
	int k=0;
	if(lengthStr(S)==0) k=1;
	return k;
}


int min(int a,int b){
	if(a>b) return b; 
	else return a;
}

int compareStr(Smode S,Smode T){
	int i=0;
	while(i!=min(S.length,T.length)){
		if(S.str[i]>T.str[i]) return 1;
		else if(S.str[i]<T.str[i]) return -1;
		else ;
		i++;
	}
	if(S.length==T.length) return 0;
	else if(S.length>T.length) return 1;
	else return -1;
}

void concatStr(Smode &t,Smode s1,Smode s2){
    if (s1.length + s1.length <= strSize) {
        //装得下两个子串->直接装入
        for (int i = 0; i < s1.length; i ++) {
            t.str[i] = s1.str[i];
        }
        for (int j = 0; j < s2.length; j ++) {
            t.str[s1.length+j] = s2.str[j];
        }
        t.str[s1.length+s2.length] = '\0';
    }else if(s1.length < strSize){
        //只装得下s1和部分s2->s2需要截断
        for (int i = 0; i < s1.length; i ++) {
            t.str[i] = s1.str[i];
        }
        for (int j = 0; j < strSize - s1.length; j ++) {
            t.str[s1.length+j] = s2.str[j];
        }
        //最后一个位置设为'\0'表示结束
        t.str[strSize] = '\0';
    }else{
        //只装得下s1
        for (int i = 0; i < s1.length; i ++) {
            t.str[i] = s1.str[i];
        }
        t.str[strSize] = '\0';
    }
    t.length=s1.length+s2.length;
}

void SubStr(Smode s,Smode &sub,int pos,int len){
    if (pos<0 || pos>= s.length || len<0 || len>s.length || pos+len>s.length) {
        printf("要截取的位置或长度不合法\n");
        return;
    }
    for (int i = 0; i < len; i ++) {
        sub.str[i] = s.str[pos+i-1];
    }
    sub.str[len] = '\0';
}

int StrIndex(Smode s,Smode t,int pos){
    int i = pos-1;
    int j = 0;
    while (s.str[i]!='\0' && t.str[j]!='\0') {
        if (s.str[i] == t.str[j]) {
            i ++;
            j ++;
        }else{
            i = i-j+1;
            j = 0;
        }
    }
    if (t.str[j] == '\0') {return i-j+1;}
    return -1;
}

void printfStr(Smode S){
	printf("%s\n",S.str);
}

int main(){
	Smode s1,s2,S,sub;
	clearStr(sub);
	empStr(s1);
	printf("请输入您想输入的字符串:\n");
	char M[30];
	scanf("%s",M);
	pushStr(s1,M);
	printf("请输入您想输入的字符串:\n");
	scanf("%s",M);
	pushStr(s2,M);
	printf("两字符串大小为：\n");
	if(compareStr(s1,s2)>0) printf("%s大\n",s1.str);
	else if(compareStr(s1,s2)<0) printf("%s大\n",s2.str);
	else printf("%s %s 一样大\n",s1.str,s2.str);
	printf("合并字符串为：\n");
	concatStr(S,s1,s2);
	printfStr(S);
	printf("合并后字符串在第三位的长度为2的子串为：\n");
	SubStr(S,sub,3,2);
	printfStr(sub);
	scanf("%s",M);
	pushStr(s2,M);
	printf("合并字符串中与%s相等的位置为：\n",M);
	printf("%d",StrIndex(S,s2,1));
	return 0;
}
