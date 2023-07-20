//#include<iostream>
//#include<fstream>
//using namespace std;
//void getAchieversList(const int* const* scores, const int rows, const int cols, int**& achievers,string NAMES[]) {
//	int n_rows = 0;
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			if (scores[j][i] > 300) {
//				n_rows++;
//				break;
//			}
//		}
//	}
//	achievers = new int* [n_rows];
//	for (int i = 0; i < n_rows; i++)
//	{
//		int n_col = 0;
//		for (int j = 0; j < cols; j++) {
//			if (scores[j][i] > 300) {
//				n_col++;
//			}
//		}
//		achievers[i] = new int[n_col + 1];
//		int p = 0;
//		for (int k = 0; k < cols; k++) {
//			if (scores[k][i] > 300) {
//				achievers[i][p++] = scores[k][i];
//			}
//		}
//		achievers[i][n_col] = -1;
//	}
//	for (int i = 0; i < n_rows; i++){
//			cout << NAMES[i] << "\t : ";
//		for (int j = 0; achievers[i][j] != -1; j++) {
//			cout << achievers[i][j] << "\t";
//		}cout << endl;
//	}
//
//}
//int main() {
//	int row = 5, col = 5;
//	int** score = new int* [row];
//	for (int i = 0; i < row; i++)
//	{
//		score[i] = new int[col];
//	}
//	string teams[5] = {"AUS","ENG","IND","PAK","NZ"};
//	ifstream r1("score.txt");
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			r1 >> score[i][j];
//		}
//	}
//	cout << "Before Filtering the players for Prize reward : " << endl;
//	cout << "Aus\tEng\tInd\tPak\tNz" << endl;
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			cout << score[i][j] << "\t";
//		}cout << endl;
//	}
//	int** achiever = NULL;
//	cout << "**********************" << endl;
//	cout << "THE Achievers are : " << endl;
//	getAchieversList(score, row, col, achiever,teams);
//}
