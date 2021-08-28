#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Grade{
    public:
        Grade(string nname,int ggrade=0):name(nname),grade(ggrade){grading();count++;};
        void PrintData() const{
            cout<<"Name:"<<name<<"  Grade:"<<grade<<"   Rank:"<<rank<<endl;
        }
        static int count;
        friend void Horl(Grade &m,Grade &n){
            if(m.grade>=n.grade) m.PrintData();
            else n.PrintData();
        }
    private:
        void grading(){
            if(grade<60) rank='E';
            else if(grade<70) rank='D';
            else if(grade<80) rank='C';
            else if(grade<90) rank='B';
            else rank='A';
        }
        int grade;
        string name;
        string rank;
};
int Grade::count=0;
int main(){

    Grade s1("Sun",100),s2("Wu",90),s3("Jiang",52),s4("Zhou"),s5("He",76),s6("Liu",88);
    cout<<"Number of students:";
    cout<<Grade::count<<endl; 
    cout<<"student who has higher grade from Sun and Jiang"<<endl;
    Horl(s1,s3);
    cout<<"data of Wu"<<endl;
    s2.PrintData();
    system("pause");
    return 0;
}