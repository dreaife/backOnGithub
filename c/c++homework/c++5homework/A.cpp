#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
class Student{
    public:
        Student(string a,string b,string c,string d):num(a),name(b),gender(c),major(d){}
        Student(Student &a):num(a.num),name(a.name),gender(a.gender),major(a.major){}
        void display(){
            cout<<"学号:"<<num<<"\t姓名:"<<name<<"\t性别:"<<gender<<"\t专业:"<<major<<endl;
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
            cout<<"导师:"<<tutor<<"\t津贴:"<<allowance<<"\t研究方向:"<<research<<endl;
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