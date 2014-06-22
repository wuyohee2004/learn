#include<iostream>
#include<string.h>
using namespace std;

template<typename T1,typename T2>
class Node
{
	private:
		T1 key;
		T2 value;
		Node<T1,T2>* next;
	public:
		Node(T1 k,T2 v)
		{
			key = k;
			value = v;
		}

		Node<T1,T2>* getNext()
		{
			return next;
		}

		T1 getkey()
		{
			return key;
		}

		void setNext(Node<T1,T2>* node)
		{
			next = node;
		}

		void setValue(T2 v)
		{
			value = v;
		}

		T2 getValue()
		{
			return value;
		}

};

template <typename T1,typename T2>
class HashMap
{
	protected:
		static const int SIZE = 100;  
	
	
	public:
		Node<T1,T2>* buff[SIZE];
		HashMap()
		{
			for(int i=0;i<SIZE;i++)
				buff[i] = NULL;
		}

		virtual int hash(T1) = 0;
		virtual bool equal(T1,T1) = 0;

		~HashMap()
		{
			Node<T1,T2> *node,*next;
			for(int i=0;i<SIZE;i++)
			{
				node = buff[i];
				while(node)
				{
					next = node->getNext();
					delete node;
					node = next;
				}
			}
		}
		
		void hashput(T1 k,T2 v)
		{
			int i = hash(k);
			Node<T1,T2>* node = buff[i];
			while(node)
			{
				if(equal(k,node->getkey()))
				{
					node->setValue(v);
					return;
				}
				node = node->getNext();
			}
			node = new Node<T1,T2>(k,v);
			node->setNext(buff[i]);
			cout << "node 2st" << node->getValue() << endl;
			buff[i] = node;
			
		}

		bool get(T1 k,T2 &v)
		{
			int i = hash(k);
			Node<T1,T2>* node = buff[i];
			while(node)
			{
				if(equal(k,node->getkey()))
				{
					v = node->getValue();
					return true;
				}
				node = node->getNext();
			}
			return false;
		}
};

class MyHashMap:public HashMap<const char *,const char *>
{
	public:
		MyHashMap():HashMap(){}
		int hash(const char* s)
		{
			int a = 0;
			while(*s)
			{
				a += *s;
				s++;
			}
			return a%SIZE;
		}

		bool equal(const char *a,const char *b)
		{
			return !strcmp(a,b);
		}
};

int main()
{
	MyHashMap map;
	const char* a = NULL;
	map.hashput("age","18");
	map.hashput("name","emily");
	map.get("name",a);
	cout << a << endl;
	map.get("age",a);
	cout << a << endl;
	map.hashput("nmae","cisco");
	map.get("name",a);
	cout << a << endl;
	map.get("nmae",a);
	cout << a << endl;
	return 0;

}






