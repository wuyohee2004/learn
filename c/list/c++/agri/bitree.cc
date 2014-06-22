#include<stdio.h>
#include "stack.h"
#include<stdlib.h>
#include<iostream>

using namespace std;

template <typename T>
class Node
{
	private:
		T data;
		Node<T> *lsub,*rsub;
	public:
		Node(T d)
		{
			data = d;
			lsub = NULL;
			rsub = NULL;
		}
		void setlsub(Node<T>* node)
		{
			lsub = node;
		}
		void setrsub(Node<T>* node)
		{
			rsub = node;
		}
		Node<T>* getlsub()
		{
			return lsub;
		}
		Node<T>* getrsub()
		{
			return rsub;
		}
		T getData()
		{
			return data;
		}
};

template<typename T>
class binTree
{
	private:
		Node<T>* root;
		void preTraversal(Node<T>* node)
		{
			if(node == NULL)
				return;
			visit(node);
			preTraversal(node->getlsub());
		
			preTraversal(node->getrsub());
		
		}

		void midTraversal(Node<T>* node)
		{
			if(node == NULL)
				return;
			midTraversal(node->getlsub());
			visit(node);
			midTraversal(node->getrsub());
		}

		void postTraversal(Node<T>* node)
		{
			if(node == NULL)
				return;
			postTraversal(node->getlsub());
			postTraversal(node->getrsub());
			visit(node);
		}

	public:
		binTree()
		{
			root = NULL;
		}
		
		binTree(int n)
		{
			root = create(n);
		}

		Node<T>* create(int n)
		{
			if(n < 0)
				return NULL;
			Node<T>* node = new Node<T>(n);
			node->setlsub(create(n-1));
			node->setrsub(create(n-1));
			return node;
		}
		
		void preTraversal()
		{
			preTraversal(root);
		}

		void midTraversal()
		{
			midTraversal(root);
		}

		void postTraversal()
		{
			postTraversal(root);
		}

		void visit(Node<T> *node)
		{
			cout << node->getData() << " ";
		}

		void depthtraversal()
		{
			Node<T> *node;
			Stack<Node<T>*> s(50);
			s.push(root);
			while(!s.isEmpty())
			{
				s.pop(node);
				visit(node);
				if(node->getrsub())
					s.push(node->getrsub());
				if(node->getlsub())
					s.push(node->getlsub());
			}
		}

		void stackpre()
		{
			Stack<Node<T>*> s(50);
			Node<T> *p = root;
			while(p || !s.isEmpty())
			{
				while(p)
				{
					visit(p);
					s.push(p);
					p = p->getlsub();
				}
				if( !s.isEmpty() )
				{
					s.pop(p);
					p = p->getrsub();
				}
			}
		}

		void stackmid()
		{
			Stack<Node<T>*> s(50);
			Node<T> *p = root;
			while( p || !s.isEmpty() )
			{
				while(p)
				{
					s.push(p);
					p = p->getlsub();
				}
				if( !s.isEmpty())
				{
					s.pop(p);
					visit(p);
					p = p->getrsub();
				}
			}
		}
		
		void stackpost()
		{
			Stack<Node<T>*> s(50);
			Node<T> *node,*pre=NULL;
			s.push(root);
			while(!s.isEmpty())
			{
				s.top(node);
				if((node->getrsub() == NULL && node->getlsub() == NULL) \
				|| (pre != NULL && (pre == node->getrsub() \
				|| pre == node->getlsub())))
				{
					s.pop(node);
					visit(node);
					pre = node;
				}else
				{
					if(node->getrsub())
						s.push(node->getrsub());
					if(node->getlsub())
						s.push(node->getlsub());
				}
			}
		}



		void widetraversal()
		{
			Node<T> *node;
			Queue<Node<T>*> q(50);
			q.enqueue(root);
			while(!q.isEmpty())
			{
				q.dequeue(node);
				visit(node);
				if(node->getrsub())
					q.enqueue(node->getrsub());
				if(node->getlsub())
					q.enqueue(node->getlsub());
			}
		}

		int height(Node<T>* node)
		{
			if(NULL == node)
				return -1;
			int l = height(node->getlsub())+1;
			int r = height(node->getrsub())+1;
			return l > r ? l : r;

		}

		int Height()
		{
			return	height(root);
		}

		int leafNum(Node<T>* node,int k)
		{
			if(node == NULL || k<0)
				return 0;
			if(k == 0)
				return 1;
			int l = leafNum(node->getlsub(),k-1);
			int r = leafNum(node->getrsub(),k-1);
			return l+r;
		}

		int LeafNum()
		{
			return leafNum(root,3);
		}

		int subNum(Node<T>* node)
		{
			if(node == NULL)
				return 0;
			if(node->getlsub() == NULL && node->getrsub() == NULL)
				return 1;
			int l = subNum(node->getlsub());
			int r = subNum(node->getrsub());
			return l+r;
		}
		
		int SubNum()
		{
			return subNum(root);
		}

		int nodeNum(Node<T>* node)
		{
			if(node == NULL)
				return 0;
			int l = nodeNum(node->getlsub());
			int r = nodeNum(node->getrsub());
			return l+r+1;
		}

		int NodeNum()
		{
			nodeNum(root);
		}



					




};

int main()
{
	binTree<int> tree(3);
//	tree.preTraversal();
//	cout << endl;
//	tree.depthtraversal();
//	cout << endl;
//	tree.stackpre();
//	cout << endl;
//	tree.stackmid();
//	cout << endl;
//	tree.widetraversal();
//	cout << endl;
//	tree.midTraversal();
//	cout << endl;
//	tree.stackpost();
//	cout << endl;
	tree.postTraversal();
	cout << endl;
	cout << tree.Height() << endl;
	cout << tree.LeafNum() << endl;
	cout << tree.SubNum() << endl;
	cout << tree.NodeNum() << endl;



}

			
		

			
