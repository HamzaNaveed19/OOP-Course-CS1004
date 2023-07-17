#include<iostream>
using namespace std;
//1
void allocateMemory(int* &p,int &SIZE) {
	cout << "Enter the Size of Array :  ";
	cin >> SIZE;
	while (cin.fail() || SIZE<=0) {
		cout << "you have entered wrong input : ";
		cin.clear();
		cin.ignore();
		cin >> SIZE;
		
	}
	p = new int[SIZE];
}
// Q=What if both the parameters were by value?
// the answer is if both parameters were by value then the local variable SIZE 
// and pointer to integer i.e. arr will reamin NUll and will not be updated 
//2
void getData(int* const &p, int* const &q) {
	cout << "Enter the Elements of Array : ";
	for (int i = 0; p + i <= q; i++) {
		cin >> *(p + i);
		while (cin.fail() || *(p+i) <= 0) {
			cout << "you have entered wrong input : ";
			cin.clear();
			cin.ignore();
			cin >> *(p + i);
		}
	}
}//Q: What if we receive the parameters as by reference const pointer to const int?
// the answer is then you will not be able to fill the data in array as you 
// as you have declared each index as a constant integer
//3
void GrowArray(int* &p,int &SIZE) {
	int NewSize = 0;
	cout << "enter the updated size of array : ";
	cin >> NewSize;
	while (cin.fail() || NewSize<2*SIZE) {
		cout << "Please enter value greater than the double of previous size : ";
		cin.clear();
		cin.ignore();
		cin >> NewSize;
	}
	int* temp;
	temp = new int[NewSize];
	// copying previous data
	int i = 0;
	for ( i = 0; i < SIZE; i++) {
		*(temp+i) = *(p+i);
	}
	// filling the remaining array indices
	cout << "enter the new data of array : ";
	for (i; i < NewSize; i++) {
		cin >> *(temp + i);
		while (cin.fail() || *(temp + i) <= 0) {
			cout << "you have entered wrong input : ";
			cin.clear();
			cin.ignore();
			cin >> *(temp + i);
		}
	}
	SIZE = NewSize;
	delete[]p;
	p = temp; // assigning p the value of new memory location in heap
	
}//(Q: Why de-allocation and relocation?)
// the answer is because in order to free the memory from heap allocated by pointer
// p, we have to deallocte that memory location and as sometimes the memory we want to 
// expand is not availabe in consecutive location, but as we know heap always locates 
// or grant memory in consecutive way so we have to create a temporary variable pointer
// and first deallcate the previous small memory and the assign P the value of temporary
// variable pointer
//(Q: What if any of the parameters i.e., pointer or
//  the size variable or both of them were by-value).
// obviously the answer is same that these variables will not be updated in main function
// and will disturb in later functions.
//5
void PrintArray(const int* const &p,const int &SIZE) {
	cout << "\nthe data in array is  :" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << *(p+i) << "\t";
	}
}
//Q: Why we are receiving the parameters by-reference?
// well it doesnt really matter in case of this function,but we are calling it
// by refernce so that if any change occurs,it will also chnaged in main function.
//Q: Why we are receiving by - reference const pointer ?
// we are receiving by refernce constant pointer so that the function could not allow
// to change the location where the pointer is pointing. in simple ,you cannot
// reassign the value to pointer because it is constant here.
//Q : Why we are receiving by - reference const pointer to const integer ?
// we are receiving by - reference const pointer to const integer so that the function 
// would not be able to change the pointer as well as the value of the memory locations 
// in heap through dereferencing
//Q : Why we are receiving by - reference const integer size ?
// well again here by reference constant calling doesnt really matter but just for the sake
// that no one can alter the size atleast in this function . that's why we are sending it 
// as constant. moreover by refernce sending doesnt really matter here. 
//6
int* ShrinkArray(int *p,int &SIZE) {
	int NewSize = 0;
	cout << "\nenter the updated size of array : ";
	cin >> NewSize;
	while (cin.fail() || NewSize >SIZE/2) {
		cout << "Please enter less than or equal to half of  of previous size : ";
		cin.clear();
		cin.ignore();
		cin >> NewSize;
	}
	int* temp;
	temp = new int[NewSize];
	// copying previous data
	int i = 0;
	for (i = 0; i < NewSize; i++) {
		*(temp + i) = *(p + i);
	}
	SIZE = NewSize;
	delete[]p;
	p = temp; // assigning p the value of new memory location in heap
	return p;
}
//7
int* DistinctElements(int*& p, int& SIZE) {
	// SORTING THE ARRAY
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (p[i] > p[j]) {
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	// COUNTING NO OF DISTINCT ELEMENTS
	int new_size = 0;
	for (int i = 0; i < SIZE; i++) {
		if (p[i] != p[i + 1])
			new_size++;
	}
	int* temp = new int[new_size];
	int k = 0;
	for (int i = 0; i < SIZE; i++) {
		if (p[i] != p[i + 1]) {
			temp[k] = p[i];
			k++;
		}
	}
	delete [] p;
	SIZE = new_size;
	return temp;
}
//9
void ReleaseResources(int* &p) {
	delete[] p;
	p = NULL;

}
//Q: What if we receive by-reference const pointer to integer in the parameters list? 
// Will there be any issue in de-allocation ? Will there be any issue in relocating the pointer to NULL ?
// Well, if we receive by-reference const pointer to integer in the function then we 
//  can free the memory only but the pointer cannot be assigned a NULL
// value as it is constant pointer thus a pointer called dangling pointer will be left
// which will cause memory leak in our program. moreover we cannot re allocate the pointer
// as it is a constant pointer
int main() {
	int SIZE = 0;
	int* p = nullptr;
	allocateMemory(p,  SIZE);
	int* q;
	q = &p[SIZE - 1];      // assigning the q last index address of p
	getData(p, q);
	GrowArray(p, SIZE);
	cout << "\nafter expanding ";
	PrintArray(p, SIZE);
	p=ShrinkArray(p, SIZE);
	cout << "\nafter shrinking ";
	PrintArray(p, SIZE);
	p=DistinctElements(p,SIZE);
	cout << "\nafter distinction of elements  ";
	PrintArray(p, SIZE);

}