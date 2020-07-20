#include <iostream>
#include <string>

using namespace std;
//=========================================
class Person{
protected:
    string szName;//����
public:
    Person(string _szName):szName(_szName){}//���캯��
    virtual void Print(){//�麯���������������¶��� 
        cout<<"Person "<<szName<<endl;
    }
};
//======================================
class Student:public Person{
protected:
    int iNumber;
public:
    Student(string _szName,int _iNumber):Person(_szName),iNumber(_iNumber){}
    void Print(){
        cout<<"Student "<<szName<<" "<<iNumber<<endl;
    }

};
class Teacher:public Person{
protected:
    int iYear;
public:
    Teacher(string _szName,int _iYear):Person(_szName),iYear(_iYear){}
    void Print(){
        cout<<"Teacher "<<szName<<" "<<iYear<<endl;
    }
};
class Graduate:public Student{
protected:
    string szResearch;
public:
    Graduate(string _szName,int _iNumber,string _szResearch):Student(_szName,_iNumber),szResearch(_szResearch){}
    void Print(){
        cout<<"Graduate "<<szName<<" "<<iNumber<<" "<<szResearch<<endl;
    }
};
int main()
{
    int num=0,size=0;
    string type="";//STL string ���� 
    int a[100];
    for(int i=0;i<100;i++){

        a[i]=0;
    }
    //==============================================
    cin>>num;
    Person* _array[num];//1.����ָ�� ������ ��size��  2.���ͼ��ݣ�����ָ���ָ����������� 

    cin>>type;//string ���ո񣬻س��������� 
    //==============================================
    while(type!="exit"){

        while(size!=num){
          if(type=="Person"){
            string _szName="";
            cin>>_szName;
            _array[size]=new Person(_szName);//��̬�������� 
        }else if(type=="Student"){
            string _szName="";
            int _iNumber=0;
            cin>>_szName>>_iNumber;
            _array[size]=new Student(_szName,_iNumber);
        }else if(type=="Graduate"){
            string _szName="",_szResearch="";
            int _iNumber=0;
            cin>>_szName>>_iNumber>>_szResearch;
            _array[size]=new Graduate(_szName,_iNumber,_szResearch);
        }else if(type=="Teacher"){
            string _szName="";
            int _iYear=0;
            cin>>_szName>>_iYear;
            _array[size]=new Teacher(_szName,_iYear);
        }else{
            cout<<"Input Error!"<<endl;
        }
        size++;
        cin>>type;//�ٴ�����Ḳ��ԭ��
            }
      //===========================================
        while(type[0]!='e'){//�ַ��������ַ�
            a[type[0]-'0']++;
            cin>>type;
        }

        //=============================================
        }
        //===========================================
        for(int i=0;i<size;i++)
        {
            if(a[i]!=0){
            _array[i]->Print();}//������-> 
        }


    return 0;
}
/*����ʱʹ�� 
#include <iostream>
#include <string>
using namespace std;
//STL:string
int main()
{
    string t;
    cin>>t;
    cin>>t;//���Ը��� 
    cout<<t.size()<<endl;
    cout<<t<<endl;
    cout<<t.front()-'0'<<endl;//c++11 
    cout<<t[0]-'0'<<endl;
    return 0;
}
*/

