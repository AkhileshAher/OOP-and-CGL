/*
Title of the Assignment: Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.
*/

#include<iostream>
#include<cstring>
#include<exception>
using namespace std;

class publication
{
protected:
	string title;
	float price;
public:
	publication(string t="no title",float p=0.0)
{
		title=t;
		price=p;
}
};

class books:public publication
{
	int pages;
public:
	books(string t="No Title",float p=0.0,int pa=0):publication(t,p)
{
		pages=pa;
}

	void getb()
	{
		cout<<"**** Enter the details of the book ***** "<<endl;
		cout<<"enter the title of the book :"<<endl;
		cin>>title;
		cout<<"Enter the price of the book :"<<endl;
		cin>>price;
		cout<<"Enter the pages of the book :"<<endl;
		cin>>pages;


		try
		{
			if(pages>500 && pages<1500)
			{
				if(price>100 && price<2000)
				{
					displayb();
				}
			}
			else throw(pages);
		}
	catch(int i)
	{
		cout<<"Caught exception in function of book"<<endl;
		cout<<"You entered an invalid data"<<endl;
		title="0";
		price=0.0;
		displayb();
		throw;
	}
	}

	void displayb()
	{
		cout<<"The book you entered is :"<<endl<<endl;
		cout<<"The entered title is :"<<title<<endl;
		cout<<"The entered price is :"<<price<<endl;
		cout<<"The entered pages are :"<<pages<<endl;
	}
};


class tape:public publication
{
	float min;
public:
	tape(string t="No title",float p=0.0,float m=0.00):publication(t,p)
{
		min=m;
}
	void gett()
	{
		cout<<"Enter the details of tape :"<<endl;
		cout<<"Enter the title of tape :"<<endl;
		cin>>title;

		cout<<"Enter the price of the tape :"<<endl;
		cin>>price;
		cout<<"Enter the pages of the playing time(in minutes):"<<endl;
		cin>>min;

		try
		{
			if(min>30.00 && min<90.00)
			{
				if(price>500 && price<100)
				{
					displayt();
				}
			}
			else throw(min);
		}
		catch(float f)
		{
			cout<<"Caught exception in the function of tape"<<endl;
			cout<<"You entered invalid data "<<endl;
			title="0";
			price=0.0;
			min=0.0;
			displayt();
			throw;
		}
	}


void displayt()
{
	cout<<"The details of tape you entered is :"<<endl;
	cout<<"The entered title is :"<<title<<endl;
	cout<<"The enetered price is :"<<price<<endl;
	cout<<"The entered play time is :"<<min<<endl;

}
};

int main()
{
	books b;
	tape t;
	int choice;
	cout<<"Do you want to buy a book (Press 1) or a tape (Press 2):"<<flush;
	cin>>choice;

	switch(choice)
	{
	case 1:try
	{
		b.getb();
	}
	catch(int i)
	{
		cout<<"Caught exception in int main()"<<endl;
	}
	break;

	case 2:try
	{
		t.gett();
	}
	catch(float f)
	{
		cout<<"Caught exception in int main()"<<endl;
	}
	break;
	default: cout<<"Entered bad choice!! Try Again"<<endl;
	}
return 0;
};

