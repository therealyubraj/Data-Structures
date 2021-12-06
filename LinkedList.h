#pragma once

#include<iostream>
#include<string>
#include<exception>

using namespace std;

class IndexNotAvailableException : public exception
{
	//what()??
public:
	string message = "Cant insert at that index because index doesnot exist!";
};

template <typename Obj> class Node
{
private:
	Obj data;
	Node* prev;
	Node* next;

public:
	Node(Obj data_, Node* prev_, Node* next_)
	{
		data = data_;
		setPrev(prev_);
		setNext(next_);
	}

	Node(Obj data_)
	{
		data = data_;
		prev = nullptr;
		next = nullptr;
	}
	Node()
	{
		prev = nullptr;
		next = nullptr;
	}
	Obj getData()
	{
		return data;
	}

	Node* getPrev()
	{
		return prev;
	}

	Node* getNext()
	{
		return next;
	}

	void setPrev(Node* p)
	{
		if (p != prev)
		{
			prev = p;
			//cout << "Setting the previous of " << getData() << " to " << p->getData() << endl;
			if (p != nullptr) {
				p->setNext(this);
			}
		}
	}

	void setNext(Node* n)
	{
		if (n != next)
		{
			next = n;
			//cout << "Setting the next of " << getData() << " to " << n->getData() << endl;
			if (n != nullptr) {
				n->setPrev(this);
			}
		}
	}
};

template<typename Obj> class LinkedList
{
private:
	Node<Obj>* head;
	Node<Obj>* tail;
	int length = 0;

public:

	LinkedList()
	{
		head = new Node<Obj>();
		tail = new Node<Obj>();
		tail->setNext(head);
		tail->setPrev(head);
	}

	int size()
	{
		return length;
	}

	void printLinkedList()
	{
		Node<Obj>* cur = head->getNext();
		for (int i = 0; i < size(); i++) {
			cout << cur->getData() << endl;
			cur = cur->getNext();
		}
		cout << endl;
	}

	//insert object o into ith position Index starting at 0
	void insert(Obj o, int i)
	{
		if (i > size() || i < 0)
		{
			throw IndexNotAvailableException();
		}

		//TODO make searching for nodes N/2 instead of always starting with head!
		Node<Obj>* cur = head;
		for (int j = 0; j < i; j++)
		{
			cur = cur->getNext();
		}

		Node<Obj>* nextCur = cur->getNext();
		Node<Obj>* itemToInsert = new Node<Obj>(o);
		cur->setNext(itemToInsert);
		itemToInsert->setNext(nextCur);
		length++;
	}

	//delete a particular index from the list
	void deleteIndex(int i)
	{
		if (i > size() || i < 0)
		{
			throw IndexNotAvailableException();
		}

		Node<Obj>* cur = head;
		//Optimizie this as for insertion
		for (int j = 0; j <= i; j++) {
			cur = cur->getNext();
		}

		//set the previous of the next of cur to the prev of cur
		//this will atuomatically set the next of prev of cur to the next of cur
		//this frees cur from the linked list
		cur->getNext()->setPrev(cur->getPrev());

		delete cur;
	}

	//get Object from index i
	Obj get(int i)
	{
		if (i > size() || i < 0)
		{
			throw IndexNotAvailableException();
		}
		
		Node<Obj>* cur = head;
		//Optimizie this as for insertion
		for (int j = 0; j <= i; j++) {
			cur = cur->getNext();
		}
		return cur->getData();
	}
};
