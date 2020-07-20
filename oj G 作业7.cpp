#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:
    double x;
    double y;
    Point(){
     x=y=0.0;
    }
    Point(double  x,double  y){
        this->x=x;
        this->y=y;
    }
    double Distance(Point r){
        return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
    }
    friend istream& operator>>(istream& in, Point& r);
};

class Line{
private:
    Point v0,v1;
public:
    Line(const Point& r1,const Point& r2){
        v0.x=r1.x;v0.y=r1.y;
        v1.x=r2.x;v1.y=r2.y;

    }
    double  getLinelen(){
        double  len=sqrt((v0.x-v1.x)*(v0.x-v1.x)+(v0.y-v1.y)*(v0.y-v1.y));
        return len;
    }
};
class Triangle{
private:
    Point d1,d2,d3;
public:

    Triangle(const Point&r1 ,const Point&r2,const Point&r3 ){
        d1.x=r1.x;d1.y=r1.y;
        d2.x=r2.x;d2.y=r2.y;
        d3.x=r3.x;d3.y=r3.y;
    }

    double  getTriangleArea(){
        double l1=d1.Distance(d2),l2=d1.Distance(d3),l3=d2.Distance(d3);
        double  p=(l1+l2+l3)/2;
        double  a=sqrt(p*(p-l1)*(p-l2)*(p-l3));
        return a;
    }
    double  getTrianglePerimeter(){
        double l1=d1.Distance(d2),l2=d1.Distance(d3),l3=d2.Distance(d3);
        double  p=l1+l2+l3;
        return p;
    }

};
istream& operator>>(istream& in, Point& r) {
	double  x, y;
	in >> x >> y;
	r =Point(x, y);
	return in;
}
int main()
{
    Point d1,d2,d3;
    cin>>d1>>d2>>d3;
	Triangle a(d1,d2,d3);
    cout<<a.getTrianglePerimeter()<<" "<<a.getTriangleArea();
    return 0;
}

