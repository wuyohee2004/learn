#include<iostream>
#include<stdlib.h>
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
		Node<T>* getNext()
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
		Node<T>* first;
	public:
		List()
		{
			first = NULL;
		}
		List(T arr[],int n)
		{
			first = NULL;
			for(int i=0;i<n;i++)
				NodeInsert(arr[i]);
		}
		void NodeInsert(T d)
		{
			Node<T>* node = new Node<T>(d);
			node->setNext(first);
			first = node;
		}
		void Nodetraversal()
		{
			Node<T>* node = first;
			while(node)
			{
				visit(node);
				node = node->getNext();
			}
		}
		void visit(Node<T>* node)
		{
			cout << node->getData() << " ";
		}
		void NodeDelete(T d)
		{
			if(first == NULL)
				return;
			Node<T>* node = first;
			if(equal(first->getData(),d))
			{	first = node->getNext();
				delete node;
				return;
			}
			while(node->getNext())
			{
				if(equal(node->getNext()->getData(),d))
				{
					Node<T>* tmp = node->getNext();
					node->setNext(tmp->getNext());
					delete tmp;
					return;
				}
				cout << node->getData() << endl;
				node = node->getNext();
				
			}
		}
		
		virtual bool equal(T a,T b){}
	
		void NodeReverse1()
		{
			Node<T> *cur,*next;
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

		void NodeReverse2()
		{
			if(first == NULL || first->getNext() == NULL)
				return;
			Node<T> *next,*pre;
			pre = first;
			next = first->getNext();
			pre->setNext(NULL);
			first = next;
			NodeReverse2();
			next->setNext(pre);
		}

		void NodeReverse3()
		{
			if(first == NULL || first->getNext() == NULL)
				return;
			Node<T> *node,*last;
			node = first;
			while(node->getNext()->getNext())
				node = node->getNext();
			last = node->getNext();
			node->setNext(NULL);
			NodeReverse2();
			last->setNext(node);
			first = last;
		}


		~List()
		{
			Node<T>* Next = first;
			while(first)
			{
				Next = first->getNext();
				delete first;
				first = Next;
			}
		}
};

			
class Mylist:public List<int>
{
	public:
		Mylist():List<int>(){};
		Mylist(int arr[],int n):List<int>(arr,n){};
		bool equal(int a, int b)
		{
			return a == b;
		}
};

int main()
{
	int arr[10],n=10;
	for(int i=0;i<10;i++)
		arr[i] = random()%100;
	Mylist mylist(arr,sizeof(arr)/sizeof(int));
	mylist.Nodetraversal();
	cout << endl;
	mylist.NodeReverse3();
	cout << endl;
	mylist.Nodetraversal();
	cout << endl;
	mylist.NodeDelete(21);
	cout << endl;
	mylist.Nodetraversal();
	cout << endl;
}



