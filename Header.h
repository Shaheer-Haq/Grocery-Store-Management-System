#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Catalog {
protected:
	string prod_category[100];
	string prod_subCategory[50];
	string prod_Name;

public:
	Catalog()
	{
		*prod_category = '0';
		*prod_subCategory = '0';
		prod_Name;
	}
	void addproduct()
	{
		int C = 0;
		cout << "----------------- This Is The Product Catalog -------------------";
		cout << endl;
		cout << "Choose the category in which you want to add the product";
		cout << "1. Food";
		cout << "2. Personal Hygiene";
		cout << "3. House Hold Cleaning";
		cout << "You Chose: ";
		cin >> C;
		if (C == 1)
		{
			cout << "Choose the Sub Category";
			cout << "1. Perishable Goods";
			cout << "2. Non-Perishable Goods";
			cout << "You Chose: ";
			cin >> C;
			cout << "Enter the Product Name";
			cin >> prod_Name;
		}
		if (C == 2)
		{
			cout << "Enter the Product Name";
			cin >> prod_Name;

		}
		if (C == 3)
		{
			cout << "Enter the Product Name";
			cin >> prod_Name;

		}

	}
	void products()
	{

	}

};

class User{
	int check;
	char recheck[20];

protected:
	char CNIC[20];
	char Password[50];
public:
	User()
	{
		check = 0;
		*recheck = '0';
		*CNIC = '0';
		*Password = '0';
	}
	bool createaccount()
	{
		cout << " Enter your CNIC Number: ";
		cin >> CNIC;

		check = 0;
		if (check == 0)
		{
			cout << "Enter Your Password: ";
			cin >> Password;
		}
		for (int x = 0; x < 9; x++)
		{
			if ((int)Password[x] > 64 && (int)Password[x] < 91)
			{
				check++;
			}
		}
		for (int x = 0; x < 9; x++)
		{
			if ((int)Password[x] > 96 && (int)Password[x] < 123)
			{
				check++;
			}
		}
		for (int x = 0; x < 9; x++)
		{
			if ((int)Password[x] > 47 && (int)Password[x] < 58)
			{
				check++;
			}
		}


		if (check == 9)
		{
			cout << "Enter your Password Again : ";
			cin >> recheck;
			if (*Password == *recheck)
			{
				cout << "Congrats! Account created. " << endl;
				return true;
			}
			else
			{
				cout << "Password Does not Match" << endl;
			}

		}
		else
		{
			cout << "Wrong Syntax" << endl;
			return false;
		}

		
	}
	char* getCNIC()      //Getter for CNIC
	{
		return CNIC;
	}
	char* getPassword() //Getter for Password
	{
		return Password;
	}
};



class manager : public User, public store
{
protected:
	string Location[10];
	string Name[10];

public:
	manager()
	{
		*Location = '0';
		*Name = '0';
	}
	void setName(char* n)
	{
		*Name = *n;
	}
	void setLocation(char* l)
	{
		*Location = *l;
	}
	bool login(char* a, char* m, char* c);
};

class customer : public User{
protected:
	char Name[10];
	char Gender[10];
	char Number[20];
	char address[50];

public:
	customer()
	{
		*Name = '0';
		*Gender = '0';
		*Number = '0';
		*address = '0';
	}
	void setname(char* x)
	{
		*Name = *x;
	}
	void setGender(char* x)
	{
		*Gender = *x;
	}
	void setnumber(char* x)
	{
		*Number = *x;
	}
	void setaddress(char* x)
	{
		*address = *x;
	}
	char* getaddress()
	{
		return address;
	}
	bool login(char* a, char* b, char* c);
	void display()
	{
		cout << "Name : " << Name << endl;
		cout << "CNIC : " << CNIC << endl;
		cout << "Password : " << Password << endl;
		cout << "Phone Number : " << Number << endl;
		cout << "Gender : " << Gender << endl;
		cout << "Address : " << address << endl;
	}
};

class Admin : public User, public Catalog
{
protected:
	string Username = "21i1657";
	string Password = "123456";

public:
	bool Credential_Check_Admin(string A, string B)
	{
		if (Username == A && Password == B)
		{
			cout << "============== Login Successful ==========";
			return true;
		}
		else
		{
			cout << "Invalid Username or Password";
			return false;
		}
	}
};



class inventory_Management
{
protected:
	char items[50];
	int prod_Price;
	int prod_Quantity;
	char measure[50];

public:
	inventory_Management()
	{
		*items = '0';
		*measure = '0';
		prod_Price = 0;
		prod_Quantity = 0;
	}
	void additem()
	{
		cout << "Enter the name of item you want to add in Inventory: ";
		cin >> items;
		cout << "Enter the quantity of items you want to add: ";
		cin >> prod_Quantity;
		cout << "Ente the measurement unit of the item you want to add: ";
		cin >> measure;
		cout << "Enter the price of item: ";
		cin >> prod_Price;
	}

	char* getitem()
	{
		return items;
	}
	int getprice()
	{
		return prod_Price;
	}
};
class store : public Catalog, public inventory_Management {
protected:
	string Location;

public:
	store()
	{
		Location = '0';
	}
	string createstore(string c)
	{
		string temp;
		string j = ".dat";
		temp = c + j;
		cout << temp << endl;
		Location = c;
		cout << "------------------------- A new store is created -------------------";
		return temp;
	}
	void eliminate_store()
	{
		Location = '0';
	}
};

class checkout {
protected:
	int amount;
	int delivery_charges;
	int total_bill;
	char number[25];

public:
	checkout()
	{
		amount = 0;
		delivery_charges = 0;
		total_bill = 0;
		*number = '0';
	}

};

class cart :public inventory_Management{
protected:
	char total_items[50];
	int quantity;
public:
	cart()
	{
		*total_items = '0';
		quantity = 0;
	}
	void fillcart(char* a, int b)
	{
		*total_items = *a;
		quantity = b;
	}
	void display_cart()
	{
		cout << total_items<< " "<< quantity;
	}
};



class store_Checkout_Simulation {
protected:
	string Cashier;

public:
	void Check_Idle_Cashier();
};



bool login(char* a, char* m, char* c)
{

	char check[20];                         //Function for checking LogIn Status
	char recheck[20];
	if (c == "a" || c == "A")
	{
		Admin temp;
		ifstream file1("admin.dat", ios::binary | ios::in);
		while (file1.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getCNIC() == a)
			{
				cout << "Login Successful" << endl;
				return true;
			}
			else
			{
				cout << "You have Entered wrong ID or Password" << endl;
				return false;
			}
		}
	}

	if (*c == 'b' || *c == 'B')
	{
		manager temp;
		*check = *(temp.getCNIC());
		*recheck = *(temp.getPassword());
		ifstream file1("manager.dat", ios::binary | ios::in);

		while (file1.read((char*)&temp, sizeof(temp)))
		{

			if (*check == *a)
			{
				cout << "Login Successful" << endl;
				return true;
			}
			else
			{
				cout << "You have Entered wrong ID or Password" << endl;
				return false;
			}
		}
		cin.ignore();
	}
	if (*c == 'c' || *c == 'C')
	{
		customer temp;
		ifstream file1("customer.dat", ios::binary | ios::in);
		while (file1.read((char*)&temp, sizeof(temp)))
		{
			*check = *(temp.getCNIC());
			*recheck = *(temp.getPassword());
			if (*check == *a && *recheck == *m)
			{
				cout << "Login Successful" << endl;
				*check = *(temp.getaddress());
				return true;
			}
			else
			{
				cout << "You have Entered wrong ID or Password" << endl;
				return false;
			}
		}
		cin.ignore();
	}


}