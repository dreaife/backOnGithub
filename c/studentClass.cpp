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
			printf("�밴������ѧ����ѧ�š��������Ա�(0Ϊ�У�1ΪŮ)���������ڡ��꼶���༶��Ժϵ��רҵ\n");
			cin>>snum>>name>>gender>>birth>>grade>>classes>>faculty>>major;
		}
		void SetInfo(){
			int k=0;
			printf("�����������޸ĵ�ѧ������\n");
			printf("1��ѧ�� 2������ 3���Ա�(0Ϊ�У�1ΪŮ) 4���������� 5���꼶 6���༶ 7��Ժϵ 8��רҵ\n");
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
			printf("ѧ��������Ϊ:\n");
			cout<<"ѧ��:"<<snum<<endl<<"����:"<<name<<endl<<"�Ա�(0Ϊ�У�1ΪŮ):"<<gender<<endl<<"��������:"<<birth<<endl<<"�꼶:"<<grade<<endl<<"�༶:"<<classes<<endl<<"Ժϵ:"<<faculty<<endl<<"רҵ:"<<major<<endl;
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
