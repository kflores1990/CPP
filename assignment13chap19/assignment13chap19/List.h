#pragma once
#include <iostream>
using namespace std;

#include "ListNode.h"

template <typename T>
class List
{
public:
	int count = 0;
	List();
	~List();
	void insertNewNode(T); 


	bool isEmpty();
	
	void insertEnd(T);
	void insertBegin(T);

	bool removeFront();
	bool removeBack();

	bool removeIndex();
	bool removeValue(T);

	ListNode<T>* search(T);

	void print();

private:
	 
	ListNode<T>* startPtr; 
	ListNode<T>* endPtr; 
	ListNode<T>* tempPtr;
};


template <typename T>
List<T>::List() 
{
	startPtr = NULL;
	endPtr = NULL;
	tempPtr = NULL;
}

template <typename T>
List<T>::~List()
{
	if (!isEmpty()) 
	{
		ListNode<T>* currentPtr = startPtr;
		ListNode<T>* tempPtr;

		while (currentPtr != 0)
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}
	}
}

template <typename T>
void List<T>::insertNewNode(T dataIn) 
{
	if (isEmpty())
	{
		insertBegin(dataIn);
	}
	else 
	{
		if (dataIn < startPtr->data)
		{
			insertBegin(dataIn);
		}
		else if (dataIn >= endPtr->data)
		{
			insertEnd(dataIn);
		}
		else 
		{
			ListNode<T>* currentPtr = startPtr;
			ListNode<T>* newPtr = new ListNode<T>(dataIn);
			while (currentPtr != endPtr) 
			{
				if ((newPtr->data < currentPtr->nextPtr->data) && (newPtr->data >= currentPtr->data)) 
				{
					ListNode<T>* next = currentPtr->nextPtr;
					currentPtr->nextPtr = newPtr; 
					newPtr->nextPtr = next; 
					break;
				}
			}
		}
	}
}


template <typename T>
bool List<T>::isEmpty()
{
	if (startPtr == NULL && endPtr == NULL) 
		return 1;
	else
		return 0;
}

template <typename T>
void List<T>::insertBegin(T dataIn)
{
	List::count++;

	if (isEmpty())
	{
		ListNode<T>* newPtr = new ListNode<T>(dataIn);
		startPtr = endPtr = newPtr;
	}
	else
	{
		ListNode<T>* newPtr = new ListNode<T>(dataIn);
		newPtr->nextPtr = startPtr;
		startPtr = newPtr;
	}

}

template <typename T>
void List<T>::insertEnd(T dataIn)
{	
	List::count++;
	if (isEmpty()) 
	{
		ListNode<T>* newPtr = new ListNode<T>(dataIn);
		startPtr = endPtr = newPtr;
	}
	else 
	{
		ListNode<T>* newPtr = new ListNode<T>(dataIn);
		endPtr->nextPtr = newPtr;  
		endPtr = newPtr; 
	}

}

template <typename T>
bool List<T>::removeFront() {
	if (isEmpty())	{return false;}
	else {
		List::count--;

		ListNode<T>* tempPtr{ startPtr };
		if (startPtr == endPtr) { startPtr = endPtr = nullptr; }
		else { startPtr = startPtr->nextPtr;	}
		delete tempPtr;
		return true;
	}
}
template <typename T>
bool List<T>::removeBack() {
	if (isEmpty()) { return false; }
	else {
		List::count--;

		ListNode<T>* tempPtr{ endPtr };
		if (startPtr == endPtr) { startPtr = endPtr = nullptr; }
		else{
			ListNode<T>* currentPtr{ startPtr };
			while (currentPtr->nextPtr != endPtr) { currentPtr = currentPtr->nextPtr; }
			endPtr = currentPtr;
			currentPtr->nextPtr = nullptr;
		}
		delete tempPtr;
		return true;
	}
}

template <typename T>
bool List<T>::removeIndex(){
	try {
		cout << "\nIndex Value: ";
		int iVal;
		cin >> iVal;
		if (isEmpty() || iVal > List::count || iVal < 0) { return false; }

		else {
			if (iVal == 0) { removeFront();  return true; }
			if (iVal == List::count - 1) { removeBack(); return true; }

			ListNode<T>* currentPtr = tempPtr = startPtr;
			ListNode<T>* delNode = nullptr;
			while (iVal >= 0) {
				if (tempPtr != nullptr) {
					tempPtr = tempPtr->nextPtr;
				}
				--iVal;
				if (iVal == 0) {
					delNode = tempPtr;
					if (tempPtr != nullptr) {
						tempPtr = tempPtr->nextPtr;
						currentPtr->nextPtr = tempPtr;
					}
					delete delNode;
					List::count--;
					return true;
				}
				currentPtr = tempPtr;
			}

		}
	}
	catch (exception e) { cout << "invalid line"; }
}

template <typename T>
bool List<T>::removeValue(T dataIn){
	
	if (isEmpty() == true) { return false; }
	if (startPtr->data == dataIn) { removeFront(); return true; }

	ListNode<T>* currentPtr = tempPtr = startPtr;
	ListNode<T>* delNode = nullptr;
	while (tempPtr->data != dataIn && tempPtr->nextPtr != nullptr) {

		tempPtr = tempPtr->nextPtr;
		if (dataIn == tempPtr->data && tempPtr !=nullptr) {
			List::count--;
			if (tempPtr == endPtr) { removeBack(); return true; }
			delNode = tempPtr;
			tempPtr = tempPtr->nextPtr;
			currentPtr->nextPtr = tempPtr;
			delete delNode;
			endPtr = currentPtr;
			currentPtr->nextPtr = nullptr;
			return true;
		}
		currentPtr = tempPtr;
	}
	return false;

}

template <typename T>
void List<T>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;

	}
	else
	{
		ListNode<T>* currentPtr = startPtr;

		cout << "The contents of the list is: ";
		while (currentPtr != NULL)
		{
			cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr; 
		}
		cout << endl;
	}

}

template <typename T>
ListNode<T>* List<T>::search(T key) 
{
	ListNode<T>* nodePtr;
	bool found = false;

	nodePtr = startPtr;

	while ((!found) && (nodePtr != NULL)) 
	{
		if (nodePtr->data == key) 
			found = true;
		else
			nodePtr = nodePtr->nextPtr; 
	}
	return nodePtr; 
}