#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

char guess;

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

	system("pause");
}

//Player's Guesses
void guesses()
{
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess);
}