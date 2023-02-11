#include<iostream>
#include<fstream>
using namespace std;
class Resturant
{
	string readfile;
	int select;	
	double price;
	int numberofitems;
	int orderloop;
	double total_price;
	int order_no;
	double getdata;
	int newday;
	public:
		Resturant()
		{
			orderloop = 0;
			orderloop = 0;
			price = 0;
			numberofitems = 0;
			total_price = 0;
			order_no = 0;
			getdata = 0;
			newday = 0;
			
		}
		void new_day();
		void showmenu();
		void select_item();
		void stupid_number();
		void order();
		void multipleorder();
		void calculate(int a);
		void calculate();
		void display();
		void total_order();
		void total_amount();
};
void Resturant::showmenu()
{
	ifstream menu("menu.txt");
	for(int i =0; i<10;)
	{
		i++;
		getline(menu,readfile);
		cout<<readfile<<"\n"<<endl;
	}
	menu.close();
	select_item();
}
void Resturant::select_item()
{
	cout<<"Press from 1 to 10 to select an item from the menu: ";
	cin>>select;

	cout<<"How many numbers of that item do you want to order: ";
	cin>>numberofitems;
	stupid_number();
}
void Resturant::stupid_number()
{
		if(select<1 or select > 10 )
	{
		cout<<"We don't have item number "<<select<<" \n" ;
		select_item();
	}
	else if(numberofitems < 1)
	{
		cout<<"You can't order "<<numberofitems<<" items\n";
		select_item();
	}
	else
	{
		order();
	}
	
}
void Resturant::order()
{
	switch (select)
	{
		case 1:
			price = price + (150 * numberofitems);
			break;
		case 2:
			price = price + (170 * numberofitems);
			break;
		case 3:
			price = price + (175 * numberofitems);
			break;
		case 4:
			price = price + (195 * numberofitems);
			break;
		case 5:
			price = price + (205 * numberofitems);
			break;
		case 6:
			price = price + (75 * numberofitems);
			break;
		case 7:
			price = price + (195 * numberofitems);
			break;
		case 8:
			price = price + (115 * numberofitems);
			break;
		case 9:
			price = price + (125 * numberofitems);
			break;
		case 10:
			price = price + (45 * numberofitems);
			break;
	}
	multipleorder();
}
void Resturant::multipleorder()
{
	cout<<"Press 0 if you want to order more items or press anything else if you are done ordering: ";
	cin>> orderloop;
	if (orderloop == 0)
	{
		select_item();
	}
}
void Resturant::calculate(int a)
{
	total_price = price + (price * a/100);
}
void Resturant::calculate()
{
	total_price = total_price + (total_price * 13/100);
}
void Resturant::display()
{
	cout<<"\n\n              BILL           \n";
	cout<<"Your total bill is Rs "<<price;
	cout<<"\nYour vat is Rs "<< ((price * 10/100) + price) * 13/100;
	cout<<"\nYour service tax is Rs "<< price * 10/100;
	cout<<"\nYOur total bill with vat and service tax is Rs "<<total_price<<"\n\n";
}
void Resturant::total_amount()
{
	ifstream amount_in("total_amount.txt");
	amount_in >> getdata;
	getdata = getdata + total_price;
	ofstream amount_out("total_amount.txt");
	amount_out << getdata;	
	amount_in.close();
}
void Resturant::total_order()
{
	ifstream order_in("total_order.txt");
	order_in >> order_no;
	order_no = order_no + 1;
	ofstream order_out("total_order.txt");
	order_out << order_no;	
	order_in.close();
}
void Resturant::new_day()
{
	cout<<"\n\nPress 1 if you want to start a new day or press anything else if it is not a new day: ";
	cin>> newday;
	if (newday == 1)
	{
		ofstream amount_out("total_amount.txt");
		ofstream order_out("total_order.txt");
		amount_out << 0;
		order_out << 0;
		amount_out.close();
		order_out.close();
	}
}
int main()
{
	Resturant r1;
	r1.new_day();
	cout << "\n\n!!!!!                           MENU                           !!!! \n \n" ;
	r1.showmenu();
	r1.calculate(10);
	r1.calculate();
	r1.display();
	r1.total_amount();
	r1.total_order();
}
