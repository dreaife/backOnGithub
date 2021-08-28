#include<iostream>
#include<windows.h>
using namespace std;
class Matrix
{
public:
	Matrix(int size=2){
        this->size=size;
        elements=new int[size*size];
    }
	Matrix(const Matrix &M){
        size=M.size;
        for(int i=0;i<size*size;i++){
            elements[i]=M.elements[i];
        }
    }
    ~Matrix(){delete[] elements;}
	void setMatrix(const int *value){
        for(int i=0;i<size*size;i++){
            elements[i]=value[i];
        }
    }
	Matrix operator + (Matrix &m){
        Matrix temp(size);
        for(int i=0;i<size*size;i++){
            temp.elements[i]=m.elements[i]+elements[i];
        }
        return temp;
    }
	Matrix operator * (Matrix &m){
        Matrix temp(size);
        int t[size*size];
        memset(t,0,sizeof(t));
        temp.setMatrix(t);
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                for(int k=0;k<size;k++)
                    temp.elements[i*size+j]+=elements[i*size+k]*m.elements[k*size+j];
        return temp;
    }
	friend ostream &operator << (ostream &out,const Matrix &m){
        for(int i=0;i<m.size;i++){
            for(int j=0;j<m.size;j++){
                out<<m.elements[i*m.size+j]<<"\t";
            }
            out<<endl;
        }
        return out;
    } 
    int getSize() const {return size;}       //得到矩阵大小
    int &element(int i,int j) {return elements[i*size+j];}//获取元素
    int element(int i,int j) const {return elements[i*size+j];}
private:
	int size;           //矩阵的大小
    int *elements;      //用于存放数组的首地址
};
int main(void)
{
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	Matrix m1(3);
	m1.setMatrix(*a);
	
	Matrix m2(3);
	m2.setMatrix(*b);
	
	Matrix m3 = m1+m2;
	Matrix m4 = m1*m2;
	
	cout << "m3 = " << endl << m3 << endl;
	cout << "m4 = " << endl << m4 << endl;
	system("pause");
    return 0;
}