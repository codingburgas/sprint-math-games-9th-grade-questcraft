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

		int difficulty;
		int lives;
		while (true) {
			cout << "Choose difficulty level:" << endl;
			cout << "1. Easy (infinite lives)" << endl;
			cout << "2. Medium (5 lives)" << endl;
			cout << "3. Hard (3 lives)" << endl;
			cout << "Enter choice: ";
			cin >> difficulty;

			if (difficulty == 1) {
				lives = -1;
				break;
			}
			else if (difficulty == 2) {
				lives = 5;
				break;
			}
			else if (difficulty == 3) {
				lives = 3;
				break;
			}
			else {
				cout << "Invalid level! Please choose again." << endl;
			}
		}
		vector <string> words = { "computer", "keyboard","mouse","monitor","printer" };
		int wordChoice;

		while (true) {
			cout << "Choose a word by number (1 - " << words.size() << "): ";
			cin >> wordChoice;
				if (wordChoice >= 1 && wordChoice <= words.size()) {
					break;
				}
				else {
					cout << "Invalid choice! Please enter a number between 1 and " << words.size() << "." << endl;
				}
			}
			string secretWord = words[wordChoice - 1];
			vector<char> guessed(secretWord.length(), '_');


			cout << "The secret word has " << secretWord.length() << " letters." << endl;
			displayedWord(guessed);

			while (lives != 0)
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
					if (lives == -1) {
						cout << "Wrong Guess! Lives remain: infinite lives" << endl;
					}
					else
					{
						lives--;
						cout << "Wrong Guess! Lives remain: " << lives << endl;
					}
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




