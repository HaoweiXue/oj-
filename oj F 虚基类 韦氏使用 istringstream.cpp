#include <iostream>
#include <string>
#include <sstream>//注意 
using namespace std;

istringstream is_1("郑七 男 22");//注意用法 istringstream 
istringstream is_2("2010123 软20101 89");
istringstream is_3("信息 软件 1");
istringstream is_4("数据结构");
class Person
{
public:
    string Name;
    Person()
    {
        // cin>>Name>>Gender>>Age;
        is_1>>Name>>Gender>>Age;
        cout<<"Person"<<Name<<"constructed"<<endl;
    }
    ~Person()
    {
        cout<<"Person"<<Name<<"destructed"<<endl;
    }
protected:
    string Gender;
    int Age;
};
//助教类由学生类和教师类派生而来，学生类和教师类又都是从人员类派生而来。故这是一个菱形继承问题，为了避免助教类继承两份人员类数据，要使学生类和教师类的继承方式为虚继承(virtual)。 
class StudentRecord:virtual public Person
{
    public:
    string Number;
    string ClassName;
    static int TotalCount;//注意静态整形变量 
    StudentRecord()
    {
        // cin>>Number>>ClassName>>Score;
        is_2>>Number>>ClassName>>Score;
        TotalCount++;
        cout<<"Student"<<Name<<"constructed"<<endl;
    }
    ~StudentRecord()
    {
        TotalCount--;
        cout<<"Student"<<Name<<"destructed"<<endl;
    }
    protected:
    int Score;
};
int StudentRecord::TotalCount=0;//类外定义，不加static 
class TeacherRecord:virtual public Person
{
public:
    string CollegeName;
    string DepartmentName;
    TeacherRecord()
    {
        // cin>>CollegeName>>DepartmentName>>Year;
        is_3>>CollegeName>>DepartmentName>>Year;
        cout<<"teacher"<<Name<<"constructed"<<endl;
    }
    ~TeacherRecord()
    {
        cout<<"teacher"<<Name<<"destructed"<<endl;
    }
protected:
    int Year;
};

class TeachingAssistant:public StudentRecord,public TeacherRecord//派生类继承基类的 属性 和 行为 
{
    public:
    string LectureName;
    TeachingAssistant()
    {
        // cin>>LectureName;
        is_4>>LectureName;
        cout<<"teachingassistant"<<Name<<"constructed"<<endl;
    }
    ~TeachingAssistant()
    {
        cout<<"teachingassistant"<<Name<<"destructed"<<endl;
    }
    void Show()
    {
        cout<<"Name:"<<Name<<" Gender:"<<Gender<<" Age:"<<Age<<" Number:"<<Number
        <<" ClassName:"<<ClassName<<" TotalCount:"<<TotalCount<<" Score:"<<Score
        <<" CollegeName:"<<CollegeName<<" DepartmentName:"<<DepartmentName
        <<" Year:"<<Year<<" LectureName:"<<LectureName<<endl;
    }
    void SetName(string name)
    {
        Name=name;//派生类 在 成员函数中可以对 基类的 成员进行修改。 
    }
};
int main()
{
    TeachingAssistant item;
    item.Show();
    item.SetName("郑八");
    item.Show();
    return 0;
}


