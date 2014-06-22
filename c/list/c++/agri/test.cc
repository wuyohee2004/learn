#include<iostream>
#include<stdlib.h>
using namespace std;
template <typename T>
class A
{
	public:
		virtual T ou(){}
		A()
		{
			cout << ou() << "class A" << endl;
		}

};
class B:public A<int>
{
	public:
		int ou()
		{
			return rand()%100;
		}
};

int main()
{
	B test;
//	cout << test.ou() << "class B" << endl;
//	test.in();
}

