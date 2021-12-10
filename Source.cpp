#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int main()
{
	//�������� ����
	vector<string>words;
	words.push_back("death");
	words.push_back("luck");
	words.push_back("world");
	words.push_back("gallow");

	//�����������
	cout << "Welcom to ***Hangman*** !" << endl;
	cout << "Try to guess the word" << endl;
	cout << "Else you will be hanged\n" << endl;

	bool again = true;
	string againT;
	while (again)
	{
		//����������
		string letter2;
		char letter;
		int errors = 0;

		//����� �����
		srand(static_cast<unsigned int>(time(0)));
		int wordN = rand() % 4;
		string word = words[wordN];

		//��������
		vector<string>wordE(word.size(), "-");
		vector<string>::const_iterator iter;
		string::iterator changer;

		//������ ����
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

			//�������� �����
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
			//������
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

			//�������� �� ������
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