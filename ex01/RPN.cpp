/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:10 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/11 18:38:51 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &original)
{
    this->numbers = original.numbers;
}

RPN &RPN::operator=(const RPN &original)
{
    if (this != &original)
        this->numbers = original.numbers;
    return *this;
}

bool is_op(char c)
{
	if (c == '-' || c == '+' || c == '*' || c == '/')
		return true;
	return false;
}

int count_words(std::string str)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (str[x] != '\0')
	{
		if ((!isspace(str[x]) && !is_op(str[x]) && (is_op(str[x+1]) || isspace(str[x+1])))
			|| (is_op(str[x]) && str[x + 1] == '\0') || ( is_op(str[x]) && isspace(str[x + 1]))
			|| (!isspace(str[x]) && !is_op(str[x]) && str[x+1] == '\0')
		)
			count++;
		x++;
	}
	return (count);
}

std::string trim(std::string &str)
{
    std::string whitespace = " \t";
    size_t strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";
    size_t strEnd = str.find_last_not_of(whitespace);
    size_t strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}
std::string **split(std::string& str, size_t size)
{
	std::string **tokens = new std::string *[size];
    size_t num_tokens = 0;
	int x = 0;
    size_t start = 0;
	while (num_tokens < size)
	{
		if ((!isspace(str[x]) && !is_op(str[x])
			&& (is_op(str[x+1]) || isspace(str[x+1]) || str[x+1] == '\0'))
			|| (is_op(str[x]) && str[x + 1] == '\0') || ( is_op(str[x]) && isspace(str[x + 1]))
			|| (is_op(str[x]) && isspace(str[x + 1])))
		{
			std::string trim_str = (str.substr(start, x + 1 - start));
			tokens[num_tokens] = new std::string(trim(trim_str));
			// std::cout << *tokens[num_tokens] << std::endl;
			num_tokens++;
			start = x + 1;
		}
		x++;
	}
    return tokens;
}

bool isNumber(std::string &str)
{
    int x = 0;
	if (str.length() > 1 && (str[x] == '-' || str[x] == '+'))
		x++;
    while (str[x])
    {
        if (!isdigit(str[x]))
            return false;
        x++;
    }
    return true;
}

void RPN::calculate(std::string &expression)
{
	if (expression.empty())
	{
		std::cout << "Error: No expression provided!" << std::endl;
		return ;
	}
    size_t len = count_words(expression);
	expression = trim(expression);
    std::string **splitted_exp = split(expression, len);
    for (size_t x = 0; x < len; x++)
    {
        std::string token = *splitted_exp[x];
		if (isNumber(token))
        {
            double number = std::strtod(token.c_str(), NULL);
            this->numbers.push(number);
        }
		else if ((token == "+" || token == "-" || token == "/" || token == "*" ))
        {
			if (numbers.size() >= 2)
			{
				double b = numbers.top();
            	numbers.pop();
            	double a = numbers.top();
            	numbers.pop();
            	if (token == "+")
            	    numbers.push(a + b);
            	else if (token == "-")
            	    numbers.push(a - b);
            	else if (token == "/")
            	    numbers.push(a / b);
            	else if (token == "*")
            	    numbers.push(a * b);
			}
			else
			{
				std::cout << "Error: Invalid input" << std::endl;
				return ;
			}
            
        }
        else if (token != "+" && token != "-" && token != "/" && token != "*")
        {
            std::cout << "Error" << std::endl;
            for (size_t x = 0; x < len; x++)
            {
                delete splitted_exp[x];
            }
            delete[] splitted_exp;
            return;
        }
    }
    if (numbers.size() == 1)
    {
        double result = numbers.top();
        numbers.pop();
        std::cout << result << std::endl;
    }
    else
        std::cout << "Error: Invalid input" << std::endl;
    for (size_t x = 0; x < len; x++)
        delete splitted_exp[x];
    delete[] splitted_exp;
}