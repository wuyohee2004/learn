#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

template <typename T>
class Node
{
	private:
		T data;
		Node<T>* next;
	public:
		Node()
		{
			next = NULL;
		}
		Node(T d)
		{
			data = d;
			next = NULL;
		}
		T getData()
		{
			return data;
		}
		Node<T>* getNext()
		{
			return next;
		}
		void *setNext(Node<T>* node)
		{
			next = node;
		}
};


template <typename T>
class List
{
	private:
		Node<T> head;
	public:
		List(){}
		List(T[],int n);
		void nodeInsert(T d);
		void nodeDelete(T d);
		virtual bool equal(T,T) = 0;
		virtual void visit(Node<T>*);
		void traversal();
		void reverse1();
		void reverse2();
		void reverse3();
		~List();
};

template <typename T>
List<T>::List(T arr[],int n)
{
	for(int i=0;i<n;i++)
		nodeInsert(arr[i]);
}

template <typename T>
void List<T>::nodeInsert(T d)
{
	Node<T>* node = new Node<T>(d);
	node->setNext(head.getNext());
	head.setNext(node);
}

template <typename T>
List<T>::~List()
{
	Node<T>* node = head.getNext();
	Node<T>* next;
	while(node)
	{
		next = node->getNext();
		delete node;
		node = next;
	}
}

template <typename T>
void List<T>::nodeDelete(T d)
{
	Node<T>* node = &head;
	while(node->getNext())
	{
		if(equal(node->getNext()->getData(),d))
		{
			Node<T>* tmp = node->getNext();
			node->setNext(tmp->getNext());
			delete tmp;
			return;
		}
		node = node->getNext();
	}
}


template <typename T>
void List<T>::traversal()
{
	Node<T>* node = head.getNext();
	while(node)
	{
		visit(node);
		node = node->getNext();
	}
}

template <typename T>
void List<T>::visit(Node<T>* node)
{
	cout << node->getData() << " ";
}

template <typename T>
void List<T>::reverse1()
{
	Node<T> *cur,*next;
	cur = head.getNext();
	head.setNext(NULL);
	while(cur)
	{
		next = cur->getNext();
		cur->setNext(head.getNext());
		head.setNext(cur);
		cur = next;
	}
}

template <typename T>
void List<T>::reverse2()
{
	if(head.getNext() == NULL || head.getNext()->getNext() == NULL)
		return;
	Node<T> *pre,*next;
	pre = head.getNext();
	next = pre->getNext();
	head.setNext(next);
	reverse2();
	pre->setNext(NULL);
	next->setNext(pre);
}

template <typename T>
void List<T>::reverse3()
{
	if(head.getNext() == NULL || head.getNext()->getNext() == NULL)
		return;
	Node<T> *node,*last;
	node = head.getNext();
	while(node->getNext()->getNext())
		node = node->getNext();
	last = node->getNext();
	node->setNext(NULL);
	reverse3();
	last->setNext(node);
	head.setNext(last);
}

class Mylist:public List<int>
{
	public:
		Mylist():List(){}
		Mylist(int arr[],int n):List(arr,n){}
		bool equal(int a,int b)
		{
			return a == b;
		}
};

int main()
{
	int a[10],n=10;
	for(int i=0;i<n;i++)
		a[i] = rand()%100;
	Mylist list(a,sizeof(a)/sizeof(int));
	list.traversal();
	cout << endl;
	list.nodeDelete(21);
	list.traversal();
	cout << endl;
	list.reverse1();
	list.traversal();
	cout << endl;

	list.reverse2();
	list.traversal();
	cout << endl;
	list.reverse3();
	list.traversal();
	cout << endl;
	return 0;
}

