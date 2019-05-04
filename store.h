class Store
{
	string storeName;
	Item* item;
	unsigned int item_count;
public:
	
	void setStoreName(string n){
		
		storeName = n;
	}
	
	string getStoreName(){
		
		return storeName;
	}
	
	int getCount(){
		return item_count;
		
	}
	
	string getName(){
		
		return item->getName();
	}
	
	Store(){}
	Store(string n, Item* m): storeName(n), item(0), item_count(0)
	{
		if (m != 0)
		{
			item = new Item[1];
			item[0].setInfo(m->getCode(), m->getName(),m->getPrice());
			item_count++;
		}
	}
	friend ostream& operator<< (ostream& o, Store& s)
	{
		o<<"LEARZA's Store at "<<s.storeName<<endl;
		o<<endl;
		o << "-------------------------------------------------------------------" << endl;
		o <<left<<setw(3)<<"No"<<left<<setw(12)<< "|Item Code"<<left<<setw(40)<<"|Item Name"<<left<<setw(50)<<"|Item Price|" << endl;
		o << "-------------------------------------------------------------------" << endl;
		
		for (int x = 0; x < s.item_count; x++)
			o<<left<<setw(3)<<x+1<<s.item[x]<<endl;
		o << "-------------------------------------------------------------------" << endl;
		return o;
	}
	void addItem(Item* m)
	{
		if (item_count == 0)
		{
			item = new Item[1];
			item[0].setInfo(m->getCode(), m->getName(),m->getPrice());
			item_count++;
		}
		else
		{
			Item* temp = new Item[ item_count + 1 ];
			for (int x = 0; x < item_count; x++)
			{
				temp[x] = item[x];
			}
			temp[item_count].setInfo(m->getCode(), m->getName(),m->getPrice());
			delete [] item;
			item = temp;
			item_count++;
		}
	}
	
/*	Item& addItem2 (Item* m,int r){

			Item* temp =  new Item[getCount() + r];
			cout<<getCount();
			for (int x= 0;x<getCount();x++){
				temp[x] = m[x];
			}
			
			int code;
			string name;
			float price;
			int test = getCount();
			int test2 = r+getCount();
			for (int x = test ; x<test2; x++){
				cout<<"code: ";
				cin>>code;
				cout<<"name: ";
				cin>>name;
				cout<<"price: ";
				cin>>price;
				
				temp[x].setInfo(code,name,price);
				
				addItem(&temp[x]);
				
			}
			cout<<"sucsess2"<<endl;
			delete [] m;
			cout<<"sucsess3"<<endl;
			cout<<sizeof(m);
			cout<<sizeof(temp);
			m = temp;
			cout<<"sucsess4"<<endl;
			delete [] temp;
			return *m;
			cout<<"sucsess5"<<endl;
		
		
		
	}*/
	
	void editItem (int index){
		float price;
		index = index -1;
		
		cout<<"Input new price: ";
		cin>>price;
		item[index].setPrice(price);
		
	}
	void removeItem(int index)
	{
		if ((index < 1)||(index > item_count)) return;

		Item* temp = new Item[ item_count - 1 ];

		int j = 0;
		for(int i = 0; i < item_count; i++)
		{
			if (i != index - 1) //index NOT to be deleted ?
			{
				temp[j].setInfo(item[i].getCode(),item[i].getName(), item[i].getPrice());
				j++;
			}
		}

		delete [] item;
		item = temp;
		item_count--;
	}
};
