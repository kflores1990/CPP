#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
template<typename T>
class STACK
{

public:
	void push(string a) { vec.push_back(a); }
	auto pop() { 
		try {
			if (vec.empty() == true) { throw runtime_error("\nEmpty value attempted to be popped"); }
			else { cout << "\nPopped Top\n"; vec.pop_back(); }
		}
		catch (exception e) { cout << "\nAn attempt to pop the top on the empty stack was performed...\n"; }
		
		}
	auto top() { 
		try {
			if (vec.empty() == true) { throw exception("\nEmpty value attempted to be peeped"); }
			return vec.back();
		}
		catch (exception e) { cout << "\nAn attempt to peek the top on the empty stack was performed...\n"; }

	
	
	
	}
	void clear() { vec.clear(); }
	bool empty() { return vec.empty(); }

	void dpush(double a) { vd.push_back(a); }
	auto dpop() { 
		
		try {
			if (vd.empty() == true) { throw runtime_error("\nEmpty value attempted to be popped"); }
			vd.pop_back();
			cout << "\nPopped Top\n";
		}
		catch (exception e) { cout << "\nAn attempt to pop the top on the empty stack was performed...\n"; }
	 }
	auto dtop() { 
		
		try {
			if (vd.empty() == true) { throw exception("\nEmpty value attempted to be peeped"); }
			return vd.back();
		}
		catch (exception e) { cout << "\nAn attempt to peek the top on the empty stack was performed...\n"; }
		
	}
	void dclear() { vd.clear(); }
	bool dempty() { return vd.empty(); }











private:
	vector<string> vec;
	vector<double> vd;

};
