/*
 Title of the Assignment:  Write a function template for selection sort that inputs, sorts and outputs
 an integer array and a float array.
 */

#include <iostream>
using namespace std;
int n;
#define size 10

template<class T>

void se1(T a[size])
{
	int i,j,min;
	int temp;
	for(i=0;i<n;i++)
	{
			min=i;
			for(j=1;j<n; j++)
			{
				if(a[j]<a[min])
					min=j;
			}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;


	}
	cout<<"\n sorted array : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<a[i];
	}


}
int main()
{
	int a[size];
	float b[size];
	cout<<"\n enter total number of integer element :"<<endl;
	cin>>n;
	cout<<"\n enter integer element : "<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];

	}
	se1(a);

	cout<<"\n enter total number of float : ";
	cin>>n;
	cout<<"\n enter float element : ";
	for(int i=0;i<n;i++)
	{
		cin>>b[size];

	}
	se1(b);
return 0;
}


