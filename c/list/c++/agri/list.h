#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

template <typename T>
class Node
{
	private:
		T data;
		Node<T> *next;
	public:
		Node(T d)
		{
			data = d;
			next = NULL;
		}
		Node<T> *getNext()
		{
			return next;
		}
		void setNext(Node<T> *node)
		{
			next = node;
		}
		T getData()
		{
			return data;
		}
};


template <typename T>
class List
{
	private:
		Node<T> *first;
	public:
		List();
		List(T arr[],int n);
		void nodeInsert(T d);
		void traversal();
		virtual void visit(Node<T> *node);
		void nodedelete(T);
		virtual bool equal(T a, T b) = 0;
		void reverse1();
		void reverse2();
		void reverse3();
		~List();
};

template <typename T>
List<T>::List()
{
	first = NULL;
}


template <typename T>
List<T>::List(T arr[],int n)
{
	first = NULL;
	for(int i = 0;i < n;i++)
	{
		nodeInsert(arr[i]);
	}
}

template <typename T>
List<T>::~List()
{
	Node<T> *next;
	while(first)
	{
		next = first->getNext();
		delete first;
		first = next;
	}
}

template <typename T>
void List<T>::nodeInsert(T d)
{
	Node<T> *node = new Node<T>(d);
	node->setNext(first);
	first = node;
}


template <typename T>
void List<T>::traversal()
{
	Node<T> *node = first;
	while(node)
	{
		visit(node);
		node = node->getNext();
	}
}


template <typename T>
void List<T>::visit(Node<T> *node)
{
	cout << node->getData() << " ";
}

template <typename T>
void List<T>::nodedelete(T d)
{
	if(first == NULL)
		return;
	Node<T> *node = first;
	if(equal(first->getData(),d))
	{
		first = first->getNext();
		delete node;
		return;
	}

	while(node->getNext())
	{
		if(equal(node->getNext()->getData(),d))
		{	
			Node<T> *tmp = node->getNext();
			node->setNext(tmp->getNext());
			delete tmp;
			return;
		}
	
		node = node->getNext();
	}

}

template <typename T>
void List<T>::reverse1()
{
	Node<T> *next,*cur;
	cur = first;
	first = NULL;
	while(cur)
	{
		next = cur->getNext();
		cur->setNext(first);
		first = cur;
		cur = next;
	}
}


template <typename T>
void List<T>::reverse2()
{
	if(first == NULL || first->getNext() == NULL)
		return;
	Node<T> *pre,*next;
	pre = first;
	next = first->getNext();
	pre->setNext(NULL);
	first = next;

	reverse2();
	next->setNext(pre);
}

template <typename T>
void List<T>::reverse3()
{
	if(first == NULL || first->getNext() == NULL)
		return;
	Node<T> *node,*last;
	node = first;
	while(node->getNext()->getNext())
		node = node->getNext();
	last = node->getNext();
	node->setNext(NULL);
	reverse3();
	last->setNext(node);
	first = last;
}

class Mylist:public List<int>
{
	public:
		Mylist():List(){}
		Mylist(int arr[],int n):List<int>(arr,n){}



		bool equal(int a, int b)
		{
			return a == b;
		}
};
