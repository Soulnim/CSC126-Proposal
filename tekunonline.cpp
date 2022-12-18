#include <iostream>
#include <string.h>
using namespace std;

string username[99] = {"Luqman", "Syafiq", "Ian"}; // List nama mahasiswa UiTM Raub
string password[99] = {"luqman123", "syafiqsem35", "ian123456"}; // List password

void menu(string name) {
	cout << "--------------------" << endl;
	cout << " Hello " << name << " ." << endl;
	cout << " Welcome to Tekun Online!" << endl;
	cout << "--------------------" << endl;
	cout << " 1. Shop Now!" << endl;
	cout << " 2. My Cart" << endl;
	cout << " 3. My Purchase" << endl;
	cout << " 4. Settings" << endl;
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
			cout << "Logged in successfully!" << endl;
		} else {
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


int main() {
	string name = login();
	
	if (name.length() != 0) {
		bool continueProgram = true;
		while (continueProgram == true) {
			int keyMenu;
			menu(name);
			cout << "Choose your command (1-5)";
			cin >> keyMenu;
			if (keyMenu == 1) { //----------------------------Shop Now!--------
				cout << "Shop Now!" << endl;
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
			} else if (keyMenu == 2) { //---------------------My Cart!--------
				cout << "My Cart" << endl;
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
			} else if (keyMenu == 3) { //---------------------My Purchase-----
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
			} else if (keyMenu == 4) { //---------------------Settings--------
				cout << "Settings" << endl;
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
		} // while first
	} // first if
	cout << "See you next time!" << endl;
	
}
