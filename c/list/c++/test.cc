#include<iostream>

using namespace std;

class Test
{
	private:
		int a;
	public:
		Test(void)
		{
			cout << __LINE__ << endl;
		}
		~Test()
		{
			cout << __LINE__ <<endl;
		}

		void show()
		{
			cout << a << endl;
		}
};

class B : Test
{
	public:
		B(void) : Test()
		{
			cout << __LINE__ << endl;
		};
};


int main()
{
	B b();
	return 0;
}











