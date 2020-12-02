#include "modAlgos.h"

auto printer = [](auto&& data) { cout << "\nContents: "; for (auto d : data) { cout << d << ' '; } cout << endl; };
static int genInt() { static int x = 0;  return x++; }
int rando() { return (rand() % 50); }



modAlgos::modAlgos() {};

void modAlgos::fillAlgo() {

	int fillAmount = 0, x = 0;
	cout << "\nInput specified number of elements: ";
	cin >> fillAmount;
	vector<int> vec1(fillAmount);
	cout << "Vector is currently filled with 0's and has:  " << fillAmount << " allocated for fill\n";
	
	printer(vec1);


	cout << "\nEnter the number you would like to fill the vector with: ";
	cin >> x;
	fill(vec1.begin(), vec1.begin() + fillAmount, x);

	printer(vec1);

}
void modAlgos::generateAlgoMinMax() {
	int fillAmount = 0, x = 0;

	cout << "\nEnter an amount of vector elements: ";
	cin >> fillAmount;
	vector<int> vec1(fillAmount);
	cout << "Vector is currently filled with 0's and has:  " << fillAmount << " allocated for fill\n";
	printer(vec1);

	cout << "\nGenerating vector:";
	generate(vec1.begin(), vec1.end(), genInt);
	printer(vec1);



	cout << "\nThe minimum is: " << *min_element(vec1.begin(), vec1.end()) << endl;

	cout << "\nThe maximum is: " << *max_element(vec1.begin(), vec1.end()) << endl;

}
void modAlgos::uniqueReverseSortAlgo() {
	vector<int> vec1(rando());
	std::vector<int>::iterator it;
	int x = 0; 
	generate(vec1.begin(), vec1.end(), rando);
	cout << "\nOriginal random vector";
	sort(vec1.begin(), vec1.end());
	printer(vec1);
	
	cout << "\nThe accoumulated total is: " << accumulate(vec1.begin(), vec1.end(), x) << endl;
	cout << "\nPartial sum will use the first 5: ";
	int ps[5];
	partial_sum(vec1.begin(), vec1.begin()+5, ps);
	cout << "\nThe partial_sum result is range is: "<< ps[4] << endl;
	
	it = std::unique(vec1.begin(), vec1.end());  
	vec1.resize(distance(vec1.begin(), it));
	cout << "\nAfter unique and sort";
	printer(vec1);


	reverse(vec1.begin(), vec1.end());
	cout << "\nReversed";
	printer(vec1);


	sort(vec1.begin(), vec1.end(), less<int>());
	cout << "\nLess function object";
	printer(vec1);


	sort(vec1.begin(), vec1.end(), greater<int>());
	cout << "\nGreater function object";
	printer(vec1);

}
void modAlgos::searchAlgos() {
	list<char> sList, sList2, sList3; 	
	list<char>::iterator it;
	char val;
	bool repeat = false, foundVal = false;

	sList2.push_back('4');	sList2.push_back('r');	sList2.push_back('R');	sList2.push_back('2');	sList2.push_back('g');	sList2.push_back('a');	sList2.push_back('h');	sList2.push_back('x');	sList2.push_back('8');
	sList3.push_back('4');	sList3.push_back('r');	sList3.push_back('R');	



	cout << "\nFill the list with chars... ";
	
	while (!repeat) {
		cout << "Add to list: ";
		cin >> val;
		sList.push_back(val);
		cout << "Add another(y/n): ";
		cin >> val;
		repeat = val == 'y' ? false : true;
	}
	cout << "Premade 'list 1' created its values are: ";
	printer(sList2); 
	cout << "Premade 'list 2' created its values are: ";
	printer(sList3);



	cout << "\nWhat char would you like to search user defined list: ";
	cin >> val;

	sList.sort(); sList2.sort(); sList3.sort();

	foundVal = binary_search(sList.begin(), sList.end(), val) ? true : false;
	
	cout << "\nThe value is in the list: " << boolalpha << foundVal;
	
	
	bool isIncludes = includes(sList.begin(), sList.end(), sList2.begin(), sList2.end());
	cout << "\nThe premade list and user created list inclusion is: " << boolalpha << isIncludes << endl;
	
	
	isIncludes = includes(sList2.begin(), sList2.end(), sList3.begin(), sList3.end());
	cout << "\nThe  premade list and 2nd premade list inclusion is: " << boolalpha << isIncludes << endl;
	
	list<char> c((sList2.size() > sList.size()) ? sList2.size() : sList.size());
	
	it = set_difference(sList.begin(), sList.end(), sList2.begin(), sList2.end(),c.begin());
	c.resize(distance(c.begin(), it));

	cout << "\nThe set differences between user list and predefined list 2 is: " << endl;
	printer(c);

}
void modAlgos::funcAlgos() {

	int arr1[5], results[5], arr2[5] = { 2,3,4,5,6 };
	for (int x = 0; x < 5; x++) { cout << "Input number for array: "; cin >> arr1[x]; }
	transform(arr2, arr2 + 5, arr1, results, multiplies<int>());
	cout << "\nPremade array";
	printer(arr2);
	cout << "\nMultiply function";
	printer(results);

	cout << "\nModulus function";
	transform(arr2, arr2 + 5, arr1, results, modulus<int>());
	printer(results);


}