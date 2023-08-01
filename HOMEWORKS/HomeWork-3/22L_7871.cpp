#include<iostream>
#include<windows.h>
using namespace std;
const int colors = 6;
const int Size = 3;
class face {
public:
	int** side;

	face(int n) {
		side = new int* [Size];
		for (int i = 0; i < Size; i++) {
			side[i] = new int[Size];
		}
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < 3; j++){
				side[i][j] = n;
			}
		}
	}
	void exposeSide() {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				cout << side[i][j] << "\t";
			}cout << endl;
		}
	}
	void SwapSide(face one) {
		int temp=0;
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				temp = side[i][j];
				side[i][j] = one.side[i][j];
				one.side[i][j] = temp;
			}
		}
	}
	void RotateAntiClockwise() {
		for (int m = 0; m < Size - 1; m++) {
			int temp = side[Size - 1][0];
			int store = 0;
			int j = 0;
			for (int i = Size - 1; i > 0; i--) {
				side[i][j] = side[i - 1][j];

			}
			j = Size - 1;
			store = side[Size - 1][1];
			side[Size - 1][1] = temp;
			temp = side[Size - 1][Size - 1];
			int i = Size - 1;
			for (i = Size - 1; i > 2; i--) {
				side[j][i] = side[j][i - 1];
			}
			side[j][i] = store;
			store = side[Size - 2][Size - 1];
			side[Size - 2][Size - 1] = temp;
			temp = side[0][j];
			for (i = 0; i + 1 < Size - 2; i++) {
				side[i][j] = side[i + 1][j];
			}
			side[i][j] = store;
			j = 0;
			store = side[0][Size - 2];
			side[0][Size - 2] = temp;
			for (i = 0; i + 1 < Size - 2; i++) {
				side[j][i] = side[j][i + 1];
			}
			side[j][i] = store;
		}
	}
	/*~face(){
		for (int i = 0; i < Size; i++) {
			delete[]side[i];
		}
		delete[] side;
	}*/
};

class Cube {
	face* front;
	face* back;
	face* left;
	face* right;
	face* top;
	face* bottom;
public:
	Cube(face* f1, face* f2, face* f3, face* f4, face* f5, face* f6) {
		front = f1;
		back = f2;
		left = f3;
		right = f4;
		top = f5;
		bottom = f6;
	}
	void PrintCube() {
		cout << "Front Side: " << endl;
		front->exposeSide();
		cout << "Back Side: " << endl;
		back->exposeSide();
		cout << "Left Side: " << endl;
		left->exposeSide();
		cout << "Right Side: " << endl;
		right->exposeSide();
		cout << "Top Side: " << endl;
		top->exposeSide();
		cout << "Bottom Side: " << endl;
		bottom->exposeSide();
	}
	void SwapFrontTop() {
		front->SwapSide(*top);
	}
	void RotateLeftColumn() {
		front->RotateAntiClockwise();
		int* temp = new int[Size];
		for (int i = 0; i < Size; i++) {
			temp[i] = top->side[Size - 1][i];
		}
		for (int i = 0; i < Size; i++) {
			top->side[Size - 1][i] = right->side[i][0];
		}
		for (int i = 0; i < Size; i++) {
			right->side[i][0] = bottom->side[0][i];
		}
		for (int i = 0; i < Size; i++) {
			bottom->side[0][i]=left->side[i][Size-1];
		}
		for (int i = 0; i < Size; i++) {
			left->side[i][Size-1]=temp[i];
		}


	}
	
};
int main() {
	face f1(1);
	face f2(2);
	face f3(3);
	face f4(4);
	face f5(5);
	face f6(6);
	Cube c1(&f1, &f2, &f3, &f4, &f5, &f6);
	c1.PrintCube();
	Sleep(9000);
	system("cls");
	cout << "after Swapping front with top : " << endl;
	c1.SwapFrontTop();
	c1.PrintCube();
	Sleep(6000);
	c1.RotateLeftColumn();
	cout << "After Performing Swap_left_column function : " << endl;
	c1.PrintCube();
}