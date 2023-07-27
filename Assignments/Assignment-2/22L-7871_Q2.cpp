#include<iostream>
#include<string>
using namespace std;
string IntConverter(int n) {
	bool isPositive = true;
	if (n < 0) {
		isPositive = false;
		n *= -1;
	}
	string str = "";
	int i = 0;
	while (n != 0) {
		str= char(n % 10+48) + str;
		n = n / 10;
	}
	if (!isPositive) {
		str = "-" + str;
	}
	return str;
}
float getdecimalpart(double  x) {
	float y = (int)x;
	float dif = x - y;
	int i = 0;
	for (i = 0; dif - (int)dif != 0; i++) {
		dif = dif * 10;
	}
	return dif;
}
class STRING {
	char* str;
public:
	STRING() {
		str = new char[1000];
	}
	void input() {
		cout << "enter the string : ";
		cin.getline(str, 1000);
	}
	int lenght() {
		int n = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			n++;
		}
		return n;
	}
	void uppercase() {
		for (int i = 0; i < lenght(); i++) {
			if (str[i] != ' ' && str[i] != '.') {
				str[i] = str[i] - 32;
			}
		}
	}
	void lowercase() {
		for (int i = 0; i < lenght(); i++) {
			if (str[i] != ' ' && str[i] != '.') {
				str[i] = str[i] + 32;
			}
		}
	}
	void display() {
		for (int i = 0; i < lenght(); i++) {
			cout << str[i];
		}cout << endl;
	}
	char at(int& index) {
		if (str[index] != ' ' && index >= 0 && index <= lenght()) {
			return str[index];
		}
		else {
			cout << "not valid index!!! " << endl;
		}
	}
	char* substring(int& start, int& end) {
		if (start >= 0 && end <= lenght()) {
			int k = 0;
			char* substring = new char[end - start+1];
			for (int i = start; i <= end; i++) {
				substring[k++] = str[i];
			}
			substring[k] = '\0';
			return substring;
		}
		else {
			cout << "invalid start or end!" << endl;
		}
	
	}
	int index(string& sub) {
		int k = 0;
		for (int i = 0; i < lenght(); i++) {
			if (sub[0] == str[i]) {
				k = 0;
				for (int j = i; j < sub.length()+i; j++) {
					if (sub[k] == str[j]) {
						k++;
					}
					else {
						break;
					}
				}
				if (k == sub.length()) {
					return i;
				}
			}
		}
		return lenght() + 5;
	}
	bool compare( STRING& obj) {

		if (lenght() == obj.lenght()) {
			for (int i = 0; i < lenght(); i++) {
				if (str[i] != obj.str[i]) {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	STRING Append( STRING& s2) {
		STRING concate;
		int i = 0;
		for ( i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		for (int k=0; k<  s2.lenght() + 1; k++) {
			concate.str[i++] = s2.str[k];
		}
		concate.str[i] = '\0';
		return concate;
	}
	STRING Prepend(STRING& s2) {
		STRING concate;
		int i = 0;
		for (i = 0; i < s2.lenght(); i++) {
			concate.str[i] = s2.str[i];
		}
		concate.str[i++] = ' ';
		for (int k = 0; k < lenght() + 1; k++) {
			concate.str[i++] =str[k];
		}
		concate.str[i] = '\0';
		return concate;
	}
	STRING Append(int & n) {
		STRING concate;
		int i = 0;
		for (i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		string intData = IntConverter(n);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i] = '\0';

		return concate;
	}
	STRING Prepend(int& n) {
		STRING concate;
		int i = 0;
		string DATA = IntConverter(n);
		for (i; i < DATA.length(); i++) {
			concate.str[i] = DATA[i];
		}
		concate.str[i++] = ' ';
		for (int j = 0; j < lenght(); j++) {
			concate.str[i++] = str[j];
		}
		concate.str[i] = '\0';
		return concate;
	}
	STRING Append(double n) {
		STRING concate;
		int i = 0;
		for (i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		int x = n;
		string intData = IntConverter(x);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i++] = '.';
		float a = getdecimalpart(n);
		int z = a;
		intData = IntConverter(z);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i] = '\0';

		return concate;
	}
	STRING Prepend(double n) {
		STRING concate;
		int i = 0;
		int x = n;
		string intData = IntConverter(x);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i++] = '.';
		float a = getdecimalpart(n);
		int z = a;
		intData = IntConverter(z);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i++] = ' ';
		for (int j=0 ; j < lenght(); j++) {
			concate.str[i++] = str[j];
		}
		concate.str[i] = '\0';

		return concate;
	}
	STRING Append(char &a) {
		STRING concate;
		int i = 0;
		for ( i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		concate.str[i++] = a;
		concate.str[i] = '\0';
		return concate;
	}
	STRING Prepend(char& a) {
		STRING concate;
		int i = 0;
		concate.str[i++] = a;
		concate.str[i++] = ' ';
		for (int j = 0; j <lenght(); j++, i++) {
			concate.str[i] = str[j];
		}
		concate.str[i] = '\0';
		return concate;
	}
	STRING operator +(STRING& obj) {
		STRING concate;
		int i = 0;
		for (i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		for (int k = 0; k < obj.lenght() + 1; k++) {
			concate.str[i++] = obj.str[k];
		}
		concate.str[i] = '\0';
		return concate;
	}
	STRING operator +(int& n) {
		STRING concate;
		int i = 0;
		for (i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		string intData = IntConverter(n);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i] = '\0';

		return concate;
	}
	STRING operator +(double& n) {
		STRING concate;
		int i = 0;
		for (i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		int x = n;
		string intData = IntConverter(x);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i++] = '.';
		float a = getdecimalpart(n);
		int z = a;
		intData = IntConverter(z);
		for (int j = 0; j < intData.length(); j++) {
			concate.str[i++] = intData[j];
		}
		concate.str[i] = '\0';

		return concate;

	}
	STRING operator +(char& a) {
		STRING concate;
		int i = 0;
		for (i = 0; i < lenght(); i++) {
			concate.str[i] = str[i];
		}
		concate.str[i++] = ' ';
		concate.str[i++] = a;
		concate.str[i] = '\0';
		return concate;
	}
	void operator =(STRING & obj) {
		delete[]str;
		str = new char[obj.lenght()];
		int i = 0;
		for ( i = 0; i < obj.lenght(); i++) {
			str[i] = obj.str[i];
		}
		str[i] = '\0';
	}
	bool operator ==(STRING& obj) {
		if (lenght() == obj.lenght()) {
			for (int i = 0; i < lenght(); i++) {
				if (str[i] != obj.str[i]) {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	bool operator !=(STRING& obj) {
		if (lenght() != obj.lenght()) {
			return true;
		}
		else {
			for (int i = 0; i < lenght(); i++) {
				if (str[i] == obj.str[i]) {
					continue;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
	bool operator <(STRING& obj) {
		if (lenght() == obj.lenght()) {
			for (int i = 0; i < lenght(); i++) {
				if (str[i] == obj.str[i]) {
					continue;
				}
				else {
					if ((int)str[i] < (int)obj.str[i]) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
		else {
			if (lenght() < obj.lenght())
				return true;
			else
				return false;
		}
		return false;
	}
	bool operator >(STRING& obj) {
		if (lenght() == obj.lenght()) {
			for (int i = 0; i < lenght(); i++) {
				if (str[i] == obj.str[i]) {
					continue;
				}
				else {
					if ((int)str[i] > (int)obj.str[i]) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
		else {
			if (lenght() > obj.lenght())
				return true;
			else
				return false;
		}
		return false;
	}

	char& operator [](int &x) {
		if (x >= 0 && x < lenght())
			return str[x];
	}
	friend STRING& operator +(int& n, STRING& obj);
	friend STRING& operator +(double& n, STRING& obj);
	friend STRING& operator +(char& A, STRING& obj);
	friend istream& operator >>(istream& input,STRING & obj);
	friend ostream& operator <<(ostream& output, STRING& obj);
};
STRING& operator +(int& n, STRING& obj) {
	STRING concate;
	int i = 0;
	string DATA = IntConverter(n);
	for (i; i < DATA.length(); i++) {
		concate.str[i] = DATA[i];
	}
	concate.str[i++] = ' ';
	for (int j = 0; j < obj.lenght(); j++) {
		concate.str[i++] = obj.str[j];
	}
	concate.str[i] = '\0';
	return concate;
}
STRING& operator +(double& n, STRING& obj) {
	STRING concate;
	int i = 0;
	int x = n;
	string intData = IntConverter(x);
	for (int j = 0; j < intData.length(); j++) {
		concate.str[i++] = intData[j];
	}
	concate.str[i++] = '.';
	float a = getdecimalpart(n);
	int z = a;
	intData = IntConverter(z);
	for (int j = 0; j < intData.length(); j++) {
		concate.str[i++] = intData[j];
	}
	concate.str[i++] = ' ';
	for (int j = 0; j < obj.lenght(); j++) {
		concate.str[i++] = obj.str[j];
	}
	concate.str[i] = '\0';

	return concate;
}
STRING& operator +(char& a, STRING& obj) {
	STRING concate;
	int i = 0;
	concate.str[i++] = a;
	concate.str[i++] = ' ';
	for (int j=0; j < obj.lenght();j++, i++) {
		concate.str[i] = obj.str[j];
	}
	concate.str[i] = '\0';
	return concate;
}
istream& operator >>(istream& input, STRING& obj) {
	cout << "enter the string plz : ";
	input.getline(obj.str, 1000);
	return input;
}
ostream& operator <<(ostream& output, STRING& obj) {
	output << obj.str << endl;
	return output;
}
int main() {
	STRING s1;
	s1.input();
	cout << "the lenght of the string is " << s1.lenght() << endl;
	s1.uppercase();
	cout << "the string in uppercase is : ";
	s1.display();
	s1.lowercase();
	cout << "the string in lowercase is : ";
	s1.display();
	cout << "enter the index of your charater : ";
	int index;
	cin >> index;
	while (cin.fail() || index < 0) {
		cout << "you have entered wrong input : ";
		cin.clear();
		cin.ignore();
		cin >> index;
	}
	cout << "the character at your given index is : " << s1.at(index) << endl;
	int start = 0, end = 0;
	cout << "enter the start of the index !";
	cin >> start;
	while (cin.fail() || start < 0) {
		cout << "you have entered wrong input : ";
		cin.clear();
		cin.ignore();
		cin >>start;
	}
	cout << "enter the end of the index !";
	cin >> end;
	while (cin.fail()  || end<start) {
		cout << "you have entered wrong input : ";
		cin.clear();
		cin.ignore();
		cin >> end;
	}
	char* substr = s1.substring(start,end);
	cout << substr << endl;
	string sub;
	cout << "enter the substring : ";
	cin.ignore();
	getline(cin, sub);
	int foundedIndex = 0;
	foundedIndex = s1.index(sub);
	if (foundedIndex < s1.lenght()) {
		cout << "the index is " << foundedIndex << endl;
	}
	else {
		cout << "the substring doesnt exist!" << endl;
	}
	STRING s2;
	s2.input();
	if (s1.compare(s2)) {
		cout << "strings are equal !" << endl;
	}
	else {
		cout << "strings are not equal !" << endl;
	}
	STRING s3;
	s3 = s1;
	cout << "after the assignment the object string to s3 is : " << endl;
	s3.display();
	cout << "enter the index u want to print using subscript notation " << endl;
	int x = 0;
	cin >> x;
	cout <<"the character of S1 at entered index is " << s1[x] << endl;
	STRING s4;
	cout << "enter the string S4 using istream and print using ostream operator : " << endl;
	cin >> s4;
	cout << s4;
	STRING s5 = s1.Append(s2);
	cout << "after appending S1 and S2 using String append function : " << s5 << endl;
	STRING s6 = s1.Prepend(s2);
	cout << "after Prepending S1 and S2 using String prepend function : : " << s6 << endl;
	cout << "enter the integer to append and prepend string with integer : ";
	int n;
	cin >> n;
	while (cin.fail()) {
		cout << "you have entered wrong input : ";
		cin.clear();
		cin.ignore();
		cin >> n;
	}
	STRING s7 = s1.Append(n);
	cout << "after appending S1 and integer using Append function : " << s7 << endl;
	STRING s8 = s1.Prepend(n);
	cout << "after Prepending S1 and integer using Prepend function : " << s8 << endl;
	double z = 0;
	cout << "enter the float or double value to append and prepend : ";
	cin >> z;
	while (cin.fail() ) {
		cout << "you have entered wrong input : ";
		cin.clear();
		cin.ignore();
		cin >> z;
	}
	STRING s9 = s1.Append(z);
	cout << "after Prepending S1 and float/double using Append function : " << s9 << endl;
	STRING s10 = s1.Prepend(z);
	cout << "after Prepending S1 and float/double using Prepend function : " << s10 << endl;
	char a = 'M';
	cout << "enter character to append and prepend : ";
	cin >> a;
	STRING s11 = s1.Append(a);
	cout << "after appending S1 and character using append is  : " << s11 << endl;
	STRING s12 = s1.Prepend(a);
	cout << "after Prepending S1 and character using prepend is  : " << s12 << endl;
	STRING s13 = s1+s2;
	cout << "after concatenating s1 and s2 using + operator is  : " << s13 << endl;
	STRING s14 = s1+n;
	cout << "after appending s1 and integer using + operator is  : " << s14 << endl;
	STRING s15 = s1+z;
	cout << "after appending s1 and float using + operator is  : " << s15 << endl;
	STRING s16 = s1 + a;
	cout<<"after appending s1 and character using + operator is : " << s16 << endl;
	if (s1 < s2) {
		cout << "s1 is less than s2" << endl;
	}
	else {
		cout << "s1 is not less than s2 " << endl;
	}
	if (s1 > s2) {
		cout << "s1 is greater than s2" << endl;
	}
	else {
		cout << "s1 is not greater than s2 " << endl;
	}
	system("pause");
}