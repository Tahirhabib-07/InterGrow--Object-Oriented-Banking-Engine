#include <iostream>

#include <fstream>

#include <vector>

#include <string>

using namespace std;

class Customer
{

private:
		
string id;

string name;

string pno;

string email;

string addr;

string searchID;

int choice;
		
public:
			
void profile()

{
				
do

{

cout<<"\n-----MENU-------\n"<<endl;

cout<<"1. Create Profile "<<endl;
		    		
cout<<"2. Update Profile "<<endl;

cout<<"3. Dicplay Profile "<<endl;

cout<<"4. Exit "<<endl;

cout<<"Enter Your choice : ";

cin>>choice;
     				
if(choice==1)
     				
{
		
string filename = id + ".txt";
						
cout<<"Enter your Name: ";
					 	
cin.ignore();
        				
getline(cin,name);
		        		
cout<<"Enter your ID: ";
				        
getline(cin,id);
        				
cout<<"Enter Your Phone NO. : ";
		        		
getline(cin,pno);
        				
cout<<"Enter your Email: ";
		        		
getline(cin,email);
		        	
cout<<"Enter your Address: ";
		        		
getline(cin,addr);
		        		
ofstream file(filename.c_str());
		        		
file<<name<<endl;
		        		
file<<id<<endl;
		        		
file<<pno<<endl;
		        		
file<<email<<endl;
		        		
file<<addr<<endl;
		        		
file.close();
		        		
cout<<"Profile Saved Successfully! "<<endl;
		        		
}
					 
else if(choice==2)
					
{
					 	
cout<<"Enter Customer ID to Update: ";
					 	
cin.ignore();
					 	
getline(cin,searchID);
					 	
if(id != searchID)
						 
{
						 	
cout<<"Customer Record Not Found! "<<endl;
						 	
}
						 
else

{
						 	
int updatechoice;
						 	
cout<<"Customer Found! "<<endl;

cout<<" 1. Update Name"<<endl;
						 	
cout<<" 2. Update Email"<<endl;
						 	
cout<<" 3. Update Phone No."<<endl;

cout<<" 4. Update Adderess"<<endl;
						 	
cin>>updatechoice;
						 	
cin.ignore();
						 	
if(updatechoice == 1)
							 
{
							 	
string newName;

cout<<"Enter New Name:";
							 	
name = newName;
getline(cin,name):
							 	
}
							 
else if(updatechoice == 2)
							 
{
							 	
string newEmail;
							 	
cout<<"Enter New Email:";
							    
email = newEmail;
							 	
}
							 
else if(updatechoice == 3)
							
{
							 	
string newPhoneNo;

cout<<"Enter New Phone N0.: ";
							 	
pno = newPhoneNo;
							 	
}
							 
else if(updatechoice == 4)
							 
{
							 	
string newadderess;
							 	
cout<<"Enter New Address: ";
							 	
addr = newadderess;
							 	
}
							 
else

{
							 	
cout<<"Invalid update option!"<<endl;
							 	
}
							 
cout<<"Profile Upadate Successfully!"<<endl;

}
						 
}
					 
else if(choice==3)
{
					 	
string filename = searchID + ".txt";
					 	
cout<<"Enter Customer ID:";
					 	
cin.ignore();
					 	
getline(cin,searchID);
					 	
ifstream file(filename.c_str());
					 	
getline(file,name);
					 	
getline(file,id);
					
getline(file,pno);
					 	
getline(file,email);
					 	
getline(file,addr);
					 	
cout<<"\n-----Customer Profile-------\n";
					 	
cout<<"Name: "<<name<<endl;
					 	
cout<<"ID: "<<id<<endl;
					 	
cout<<"Phone NO. : "<<pno<<endl;
					 	
cout<<"Email: "<<email<<endl;
					 	
cout<<"Address: "<<addr<<endl;
					 	
file.close();
					 	
}
					 
else if(choice == 4)

{
					 	
cout<<"\n-----THANKS-----\n"<<endl;
					 	
}
					 
else

{
					 	
cout<<"Invalid Choice ! "<<endl;
					 	
break;
					 	
}
					 
}
				
while(choice != 4);
				
}

};

class Account

{

protected:

int accountNo;

double balance;

public:

void setData(int no, double bal)

{

accountNo = no;

balance = bal;

}

virtual void updateAccount() = 0;

virtual ~Account()

{
	
}

void deposit(double amount)

{

balance = balance + amount;

savetransaction("Deposit",amount);

cout << "Amount deposited successfully.\n";

}

void withdraw(double amount)

{

if (amount <= balance)

{

balance = balance - amount;

savetransaction("Withdraw",amount);

cout << "Amount withdrawn successfully.\n";

}

else

{

cout << "Insufficient balance!\n";

}

}

void showBalance()

{

cout << "Account Number: " << accountNo << endl;

cout << "Current Balance: " << balance << endl;

}

void savetransaction(string type , double amount)

{
			
ofstream file("history.txt",ios::app);
			
file<<type<<": "<<amount<<" Current balance: "<<balance<<endl;
			
file.close();
			
}

};

class SavingsAccount : public Account

{

public:

void updateAccount()

{

double interest;

cout << "Enter interest percentage: ";

cin >> interest;

balance = balance + (balance * interest / 100);

savetransaction("Interest Added",balance*interest/100);

cout << "Interest added successfully.\n";

}

};

class CurrentAccount : public Account

{

public:

void updateAccount()

{

double fee;

cout << "Enter transaction fee: ";

cin >> fee;

if (fee <= balance)

{

balance = balance - fee;

savetransaction("Trabsaction FEE",fee);

cout << "Transaction fee deducted.\n";

}

else

{

cout << "Not enough balance for fee deduction.\n";

}

}

};

int main()

{

int choice, type,select;

int accNo;

double balance, amount;

Account *acc;

Customer cu;

SavingsAccount s;

CurrentAccount c;

cout<<"\n========: Banking Engine :=======\n"<<endl;

cout<<" 1. Customer profile"<<endl;

cout<<" 2. Log In"<<endl;

cout<<" 3. Exit"<<endl;

cout<<"Enter your choice:";

cin>>select;

if(select == 1)

{

cu.profile();

}

else if(select == 2)

{

cout << "1. Savings Account\n";

cout << "2. Current Account\n";

cout << "Choose account type: ";

cin >> type;

cout << "Enter Account Number: ";

cin >> accNo;

cout << "Enter Initial Balance: ";

cin >> balance;

if (type == 1)

{

acc = &s;

}

else

{

acc = &c;

}

acc->setData(accNo, balance);

do

{

cout << "\n===== BANK MENU =====\n";

cout << "1. Deposit\n";

cout << "2. Withdraw\n";

cout << "3. Show Balance\n";

cout << "4. Apply Interest/Fee\n";

cout << "5. Transactional History\n";

cout << "6. Exit\n";

cout << "Enter choice: ";

cin >> choice;

switch (choice)

{

case 1:

cout << "Enter amount: ";

cin >> amount;

acc->deposit(amount);

break;

case 2:

cout << "Enter amount: ";

cin >> amount;

acc->withdraw(amount);

break;

case 3:

acc->showBalance();

break;

case 4:

acc->updateAccount();

break;

case 5:

{

ifstream file("history.txt");

string line;

cout<<"\n----Transaction History-----\n"<<endl;
							
while(getline(file,line))

{

cout<<line<<endl;

}
							
file.close();
	
break;

}

case 6:

cout << "Thank you!\n";

break;

default:

cout << "Invalid choice!\n";

}

} while (choice != 6);

}

else 

{

cout<<"n\---Thanks For Using----\n"<<endl;

}

return 0;

}