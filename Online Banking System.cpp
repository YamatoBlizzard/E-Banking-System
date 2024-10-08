#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//user input
int choice;
double amount;

//variable for profile
string name;
int day, month, year;
string icNumber;
string phone_num;
string e_mail;

//variable for login
string username;
string password;

//user bank account
double current_account = 500;

int main()
{
	ofstream outfile;
	outfile.open("profile.txt", ios::out); //User Personal information, username & password stored

	if (!outfile)
	{
		cout << "File could not be opened!";
		return -1;
	}

	ofstream deposit_receipt;
	deposit_receipt.open("deposit_receipt.txt", ios::out); //Deposit Receipt

	if (!deposit_receipt)
	{
		cout << "File could not be opened!";
		return -1;
	}

	ofstream withdrawal_receipt;
	withdrawal_receipt.open("withdrawal_receipt.txt", ios::out); //Withdrawal Receipt

	if (!withdrawal_receipt)
	{
		cout << "File could not be opened!";
		return -1;
	}

	ifstream infile;
	infile.open("profile.txt", ios::out);

	if (!infile)
	{
		cout << "File could not be opened!";
		return -1;
	}


	cout << "Welcome to our e-banking.\n";         //1st page display
	cout << "Press 1 to create an account.\n";
	cout << "Press 2 to exit the program.\n";
	cout << "========================================\n";
	cin >> choice;
	cout << "========================================\n";

	switch (choice) //Creating an account
	{
	case 1:
		cout << "Thank you for opening an account with us.\n";
		cout << "Please input your personal information.\n";
		cout << "E.g. John\n";
		cout << "Enter your name here: \n";
		cin >> name;
		cout << "E.g. day, month, year\n";
		cout << "Enter your date of birth here: ";
		cin >> day >> month >> year;
		cout << "E.g. 980628-14-0908\n";
		cout << "Enter your ic here: ";
		cin >> icNumber;
		cout << "E.g. 012-345-6789\n";
		cout << "Enter your phone number here: ";
		cin >> phone_num;
		cout << "E.g. youremail@gmail.com\n";
		cout << "Enter your e-mail here: ";
		cin >> e_mail;
		cout << "========================================\n";
		cout << "Is the above information correct?\n";
		cout << "Press 1 for yes\n";
		cout << "Press 2 for no\n";
		cout << "=======================================\n";
		cin >> choice;

		if (choice == 1) //If yes
		{
			cout << "==============================\n";
			cout << "Input your new username here: ";
			cin >> username;
			cout << "Input your password here: ";
			cin >> password;
			cout << "========================================\n";
			cout << "Is the above information correct?\n";
			cout << "Press 1 for yes\n";
			cout << "Press 2 for no\n";
			cout << "========================================\n";
			cin >> choice;
			if (choice == 1)
			{
				outfile << name << " \n"   //Stored info for profile
					<< day << "/" << month << "/" << year << "\n"
					<< icNumber << "\n"
					<< phone_num << "\n"
					<< e_mail << "\n" << endl;

				outfile << username << " //Username\n" << password << " //Password\n";
				cout << "=============================\n";
				cout << "       ACCOUNT CREATED       \n";
				cout << "=============================\n";
				break;
			}
			else (choice == 2);  //If no
			{
				cout << "=============================\n";
				return main();
			}
		}
		else (choice == 2);      // Return to 1st page
		{
			cout << "==================================\n";
			return main();
		}

	case 2: //Exiting the program
		cout << "Thank you for visiting.";
		return 0;

	default: //Wrong input
		cout << "Input does not exist.\n";
		return main();
	}

	bool acc = true;
	while (acc == true)
	{
		cout << "Welcom " << username << ", what would you like to do?\n";
		cout << "Your current account has: $" << current_account << endl;
		cout << "Press 1 to deposit\n";
		cout << "Press 2 to withdraw\n";
		cout << "Press 3 to view your profile\n";
		cout << "Press 4 to exit the program\n";
		cin >> choice;

		switch (choice)
		{
		case 1:     //User choice
			cout << "=========================================\n";
			cout << "Your current account has $" << current_account << endl;
			cout << "How much would you like to deposit?\n";
			cin >> amount;
			cout << "Press 1 if yes\n";
			cout << "Press 2 if no\n";
			cin >> choice;
			cout << "=========================================\n";

			if (choice == 1)
			{
				current_account = current_account + amount;
				cout << "Would you like a reciept?\n";
				cout << "Press 1 if yes\n";
				cout << "Press 2 if no\n";
				cout << "=============================\n";
				cin >> choice;

				if (choice == 1)
				{
					deposit_receipt << "$" << amount << " has been deposited in your account.";
					cout << "==========================================\n";
					cout << "YOUR RECIEPT HAS BEEN SENT TO YOUR E-MAIL \n";
					cout << "==========================================\n";
					cout << "$" << amount << " Has been deposited in your account.\n";
				}
				else (choice == 2);
				{
					cout << "===============================\n";
					break;
				}
			}
			else (choice == 2);
			{
				cout << "==============================\n";
				break;
			}

		case 2:       //User choice
			cout << "==========================================\n";
			cout << "your current accoun has $" << current_account << endl;
			cout << "How much would you like to withdraw?\n";
			cin >> amount;
			cout << "Press 1 if yes\n";
			cout << "Press 2 if no\n";
			cout << "==========================================\n";
			cin >> choice;

			if (amount > current_account)
			{
				cout << "This transaction is not possible.\n";
				break;
			}
			else if (choice == 1)
			{
				current_account = current_account - amount;
				cout << "Would you like a receipt?\n";
				cout << "Press 1 if yes\n";
				cout << "Press 2 if no\n";
				cin >> choice;

				if (choice == 1)
				{
					withdrawal_receipt << "$" << amount << " has been withdrawn in your account.";
					cout << "==========================================\n";
					cout << "YOUR RECIEPT HAS BEEN SENT TO YOUR E-MAIL \n";
					cout << "==========================================\n";
					cout << "$" << amount << " Has been withdrawn in your account.\n";
				}

				else (choice == 2);
				{
					cout << "==============================\n";
					break;
				}
			}
			else (choice == 2);
			{
				cout << "==============================\n";
				break;
			}

		case 3:
			cout << "\n==============================";
			cout << "\nThis is your profile";
			cout << "\n==============================";
			cout << "\nUsername: " << username;
			cout << "\nReal name: " << name;
			cout << "\nDate of birth: " << day << "/" << month << "/" << year;
			cout << "\nIc number: " << icNumber;
			cout << "\nPhone number: " << phone_num;
			cout << "\nE-mail: " << e_mail;
			cout << "\n==============================";
			cout << "\nPress any number to return to home page\n";
			cin >> choice;
			cout << "\n=================================\n";
			break;

		case 4:
			cout << "Thank you.";
			return 0;

		default:
			cout << "Invalid input\n";
			cout << "================================\n";
			break;
		}

	}

	deposit_receipt.close();
	withdrawal_receipt.close();
	outfile.close();
	infile.close();

	return 0;
}