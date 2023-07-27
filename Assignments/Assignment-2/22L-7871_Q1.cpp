#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
class VectorType {
	double* x;
	double* y;
	double* z;
public:
	VectorType() {
		x = new double;
		y = new double;
		z = new double;
		*x = 1;
		*y = 1;
		*z = 1;
	}
	VectorType(double a, double b, double c) {
		x = new double;
		y = new double;
		z = new double;
		*x = a;
		*y = b;
		*z = c;
	}
	VectorType(const VectorType& obj) {
		x = new double;
		y = new double;
		z = new double;
		*x = *obj.x;
		*y = *obj.y;
		*z = *obj.z;
	}
	/*~VectorType() {
		delete x;
		delete y;
		delete z;
		x = nullptr;
		y = nullptr;
		z = nullptr;
	}*/
	VectorType& operator =(const VectorType& obj);
	VectorType& operator +(const VectorType& obj);
	VectorType& operator -(const VectorType& obj);
	double& operator *(const VectorType& obj);
	void operator ++(int) {
		(*x)++;
		(*y)++;
		(*z)++;
	}
	void operator ++() {
		(*x)++;
		(*y)++;
		(*z)++;
	}
	void operator --(int) {
		(*x)--;
		(*y)--;
		(*z)--;
	}
	void operator --() {
		(*x)--;
		(*y)--;
		(*z)--;
	}
	friend bool operator ==(const VectorType& v1, const VectorType& v2);
	friend bool operator !=(const VectorType& v1, const VectorType& v2);
	friend ostream& operator <<(ostream &out,const VectorType&v1);
	friend istream& operator >>(istream& in, const VectorType& v1);
	double lenght() const {
		return sqrt((*x) * (*x) + (*y) * (*y) + (*z) * (*z));
	}
	double& angle(const VectorType& obj) {
		double x = *this * obj;
		double l1 = obj.lenght();
		double l2 = this->lenght();
		double theta = x / (l1 * l2);
		if (*this == obj) {
			theta = 0;
			return theta;
		}
		theta = acos(theta);
		theta = theta * 180 / 3.14159265;
		return theta;
	}
	void display() {
		cout << "the vector is : " << *x << "i+" << *y << "j+" << *z << "k" << endl;
	}

};
VectorType &VectorType :: operator =(const VectorType& obj) {
	if (this != &obj) {
		x = obj.x;
		y = obj.y;
		z = obj.z;
	}
	return *this;
}
double &VectorType :: operator *(const VectorType& obj) {
	double product = 0;
	product = (*x)*(*obj.x)+ (*y) * (*obj.y)+ (*z) * (*obj.z);
	return product;
}
VectorType& VectorType :: operator +(const VectorType& obj) {
	VectorType sum;
	*sum.x = *x + *obj.x;
	*sum.y = *y + *obj.y;
	*sum.z = *z + *obj.z;
	return sum;
}
VectorType& VectorType :: operator -(const VectorType& obj) {
	VectorType subtract;
	*subtract.x = *x - *obj.x;
	*subtract.y = *y - *obj.y;
	*subtract.z = *z - *obj.z;
	return subtract;
}
bool operator ==(const VectorType&v1, const VectorType& v2) {
	return ((*v1.x == *v2.x) && (*v1.y == *v2.y) && (*v1.z == *v2.z));
}
bool operator !=(const VectorType& v1, const VectorType& v2) {
	return ((*v1.x != *v2.x) || (*v1.y != *v2.y) || (*v1.z == *v2.z));
}
ostream& operator <<(ostream& out, const VectorType& v1) {
	out<<"the vector is " << *v1.x << "i+" << *v1.y << "j+" << *v1.z << "k" << endl;
	return out;
}
istream& operator >>(istream& in, const VectorType& v1) {
	cout << "enter the value of x : " << endl;
	in >> *v1.x;
	while (in.fail()) {
		cout << "you have entered wrong input : ";
		in.clear();
		in.ignore();
		in >> *v1.x;
	}
	cout << "enter the value of y : " << endl;
	in >> *v1.y;
		while (in.fail()) {
		cout << "you have entered wrong input : ";
		in.clear();
		in.ignore();
		in >> *v1.y;
	}

	cout << "enter the value of z : " << endl;
	in >> *v1.z;
	while (in.fail()) {
		cout << "you have entered wrong input : ";
		in.clear();
		in.ignore();
		in >> *v1.z;
	}

	return in;
}
int main() {
	VectorType a1(1,2,3);
	VectorType a2(1,2,3);
	cin >> a1;
	cout << a1;
	cin >> a2;
	cout << a2;
	cout << "a1 and a2 using display function respectively is : " << endl;
	a1.display();
	a2.display();
	double product=0;
	product = a1 * a2;
	cout <<"the dot product is : " << product << endl;
	double lenghtV=0;
	lenghtV = a1.lenght();
	cout << "the lenght of a1 is : " << lenghtV << endl;
	double angle = a1.angle(a2);
	cout << "the angle between the vectors is " << angle << endl;
	VectorType sum;
	sum = a1 + a2;
	cout << "the sum of a1 and a2 is : ";
	sum.display();
	VectorType subtract;
	subtract = a1 - a2;
	cout << "the difference of a1 and a2 is : ";
	subtract.display();
	system("pause");
}
