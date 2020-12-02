#pragma once



template<typename T> class List;

template <typename T>
class ListNode // nodes to be contained with a list
{
	friend class List<T>;

public:
	ListNode(T);
	T getData();


	T data;
	ListNode* nextPtr;

};

template <typename T>
ListNode<T>::ListNode(T dataIn)
{
	data = dataIn;
	nextPtr = 0;
}

template<typename T>
T ListNode<T>::getData() {
	return data;
}

