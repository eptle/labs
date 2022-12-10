#include <iostream>
#include <fstream>
#include <string>

bool sameWordInArr(std::string str, std::string words[10000], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		if (words[i].compare(str) == 0)
			return true;
	}
	return false;
}

int minLen(std::string a, std::string b)
{
	if (a.length() >= b.length())
		return b.length();
	else return a.length();
}

int main()
{

	setlocale(LC_ALL, "Russian");

	std::string word, str;
	std::string words[10000]{};
	std::cin >> word;
	int n;
	std::cin >> n;

	std::ifstream in("input.txt", std::ios::in);
	std::ofstream out("output.txt", std::ios::out);

	int cnt = 0;
	while (!in.eof()) 
	{
		in >> str;

		if (word.find(str) == std::string::npos)
		{
			str[0] = (char)tolower(str[0]);

			//исключаем одинаковые слова, знаки препинания остаются
			if (!sameWordInArr(str, words, cnt))
			{
				words[cnt] = str;
				cnt++;
			}
		}
	}
	std::cout << cnt << std::endl;

	//упорядочиваем в алфавитном порядке
	for (int i = 0; i < cnt - 1; i++) 
		for (int j = 0; j < cnt - i - 1; j++)
			if ((words[j].compare(words[j + 1]) == -1))
				std::swap(words[j], words[j + 1]);

	std::string marks = " .,:;!?";
	for (int i = 0; i < cnt-1; i++)
	{
		bool flag = true;
		if (marks.find(words[i]) == std::string::npos)
			{
			if (words[i].length() == words[i + 1].length() and (marks.find(words[i+1]) == std::string::npos))
				for (int j = 0; j < words[i].length() - 1; j++)
					if (words[i][j] != words[i + 1][j])
						flag = false;
			else if (words[i].length() - words[i + 1].length() == 1 or words[i].length() - words[i + 1].length() == -1)
				for (int j = 0; j < minLen(words[i], words[i+1]) - 1; j++)
					if (words[i][j] != words[i + 1][j])
						flag = false;
			if (flag)
				words[i + 1] = "";
			}
	}

	int len_word[10000];
	for (int i = 0; i < cnt; i++)
	{
		if (marks.find(words[i + 1]) == std::string::npos)
			len_word[i] = words[i].length() - 1;
		else
			len_word[i] = words[i].length();
	}

	for (int i = 0; i < cnt; i++)
		for(int j = 0; j < cnt - i - 1; j++)
			if (len_word[j] < len_word[j + 1])
			{
				std::swap(len_word[j], len_word[j + 1]);
				std::swap(words[j], words[j + 1]);
			}

	for (int i = 0; i < n; i++)
	{
		std::cout << words[i] << std::endl;
		out << words[i] << "\n";
	}
}