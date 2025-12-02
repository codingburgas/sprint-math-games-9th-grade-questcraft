#include <iostream>
#include <vector>
using namespace std;

void displayedWord(const vector<char>& guessed)
{
	for (char c : guessed)
	{
		cout << c << " ";
	}
	cout << endl;
}

int main()
{
    cout << "Welcome to Hangman!" << endl;
	string secretWord = "computer";
	vector<char> guessed(secretWord.length(), '_');

	int lives = 5;

	cout << "The secret word has " << secretWord.length() << " letters." << endl;
	displayedWord(guessed);

	while (lives > 0) 
	{
		char guess;
		count << "Enter your guess: ";
		cin >> guess;

		bool correct = false;
		for (int i = 0; i < secretWord.length(); ++i) 
		{
			if (secretWord[i] == guess)
		{
				guessed[i] = guess;
				correct = true;
		}
	}

	if (!correct) 
	{
		lives--;
		cout << "Wrong Guessed! Lives remain: " << lives << endl;
	}
	displayedWord(guessed);
	}
	return 0;
}

