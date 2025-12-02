#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Welcome to Hangman!" << endl;
	string secretWord = "computer";
	vector<char> guessed(secretWord.length(), '_');
	return 0;
}
