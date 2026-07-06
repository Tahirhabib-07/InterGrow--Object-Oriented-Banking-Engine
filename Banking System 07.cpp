#include <iostream>

using namespace std;

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

void deposit(double amount)

{

balance = balance + amount;

cout << "Amount deposited successfully.\n";

}

void withdraw(double amount)

{

if (amount <= balance)

{

balance = balance - amount;

cout << "Amount withdrawn successfully.\n";

}

else

{

cout << "Insufficient balance!\n";

}

}

virtual void updateAccount()

{

cout << "No special update.\n";

}

void showBalance()

{

cout << "Account Number: " << accountNo << endl;

cout << "Current Balance: " << balance << endl;

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

int choice, type;

int accNo;

double balance, amount;

Account *acc;

SavingsAccount s;

CurrentAccount c;

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

cout << "5. Exit\n";

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

cout << "Thank you!\n";

break;

default:

cout << "Invalid choice!\n";

}

} while (choice != 5);

return 0;

}
