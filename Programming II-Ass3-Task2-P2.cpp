/*
 * Author: Mostafa Omar Mahmoud, 20170292, G16
 * Purpose: Reverse a range or a spelling in a string
 * Date: Nov. 1st 2018
 * Version: 1.0
 */
#include <iostream>
#include <cstring>
using namespace std;


void reverseRange(char word[], int st, int en);
void reverseFullWord(char word[]);
void swapChars(char &a, char &b);

int main() {
	const int MAX_LEN = 1000;

	char word[MAX_LEN];
	cout << "Enter word: ";
	cin >> word;

	cout << "Do you want to reverse a range or the full word(0/1): ";
	int choice;
	cin >> choice;

	switch(choice)
	{
	case 0:
		int st, en;
		cout << "Enter start index you want to reverse (1-based): ";
		cin >> st;
		cout << "Enter end index you want to reverse (1-based) : ";
		cin >> en;
		reverseRange(word, st - 1, en - 1); // Decrementing 1 because input is 1-based
		cout << "Reversed word: " << word;
		break;
	case 1:
		reverseFullWord(word);
		cout << "Reversed word: " << word;
		break;
	default:
		cout << "Invalid input. Reverse failed\n";
	}

	return 0;
}

void swapChars(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void reverseRange(char word[], int st, int en)
{
	if (st >= en)
		return;
	swapChars(word[st], word[en]);
	reverseRange(word, st+1, en-1);
}

void reverseFullWord(char word[])
{
	reverseRange(word, 0, strlen(word) - 1);
}
