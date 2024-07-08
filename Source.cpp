#include<iostream>
#include<string>
#include<fstream>
#include"Header.h"
using namespace std;

int main()
{
	int count = 0;
	int city;
	int branch;
	int choice;
	char Choice[1];
	char A[50];
	char B[50];
	char C[50];
	char CNIC[50];
	char Password[20];
	char address[100];
	int price;
	int total;

	string filename;
	bool check;
	if (true)
	{
		cout << "==============Welcome================";
		cout << "==========To Grocery Store==============";
		cout << "Choose between the following";
		cout << "1. Admin";
		cout << "2. Manager";
		cout << "3. Customer";
		cout << "You Chose:  ";
		cin >> choice;
		if (choice == 1)
		{
			Admin member;

			system("");
			cout << "======================Welcome Sir================";
			cout << "==============Please Login into your Account=================";
			cout << "Username: ";
			cin >> A;
			cout << "Password: ";
			cin >> B;
			check = member.Credential_Check_Admin(A, B);
			if (check == 1)
			{
				cout << "========== Welcome Back Sir================";
				cout << "----------- Please Choose Between The Following --------";
				cout << endl;
				cout << endl;
				cout << "1. Stores";
				cout << "2. Accounts";
				cout << "3. Logout";
				cout << endl;
				cout << "You Chose: ";
				cin >> choice;

				if (choice == 1)
				{
					cout << "1. Create Store";
					cout << "2. Manage Product Catalog";

					cout << "Your Choice:";
					cin >> choice;

					if (choice == 1)
					{
						/*store a;
						cout << "Enter the location where you want to open a new store:";
						cin >> l;
						filename = a.createstore(l);
						cout << "Congrats.. A new Store is created";*/
					}
					if (choice == 2)
					{
						Catalog t;
						t.addproduct();

						ofstream myFile("Catalog.dat", ios::binary | ios::app);
						if (myFile.write((char*)&t, sizeof(t)))
						{
							cout << "Object Added";
						}
						else
							cout << "Object Addition Failed";
						myFile.close();
						choice = 0;
					}
				}
				if (choice == 2)
				{
					cout << "Make Manager of the New Store" << endl;
					manager m;
					check = m.createaccount();
					*A = '0';
					*B = '0';
					*C = '0';
					if (check == 1) 
					{
						cout << "Enter Your Location: ";
						cin >> A;
						cout << "Enter Your Name: ";
						cin >> B;
						m.setName(B);
						m.setLocation(A);
					}
					ofstream myFile("manager.dat", ios::binary | ios::app);
					if (myFile.write((char*)&m, sizeof(m)))
						cout << "Object Inserted";
					else
						cout << "Object insertion Failed";
					myFile.close();
				}
				if (choice == 3)
				{
					system("cls");
				}
			}
			

		}
		if (choice == 2)
		{
			cout << "1. Login";
			cout << "2. Signup";
			cout << "Your Choice: ";
			cin >> Choice;
			if (choice == 1)
			{
				cout << "Enter Your CNIC: ";
				cin >> A;
				cout << "Enter Your Password: ";
				cin >> B;
				cout << "1. Islamabad";
				cout << "2. Karachi";
				cout << "3. Lahore";
				cout << "Enter your Branch: ";
				cin >> branch;
				check = 1;
				if (check == 1)
				{
					cout << "1.Manage Inventory";
					cout << "2.Search Item";
					cout << "What is your choice? : ";
					cin >> choice;
					if (choice == 1)
					{
						cout << "1. Add Item";
						cout << "2. Remove Item";
						cout << " Your Choice: ";
						cin >> choice;
						if (choice == 1)
						{
							if (branch == 1)
							{
								store s;
								s.addproduct();
								ofstream myFile("Islamabad.dat", ios::binary | ios::app);
								if (myFile.write((char*)&s, sizeof(s)))
									cout << "Product Added";
								else
									cout << "Product Not Added";
								myFile.close();
							}
							if (branch == 2)
							{
								store s;
								s.addproduct();
								ofstream myFile("Karachi.dat", ios::binary | ios::app);
								if (myFile.write((char*)&s, sizeof(s)))
									cout << "Product Added";
								else
									cout << "Product Not Added";
								myFile.close();
							}
							if (branch == 3)
							{
								store s;
								s.addproduct();
								ofstream myFile("Karachi.dat", ios::binary | ios::app);
								if (myFile.write((char*)&s, sizeof(s)))
									cout << "Product Added";
								else
									cout << "Product Not Added";
								myFile.close();

							}
						}
						if (choice == 2)
						{
							if (branch == 1)
							{
								cout << "Enter the item that is to be deleted";
								cin >> A;
								store s;
								fstream myFile("Islamabad.dat", ios::in | ios::out | ios::binary);
								ofstream myFile_temporary("s.dat", ios::app | ios::binary);
								if (myFile.read((char*)&s, sizeof(s)))
								{
									if (s.getitem() != A)
									{
										myFile_temporary.write((char*)&s, sizeof(s));
									}
								}
								myFile.close();
								myFile_temporary.close();
								remove("Islamabad.dat");
								char i[] = "Islamabad.dat";
								rename("s.dat", i);


							}
							if (branch == 2)
							{
								cout << "Enter the item that is to be deleted";
								cin >> A;
								store s;
								fstream myFile("Karachi.dat", ios::in | ios::out | ios::binary);
								ofstream myFile_temporary("s.dat", ios::app | ios::binary);
								if (myFile.read((char*)&s, sizeof(s)))
								{
									if (s.getitem() != A)
									{
										myFile_temporary.write((char*)&s, sizeof(s));
									}
								}
								myFile.close();
								myFile_temporary.close();
								remove("Karachi.dat");
								char i[] = "Karachi.dat";
								rename("s.dat", i);
							}
							if (branch == 3)
							{
								cout << "Enter the item that is to be deleted";
								cin >> A;
								store s;
								fstream myFile("Lahore.dat", ios::in | ios::out | ios::binary);
								ofstream myFile_temporary("s.dat", ios::app | ios::binary);
								if (myFile.read((char*)&s, sizeof(s)))
								{
									if (s.getitem() != A)
									{
										myFile_temporary.write((char*)&s, sizeof(s));
									}
								}
								myFile.close();
								myFile_temporary.close();
								remove("Lahore.dat");
								char i[] = "Lahore.dat";
								rename("s.dat", i);
							}
						}
						
					}
					if (choice == 2)
					{
						cout << "Choose the branch in which you want to search for the item:";
						cout << "1. Islambad";
						cout << "2. Karachi";
						cout << "3.Lahore";
						cout << "Your Choice: ";
						cin >> branch;

						if (branch == 1)
						{
							cout << "Enter the item you want to search";
							cin >> A;
							inventory_Management t;
							ifstream myFile("Islamabad.dat", ios::binary);
							if (myFile.read((char*)&t, sizeof(t)))
							{
								if (t.getitem() == A)
								{
									cout << "Item Found";
								}
								else
									cout << "Item Not Found";
							}
							myFile.close();
						}
						if (branch == 2)
						{
							cout << "Enter the item you want to search";
							cin >> A;
							inventory_Management t;
							ifstream myFile("Karachi.dat", ios::binary);
							if (myFile.read((char*)&t, sizeof(t)))
							{
								if (t.getitem() == A)
								{
									cout << "Item Found";
								}
								else
									cout << "Item Not Found";
							}
							myFile.close();
						}
						if (branch == 3)
						{
							cout << "Enter the item you want to search";
							cin >> A;
							inventory_Management t;
							ifstream myFile("Lahore.dat", ios::binary);
							if (myFile.read((char*)&t, sizeof(t)))
							{
								if (t.getitem() == A)
								{
									cout << "Item Found";
								}
								else
									cout << "Item Not Found";
							}
							myFile.close();
						}
					}
					
					
				}
			}
		}
		if (choice == 3)
		{
			customer c;
			cout << "Choose between the following: ";
			cout << "1. Login";
			cout << "2. Signup";
			cout << "You Chose";
			cin >> choice;
			if (choice==1)
			{
				cout << "Enter your CNIC";
				cin >> CNIC;
				cout << "Enter Your Password";
				cin >> Password;
				check = login(CNIC, Password, Choice);
				if (check == 1)
				{
					cout << "1. Online Shopping";
					cout << "2. LogOut";
					cout << "You Chose: ";
					cin >> choice;
					if (choice == 1)
					{
						cout << "Enter the Store From Which You Want to buy:";
						cout << "1. Islamabad";
						cout << "2.Karachi";
						cout << "3.Lahore";
						cout << "Branch You Chose: ";
						cin >> branch;
						if (branch == 1)
						{
							char z[] = "Islamabad";
							inventory_Management i;
							cout << "1. Search For an item";
							cout << "2. Buy an item";
							cout << "You chose: ";
							cin >> choice;
							if (choice == 1)
							{
								cout << "Enter the item";
								cin >> A;
								inventory_Management t;
								ifstream myFile("Islamabad.dat", ios::binary);
								count = 0;
								if (myFile.read((char*)&t, sizeof(t)))
								{
									if (t.getitem() == A)
									{
										cout << "Item Found";
										cout << t.getprice();
										price = t.getprice();
										myFile.close();
										count = 1;
									}
								}
								if (count != 1)
								{
									cout << "Item Not Found";
									cout << "1. Search For an item";
									cout << "2. Buy an item";
									cout << "You chose: ";
									cin >> choice;
								}
							}
							if (choice == 2)
							{
								if (choice != 0)
								{
									cout << "Enter the item";
									cin >> A;
									cout << "Quantity of Items";
									cin >> count;
									cart c;
									c.fillcart(A, count);
									ofstream myFile("car.dat", ios::binary | ios::app);
									if (myFile.write((char*)&c, sizeof(c)))
										cout << "Item inserted in cart";
									else
										cout << "Item not inserted in cart";
									myFile.close();
									ifstream myFile1("cart.dat", ios::binary);
									if (myFile1.read((char*)&c, sizeof(c)))
									{
										c.display_cart();
									}
									myFile.close();
									total = total + (count * 50);
									cout << "1. Checkout";
									cout << "2.Continue";
									cout << "You chose :";
									cin >> choice;
									if (choice == 1)
									{
										cout << "Choose the method of payment";
										cout << "1. COD";
										cout << "2. Online";
										cout << "You chose: ";
										cin >> choice;
										if (choice == 1)
										{
											system("cls");
										}
										if (choice == 2)
										{
											system("cls");
										}
									}
								}
								
							}
						}
					}
					if (choice == 2)
					{
						system("cls");
					}
				}
			}
		}
	}
	return 0;
}