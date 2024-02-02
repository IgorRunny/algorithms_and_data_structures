#include <iostream>
#include <stack>

int main()
{
	setlocale(LC_ALL, "ru");
	std::stack<char> brackets;
	std::string str;
	std::cout << "Введите строку: ";
	std::cin >> str;
	if (str[0] == ')' || str[0] == ']' || str[0] == '}')
	{
		std::cerr << "Строка не существует";
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				brackets.push(str[i]);
			}
			else if ((str[i] == ')' && brackets.top() == '(') || (str[i] == ']' && brackets.top() == '[') || (str[i] == '}' && brackets.top() == '{'))
			{
				brackets.pop();
			}
		}
	}

	if (!brackets.empty())
	{
		std::cerr << "Строка не существует";
	}
	else
	{
		std::cerr << "Строка может существовать";
	}
}