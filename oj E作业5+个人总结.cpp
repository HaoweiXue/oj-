#include <iostream>

using namespace std;
class Vect{
     int *p;//在编写中，遇到问题的原因是多次定义int*p ，定义一次就行。 
     int Size=0;
public:



    Vect();//v1 
    Vect(int n);//v2
    Vect(const Vect& scopy );//v3
    ~Vect();

    void setArr(int m1,int n1 )const;//注意 函数名 和 变量名的定义 
    int getSize()const;
    void Output();

};


Vect::Vect()//v1
{
    Size=5;
    p=new int [Size];//注意，这里无需再次定义。 
    for(int i=0;i<Size;i++)
    {
        p[i]=i+1;
    }
}
 Vect::Vect(int n){//v2
    Size=n;
    p=new int [Size];//同上 
    for(int i=0;i<n;i++)
    {
        p[i]=0;
    }
}
Vect::Vect(const Vect& scopy ){//v3
   Size=scopy.Size;
   if(Size!=0)
   {
        p=new int[Size];
    for(int i=0;i<5;i++)
    {
        p[i]=scopy.p[i];
    }
   }
}
Vect::~Vect(){
    if(p!=NULL)
    {
        delete []p;
        p=NULL;
    }
}
void Vect::setArr(int m1,int n1)const{
   if(m1>5||m1<0){
     cout<<"out of boundary"<<endl;

   }
   else
    p[m1]=n1;
}
int Vect:: getSize()const{
    return Size;
}
 void Vect::Output(){
     int i=0;
    for( i=0;i<Size-1;i++)//再此定义的int i，生存期只限循环开始到结束。 
    {
        cout<<p[i]<<" ";
    }
    cout<<p[i]<<endl;
 }
int main()
{

    int n,m1,n1;
    cin>>n>>m1>>n1;

   Vect v1,v2(n);


   v1.Output();

   v2.Output();

   v1.setArr(m1,n1);
   Vect v3(v1);

   v1.Output();

   v3.Output();



    return 0;
}

