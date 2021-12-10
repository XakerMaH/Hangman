#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int main()
{
	//варианты слов
	vector<string>words;
	words.push_back("death");
	words.push_back("luck");
	words.push_back("world");
	words.push_back("gallow");

	//приветствие
	cout << "Welcom to ***Hangman*** !" << endl;
	cout << "Try to guess the word" << endl;
	cout << "Else you will be hanged\n" << endl;

	bool again = true;
	string againT;
	while (again)
	{
		//переменные
		string letter2;
		char letter;
		int errors = 0;

		//выбор слова
		srand(static_cast<unsigned int>(time(0)));
		int wordN = rand() % 4;
		string word = words[wordN];

		//пропуски
		vector<string>wordE(word.size(), "-");
		vector<string>::const_iterator iter;
		string::iterator changer;

		//первая игра
		while (again)
		{
			bool error;
			bool win = true;
			bool check = true;

			for (iter = wordE.begin(); iter != wordE.end(); ++iter)
			{
				cout << * iter;
			}

			cout << "\n\nEnter a letter: ";
			cin >> letter;
			letter2 = letter;

			//проверка буквы
			int i = 0;
			for (changer = word.begin(); changer != word.end(); ++changer)
			{
				if (letter == *changer and letter != '-')
				{
					error = false;
					wordE[i] = letter;
					word[i] = '-';
					break;
				}
				else
				{
					error = true;
				}

				++i;
			}
			//ошибки
			if (error)
			{
				cout << "\nwrong\n\n";
				errors += 1;
			}
			if (errors == 8)
			{
				cout << "\n\nYou were hanged";
				again = false;
				break;
			}

			//проверка на победу
			for (iter = wordE.begin(); iter != wordE.end(); ++iter)
			{
				if (*iter == "-")
				{
					win = false;
					break;
				}
			}
			if (win)
			{
				cout << "\n\nYou win!\n\n";
				while (again)
				{
					cout << "Again?(y/n): ";
					cin >> againT;
					if (againT == "y")
					{
						cout << "\nOk\n\n";
						break;
					}
					else if (againT == "n")
					{
						cout << "\nOk bye";
						again = false;
					}
				}
				break;
			}
		}
	};
	return 0;
}