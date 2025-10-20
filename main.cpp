#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu ();
void checkBalance(double balance);
void depositMoney(double &balance);
void withdrawMoney(double &balance);
bool validateAmount(double amount);


int main (){

     double balance = 0.0;
    int choice;

     do {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please enter 1–4: ";
            cin >> choice;
        }

         switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                depositMoney(balance);
                break;
            case 3:
                withdrawMoney(balance);
                break;
            case 4:
                cout << "Exiting... Thank you for using our service!\n";
                break;
        }

        cout << endl;

    } while (choice != 4);

    return 0;

}

void displayMenu() {
    cout << "\n====== Banking Menu ======\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "=================================\n";
}

void checkBalance(double balance) {
    cout << fixed << setprecision(2);
    cout << "Your current balance is: $" << balance << endl;
}

void depositMoney(double &balance) {
    double amount;
    cout << "Enter amount to deposit: $";
    cin >> amount;

    if (!validateAmount(amount)) {
        cout << "Invalid deposit amount. Must be positive.\n";
        return;
    }

    balance += amount;
    cout << "Successfully deposited $" << amount << ".\n";
    checkBalance(balance);
}

void withdrawMoney(double &balance) {
    double amount;
    cout << "Enter amount to withdraw: $";
    cin >> amount;

    if (!validateAmount(amount)) {
        cout << "Invalid withdrawal amount. Must be positive.\n";
        return;
    }

    if (amount > balance) {
        cout << "Insufficient funds! Withdrawal canceled.\n";
        return;
    }

    balance -= amount;
    cout << "Successfully withdrew $" << amount << ".\n";
    checkBalance(balance);
}

bool validateAmount(double amount) {
    return (amount > 0);
}