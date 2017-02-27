//
// JRV_RegexStudy.cpp by James R. Vaughan
// This program uses regular expressions to determine what format the input is in
// 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string input;

	regex digit("[[:digit:]]");
	regex number("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
	regex integer("(\\+|-)?[[:digit:]]+");
	regex floating("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))");
	regex mmddyyyy("[0-9]{1,2}(\/|-|.)[0-9]{1,2}(\/|-|.)[0-9]{4}"); // MM/DD/YYYY & MM-DD-YYYY & MM.DD.YYYY
	regex yyyymmdd("[0-9]{4}(\/|-|.)[0-9]{1,2}(\/|-|.)[0-9]{1,2}"); // YYYY/MM/DD & YYYY-MM-DD & YYYY.MM.DD
	regex mmddyy("[0-9]{1,2}(\/|-|.)[0-9]{1,2}(\/|-|.)[0-9]{2}"); // MM/DD/YY & MM-DD-YY & MM.DD.YY
	regex yymmdd("[0-9]{2}(\/|-|.)[0-9]{1,2}(\/|-|.)[0-9]{1,2}"); // YY/MM/DD & YY-MM-DD & YY.MM.DD
	regex mmdd("[0-9]{1,2}(\/|-|.)[0-9]{1,2}"); // MM/DD & MM-DD & MM.DD
	regex ddmm("[0-9]{1,2}(\/|-|.)[0-9]{1,2}"); // DD/MM & DD-MM & DD.MM
	regex mmyy("[0-9]{1,2}(\/|-|.)[0-9]{2}"); // MM/YY & MM-YY & MM.YY
	regex yyyy("[0-9]{4}"); // YYYY

	string testString = "01/01/1990";
	smatch match;

	bool noMatch = true;

	while (true)
	{
		noMatch = true;
		cout << "Type a word, number, or date: ";
		cin >> input;
		if (!cin) break;

		if (input == "q")
			break;

		cout << "Your input matches: ";

		if (regex_match(input, digit))
		{
			cout << "Digit "; noMatch = false;
		}

		if (regex_match(input, number))
		{
			cout << "Number "; noMatch = false;
		}

		if (regex_match(input, integer))
		{
			cout << "Integer "; noMatch = false;
		}

		if (regex_match(input, floating))
		{
			cout << "Floating "; noMatch = false;
		}

		if (regex_match(input, mmddyyyy))
		{
			cout << "Date(MMDDYYYY) "; noMatch = false;
		}

		if (regex_match(input, yyyymmdd))
		{
			cout << "Date(YYYYMMDD) "; noMatch = false;
		}

		if (regex_match(input, yymmdd))
		{
			cout << "Date(YYMMDD) "; noMatch = false;
		}

		if (regex_match(input, mmddyy))
		{
			cout << "Date(MMDDYY) "; noMatch = false;
		}

		if (regex_match(input, mmdd))
		{
			cout << "Date(MMDD) "; noMatch = false;
		}

		if (regex_match(input, ddmm))
		{
			cout << "Date(DDMM) "; noMatch = false;
		}

		if (regex_match(input, mmyy))
		{
			cout << "Date(MMYY) "; noMatch = false;
		}

		if (regex_match(input, yyyy))
		{
			cout << "Date(YYYY) "; noMatch = false;
		}

		if (noMatch)
		{
			cout << "No match";
		}

		cout << endl << endl;

	}


	return 0;
}

