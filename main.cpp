#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "item.h"
#include "store.h"
using namespace std;

int main()
{	
	int code;
	int checknum;
	LPCTSTR caption;
	string name;
	float price;
	int index;
	bool bFail;
	int add;
	int test;
	int test2;
	int branch;
		Item* temp;
	Item* item = new Item[2];
	Store* store = new Store[10];
	
	store[0].setStoreName("Skudai");
	item[0].setInfo(1234, "Aji Na Moto",1.43);
	item[1].setInfo(12334, "Ajsfdi Na Moto",12.43);
	store[0].addItem(&item[0]);
	//store[0].addItem(&item[1]);
	
	store[1].setStoreName("Pasir Gudang");
	store[2].setStoreName("Janda Baik");
	store[3].setStoreName("Janda Jahat");
	store[4].setStoreName("Batang Buruk");
	store[5].setStoreName("Batang Cantik");
	store[6].setStoreName("Pontian");
	store[7].setStoreName("Pontianak");
	store[8].setStoreName("Yong Peng");
	store[9].setStoreName("Chin Peng");
	//item[0].setInfo(1234, "Aji Na Moto",1.43);
	//store[0].addItem(&item[0]);
	//cout <<store[0]<<endl;
	
	
	
	//Store st1("Ali",&item[0]);
	//Store st2("Ali",&item[0]);
	//cout<<"Add item"<<endl;
	//cin>>add;
	//st1.addItem2(item,add);
	//cout<<"remove item"<<endl;
	
	//cin>>index;
	//st1.removeItem(1);
	
	int choose;
	do{
	cout<<"\n==========================";
	cout<<"\n Choose Branch/Store";
	cout<<"\n=========================="<<endl;
	
	for (int i=0;i<10;i++){
		cout<<i+1<<".) "<<store[i].getStoreName()<<endl;
	}
	cout<<"\n=========================="<<endl;
	cin>>branch;
	bFail=cin.fail();
	cin.clear();
	cin.ignore(numeric_limits < streamsize > ::max(), '\n');
	if (branch == 1|| branch == 2){
		branch = branch -1;	
	}
	
	else {
		system("exit");
	}
	
	}while(bFail==true);
	

	

	char selection;

do {
	system("cls");
cout<<"\033[0;32m"<<store[branch]<<endl;	

cout<<"\n Menu";

cout<<"\n========";

cout<<"\n A - Add item";

cout<<"\n D - Delete item";

cout<<"\n E - Change item price (Promotion)";

cout<<"\n C - Change Branch";

cout<<"\n R - Report";

cout<<"\n X - Exit";

cout<<"\n Enter selection: ";

cin>>selection;

switch(selection)

{

case 'A' :

case 'a' :{
	
cout<<"\n Input the product.\n";



do{
cout<<"\n Code: ";
cin>>code;
bFail=cin.fail();
cin.clear();
cin.ignore(numeric_limits < streamsize > ::max(), '\n');
}while(bFail==true);


cout<<" Name: ";
//cin>>name;
cin.ignore();
//gets(name);
getline(cin,name);
//cout<<name;
do{
cout<<"Price: ";
cin>>price;
bFail=cin.fail();
cin.clear();
cin.ignore(numeric_limits < streamsize > ::max(), '\n');
}while(bFail==true);


	temp =  new Item[1];
				
	temp[0].setInfo(code,name,price);
		
	store[branch].addItem(&temp[0]);
	delete [] temp;
	caption = "Success";
	MessageBox(NULL, "Success. Item has been added to the store.", caption, MB_ICONASTERISK);
}

break;

case 'e' :

case 'E' :{
	
	cout<<"put item no. to edit: ";
	cin>>price;
	store[branch].editItem(price);
	cout<<store[branch]<<endl;
	
}

break;

case 'M' :

case 'm' :{cout<<"\n To modify a record";}

break;

case 'C' :

case 'c' :{

	cout<<"\n==========================";
	cout<<"\n Choose Branch/Store";
	cout<<"\n=========================="<<endl;
	
	for (int i=0;i<10;i++){
		cout<<i+1<<".) "<<store[i].getStoreName()<<endl;
	}
	cout<<"\n=========================="<<endl;
	cin>>branch;
	branch = branch -1;
	cout<<store[branch]<<endl;
}

break;

case 'D' :

case 'd' :{
cout<<store[branch]<<endl;
cout<<"input Item code to delete: ";
cin>>index;
store[branch].removeItem(index);
MessageBox(NULL, "Item has been deleted from the store.", "Deleted", MB_ICONWARNING);

}

break;

case 'X' :

case 'x' :{cout<<"\n To exit the menu";}

break;

case 'R' :

case 'r' :{

ofstream myfile,myfile2;
myfile.open ("Report.txt");
myfile2.open("backup"); 
for (int x = 0;x<10;x++){
	
	myfile <<store[x];
	myfile<<endl<<endl<<endl<<endl;
}
myfile.close();
MessageBox(NULL, "The data has been reported to Report.txt", NULL, NULL);
cin.ignore() ; 
cin.get();
system("cls");
}

break;

// other than A, M, D and X...

default : 
{
	cout<<"Invalid selection"<<endl;
	system("pause");
}
// no break in the default case

}

}while (selection != 'x');

cout<<"\n";

// read the input

	/*Item* temp =  new Item[st1.getCount() + add];
	
	for (int x= 0;x<st1.getCount();x++){
		temp[x] = item[x];
	}
	
	int code;
	string name;
	float price;
	int test = st1.getCount();
	int test2 = add+st1.getCount();
	for (int x = test ; x<test2; x++){
		cout<<"code: ";
		cin>>code;
		cout<<"name: ";
		cin>>name;
		cout<<"price: ";
		cin>>price;
		
		temp[x].setInfo(code,name,price);
		st1.addItem(&temp[x]);
	}
	
	delete [] item;
	item = temp; */

	

	//Store st1("Ali",&item[0]);
	//Student st2("Baba", &mp1);

//	st1.addItem(&item[1]);


//	cout<<st1<<endl;
	//cout<<item[2];
	return 0;
}
