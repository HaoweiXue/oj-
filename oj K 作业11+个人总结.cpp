

#include <string>
#include <iostream>
#include <cassert>//assert
#include <sstream>
using namespace std;
//---------------------------------

class Rational {
public:
	//constructor
	Rational(int n, int d);
	
	Rational operator-() const;
	Rational operator+(const Rational& r) const;
	Rational operator-(const Rational& r) const;
	Rational operator*(const Rational& r) const;
	Rational operator/(const Rational& r) const;

	string toString() const;

	Rational& operator++() ;
	Rational& operator--() ;
	Rational operator++(int ) ;//int 是区分前缀和后缀的标志 
	Rational operator--(int ) ;

	friend istream& operator>>(istream& in, Rational& r);
	friend ostream& operator<<(ostream& out, const Rational& r);

	friend bool operator==(const Rational& left, const Rational& right);
	friend bool operator!=(const Rational& left, const Rational& right);
	friend bool operator<(const Rational& left, const Rational& right);
	friend bool operator<=(const Rational& left, const Rational& right);
	friend bool operator>(const Rational& left, const Rational& right);
	friend bool operator>=(const Rational& left, const Rational& right);
private:
	int deno ;
	int nume ;

	static int gcd(int m, int n);
	static int iabs(int n);
};
//---------------------------

Rational::Rational(int n, int d) {	//validate
	assert(d != 0);//宣称
	if (n == 0) {
		nume = 0;
		deno = 1;
		return;
	}
	int g = gcd(iabs(d), iabs(n));
	if (d > 0) {
		deno = d / g;
		nume = n / g;
	} else if (d < 0) {
		deno = -1 * d / g;
		nume = -1 * n / g;
	} else {
		deno = 1;
		nume = 0;
	}
}

//arithmatic operations 算术操作
Rational Rational::operator-() const {
	int d = deno;
	int n = -1 * nume;
	return Rational(n, d);
}

Rational Rational::operator+(const Rational& r) const {
	int d = deno * r.deno;
	int n = deno * r.nume + nume * r.deno;
	return Rational(n, d);
}
Rational Rational::operator-(const Rational& r) const {
	int d = deno * r.deno;
	int n = nume * r.deno - deno * r.nume;
	return Rational(n, d);
}
Rational Rational::operator*(const Rational& r) const {
	int d = deno * r.deno;
	int n = nume * r.nume;
	return Rational(n, d);
}
Rational Rational::operator/(const Rational& r) const {
	int d = deno * r.nume;
	int n = nume * r.deno;
	return Rational(n, d);
}
//conversion 转化
string Rational::toString() const {
	ostringstream val;
	val << nume;
	if (deno != 1)
		val << "/" << deno;
	return val.str();
}

Rational& Rational::operator++() {
	nume=nume+deno;
	return *this;
}
Rational& Rational::operator--() {
	nume = nume-deno;
	return *this;
}
Rational Rational::operator++(int ) {
	Rational r=*this;
    nume=nume+deno;
    return r;
}
Rational Rational::operator--(int ) {
	Rational r=*this;
    nume=nume-deno;
    return r;
}

int Rational::gcd(int m, int n) {
	int g = m < n ? m : n;
	while (g > 1) {
		if (m % g == 0 && n % g == 0)
			break;
		--g;
	}
	return g;
}

int Rational::iabs(int n) {
	if (n < 0)
		return -1 * n;
	else
		return n;
}

//relational operations
bool operator ==(const Rational& left, const Rational& right) {
	Rational temp = left - right;
	if(temp.nume == 0)
		return true;
	else
		return false;

}

bool operator !=(const Rational& left, const Rational& right) {
	return !(left == right);
}

bool operator <(const Rational& left, const Rational& right) {
	Rational temp = left - right;
	if(temp.nume < 0)
		return true;
	else
		return false;
}

bool operator <=(const Rational& left, const Rational& right) {
	return (left == right || left < right);
}

bool operator >(const Rational& left, const Rational& right) {
	return (right < left)&&(left != right);
}

bool operator >=(const Rational& left, const Rational& right) {
	return !(left < right);
}
//operator << and >>
istream& operator>>(istream& in, Rational& r) {
	int n, d;
	in >> n >> d;
	r = Rational(n, d);  //create a rational
	return in;
}
ostream& operator<<(ostream& out, const Rational& r) {
	out << r.toString();
	return out;
}

int main() {
	Rational r1(0,1),r2(0,1);
	cin >> r1>>r2;
	cout <<"a+b: "<< r1+r2 << endl;
	cout <<"a-b: "<< r1-r2<< endl;
	cout <<"a*b: "<< r1*r2<< endl;
	cout <<"a/b: "<<r1/r2 << endl;
	cout<<"-a: "<<-r1<<endl;
	cout<<"++a: "<<++r1<<endl;
	cout<<"--a: "<<--r1<<endl;
	cout<<"a++: "<<r1++<<endl;
	cout<<"a--: "<<r1--<<endl;
	cout<<"a<b: ";
	if(r1<r2)
		cout<<"true";
	else
		cout<<"false";
	cout<<endl;
	cout<<"a<=b: ";
	if(r1<=r2)
		cout<<"true";
	else
		cout<<"false";
	cout<<endl;
	cout<<"a>b: ";
	if(r1>r2)
		cout<<"true";
	else
		cout<<"false";
	cout<<endl;
	cout<<"a>=b: ";
	if(r1>=r2)
		cout<<"true";
	else
		cout<<"false";
	cout<<endl;
	return 0;
}

