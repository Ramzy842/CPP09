/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:50:58 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/10 19:16:32 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream dataFile("./data.csv");
    if (!dataFile)
        return;
    std::string line;
    std::getline(dataFile, line);
    while (std::getline(dataFile, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
        {
            std::cerr << "Error : Invalid line" << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        double value;
        try
        {
            std::string temp_val = line.substr(pos + 1);
            value = std::strtod(temp_val.c_str(), NULL);
        }
        catch (std::exception &e)
        {
            (void)e;
            std::cerr << "Error: could not parse value" << std::endl;
            continue;
        }
        this->fileData[date] = value;
    }
    dataFile.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
    this->fileData = original.fileData;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
        this->fileData = original.fileData;
    return *this;
}

std::map<std::string, float> BitcoinExchange::getFileData()
{
    return this->fileData;
}

std::string BitcoinExchange::trim(std::string &str)
{
    std::string whitespace = " \t";
    size_t strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";

    size_t strEnd = str.find_last_not_of(whitespace);
    size_t strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

std::vector<std::string> BitcoinExchange::split_line(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t pos;

    while ((pos = str.find(delimiter, start)) != std::string::npos)
    {
        tokens.push_back(str.substr(start, pos - start));
        start = pos + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

bool isNumber(std::string &str)
{
    int x = 0;
    if (str[x] == '-' || str[x] == '+')
        x++;
    while (str[x])
    {
        if (!isdigit(str[x]) && str[x] != '.')
            return false;
        x++;
    }
    return true;
}

bool isValidKey(std::vector<std::string> key_vec)
{
    for (std::vector<std::string>::iterator it = key_vec.begin(); it != key_vec.end(); it++)
    {
        std::string temp = *it;
        if (std::strtod(temp.c_str(), NULL) == 0)
            return false;
    }
    return true;
}

void BitcoinExchange::outputValues(char *file)
{
    std::ifstream inputFile(file);
    if (!inputFile)
        return;
    std::string line;
    std::vector<std::string> line_vec;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {

        line_vec = split_line(line, '|');
        if (line_vec.size() < 2 || line_vec[1].length() == 0)
        {
            std::cout << "Error: bad input => " << line_vec[0] << std::endl;
            continue;
        }
        std::string key = trim(line_vec[0]);
        if (!isValidKey(split_line(key, '-')))
        {
            std::cout << "Error: bad input => " << line_vec[0] << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = fileData.lower_bound(key);
        std::pair<std::string, float> line_pair;
        if (it == fileData.end() || it->first > key)
        {
            if (it != this->fileData.begin())
            {
                std::map<std::string, float>::iterator prev_it = it;
                --prev_it;
                line_pair = *(prev_it);
            }
        }
        else if (it == fileData.end() || it->first == key)
            if (it != this->fileData.begin())
                line_pair = *(it);
        try
        {
            std::string num = trim(line_vec[1]);
            if (!isNumber(num))
                std::cout << "Error: Not a number" << std::endl;
            else
            {
                double value = std::strtod(line_vec[1].c_str(), NULL);
                if (value > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else if (value < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else
                    std::cout << line_vec[0] << " => " << line_vec[1] << " = " << std::strtod(line_vec[1].c_str(), NULL) * line_pair.second << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
    inputFile.close();
}