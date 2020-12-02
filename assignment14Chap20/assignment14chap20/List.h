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

	int LinearSearch(T);
	bool binarySearch(T);

	bool selectionSort();

	ListNode<T>* getMid(ListNode<T>*);
	ListNode<T>* sortList(ListNode<T>*);
	ListNode<T>* merge(ListNode<T>*, ListNode<T>*);
	bool mergeSortList();
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
	if (isEmpty()) { return false; }
	else {
		List::count--;

		ListNode<T>* tempPtr{ startPtr };
		if (startPtr == endPtr) { startPtr = endPtr = nullptr; }
		else { startPtr = startPtr->nextPtr; }
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
	else {
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
bool List<T>::removeIndex() {
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

			tempPtr = tempPtr->nextPtr;
			--iVal;
			if (iVal == 0) {
				delNode = tempPtr;
				tempPtr = tempPtr->nextPtr;
				currentPtr->nextPtr = tempPtr;
				delete delNode;
				List::count--;
				return true;
			}
			currentPtr = tempPtr;
		}

	}
	return true;
}

template <typename T>
bool List<T>::removeValue(T dataIn) {

	if (isEmpty() == true) { return false; }
	if (startPtr->data == dataIn) { removeFront(); return true; }

	ListNode<T>* currentPtr = tempPtr = startPtr;
	ListNode<T>* delNode = nullptr;
	while (tempPtr->data != dataIn && tempPtr->nextPtr != nullptr) {

		tempPtr = tempPtr->nextPtr;
		if (dataIn == tempPtr->data && tempPtr != nullptr) {
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
int List<T>::LinearSearch(T dataIn) {
	int location, LSCounter = 0; 
	ListNode<T>* currentPtr = startPtr;

	while(currentPtr != nullptr){
		if (dataIn == currentPtr->data) { location = LSCounter; return location; }
		currentPtr = currentPtr->nextPtr;
		LSCounter++;
	}
	return -1;

}


template <typename T>
bool List<T>::selectionSort() {
	if (isEmpty()){
		cout << "The list is empty" << endl;
		return false;
	}

	if (startPtr->nextPtr == nullptr) { return true; }
	ListNode<T>* tempStartPtr = nullptr;
	ListNode<T>* tempEndPtr =nullptr;
	ListNode<T>* temp2Ptr = tempStartPtr;
	ListNode<T>* temp2PrevPtr = nullptr;

	ListNode<T>* currentPtr = startPtr;
	ListNode<T>* prevPtr = nullptr;

	while (startPtr != nullptr) {

		temp2Ptr = startPtr;
		currentPtr = startPtr;
		prevPtr = nullptr;
		temp2PrevPtr = nullptr;

		while (currentPtr != nullptr) {
			if (temp2Ptr->data < currentPtr->data) {//finds largest
				temp2Ptr = currentPtr;
				temp2PrevPtr = prevPtr;

			}
			prevPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (temp2PrevPtr != nullptr) {
			temp2PrevPtr->nextPtr = temp2Ptr->nextPtr;
		} 
		else {
			startPtr = startPtr->nextPtr;
		}
		temp2Ptr->nextPtr = tempStartPtr;

		if (tempStartPtr == nullptr) {
			tempEndPtr = temp2Ptr;
		}
		tempStartPtr = temp2Ptr;
		
	}
	startPtr = tempStartPtr;
	endPtr = tempEndPtr;

	print();

	return true;
}


template <typename T>
bool List<T>::binarySearch(T dataIn) {
	if (isEmpty() == true) { return false; }
	if (startPtr != endPtr) {selectionSort();}

	ListNode<T>* begPtr = startPtr;
	ListNode<T>* lastPtr = endPtr;
	
	if (endPtr->data < dataIn) { return false; }
	if (startPtr->data == dataIn) { return true; }
	
	ListNode<T>* mid = nullptr;
	ListNode<T>* single = startPtr;
	ListNode<T>* skip = startPtr->nextPtr;
	
	while (skip != endPtr ) {//find middle
		skip = skip->nextPtr;
		if (skip != endPtr) {
			single = single->nextPtr;
			skip = skip->nextPtr;
		}
		mid = single;

	}

	if (mid->data == dataIn) { return true; }

	if (mid->data > dataIn) {//do lower list
		while (begPtr != mid) {
			begPtr->nextPtr;
			if (begPtr->data == dataIn) { return true; }
		}

	}
	else if (mid->data < dataIn) {//do upper list
		while (mid != endPtr) {
			mid = mid->nextPtr;
			if (mid->data == dataIn) { return true; }
		}
	}
	return false; //not in list
	

}


template<typename T>
bool List<T>::mergeSortList() {
	if (startPtr == endPtr) { return true; }
	
	ListNode<T>* head = startPtr;
	startPtr = sortList(head);
	print();
	return (startPtr != head ? true : false);
}
template<typename T>
ListNode<T>* List<T>::sortList(ListNode<T>* head) {
	if (!head || !head->nextPtr)
		return head;
	ListNode<T>* mid = getMid(head);
	ListNode<T>* left = sortList(head);
	ListNode<T>* right = sortList(mid);
	return merge(left, right);
}
template<typename T>
ListNode<T>* List<T>::merge(ListNode<T>* list1, ListNode<T>* list2) {
	ListNode<T> dummyHead(0);
	ListNode<T>* ptr = &dummyHead;
	while (list1 && list2) {
		if (list1->data < list2->data) {
			ptr->nextPtr = list1;
			list1 = list1->nextPtr;
		}
		else {
			ptr->nextPtr = list2;
			list2 = list2->nextPtr;
		}
		ptr = ptr->nextPtr;
	}
	if (list1) ptr->nextPtr = list1;
	else ptr->nextPtr = list2;

	return dummyHead.nextPtr;
}
template <typename T>
ListNode<T>* List<T>::getMid(ListNode<T>* head) {
	ListNode<T>* midPrev = nullptr;
	while (head && head->nextPtr) {
		midPrev = (midPrev == nullptr) ? head : midPrev->nextPtr;
		head = head->nextPtr->nextPtr;
	}
	ListNode<T>* mid = midPrev->nextPtr;
	midPrev->nextPtr = nullptr;

	return mid;
}