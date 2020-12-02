//Kyle Flores //
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

void calculateDiscount(double* value1, double* value2);
int determineLarger(int* value1, int* value2);
bool compareArrays(const char* str1, const char* str2);
void sortArrays(string* arr1, array<string, 3>* arr2);
void demoPtrTechniques(int& a, int const* b, int* c, int* d, int e);


int main()
{
	///function 1   
	double num1 = 0, num2 = 0;
	
		cout << "FUNCTION 1\nEnter both values\n(listed price then discounted): ";
		cin >> num1 >> num2;
		calculateDiscount(&num1, &num2);
		cout << "discounted price: " << num1;
	
	///function 1 end

	///function 2   
	
		int inum1 = 0, inum2 = 0;
		int* ptr_int1 = nullptr; int* ptr_int2 = nullptr;
		cout << "\n\nFUNCTION 2\nEnter both values\nAnd find out which is larger: ";
		cin >> inum1 >> inum2;
		ptr_int1 = &inum1;
		ptr_int2 = &inum2;
		int larger = determineLarger(ptr_int1, ptr_int2);
		cout << "The larger number isssss: " << larger;
	
	///function 2 end

	///function 3  
		cin.ignore();
		int const size = 1000;
		char str1[size];
		cout << "\n\nFunction 3\nenter string 1: ";
		cin.getline(str1, size);
		char str2[size];
		cout << "enter string 2: ";
		cin.getline(str2, size);

		const char* ptrArr1{ str1 };
		const char* ptrArr2{ str2 };
		bool func3 = compareArrays(ptrArr1, ptrArr2);
		cout << endl << "Are the strings the same: " << boolalpha << func3 << endl;
	
	///function 3 end

	///function 4   
		cout << "\nFunction 4";
		string bltInArr[] = { "b", "a ", "c" };
		array< string, 3> tempArr = { "the" , "quick", "brown" };
		string* ptr_blt{ bltInArr };

		cout << "\nbefore sort\n";
		for (string item : bltInArr) {
			cout << item << " ";
		}
		cout << endl;
		for (string item : tempArr) {
			cout << item << " ";
		}
		cout << endl;



		sortArrays(ptr_blt, &tempArr);
		cout << "\nAfter sort\n";

		for (string item : bltInArr) {
			cout << " " << item << " ";
		}
		cout << endl;
		for (string item : tempArr) {
			cout << item << " ";
		}
		cout << endl;

	
	///function 4 end
	
	///function 5 
	cout << "\nFunction 5\n";

	int a1 = 1,const b1 =2, c1 = 3, d1 =4, e1 = 5;
	
	demoPtrTechniques(a1, &b1, &c1, &d1, e1);
	cout<< "\nD1 in main follow Demo changes" << d1;
	cout << "\nE1 unchanged from Demo" << e1;
	///function 5 end

	cout << "\n\n\n" << "press enter to quit";
	cin.get();
}

void calculateDiscount(double* value1, double* value2) {
	*value1 = *value1 - (*value1 * (*value2 / 100));
}
int determineLarger(int* value1, int* value2) {
	return *value1 > * value2 ? *value1 : *value2;
}
bool compareArrays(const char* str1, const char* str2) {
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}
void sortArrays(string* arr1, array<string, 3>* arr2) {
	sort(arr1, arr1 + 3);
	sort(arr2->begin(), arr2->end());
}
void demoPtrTechniques(int& a, int const* b, int* c, int* d, int e) {
	cout << "\nA value: " << a << "\nB value: " << *b << "\nC value: " << *c << "\nD value: " << *d << "\nE value: " << e;
	*d = 20;
	cout << "\nD's new value in demoPtrTechniques: " << *d;

	e = 30;
	cout << "\nE's new value in demoPtrTechniques: " << e;
}