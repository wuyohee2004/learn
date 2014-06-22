#include<stdio.h>
#include "stack.h"
#include<stdlib.h>
#include<iostream>

template<typename T>
class Node
{
	private:
		T data;
		Node<T> *lchild,*sibling;
	public:
		Node(T d)
		{
			data = d;
			lchild = NULL;
			sibling = NULL;
		}

		void setlChild(Node<T>* node)
		{
			lchild = node;
		}

		void setSibling(Node<T>* node)
		{
			sibling = node;
		}

		Node<T>* getlChild()
		{
			return lchild;
		}
		Node<T>* getSibling()
		{
			return sibling;
		}

		T getData()
		{
			return data;
		}

};

template<typename T>
class Tree
{
	private:
		Node<T>* root;
	public:
		Tree()
		{
			root = NULL;
		}

		Tree(int n)
		{
			root = create(n);
		}

		Node<T>* create(int n)
		{
			if( n < 0)
				return NULL;
			Node<T>* node = new Node<T>(n);
			Node<T> *p;
			int num = random()%4;
			cout << "(" << num << ")";
			if(num > 0)
			{
				p = create(n-1);
				node->setlChild(p);
				for(int i=1;p && i<num;i++)
				{
					p->setSibling(create(n-1));
					p = p->getSibling();
				}
			}
			return node;
		}

		void visit(Node<T>* node)
		{
			cout << node->getData() << " ";
		}


		void preTraversal(Node<T>* node)
		{
			if(node == NULL)
				return;
			Node<T> *p = node->getlChild();
			visit(node);
			while(p)
			{
				preTraversal(p);
				p = p->getSibling();
			}
		}

		void preTraversal()
		{
			preTraversal(root);
		}

		void postTraversal(Node<T>* node)
		{
			if(node == NULL)
				return;
			Node<T>* p = node->getlChild();
			while(p)
			{
				postTraversal(p);
				p = p->getSibling();
			}
			visit(node);
		}

		void postTraversal()
		{
			postTraversal(root);
		}

};

int main()
{
	Tree<int> tree(2);
	tree.postTraversal();
	cout << endl;
	return 0;
}





