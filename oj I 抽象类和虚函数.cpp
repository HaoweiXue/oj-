#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Shape{
public:
    virtual double Area()=0;//�ṩ�ӿ�
    virtual void Show()=0;//�ṩ�ӿ�
    virtual~Shape(){}
    friend bool operator==( Shape&a ,Shape&b);//����const ��ᱨ��
    friend bool operator>( Shape&a ,Shape&b);
    friend bool operator<(Shape&a, Shape&b);
};
bool operator==( Shape&a, Shape&b){//����const ��ᱨ��--C:\Users\Admin\Desktop\2\main.cpp|15|����:��'const Shape'��Ϊ'virtual double Shape::Area()'��'this'�������ݸ�|
    if(fabs(a.Area()-b.Area())<0.00001){//cmath
        return true;
    }else
        return false;
}
bool operator>( Shape&a, Shape&b){
    return a.Area()>b.Area();
}
bool operator<( Shape&a, Shape&b){
    return a.Area()<b.Area();
}
//================================================================
class Rectangle:public Shape{
protected:
    double rectWidth;
    double rectHeight;
public:
    Rectangle(double _rectWidth,double _rectHeight):rectWidth(_rectWidth),rectHeight(_rectHeight){}

    double  Area(){
       double area=rectHeight*rectWidth;
        return area;
    }
    void Show(){
        cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;//��Ա�������Ե��ó�Ա����
    }
};
//================================================================
class Ellipse:public Shape{
protected:
    double rectWidth;
    double rectHight;
public:
    Ellipse(double _rectWidth,double _rectHight):rectWidth(_rectWidth),rectHight(_rectHight){}

    double  Area(){
       double area=3.1415926*(rectHight/2)*(rectWidth/2);
        return area;
    }
    void Show(){
         cout<<"W: "<<rectWidth<<"; H:"<<rectHight<<"; Area: "<<Area()<<endl;
    }
};
int main()
{
   int num=0,_size=0;
   string type="";
   double w=0,h=0;
   //============================
   cin>>num;
   Shape* _array[num];
   //==============================
   while(_size!=num){
    cin>>type;
    if(type=="R"){
        
        cin>>w>>h;
        _array[_size]=new Rectangle(w,h);//��̬���� 

    }else if(type=="E"){
        
        cin>>w>>h;
        _array[_size]=new Ellipse(w,h);
    }

    _size++;


   }
   //===========================
   for(int i=0;i<_size;i++)
   {
    _array[i]->Show();//_array[i]ָ��Ķ��� 

   }
   //=========================
   for(int i=0;i<_size-1;i++){
        for(int j=i+1;j<_size;j++)
            if((*_array[i])==(*_array[j])){
                cout<<"Area of Shape["<<i<<"] is equal to Shape["<<j<<"]"<<endl;
            }

   }
   //===============================================
   for(int i=0;i<_size-1;i++){
        for(int j=i+1;j<_size;j++)
            if((*_array[i])<(*_array[j])){
                Shape*s;
                s=_array[i];
                _array[i]=_array[j];
                _array[j]=s;
            }

   }
 //================================================
   for(int i=0;i<_size;i++)
   {
      _array[i]->Show();

       delete _array[i];//delete 
   }

	
    return 0;
}

