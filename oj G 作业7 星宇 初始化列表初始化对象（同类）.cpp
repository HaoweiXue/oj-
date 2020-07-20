#include<iostream>
#include<cmath>
using namespace std;
class Point
{
public:
    Point(double x,double y):m_iX(x),m_iY(y){}
    ~Point(){}
    double getX()
    {
        return m_iX;
    }
    double getY()
    {
        return m_iY;
    }
private:
    double m_iX;
    double m_iY;
};
class Line
{
public:
    Line(const Point &p1,const Point &p2):pStart(p1),pEnd(p2){}//注意：对象初始化。传数据，函数不变。 
    ~Line(){}
    double Length()
    {
        return sqrt((pStart.getX()-pEnd.getX())*(pStart.getX()-pEnd.getX())+(pStart.getY()-pEnd.getY())*(pStart.getY()-pEnd.getY()));
    }
private:
    Point pStart;
    Point pEnd;
};
class Triangle
{
public:
    Triangle(const Point &p1,const Point &p2,const Point &p3):ptA(p1),ptB(p2),ptC(p3){}
    ~Triangle(){}
    double Perimeter()
    {
        double s1,s2,s3;
        Line lab(ptA,ptB);
        Line lbc(ptB,ptC);
        Line lac(ptA,ptC);
        s1=lab.Length();
        s2=lbc.Length();
        s3=lac.Length();
        return s1+s2+s3;
    }
    double Area()
    {
        double s1,s2,s3;
        Line lab(ptA,ptB);
        Line lbc(ptB,ptC);
        Line lac(ptA,ptC);
        s1=lab.Length();
        s2=lbc.Length();
        s3=lac.Length();
        double p=(s1+s2+s3)/2;
        return sqrt(p*(p-s1)*(p-s2)*(p-s3));//海伦公式。 
    }
private:
    Point ptA;
    Point ptB;
    Point ptC;
};
int main()
{
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point pointA(x1,y1);
    Point pointB(x2,y2);
    Point pointC(x3,y3);
    Triangle t(Point(x1,y1),Point(x2,y2),Point(x3,y3));
    cout<<t.Perimeter()<<" "<<t.Area()<<endl;
    return 0;
}

