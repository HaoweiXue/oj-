#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    string Name;
    Person(string _name="֣��",string _gender="��",int _age=22 ):Name(_name),Gender(_gender),Age(_age){
    cout<<"Person֣��constructed"<<endl;
    }
    ~Person(){
    cout<<"Person֣��destructed"<<endl;
    }
protected:
    string Gender;
    int Age;

};
class StudentRecord: virtual public Person{
public:
    string Number,ClassName;
    static int TotalCount;
    StudentRecord(string _number="2010123",string _classname="��20101",int _score=89):Number(_number),ClassName(_classname),Score(_score){
    cout<<"Student֣��constructed"<<endl;
    }
    ~StudentRecord(){
    cout<<"Student֣��destructed"<<endl;
    }
protected:
    int Score;

};
 int StudentRecord::TotalCount=1;
class TeacherRecord:virtual public Person{
public:
	string CollegeName,DepartmentName;
	TeacherRecord(string _collegename="��Ϣ",string _departmentname="���",int _year=1):CollegeName(_collegename),DepartmentName(_departmentname),Year(_year){
    cout<<"teacher֣��constructed"<<endl;
	}
	~TeacherRecord(){
    cout<<"teacher֣��destructed"<<endl;
	}
protected:
	int Year;



};
class TeachingAssistant:public StudentRecord,public TeacherRecord{
public:
    string LectureName;
    TeachingAssistant(string _lecturename="���ݽṹ"):LectureName(_lecturename){
    cout<<"teachingassistant֣��constructed"<<endl;
    }
    ~TeachingAssistant(){
    cout<<"teachingassistant֣��destructed"<<endl;
    }
    void OutPut(){//�������� �� ��Ա���� �п���ʹ�û���� ���Ժ���Ϊ ����Ϊ������̳��˻�������Ժ���Ϊ�� 
        cout<<"Name:"<<Name<<" Gender:"<<Gender<<" Age:"<<Age<<" Number:"<<Number<<" ClassName:"<< ClassName<<" TotalCount:"<<TotalCount<<" Score:"<<Score<<" CollegeName:"<<CollegeName<<" DepartmentName:"<<DepartmentName<<" Year:"<<Year<<" LectureName"<<LectureName<<endl;

           }
    void SetName(string name){//�������� �� ��Ա���� �п����޸Ļ���� ���Ժ���Ϊ ����Ϊ������̳��˻�������Ժ���Ϊ��  
        Name=name;
    }

};
int main()
{
    TeachingAssistant ta;
    ta.OutPut();
    ta.SetName("֣��");
    ta.OutPut();
    return 0;
}

