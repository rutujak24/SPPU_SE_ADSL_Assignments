//============================================================================
// Name        : assisgnment6.cpp
// Author      : kandlagunta rohith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
#define size (26)
class Entry
{
	string word, meaning;

public:
	Entry(string w, string m)
	{
		word = w;
		meaning = m;
	}
	Entry()
	{
		word = "";
		meaning = "";
	}
	friend class Hashtable;
};
class Hashtable
{
	Entry *table;

public:
	Hashtable()
	{
		table = new Entry[size];
	}
	void create(bool);
	void insert_WOR(); // without replacement
	void insert_WR();  //with replacement
	int hashindex(string);
	void search();
	void printtable();
	void modify();
	void delete_WOR();
	void delete_WR();
};
void Hashtable ::delete_WR()
{
	cout << "ENTER THE KEY TO DELETE :";
	string s;
	cin >> s;
	int index = hashindex(s);
	int i = index;
	while (table[i].word != s && table[i].word.empty() == 0)
	{
		i++;
		if (i == size)
			i = 0;
	}
	if (table[i].word.empty())
	{
		cout << "2.KEY NOT FOUND!" << endl;
		return;
	}
	if (table[index].word == s)
	{
		table[index].word = "";
		table[index].meaning = "";
		int j;
		if (i == size - 1)
			j = 0;
		else
			j = i + 1;
		while (hashindex(table[j].word) == i && table[j].word.empty() == 0)
		{
			j++;
			if (j == size - 1)
				j = 0;
			else
				j++;
		}
		if (hashindex(table[j].word) == i)
		{
			table[i].word = table[j].word;
			table[i].meaning = table[j].meaning;
			table[j].word = "";
			table[j].meaning = "";
			i = j;
		}
		if (i == size - 1)
			j = 0;
		else
			j = i + 1;
		while (table[j].word.empty() == 0)
		{
			if (hashindex(table[j].word) <= i)
			{
				table[i].word = table[j].word;
				table[i].meaning = table[j].meaning;
				table[j].word = "";
				table[j].meaning = "";
				i = j;
			}
			if (j == size - 1)
				j = 0;
			else
				j++;
		}
	}
	cout << "WORD DELETED!" << endl;
}
void Hashtable ::delete_WOR()
{
	cout << "ENTER THE KEY TO DELETE :";
	string s;
	cin >> s;
	int index = hashindex(s);
	int i = index;
	while (table[i].word != s && table[i].word.empty() == 0)
	{
		i++;
		if (i == size)
			i = 0;
	}
	if (table[i].word.empty())
	{
		cout << "2.KEY NOT FOUND!" << endl;
		return;
	}
	if (table[index].word == s)
	{
		table[index].word = "";
		table[index].meaning = "";
		int j;
		if (i == size - 1)
			j = 0;
		else
			j = i + 1;
		while (table[j].word.empty() == 0)
		{
			if (hashindex(table[j].word) <= i)
			{
				table[i].word = table[j].word;
				table[i].meaning = table[j].meaning;
				table[j].word = "";
				table[j].meaning = "";
				i = j;
			}
			if (j == size - 1)
				j = 0;
			else
				j++;
		}
	}
	cout << "WORD DELETED!" << endl;
}
void Hashtable ::modify()
{
	string s;
	cout << "ENTER KEY TO REPLACE : ";
	cin >> s;
	int index = hashindex(s);
	int i = index;
	while (table[i].word != s && table[i].word.empty() == 0)
	{
		i++;
	}
	cout << "NUMBER OF COMPARISIONS :" << abs(i - index) << endl;
	if (table[i].word == s)
	{
		cout << "ENTER THE MEANING FOR THE  WORD " << s << " :";
		cin >> s;
		table[i].meaning = s;
		cout << "WORD MODIFIED!" << endl;
		cout << table[i].word << " :" << table[i].meaning << endl;
	}
	else
		cout << "KEY NOT FOUND!" << endl;
}
void Hashtable ::create(bool b)
{
	int n;
	cout << "ENTER NUMBER OF ENTRIES :";
	cin >> n;
	while (n--)
	{
		if (b == 0)
			insert_WOR();
		else
			insert_WR();
	}
}
void Hashtable ::printtable()
{
	cout << left << setw(4) << "NO." << setw(10) << "KEY :" << setw(10) << "MEANING :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << i + 1 << setw(10) << left << table[i].word << setw(10) << table[i].meaning << endl;
	}
}
void Hashtable ::search()
{
	string s;
	cout << "ENTER KEY TO SEARCH : ";
	cin >> s;
	int index = hashindex(s);
	int i = index;
	while (table[i].word != s && table[i].word.empty() == 0)
	{
		i++;
	}
	cout << "NUMBER OF COMPARISIONS :" << abs(i - index) << endl;
	if (table[i].word == s)
		cout << "KEY :" << table[i].word << "    "
			 << "MEANING :" << table[i].meaning << endl;
	else
		cout << "KEY NOT FOUND!" << endl;
}
void Hashtable ::insert_WOR()
{
	string word, meaning;
	cout << "ENTER WORD :";
	cin >> word;
	cout << "ENTER MEANING :";
	cin >> meaning;
	Entry tmp(word, meaning);
	int index = hashindex(word);
	int i = index;
	while (table[index].word.empty() == 0)
	{
		index++;
		if (index == i)
		{
			cout << "OVERFLOW!" << endl;
			return;
		}
		if (index == size)
			index = 0;
	}
	table[index] = tmp;
	cout << "NUMBER OF COMPARISIONS :" << abs(i - index) << "\n";
}
int Hashtable ::hashindex(string s)
{
	int index = 0;
	for (int i = 0; i < s.length(); i++)
		index += (i + 1) * s[i];
	return (index % size);
}
void Hashtable ::insert_WR()
{
	string word, meaning;
	cout << "ENTER WORD :";
	cin >> word;
	cout << "ENTER MEANING :";
	cin >> meaning;
	Entry tmp(word, meaning);
	int index = hashindex(word);
	int i = index;
	if (table[index].word.empty())
	{
		table[index] = tmp;
	}
	else
	{
		Entry t = table[index];
		if (hashindex(t.word) == index)
		{
			while (table[index].word.empty() == 0)
			{
				index++;
				if (index == i)
				{
					cout << "OVERFLOW!" << endl;
					return;
				}
				if (index == size)
					index = 0;
			}
			table[index] = tmp;
		}
		else
		{
			while (table[index].word.empty() == 0)
			{
				index++;
				if (index == i)
				{
					cout << "OVERFLOW!" << endl;
					return;
				}
				if (index == size)
					index = 0;
			}
			table[index] = t;
			table[i] = tmp;
		}
	}
}

int main()
{
	bool tmp = 1;
	while (tmp)
	{
		Hashtable table;
		cout << "ENTER CHOICE:\n";
		cout << "1. WITHOUT REPLACEMENT \n";
		cout << "2. WITH REPLACMENT \n";
		cout << "3. EXIT \n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			bool t1 = 1;
			while (t1)
			{
				cout << "WITHOUT REPLACEMENT: \n";
				cout << "1.CREATE\n";
				cout << "2.SEARCH \n";
				cout << "3.INSERT \n";
				cout << "4.DELETE \n";
				cout << "5.MODIFY \n";
				cout << "6.EXIT\n";
				int ch;
				cin >> ch;
				switch (ch)
				{
				case 1:
					table.create(0);
					table.printtable();
					break;
				case 2:
					table.search();
					break;
				case 3:
					table.insert_WOR();
					table.printtable();
					break;
				case 4:
					table.delete_WOR();
					table.printtable();
					break;
				case 5:
					table.modify();
					table.printtable();
					break;
				case 6:
					t1 = 0;
					break;
				default:
					cout << "INVALID!" << endl;
				}
			}
		}
		break;
		case 2:
		{
			bool t1 = 1;
			while (t1)
			{
				cout << "WITH REPLACEMENT: \n";
				cout << "1.CREATE\n";
				cout << "2.SEARCH \n";
				cout << "3.INSERT \n";
				cout << "4.DELETE \n";
				cout << "5.MODIFY \n";
				cout << "6.EXIT\n";
				int ch;
				cin >> ch;
				switch (ch)
				{
				case 1:
					table.create(1);
					table.printtable();
					break;
				case 2:
					table.search();
					break;
				case 3:
					table.insert_WR();
					table.printtable();
					break;
				case 4:
					table.delete_WR();
					table.printtable();
					break;
				case 5:
					table.modify();
					table.printtable();
					break;
				case 6:
					t1 = 0;
					break;
				default:
					cout << "INVALID!" << endl;
				}
			}
		}
		break;
		case 3:
			tmp = 0;
			break;
		default:
			cout << "INVALID CHOICE!" << endl;
		}
	}
	_getch();
	return 0;
}
