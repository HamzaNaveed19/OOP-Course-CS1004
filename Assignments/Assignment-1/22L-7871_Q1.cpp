#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
void WordDictionary(char**& diction, char*& sentence) {
	int row = 0, col = 0;
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] != ' ' && sentence[i] != '.') {
			diction[row][col++] = sentence[i];
		}
		else if (sentence[i] == ' ' || sentence[i + 1] == '\0') {
			diction[row][col] = '\0';
			col = 0;
			row++;
		}
	}

}
void memoryallocation(char**& dictionary, char*& sentence, int words) {
	int lenght = 0, k = 0;
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] != ' ' && sentence[i] != '.') {
			lenght++;
		}
		if (sentence[i] == ' ' || (sentence[i] == '.' && sentence[i + 1] == ' ') || sentence[i + 1] == '\0') {
			dictionary[k] = new char[lenght + 1];
			dictionary[k][lenght] = '\0';
			lenght = 0;
			k++;
		}
	}

}
void wordcount(const char* sentence, int& words) {
	words = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == ' ') {
			words++;
		}
	}
	words = words + 1;
}
bool found(int*& arr, int i) {
	for (int m = 0; arr[m] != -1; m++) {
		if (arr[m] == i)
			return true;
	}
	return false;
}
void printdictinary(char** &temp, int& words) {
	for (int i = 0; i < words; i++) {
		for (int j = 0; j < strlen(temp[i]); j++)
			cout << temp[i][j];
		cout << endl;
	}
}
void uniqueWords(char**& temp, int &words,char**&dictionary) {
	int count = 0;
	int* arr = new int[words];
	for (int i = 0; i < words; i++) {
		arr[i] = -1;
	}
	int c = 0;
	int j = 0, i = 0;
	for (i = 0; i < words - 1; i++) {
		for (j = i + 1; j < words; j++) {
			if (temp[i][0] == temp[j][0] && strlen(temp[i]) == strlen(temp[j])) {
				for (int m = 0; m < strlen(temp[i]); m++) {
					if (temp[i][m] == temp[j][m]) {
						c++;
					}
				}
				if (c == strlen(temp[i] )) {
					arr[count] = j;
					count++;
				}
				c = 0;
			}
		}
	}c = 0;
	dictionary = new char* [words - count];
	for (int i = 0; i < words - count; i++) {
		dictionary[i] = nullptr;
	}
	cout << endl;
	c = 0;
	bool exist = false;
	for (int i = 0; i < words ; i++) {
		if (!found(arr,i)) {
			dictionary[c] = new char[1 + strlen(temp[i])];
			dictionary[c][strlen(temp[i])] = '\0';
			for (int h = 0; h < strlen(dictionary[c]); h++) {
				dictionary[c][h] = temp[i][h];
			}
			c++;
		}
	}
	
	words=words-count;
}
void copy(char***& synonym, char* means, int i, int s) {
	for (int k = 0; k < strlen(means); k++) {
		synonym[i][s][k] = means[k];
	}
	synonym[i][s][strlen(means)] = '\0';
}
void allocatememory(char***& synonym, char** dictionary, int words, int*& count_s) {
	int syn_count = 0;
	char means[50] = { 'a' };
	int m = 0;
	for (int i = 0; i < words; i++) {
		int syn = 0;
		cout << "do you want to store synonyms of the word  -> " << dictionary[i] << endl;
		cout << "if no then press 0 else any other number  : ";
		cin >> syn;
		while (cin.fail() || syn < 0) {
			cout << "you have entered wrong input : ";
			cin.clear();
			cin.ignore();
			cin >> syn;

		}
		cin.ignore();
		syn_count = 0;
		if (syn >= 1) {
			cout << "enter the number of synonym u wanna store : ";
			cin >> syn_count;
			while (cin.fail() || syn_count < 1) {
				cout << "you have entered wrong input : ";
				cin.clear();
				cin.ignore();
				cin >> syn_count;

			}
			synonym[i] = new char* [syn_count];
			count_s[m++] = syn_count;
			for (int s = 0; s < syn_count; s++) {
				cin.ignore();
				cout << "enter the " << s + 1 << " synonym : ";
				cin >> means;
				synonym[i][s] = new char[strlen(means) + 1];
				copy(synonym, means, i, s);
			}
		}

	}
}
int matchwords(char**& dictionary, char**& matching2d, int& entered_words, int words, int*& matchedindex, int*& matchedindex2) {
	int matchedwords = 0;
	int n = 0;
	int count = 0;
	cin.ignore();
	cin.clear();
	for (int i = 0; i < entered_words; i++) {
		for (int j = 0; j < words; j++) {
			if (dictionary[j][0] == matching2d[i][0]) {
				for (int k = 0; k < strlen(matching2d[i]); k++) {
					if (dictionary[j][k] == matching2d[i][k]) {
						count++;
					}
					else {
						break;
					}
				}
				if (count == strlen(matching2d[i])) {
					matchedindex[n] = j;
					matchedindex2[n] = i;
					matchedwords++;
					n++;
				}
			}
			count = 0;


		}
	}
	return matchedwords;
}
void dealloacteAll(int words, char*& sentence, char**& dictionary, char***& synonym, int*& count_S, char*& usecase1, char**& matching2d, int*& matchingindex, int*& matchingindex2) {
	delete[]sentence;
	sentence = nullptr;
	for (int i = 0; i < words; i++) {
		delete[]dictionary[i];
		dictionary[i] = nullptr;
	}
	delete[]dictionary;
	dictionary = nullptr;
	for (int i = 0; i < words; i++) {
		if (synonym[i] != nullptr) {
			for (int j = 0; j < 3; j++) {
				delete[]synonym[i][j];
				synonym[i][j] = nullptr;
			}
			delete[]synonym[i];
			synonym[i] = nullptr;
		}
		delete[]synonym[i];
		synonym[i] = nullptr;
	}
	delete[]synonym;
	synonym = nullptr;
	delete[]count_S;
	count_S = nullptr;
	delete[]usecase1;
	usecase1 = nullptr;
	delete[]matching2d;
	matching2d = nullptr;
	delete[]matchingindex;
	matchingindex = nullptr;
	delete[]matchingindex2;
	matchingindex2 = nullptr;
}
int main() {
	char* sentence = new char[1000];
	ifstream read("Text.txt");
	int i = 0;
	while (!read.eof()) {
		read.getline(sentence, 1000);
	}
	sentence[strlen(sentence)] = '\0';
	int words = 0;
	wordcount(sentence, words);
	char** temp = new char* [words];
	memoryallocation(temp, sentence, words);
	WordDictionary(temp, sentence);
	char** dictionary = nullptr;
	char*** synonym = new char** [words];
	for (int i = 0; i < words; i++) {
		synonym[i] = nullptr;
	}
	uniqueWords(temp,words,dictionary);
	printdictinary(dictionary, words);
		//task_2
	cout << "\n--------------------------------\n";
	int* count_S = new int[words];
	for (int i = 0; i < words; i++)
		count_S[i] = 0;
	allocatememory(synonym, dictionary, words, count_S);
	int m = 0;
	for (int i = 0; i < words; i++) {
		if (synonym[i] != nullptr) {
			cout << "the synonym of " << dictionary[i] << " is \n";
			for (int j = 0; j < count_S[m]; j++) {
				cout << synonym[i][j] << "\t";
			}
			cout << endl;
			m++;
		}
	}
	// task_3
	char* usecase1 = new char[1000];
	cout << "\n--------------------------------\n";
	cout << "enter the sentence to search words in dictionary: ";
	cin.getline(usecase1, 1000);
	int entered_words = 0;
	usecase1[strlen(usecase1)] = '\0';
	wordcount(usecase1, entered_words);
	char** matching2d = new char* [entered_words];
	memoryallocation(matching2d, usecase1, entered_words);
	WordDictionary(matching2d, usecase1);
	int* matchedindex = new int[strlen(usecase1)];
	for (int i = 0; i < strlen(usecase1); i++) {
		matchedindex[i] = -1;
	}
	int* matchedindex2 = new int[strlen(usecase1)];
	for (int i = 0; i < strlen(usecase1); i++) {
		matchedindex2[i] = -1;
	}
	int x = matchwords(dictionary, matching2d, entered_words, words, matchedindex, matchedindex2);
	cout << "\n--------------------------------\n";
	cout << "the matched words are : " << x << endl;
	for (int i = 0; i < x; i++) {
		cout << dictionary[matchedindex[i]] << "\t";
	}
	//task4
	cout << "\n--------------------------------\n";
	int u = 0;
	int j = 0;
	for (int z = 0; z < x; z++) {
		for (int c = 0; c < words; c++) {
			if (synonym[c] != nullptr) {
				if (c == matchedindex[z]) {
					delete[] matching2d[matchedindex2[z]];
					matching2d[matchedindex2[z]] = new char[strlen(synonym[c][0]) + 1];
					matching2d[matchedindex2[z]][strlen(synonym[c][0])] = '\0';
					for (u = 0; u < strlen(synonym[c][0]); u++) {
						matching2d[matchedindex2[z]][u] = synonym[c][0][u];
					}
				}
			}
		}
	}
	//printdictinary(matching2d, entered_words);
	u = 0;
	delete[]usecase1;
	usecase1 = new char[500];
	for (int k = 0; k < entered_words; k++) {
		for (int m = 0; m < strlen(matching2d[k]); m++) {
			usecase1[u++] = matching2d[k][m];
		}
		usecase1[u++] = ' ';
	}

	usecase1[u++] = '\0';
	cout << "After replacing the matched words with synonym are :  \n";
	cout << usecase1;
}