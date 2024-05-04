#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random password
string generatePassword(int length) {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    string password = "";
    srand(time(nullptr));
    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

// Function to save the password to a file
void savePassword(const string& website, const string& username, const string& password) {
    ofstream file("passwords.txt", ios::app);
    if (file.is_open()) {
        file << "Website: " << website << ", Username: " << username << ", Password: " << password << endl;
        file.close();
        cout << "Password saved successfully!" << endl;
    } else {
        cout << "Unable to open file!" << endl;
    }
}

int main() {
    string website, username;
    int passwordLength;

    cout << "Welcome to Password Manager!" << endl;
    cout << "Enter the website: ";
    getline(cin, website);
    cout << "Enter the username: ";
    getline(cin, username);
    cout << "Enter the desired length of password: ";
    cin >> passwordLength;

    string password = generatePassword(passwordLength);
    cout << "Generated Password: " << password << endl;

    savePassword(website, username, password);

    return 0;
}
