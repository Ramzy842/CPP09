#include "RPN.hpp"

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

int count_words(std::string *str_ptr)
{
    if (str_ptr == NULL || str_ptr->empty())
        return 0;
    int word_count = 0;
    bool in_word = false;

    for (size_t i = 0; i < str_ptr->length(); ++i)
    {
        char c = str_ptr->at(i);
        if (isspace(c))
        {
            if (in_word)
                word_count++;
            in_word = false;
        }
        else
            in_word = true;
    }
    if (in_word)
        word_count++;
    return word_count;
}

std::string **split(std::string *str, size_t size)
{
    std::string **tokens = new std::string *[size];
    size_t num_tokens = 0;
    size_t start = 0;
    size_t pos;

    while (((pos = str->find(' ', start)) != std::string::npos) || ((pos = str->find('\t', start)) != std::string::npos))
    {
        if (num_tokens >= size)
            return NULL;
        tokens[num_tokens] = new std::string(str->substr(start, pos - start));
        start = pos + 1;
        num_tokens++;
    }
    if (start < str->length())
        tokens[num_tokens++] = new std::string(str->substr(start));

    return tokens;
}

bool isNumber(std::string &str)
{
    int x = 0;
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
    size_t len = count_words(&expression);
    std::string **splitted_exp = split(&expression, len);
    for (size_t x = 0; x < len; x++)
    {
        std::string token = *splitted_exp[x];
        if (isNumber(token))
        {
            int number = std::strtod(token.c_str(), NULL);
            this->numbers.push(number);
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
        else if (numbers.size() >= 2)
        {
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
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
    }
    if (numbers.size() == 1)
    {
        int result = numbers.top();
        numbers.pop();
        std::cout << result << std::endl;
    }
    else
        std::cout << "Error: Invalid input" << std::endl;
    for (size_t x = 0; x < len; x++)
    {
        delete splitted_exp[x];
    }
    delete[] splitted_exp;
}
