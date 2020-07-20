#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    string Name;
    Person(string _name="郑七",string _gender="男",int _age=22 ):Name(_name),Gender(_gender),Age(_age){
    cout<<"Person郑七constructed"<<endl;
    }
    ~Person(){
    cout<<"Person郑八destructed"<<endl;
    }
protected:
    string Gender;
    int Age;

};
class StudentRecord: virtual public Person{
public:
    string Number,ClassName;
    static int TotalCount;
    StudentRecord(string _number="2010123",string _classname="软20101",int _score=89):Number(_number),ClassName(_classname),Score(_score){
    cout<<"Student郑七constructed"<<endl;
    }
    ~StudentRecord(){
    cout<<"Student郑八destructed"<<endl;
    }
protected:
    int Score;

};
 int StudentRecord::TotalCount=1;
class TeacherRecord:virtual public Person{
public:
	string CollegeName,DepartmentName;
	TeacherRecord(string _collegename="信息",string _departmentname="软件",int _year=1):CollegeName(_collegename),DepartmentName(_departmentname),Year(_year){
    cout<<"teacher郑七constructed"<<endl;
	}
	~TeacherRecord(){
    cout<<"teacher郑八destructed"<<endl;
	}
protected:
	int Year;



};
class TeachingAssistant:public StudentRecord,public TeacherRecord{
public:
    string LectureName;
    TeachingAssistant(string _lecturename="数据结构"):LectureName(_lecturename){
    cout<<"teachingassistant郑七constructed"<<endl;
    }
    ~TeachingAssistant(){
    cout<<"teachingassistant郑八destructed"<<endl;
    }
    void OutPut(){//在派生类 的 成员函数 中可以使用基类的 属性和行为 ；因为派生类继承了基类的属性和行为。 
        cout<<"Name:"<<Name<<" Gender:"<<Gender<<" Age:"<<Age<<" Number:"<<Number<<" ClassName:"<< ClassName<<" TotalCount:"<<TotalCount<<" Score:"<<Score<<" CollegeName:"<<CollegeName<<" DepartmentName:"<<DepartmentName<<" Year:"<<Year<<" LectureName"<<LectureName<<endl;

           }
    void SetName(string name){//在派生类 的 成员函数 中可以修改基类的 属性和行为 ；因为派生类继承了基类的属性和行为。  
        Name=name;
    }

};
int main()
{
    TeachingAssistant ta;
    ta.OutPut();
    ta.SetName("郑八");
    ta.OutPut();
    return 0;
}

