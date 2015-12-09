//===================================================
//================DOUBLY LINKED LIST=================
//=================OVERFIELD 10/21/15================
//===================================================

#include <iostream>
using namespace std;
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <class T>
struct Node
{
public:
	T data;
	Node<T> *next;
	Node<T> *prev;
	Node()
	{
		next = NULL;
		prev = NULL;
	}
};

teamplate <class T>
class LinkedList
{
public:
	Node<T> *head = NULL;
	Node<T> *curr = NULL;
	LinkedList();
	int ListLength();
	void ListInsert(T);
	void ListDelete(T);
	void ListDisplay();
	void ReverseDisplay();
	void Search(T);
	Node<T> *PointTo(T);
private:
	int size = 0;
	Node<T> *tail = NULL;
};

teamplate <class T>
LinkedList<T>::LinkedList():size(0), head(NULL){}

teamplate <class T>
int LinkedList<T>::ListLength()
{
	return size;
}

teamplate <class T>
void LinkedList<T>::ListInsert(T a)
{
	int newLength = ListLength() + 1;
	Node<T> *newNode = new Node<T>;
	if (head == NULL)
	{
		head = newNode;
		curr = newNode;
		tail = curr;
		tail->next = head;
		newNode->data = a;
	}
	else
	{
		curr->next = newNode;
		newNode->prev = curr;
		curr = newNode;
		tail = curr;
		newNode->data = a;
	}
	size = newLength;
}

teamplate <class T>
void LinkedList<T>::ListDelete(T b)
{
	int pos = 1;
	int newLength = ListLength() - 1;
	Node<T> *temp = new Node<T>;
	Node<T> *prev = new Node<T>;
	temp = head;
	while (temp->num != b)
	{
		temp = temp->next;
		pos++;
	}
	prev = PointTo(pos-1);
	prev->next = prev->next->next;
	delete temp;
	temp = NULL;
	size = newLength;

}

teamplate <class T>
void LinkedList<T>::ListDisplay()
{
	for (Node<T> *current = head; current != NULL; current = current->next)
	{
		cout << "Current Node Data:\t" << current->data << endl;
		cout << "Current Node Address:\t" << current << endl;
		cout << "Next Node Address:\t" << current->next << endl << endl;
		cout << "*****************************************************" << endl << endl;
	}
}

teamplate <class T>
void LinkedList<T>::ReverseDisplay()
{
	for (Node<T> *current = tail; current != head; current = current->prev)
	{
		cout << "Current Node Data:\t" << current->data << endl;
		cout << "Current Node Address:\t" << current << endl;
		cout << "Next Node Address:\t" << current->prev << endl << endl;
		cout << "*****************************************************" << endl << endl;
	}
	cout << "Current Node Data:\t" << head->data << endl;
	cout << "Current Node Address:\t" << head << endl;
	cout << "Next Node Address:\t" << head->prev << endl << endl;
	cout << "*****************************************************" << endl << endl;
}

teamplate <class T>
Node<T> *LinkedList<T>::PointTo(T pos)
{
	if ((pos<1) || (pos > ListLength())) return NULL;
	else
	{
		Node<T> *current = head;
		for (int skip = 1; skip < pos; skip++)
		{
			current = current->next;
		}
		return current;
	}
}

#endif