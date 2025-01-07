#include <iostream>
using namespace std;

void callByReferences(int &y)	// y is a reference variable
{
	cout << "y = " << y << endl;

	y = 69;

	cout << "y = " << y << endl;
}	// y is destroyed here

int main()
{
	int x(1);
	cout << "x = " << x << endl;

	callByReferences(x);

	cout << "x = " << x << endl;

	return 0;
}
