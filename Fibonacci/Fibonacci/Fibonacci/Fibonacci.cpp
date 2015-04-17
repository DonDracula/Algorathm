// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//Version 1
long Fibonacci1(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else if(n>1)
		return Fibonacci1(n-1)+Fibonacci1(n-2);
	else 
		return -1;
}

//Version 2
long Fibonacci2(int n)
{
	long cur=1,pre=0;
	if(n==0)
		return 0;
	else if(n>0)
	{
		for(int i=1;i<n;i++)
		{
			cur=cur+pre;
			pre=cur-pre;
		}
		return cur;
	}
}

int main(int argc, char *argv[])
{
	cout <<Fibonacci1(100)<<endl;
	cout <<Fibonacci2(100)<<endl;
}
