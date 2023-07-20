//#include<iostream>
//using namespace std;
//void AllocateMemory(int**& org_ptr, int& rows, int& cols) {
//	cout << "Enter the no. of rows for array : ";
//	cin >> rows; 
//	while (cin.fail() || rows < 1) {
//		cout << "you have entered wrong input : ";
//		cin.clear();
//		cin.ignore();
//		cin >> rows;
//
//	}
//	cout << "Enter the no. of columns for array : ";
//	cin >> cols;
//	while (cin.fail() || cols < 1) {
//		cout << "you have entered wrong input : ";
//		cin.clear();
//		cin.ignore();
//		cin >> cols;
//
//	}
//	org_ptr = new int* [rows];
//	for (int i = 0; i < rows; i++) {
//		org_ptr[i] = new int[cols];
//	}
//}
//void GetData(int* const* const& org_ptr, const int& rows, const int& cols) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			cout << "enter the data of " << i << " row and " << j << " column : ";
//			cin >> org_ptr[i][j];
//			while (cin.fail() || org_ptr[i][j] <= 10) {
//				cout << "you have entered wrong input : ";
//				cin.clear();
//				cin.ignore();
//				cin >> org_ptr[i][j];
//
//			}
//		}
//	}
//}//Q: why we are not writing const before the very first ‘int’ in the expression?
////what will happen if we also write const before the very first ‘int’ in the expression ?
////ANS : beacuse if we put constant int in paramter then we will not be able to take input from the user 
//// as the 2d array will be treated as constant elements.
//bool checkprime(int number) {
//	int factor = 0;
//	for (int i = 1; i <= number; i++) {
//		if (number % i == 0) {
//			factor++;
//		}if (factor > 2) {
//			return false;
//		}
//	}
//	if (factor == 2) {
//		return true;
//	}
//}
//int** fetchdata(const int* const* const org_ptr, const int& rows, const int& cols, int& fd_row) {
//	int count_1 = 0, count_2 = 0, count_3 = 0;
//	fd_row = 3;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			if (org_ptr[i][j] % 2 == 0 && j % 2 != 0) {
//				count_1++;
//			}
//			if (org_ptr[i][j] % 2 != 0 && j % 2 == 0) {
//				count_2++;
//			}
//			if (checkprime(org_ptr[i][j])) {
//				count_3++;
//			}
//		}
//	}
//	int** fd_array = new int* [fd_row];
//	fd_array[0] = new int[count_1 + 1];
//	fd_array[1] = new int[count_2 + 1];
//	fd_array[2] = new int[count_3 + 1];
//	fd_array[0][count_1] = -1;
//	fd_array[1][count_2] = -1;
//	fd_array[2][count_3] = -1;
//
//	int e = 0, o = 0, p = 0;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			if (org_ptr[i][j] % 2 == 0 && j % 2 != 0) {
//				fd_array[0][e++] = org_ptr[i][j];
//			}
//			if (org_ptr[i][j] % 2 != 0 && j % 2 == 0) {
//				fd_array[1][o++] = org_ptr[i][j];
//			}
//			if (checkprime(org_ptr[i][j])) {
//				fd_array[2][p++] = org_ptr[i][j];
//			}
//		}
//	}
//	return fd_array;
//}
//void print(int** fd_array) {
//	cout << "***** OUTPUT *****" << endl;
//	for (int i = 0; i < 3; i++) {
//		if (i == 0)
//			cout << " Even Elements according to condition are : ";
//		else if (i == 1)
//			cout << " ODD Elements according to condition are : ";
//		if (i == 2)
//			cout << " Prime  Elements according to condition are : ";
//		for (int j = 0; fd_array[i][j] != -1; j++) {
//			cout << fd_array[i][j] << "\t";
//		}cout << endl;
//	}
//}
//int main() {
//	int** org_ptr;		//oiginal array = org_ptr
//	int** fd_ptr;		// fetched array= fd_ptr
//	int rows = 0, cols = 0;
//	int fd_row = 0;
//	AllocateMemory(org_ptr, rows, cols);
//	GetData(org_ptr, rows, cols);
//	fd_ptr = fetchdata(org_ptr, rows, cols, fd_row);
//	print(fd_ptr);
//}