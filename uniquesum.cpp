#include <bits/stdc++.h>
using namespace std;

int func()
{
	long long n;
	cin >> n;
	//considering n is even
	int a = ceil(
		(1 + sqrt(1 + 24 * n)) / 3.00);
	if (a % 2 != 0)
	{
		a = a + 1;
	}
	int b = ceil(
		sqrt((8 * n + 3)) / sqrt(3));
	if (b % 2 != 1)
	{
		b = b + 1;
	}

	if (b > a)
	{
		cout << a << endl;
		return 0;
	}
	else
	{
		cout << b << endl;
		return 0;
	}
	
	return 0;
}
int main()
{
	//write your code from here
	int testcases;
	cin >> testcases;
	while (testcases--)
	{
		func();
	}
	return 0;
}
