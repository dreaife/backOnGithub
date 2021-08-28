#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
class Student{
    public:
        Student(string a,string b,string c,string d):num(a),name(b),gender(c),major(d){}
        Student(Student &a):num(a.num),name(a.name),gender(a.gender),major(a.major){}
        void display(){
            cout<<"ѧ��:"<<num<<"\t����:"<<name<<"\t�Ա�:"<<gender<<"\tרҵ:"<<major<<endl;
        }
    private:
        string num,name,major,gender;
};
class PostGraduate:public Student{
    public:
        PostGraduate(string a,string b,string c,string d,string e,string f,string g):Student(a,b,c,d),tutor(e),allowance(f),research(g){}
        PostGraduate(Student A,string e,string f,string g):Student(A),tutor(e),allowance(f),research(g){}
        void display(){
            Student::display();
            cout<<"��ʦ:"<<tutor<<"\t����:"<<allowance<<"\t�о�����:"<<research<<endl;
        }
    private:
        string tutor,allowance,research;
};
int main(){
    Student s1("20190001", "Michael","Male", "Computer Science");
    cout<<"Student Class:"<<endl;
    s1.display();
    cout<<endl;
    PostGraduate p1(s1,"Liu","1000","Deep learning");
    cout<<"PostGraduate Class:"<<endl;
    p1.display();
    system("pause");
    return 0;
}