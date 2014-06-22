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
		Node<T>* pre;
	public:
		Node(T d)
		{
			data = d;
			next = NULL;
		}
		Node()
		{
			pre = NULL;
			next = NULL;
		}
		Node<T> *getPre()
		{
			return pre;
		}
		void setPre(Node<T>* node)
		{
			pre = node;
		}
		Node<T> *getNext()
		{
			return next;
		}
		void setNext(Node<T>* node)
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
		Node<T>* head;
	public:
		List();
		List(T[],int);
		virtual ~List();
		void headInsert(T);
		void tailInert(T);
		void traversal();
		void reverse();
		void nodeDelete(T);
		virtual void visit(Node<T>*);
		virtual bool equal(T,T) = 0;
};

template <typename T>
List<T>::List()
{
	head = new Node<T>();
}

template <typename T>
void List<T>::headInsert(T d)
{
	Node<T>* node = new Node<T>(d);
	node->setNext(head->getNext());
	node->setPre(head);
	head->getNext()->setPre(node);
	head->setNext(node);
}

template <typename T>
void List<T>::tailInert(T d)
{
	Node<T>* node = new Node<T>(d);
	node->setNext(head);
	node->setPre(head->getPre());
	head->getPre()->setNext(node);
	head->setPre(node);
}

template<typename T>
List<T>::List(T arr[],int n)
{
	head = new Node<T>();
	head->setNext(head);
	head->setPre(head);
	for(int i=0;i<n;i++)
		headInsert(arr[i]);
}

template<typename T>
void List<T>::nodeDelete(T d)
{
	Node<T> *node = head->getNext();
	while(node != head)
	{
		if(equal(node->getData(),d))
		{
			node->getPre()->setNext(node->getNext());
			node->getNext()->setPre(node->getPre());
			delete node;
			return;
		}
		node = node->getNext();

	}
}

template <typename T>
void List<T>::traversal()
{
	Node<T>* node = head->getNext();
	while(node != head)
	{
		visit(node);
		node = node->getNext();
	}
}

template <typename T>
void List<T>::visit(Node<T>* node)
{
	cout << node->getData() <<" ";
}

template <typename T>
void List<T>::reverse()
{
	Node<T> *tempre,*pre=head,*cur,*next;
	tempre=cur=head->getNext();
	while(cur != head)
	{
		next = cur->getNext();
		cur->setPre(next);
		cur->setNext(pre);
		pre = cur;
		cur = next;
	}
	head->setNext(pre);
	head->setPre(tempre);
}

template <typename T>
List<T>::~List()
{
	Node<T> *node,*next;
	node = head->getNext();

	while(node != head)
	{
		next = node->getNext();
		delete node;
		node = next;
	}
	delete head;
}

class Mylist:public List<int>
{
	public:
		Mylist():List(){}
		Mylist(int arr[],int n):List(arr,n){}
		bool equal(int a ,int b)
		{
			return a==b;
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
	list.nodeDelete(49);
	list.traversal();
	cout << endl;
	list.reverse();
	list.traversal();
	cout << endl;

}






