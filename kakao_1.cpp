#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

string solution(string new_id)
{
	//1
	for (int i = 0; i < new_id.length(); i++)
	{
		new_id[i] = tolower(new_id[i]);
	}

	//2
	for (int i = 0; i < new_id.length();)
	{
		if (new_id[i] >= 'a' && new_id[i] <= 'z' || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			i++;
			continue;
		}
		new_id.erase(i, 1);
	}

	//3
	for (int i = 0; i < new_id.length();)
	{
		if (new_id[i] == '.')
		{
			if (i + 1 <= new_id.length())
			{
				if (new_id[i + 1] == '.')
				{
					new_id.erase(i + 1, 1);
				}
				else
				{
					i++;
					continue;
				}
			}
		}
		else
			i++;
	}

	//4
	if (new_id.empty() == 0)
	{
		if (new_id[0] == '.')
			new_id.erase(0, 1);
	}
	if (new_id.length() > 0)
	{
		if (new_id.at(new_id.length() - 1) == '.')
			new_id.erase(new_id.length() - 1, 1);
	}

	//5
	if (new_id.empty() == 1)
		new_id.assign(1, 'a');

	//6
	if (new_id.length() >= 16)
	{
		new_id.assign(new_id, 0, 15);
	}
	if (new_id.length() > 0)
	{
		if (new_id.at(new_id.length() - 1) == '.')
			new_id.erase(new_id.length() - 1, 1);
	}

	//7
	if (new_id.length() <= 2 && new_id.length() > 0)
	{
		new_id.append(3 - new_id.length(), new_id.at(new_id.length() - 1));
	}

	return new_id;
}

int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
	cout << solution("z-+.^.") << endl;
	cout << solution("=.=") << endl;
	cout << solution("123_.def") << endl;
	cout << solution("abcdefghijklmn.p") << endl;
}