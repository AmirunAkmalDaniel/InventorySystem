#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

class Item
{
	float price;
	string name;
	int code;
public:
	Item() {}
	Item( int c,string m,float p): code(c),price(p), name(m) {} 
	friend ostream& operator<< (ostream& o, Item& i)
	{
	
	o <<left<<setw(12)<<i.code <<left<<setw(40)<< i.name <<left<< setw(50)<< i.price ;
	 //o<<i.code<<"("<<i.name<<")(RM"<<i.price<<")"; 
	 return o;
	
	 }
	void setInfo(int c,string m,float p) { code=c;name=m;price=p; }
	float getPrice() { return price; }
	void setPrice(float p) {price = p;}
	string getName() { return name; }
	int getCode() { return code; }
	
};
