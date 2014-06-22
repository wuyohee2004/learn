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
};



