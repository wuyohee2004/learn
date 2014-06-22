#include "list.h"
int main()
{
	int arr[]={20,30,21,2,23,17,18,4,6,7};
	Mylist list(arr,sizeof(arr)/sizeof(int));
	list.traversal();
	cout << endl;
	list.nodedelete(30);
	
	list.traversal();
	cout << endl;
	list.reverse2();
	cout << endl;
	list.traversal();
	cout << endl;

	return 0;

}

