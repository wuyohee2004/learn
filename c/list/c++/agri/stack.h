#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

template <typename S>
class Stack
{
	private:
		S *data;
		int sp;
		int size;
	public:
		Stack(int n)
		{
			size = n;
			sp = 0;
			data = new S[n];
		}
		bool isEmpty()
		{
			return sp == 0;
		}
		bool isFull()
		{
			return sp == size;
		}
		bool push(S d)
		{
			if(isFull())
				return false;
			data[sp++] = d;
		}
		bool pop(S &d)
		{
			if(isEmpty())
				return false;
			sp--;
			d = data[sp];
			return true;
		}

		void top(S &d)
		{
			d = data[sp-1];
		}

};

template<typename Q>
class Queue
{
	private:
		Q *data;
		int rear;
		int front;
		int size;
	public:
		bool isEmpty()
		{
			return rear == front;
		}

		bool isFull()
		{
			return (rear+1)%size == front;
		}

		Queue(int s)
		{
			data = new Q[s];
			rear = 0;
			front = 0;
			size = s;
		}

		~Queue(){}
		//FIXME
		
		int dequeue(Q &d)
		{
			if(isEmpty())
				return -1;
			d = data[front];
			front++;
			front %= size;
			return 0;
		}

		int enqueue(Q d)
		{
			if(isFull())
				return -1;
			data[rear] = d;
			rear++;
			rear %= size;
			return 0;
		}
};

		

