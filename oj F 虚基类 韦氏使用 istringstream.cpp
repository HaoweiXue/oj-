#include <iostream>
#include <string>
#include <sstream>//ע�� 
using namespace std;

istringstream is_1("֣�� �� 22");//ע���÷� istringstream 
istringstream is_2("2010123 ��20101 89");
istringstream is_3("��Ϣ ��� 1");
istringstream is_4("���ݽṹ");
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
//��������ѧ����ͽ�ʦ������������ѧ����ͽ�ʦ���ֶ��Ǵ���Ա������������������һ�����μ̳����⣬Ϊ�˱���������̳�������Ա�����ݣ�Ҫʹѧ����ͽ�ʦ��ļ̳з�ʽΪ��̳�(virtual)�� 
class StudentRecord:virtual public Person
{
    public:
    string Number;
    string ClassName;
    static int TotalCount;//ע�⾲̬���α��� 
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
int StudentRecord::TotalCount=0;//���ⶨ�壬����static 
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

class TeachingAssistant:public StudentRecord,public TeacherRecord//������̳л���� ���� �� ��Ϊ 
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
        Name=name;//������ �� ��Ա�����п��Զ� ����� ��Ա�����޸ġ� 
    }
};
int main()
{
    TeachingAssistant item;
    item.Show();
    item.SetName("֣��");
    item.Show();
    return 0;
}


