#include <iostream>
#include <string>
#include <list>//用到list库 
using namespace std;//针对问题，解决问题。找对位置，一个方法不行就尝试新的方法，不断尝试，不断尝试，加油！
//类类型 对象==int x  
//======================================

class StudentRecord{
    string stuName;
    int stuNo;
public:
    StudentRecord(){}
    StudentRecord(string stuNa,int stuN):stuName(stuNa),stuNo(stuN){}
    void print(){
    cout<<"Name: "<<stuName<<", "<<"Number: "<<stuNo<<endl;
    };

};
//=====================================
class StudentList{
private:
     list<StudentRecord>stu;//list 库函数使用
public:
    void insert_front(StudentRecord record);
    void insert_back(StudentRecord record);
    void del_front();
    void del_back();
    StudentRecord front();
    StudentRecord back();
     bool empty();

};
void StudentList::insert_front(StudentRecord record){
    stu.push_front(record);
}
void StudentList::insert_back(StudentRecord record){
    stu.push_back(record);
}
bool StudentList::empty(){
    return stu.empty();
}
void StudentList::del_front(){
    if(stu.empty())
        return;
    stu.pop_front();

}
void StudentList::del_back(){
     if(stu.empty())
        return ;
    stu.pop_back();

}
StudentRecord StudentList::front(){
    return stu.front();
}
StudentRecord StudentList::back(){
    return stu.back();
}
//===================================================
class ListStack:public StudentList{//公有继承 可以使用StudentList类的成员函数 
private:
    StudentList Stack;
public:

    void Push(StudentRecord record)
    {
        Stack.insert_front(record);//对象调用自己的函数改变自己的数据。 
    }
    void Pop(){
        Stack.del_front();

    }

    StudentRecord front(){
        return Stack.front();
    }
    bool empty(){
        return Stack.empty();
    }

};
//-============================================
class ListQueue:public StudentList{
private:
    StudentList Queue;
public:
    void EnQueue(StudentRecord record){
        Queue.insert_front(record);
    }
    void DeQueue(){
        Queue.del_back();
    }
    StudentRecord back(){
        return Queue.back();
    }
    bool empty(){
        return Queue.empty();
    }
};
//=================================================

int main()
{
  	ListQueue Queue;
  	ListStack Stack;
  	string order;
  	string stuName;
  	int stuNo=0;
  	int pop=0,deq=0,x=0,k1=0,k2=0;
  	//==============================================
  	cin>>order;
  	while(1){
      	if(order=="Pop"){k1++;}
       else if(order=="DeQueue"){  k2++;}
       else if(order=="Push"||order=="EnQueue"){
            break;
        }
        cin>>order;

  	}
  	//==============================
  	while(1){
    if(order=="Push"){
        cin>>stuName>>stuNo;

        Stack.Push( StudentRecord (stuName,stuNo));

  	}else if(order=="EnQueue"){

        cin>>stuName>>stuNo;

        Queue.EnQueue( StudentRecord (stuName,stuNo));

//===============================================

  	}else if(order=="Pop"){

            pop++;
  	}else if(order=="DeQueue"){
      deq++;




  	}else if(order=="Exit"){
        break;
  	}else{
        x=1;
  	}
  	cin>>order;

}
while(k1!=0){
  cout<<"Stack is empty!"<<endl;
  k1--;

}
while(k2!=0){
    cout<<"Queue is empty!"<<endl;
    k2--;

}
//===================================
 while(pop!=0){
    if(!Stack.empty())//非空
        {
            StudentRecord c(Stack.front());//用对象初始化对象 
            c.print();
            Stack.Pop();

        }
        else{
            cout<<"Stack is empty!"<<endl;
        }
        pop--;

 }
 //================================

 while(deq!=0){

    if(!Queue.empty()){//非空

            StudentRecord d(Queue.back());
            d.print();
            Queue.DeQueue();

  	    }
  	    else{
            cout<<"Queue is empty!"<<endl;
  	    }
  	    deq--;
 }
if(x==1)
{
    cout<<"Input error!";
}
  return 0;
}

