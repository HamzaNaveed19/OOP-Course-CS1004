#include<iostream>
#include<string>
using namespace std;
int RomanToInt(string no) {
	char roman[7] = { 'I','V','X','L','C','D','M' };
	int value[7] = { 1,5,10,50,100,500,1000 };

	int sum = 0;
	int k = -1;
	for (int i = 0; i < no.length(); i++) {
		for (int j = 0; j < 7; j++) {
			if (no[i] == roman[j]) {
				k = j;
			}
		}
		if (k != -1) {
			sum += value[k];
			k = -1;
		}
	}
	for (int i = 0; i < no.length() - 1; i++) {
		if (no[i] =='I' && (no[i + 1] == 'V' || no[i + 1] == 'X')) {
			sum -= 2;
		}
	}
	for (int i = 0; i < no.length() - 1; i++) {
		if (no[i] == 'C' && (no[i + 1] == 'D' || no[i + 1] == 'M')) {
			sum -= 200;
		}
	}
	for (int i = 0; i < no.length() - 1; i++) {
		if (no[i] == 'X' && (no[i + 1] == 'C' || no[i + 1] == 'L')) {
			sum -= 20;
		}
	}
	return sum;
}
string IntToRoman(int x) {
	int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string roman[13]= { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string rom = "";
	int count = 0;
	int index = 0;
	for (int i = 0; i < 13; i++){
		count = x / values[i];
		x = x % values[i];
		if (count != 0) {
			for (int j = 0; j < count; j++) {
				rom += roman[i];
			}
		}
	}
	return rom;
}
class Roman {
	string number;
	int value;
public:
	Roman(string num ="I") {
		number = num;
		value= RomanToInt(number);
	}
	Roman operator +(Roman& obj) {
		Roman sum;
		int s1 = RomanToInt(number);
		int s2 = RomanToInt(obj.number);
		sum.value = s1 + s2;
		sum.number = IntToRoman(sum.value);
		return sum;

	}
	Roman operator -(Roman& obj) {
		Roman sub;
		int s1 = RomanToInt(number);
		int s2 = RomanToInt(obj.number);
		sub.value = s1 - s2;
		if (s1 - s2 <= 0) {
			sub.value = 0;
			cout << "undefined Subtraction ! " << endl;
			sub.number = "I";
			return sub;
		}
		sub.number = IntToRoman(sub.value);
		return sub;

	}
	Roman operator *(Roman& obj) {
		Roman product;
		int m1 = RomanToInt(number);
		int m2 = RomanToInt(obj.number);
		product.value = m1*m2;
		product.number = IntToRoman(product.value);
		return product;

	}
	Roman operator /(Roman& obj) {
		Roman quotient;
		int d1 = RomanToInt(number);
		int d2 = RomanToInt(obj.number);
		quotient.value = d1 / d2;
		if (d2 > d1) {
			cout << "undefined division ! " << endl;
			quotient.number = "I";
		}
		quotient.number = IntToRoman(quotient.value);
		return quotient;

	}
	bool operator ==(Roman& obj) {
		if (RomanToInt(number) == RomanToInt(obj.number))
			return true;
		else
			return false;
	}
	bool operator !=(Roman& obj) {
		if (RomanToInt(number) == RomanToInt(obj.number))
			return false;
		else
			return true;
	}
	bool operator <(Roman& obj) {
		if (RomanToInt(number)< RomanToInt(obj.number))
			return true;
		else if(RomanToInt(number) > RomanToInt(obj.number))
			return false;
		else {
			cout << "both numbers are equal ! " << endl;
			return true;
		}
	}
	bool operator >(Roman& obj) {
		if (RomanToInt(number) > RomanToInt(obj.number))
			return true;
		else if (RomanToInt(number) < RomanToInt(obj.number))
			return false;
		else {
			cout << "both numbers are equal ! " << endl;
			return true;
		}
	}
	void operator ++() {
		value = RomanToInt(number);
		value++;
		number = IntToRoman(value);
	}
	void operator ++(int) {
		value = RomanToInt(number);
		value++;
		number = IntToRoman(value);
	}
	void operator --() {
		value = RomanToInt(number);
		value--;
		if (value != 0)
			number = IntToRoman(value);
		else
			cout << "decrement not possible " << endl;
	}
	void operator --(int) {
		value = RomanToInt(number);
		value--;
		if (value != 0)
			number = IntToRoman(value);
		else
			cout << "decrement not possible " << endl;
	}
	int getvalue() {
		return value;
	}
	string getRoman() {
		return number;
	}

};
int main() {
	cout << "enter Roman 1st number : ";
	string s1;
	cin >> s1;
	cout << "enter Roman 2nd number : ";
	string s2;
	cin >> s2;
	Roman r1(s1);
	Roman r2(s2);
	Roman r3 = r1 + r2;
	cout << "after adding : ";
	cout << r3.getRoman() << endl;
	Roman r4 = r1 - r2;
	cout << "after subtracting : ";
	cout << r4.getRoman() << endl;
	Roman r5 = r1 * r2;
	cout << "after multiplying : ";
	cout << r5.getRoman() << endl;
	Roman r6 = r1 / r2;
	cout << "after division : ";
	cout << r6.getRoman() << endl;	
	if (r1 < r2)
		cout << "r1 is less than r2 i.e. r1<r2 " << endl;
	else
		cout << "r1 is greater than r2  i.e. r1>r2 !" << endl;
	if (r1>r2)
		cout << "r1 is greater than r2  i.e. r1>r2 !" << endl;
	else
		cout << "r1 is less than r2 i.e.  r1<r2  !" << endl;
	if (r1 == r2) {
		cout << "roman are equals ! " << endl;
	}
	else {
		cout << "not equal  !" << endl;
	}
	
	r1++;
	cout << "after increment : ";
	cout << r1.getRoman() << endl;
	--r1;
	cout << "after decrement : ";
	cout << r1.getRoman() << endl;
	system("pause");
}