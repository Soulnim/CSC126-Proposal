#include <iostream>
#include <string.h>
#include <conio.h> // cls
#include <unistd.h> // sleep
using namespace std;

const string username[99] = {"Luqman", "Syafiq", "Ian"}; // List nama mahasiswa UiTM Raub
const string password[99] = {"luqman123", "syafiqsem35", "ian123456"}; // List password
string cart[99] = {}; // item in cart
string purchased[99] = {}; // purchased history
const string item[99] = {"Biskut", "Maggi", "Air"}; // items on sale
const float price[99] = {3.50, 5.00, 2.00}; // item's price
const string info[99] = {"Weight = 2.3kg, Flavor = Chocolate", "Weight = 5kg, Flavor = Kari",
					"Weight = 0.5kg, Flavor = None"}; // item's spec
float tekunPay[99] = {100, 30.5, 55.6}; // baki duit dalam tekunPay dorang

void menu(string name) {
	cout << "--------------------" << endl;
	cout << " Hello " << name << "." << endl;
	cout << " Welcome to Tekun Online!" << endl;
	cout << "--------------------" << endl;
	cout << " 1. Shop Now!" << endl;
	cout << " 2. My Cart" << endl;
	cout << " 3. My Purchase" << endl;
	cout << " 4. Profile" << endl;
	cout << " 5. Exit" << endl;
	cout << "--------------------" << endl;
}

string login() {
	string name;
	string pass;
	int loginAttempt = 3;
	bool userPassed = false;
	
	while (userPassed == false && loginAttempt >= 1) {
		int nameCounter = 0;
		
		cout << "Enter your username : ";
		cin >> name;
		cout << "Enter your password : ";
		cin >> pass;
		
		while (username[nameCounter].length() != 0 && userPassed == false) {
			if (name == username[nameCounter] && pass == password[nameCounter]) {
				userPassed = true;
			} else {
				nameCounter += 1;
			}
		}
		if (userPassed == true) {
			system("cls");
			cout << "Logged in successfully!" << endl;
		} else {
			system("cls");
			cout << "Invalid username or password!" << endl;
			loginAttempt -= 1;
			cout << "Remaining login attempt : " << loginAttempt << endl;
		}
	}
	if (userPassed == true) {
		return name;
	} else {
		return "";
	}
}

void itemList() {
	for (int i = 0;i <= 2;i++) {
		cout << i + 1 << ". " << item[i] << endl;
		cout << "Price : RM " << price[i] << endl; 
	}
}

int main() {
	string name = login();
	
	if (name.length() != 0) {
		bool continueProgram = true;
		while (continueProgram == true) {
			int keyMenu;
			menu(name);
			cout << "Choose your command (1-5) : ";
			cin >> keyMenu;
			if (keyMenu == 1) { //----------------------------Shop Now!--------
				bool continueShop = true;
				while (continueShop == true) {
					system("cls");
					cout << "Shop Now!" << endl;
					itemList();
					cout << "---------------------" << endl;
					int keyShop;
					bool keyShopCorrect = false;
					while (keyShopCorrect == false) {
						cout << "Enter key ('0' for exit): ";
						cin >> keyShop;
						if (keyShop >= 0 && keyShop <= 3) {
							keyShopCorrect = true;
						} else {
							cout << "Invalid key!" << endl;
						}
					}
					if (keyShop == 0) {
						char keyExitCorrect = false;
						char keyExit;
						while (keyExitCorrect == false) {
							cout << "Are you sure? (y/n) : ";
							cin >> keyExit;
							if (keyExit == 'y') {
								keyExitCorrect = true;
								continueShop = false;
								system("cls");
							} else if (keyExit = 'n') {
								keyExitCorrect = true;
							} else {
								system("cls");
								cout << "Invalid key!" << endl;
							}
						}
					} else {
						system("cls");
						cout << " SELECTED : " << item[keyShop] << endl;
						cout << "PRICE : " << price[keyShop] << endl;
						cout << "Additional Information : " << info[keyShop] << endl;
						cout << "Add to cart? (y/n) : ";
						char addToCart;
						cin >> addToCart;
						if (addToCart == 'y') {
							int cartCounter = 0;
							bool filled = false;
							while (filled == false) {
								if (cart[cartCounter].length() == 0) {
									cart[cartCounter] = item[keyShop];
									filled = true;
									cout << "Added to cart!" << endl;
									cout << "Cart counter : " << cartCounter << endl;
									sleep(1);
								} else {
									cartCounter += 1;
								}
							}
						}
					}
				}
			} else if (keyMenu == 2) { //---------------------My Purchase-----
				bool continueCart = true;
				while (continueCart == true) {
					system("cls");
					cout << "My Cart" << endl;
					int counter = 0;
					while (cart[counter].length() != 0) {
						cout << counter + 1 << ". " << cart[counter] << endl;
						counter += 1;
					}
					float totalPrice = 0;
					int cartCounter = 0;
					while (cart[cartCounter].length() != 0) {
						for (int j = 0;j<=2;j++) {
							if (cart[cartCounter] == item[j]) {
								totalPrice += price[j];
							} 
						}
						cartCounter += 1;
					}
					float tekunPayBal;
					for (int i = 0; i <= 2;i++) {
						if (name == username[i]) {
							tekunPayBal = tekunPay[i];
						}
					}
					cout << "Total price is : RM " << totalPrice << endl;
					cout << "Your balance is : RM " << tekunPayBal << endl;
					cout << "Checkout now? (y/n) : ";
					char checkout;
					cin >> checkout;
					if (checkout == 'y') {
						system("cls");
						cout << "Total price is : RM " << totalPrice << endl;
						if (totalPrice > tekunPayBal) {
							cout << "Insufficient balance. Please top up.";
							sleep(1);
						} else {
							cout << "Checked out successfully!" << endl;
							cout << "You can view your purchase details on the Purchase section." << endl;
							cout << "Thank you!" << endl;
							cout << "Redirecting to main menu..." << endl;
							continueCart = false;
							sleep(4);
						}
					}
				}
			} else if (keyMenu == 3) { //---------------------Settings--------
				system("cls");
				cout << "My Purchase" << endl;
				char keyExitCorrect = false;
				char keyExit;
				while (keyExitCorrect == false) {
					cout << "Are you sure? (y/n) : ";
					cin >> keyExit;
					if (keyExit == 'y') {
						keyExitCorrect = true;
					} else {
						cout << "Invalid key!" << endl;
					}
				}
			} else if (keyMenu == 4) {
				system("cls");
				cout << "Profile" << endl;
				char keyExitCorrect = false;
				char keyExit;
				while (keyExitCorrect == false) {
					cout << "Are you sure? (y/n) : ";
					cin >> keyExit;
					if (keyExit == 'y') {
						keyExitCorrect = true;
					} else {
						cout << "Invalid key!" << endl;
					}
				}
			} else if (keyMenu == 5) { //---------------------Exit------------
				system("cls");
				char keyExitCorrect = false;
				char keyExit;
				while (keyExitCorrect == false) {
					cout << "Are you sure? (y/n) : ";
					cin >> keyExit;
					if (keyExit == 'y') {
						keyExitCorrect = true;
						continueProgram = false;
					} else {
						cout << "Invalid key!" << endl;
					}
				}
			} else {
				cout << "Invalid key!" << endl;
			}
		}
	}
	system("cls");
	cout << "See you next time!" << endl;
	return 0;
} // while first
		
	
