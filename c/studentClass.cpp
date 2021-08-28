#include<iostream>
#include<cstring>
using namespace std;
class Student{
	public:
		Student(int ssnum=0,int ggender=0,int bbirth=0,int ggrade=0,int cclasses=0/*,string nname="NULL",string ffaculty="NULL",string mmajor="NULL"*/){
			snum=ssnum;gender=ggender;birth=bbirth;grade=ggrade;
			classes=cclasses;/*name=nname;faculty=ffaculty;major=mmajor;*/
		}
		Student(const Student &stu){
			snum=stu.snum;gender=stu.gender;birth=stu.birth;grade=stu.grade;
			classes=stu.classes;name=stu.name;faculty=stu.faculty;major=stu.major;
		}
		void scanfStudent(){
			printf("请按序输入学生的学号、姓名、性别(0为男，1为女)、出生日期、年级、班级、院系、专业\n");
			cin>>snum>>name>>gender>>birth>>grade>>classes>>faculty>>major;
		}
		void SetInfo(){
			int k=0;
			printf("请输入您想修改的学生数据\n");
			printf("1、学号 2、姓名 3、性别(0为男，1为女) 4、出生日期 5、年级 6、班级 7、院系 8、专业\n");
			scanf("%d",&k);
			if(k=1) cin>>snum;
			else if(k=3) cin>>gender;
			else if(k=4) cin>>birth;
			else if(k=5) cin>>grade;
			else if(k=6) cin>>classes;
			else if(k=2) cin>>name;
			else if(k=7) cin>>faculty;
			else cin>>major;
		}
		void Show(){
			printf("学生的资料为:\n");
			cout<<"学号:"<<snum<<endl<<"姓名:"<<name<<endl<<"性别(0为男，1为女):"<<gender<<endl<<"出生日期:"<<birth<<endl<<"年级:"<<grade<<endl<<"班级:"<<classes<<endl<<"院系:"<<faculty<<endl<<"专业:"<<major<<endl;
		}
	private:
		int snum,gender,birth,grade,classes;
		string name,faculty,major;
};
int main(){
	Student A;
	A.scanfStudent();
	A.Show();
	cout<<endl;
	A.SetInfo();
	A.Show();
	cout<<endl;
	return 0;
}
