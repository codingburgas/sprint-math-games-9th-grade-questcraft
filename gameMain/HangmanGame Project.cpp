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

bool wordIsGuessed(const vector<char>& guessed)
{
	for (char c : guessed)
	{
		if (c == '_')
			return false;
	}
	return true;
}

int main()
{
	cout << "=== Welcome to Hangman! ===" << endl;
	cout << "1. Start Game" << endl;
	cout << "2. Credits" << endl;
	cout << "Choose an option: " << endl;

	int choice;
	cin >> choice;
	if (choice == 2) {
		cout << "Credits:" << endl;
		cout << "Created and Deisgned by QuestCraft Studios" << endl;
	}


	if (choice == 1) {
  	  cout << "Welcome to Hangman!" << endl;
		string secretWord = "computer";
		vector<char> guessed(secretWord.length(), '_');

		int lives = 5;

		cout << "The secret word has " << secretWord.length() << " letters." << endl;
		displayedWord(guessed);

		while (lives > 0) 
		{
			char guess;
			cout << "Enter your guess: ";
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
		
			if (wordIsGuessed(guessed))
			{
				cout << "Congratulations! You've guessed the word: " << secretWord << endl;
				break;
			}
		}
			
			if (!wordIsGuessed(guessed))
			{
				cout << "Game Over! The secret word was: " << secretWord << endl;
			}
	}
	
	return 0;
}



