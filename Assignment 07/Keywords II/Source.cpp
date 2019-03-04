#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;


int main()
{
	//Setup for the program
	const int MAX_WRONG = 8; //How many guesses you can get wrong

	vector<string> words;  //words to guess
	words.push_back("DOCUMENT");
	words.push_back("INFILTRATE");
	words.push_back("GOLDENEYE");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
		//words to guess
	int wrong = 0;
		//number of incorrect guesses
	string soFar(THE_WORD.size(), '-');
		//word guessed so far
	string used = "";
		//letters already guessed

	cout << "Welcome, Agent 626. We've been expecting you." << endl;
	cout << "The Training Course for Deciphering will now begin." << endl;


	//MAIN LOOPY LOOP
	if ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;
	}


	//TAKING PLAYER GUESSES
	char guess;
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess);
	
	if (used.find(guess) != string::npos)
	{
		cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}

	used += guess;

	if (THE_WORD.find(guess) != string::npos)
	{
		cout << "That's right! " << guess << " is in the word.\n";
			//update soFar to include the newly guessed letter
		for (int i = 0; i < THE_WORD.length(); ++i)
		{
			if (THE_WORD[i] == guess)
			{
				soFar[i] = guess;
			}
		}
	}


	//SHUT THE GAME DOWN
	if (wrong == MAX_WRONG)
	{
		cout << "\nLockdown initiated!!!" << endl;
		cout << "You've been caught, Agent. I expected better from you." << endl;
	}
	else
	{
		cout << "\nAccess granted.  Great work, Agent." << endl;
	}

	cout << "\nThe word was " << THE_WORD << endl;
	return 0;
	system("pause");
}