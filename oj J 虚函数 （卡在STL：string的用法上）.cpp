#include <iostream>
#include <string>

using namespace std;
//=========================================
class Person{
protected:
    string szName;//数据
public:
    Person(string _szName):szName(_szName){}//构造函数
    virtual void Print(){//虚函数在派生类中重新定义 
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
    string type="";//STL string 容器 
    int a[100];
    for(int i=0;i<100;i++){

        a[i]=0;
    }
    //==============================================
    cin>>num;
    Person* _array[num];//1.对象指针 数组名 【size】  2.类型兼容：基类指针可指向派生类对象 

    cin>>type;//string 遇空格，回车结束输入 
    //==============================================
    while(type!="exit"){

        while(size!=num){
          if(type=="Person"){
            string _szName="";
            cin>>_szName;
            _array[size]=new Person(_szName);//动态建立对象 
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
        cin>>type;//再次输入会覆盖原有
            }
      //===========================================
        while(type[0]!='e'){//字符串里是字符
            a[type[0]-'0']++;
            cin>>type;
        }

        //=============================================
        }
        //===========================================
        for(int i=0;i<size;i++)
        {
            if(a[i]!=0){
            _array[i]->Print();}//必须用-> 
        }


    return 0;
}
/*测试时使用 
#include <iostream>
#include <string>
using namespace std;
//STL:string
int main()
{
    string t;
    cin>>t;
    cin>>t;//测试覆盖 
    cout<<t.size()<<endl;
    cout<<t<<endl;
    cout<<t.front()-'0'<<endl;//c++11 
    cout<<t[0]-'0'<<endl;
    return 0;
}
*/

