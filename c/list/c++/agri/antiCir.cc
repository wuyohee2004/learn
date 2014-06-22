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
		Node<T>* getHead()
		{
			return first;
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

		T lastN(int n)
		{
			Node<T> *fast=first,*slow=first;
			while(n-- && fast)
				fast = fast->getNext();
			if(n >0)
				return 0;
			while(fast)
			{
				fast = fast->getNext();
				slow = slow->getNext();
			}
			return slow->getData();
		}

		bool isCircle()
		{
			Node<T> *fast=first,*slow=first;
			while(fast&&fast->getNext()&&fast->getNext()->getNext())
			{
				fast = fast->getNext()->getNext();
				slow = slow->getNext();
				if(fast == slow)
					return true;
			}
			return false;
		}

		void setLoop()
		{
			Node<T>* node=first;
			while(node->getNext())
				node = node->getNext();
			node->setNext(first);
		}

		T cross(Node<T>* h2)
		{
			int len1=1,len2=1;
			Node<T> *node1=first,*node2=h2;
			while(node1->getNext())
			{
				len1++;
				node1 = node1->getNext();
				
			}
			while(node2->getNext())
			{
				len2++;
				node2 = node2->getNext();
			}
			if(node1 != node2)
				return 1;
			int n = len1-len2;
			if(n>0)
			{
				node1 = first;
				node2 = h2;
			}else
			{
				node1 = h2;
				node2 = first;
				n = len2-len1;
			}
			while(n)
			{	
				node1 = node1->getNext();
				n--;
			}
			while(node1 != node2)
			{
				node1 = node1->getNext();
				node2 = node2->getNext();
			}
			return node1->getData();
		}
			
		void setCross(Node<T>* first2)
		{
			Node<T> *node1=first,*node2=first2;
			for(int i=0;i<4;i++)
			{
				node1 = node1->getNext();
				node2 = node2->getNext();
			}
			node2->setNext(node1->getNext());
		}

		~List()
		{
			Node<T> *Next = first,*tmp = first;
			while(first&&first!=tmp)
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
	Mylist mylist2(arr,sizeof(arr)/sizeof(int));

	mylist.NodeReverse3();
	cout << "mylist:";
	mylist.Nodetraversal();
	cout << endl;
	cout << "mylist2:";
	mylist2.Nodetraversal();
	cout << endl;
	cout<< "start cross" << endl;
	mylist.setCross(mylist2.getHead());
	
	cout << "cross point is <mylist>:" << mylist.cross(mylist2.getHead()) << endl;
	cout << "mylist2:";
	mylist2.Nodetraversal();
	cout << endl;
//	cout << endl;
//	mylist.Nodetraversal();
//	cout << endl;
//	mylist.NodeDelete(21);
//	cout << endl;
//	mylist.Nodetraversal();
//	cout << endl;
//	mylist.setLoop();
	if(mylist.isCircle())
		cout << "this is a loop list" << endl;
	else
		cout << "this is a correct list" << endl;
	cout << mylist.lastN(3) << endl;

	return 0;
}




