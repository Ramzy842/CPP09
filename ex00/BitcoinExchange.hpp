/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:50:56 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/10 17:11:40 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <fstream> 
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::map <std::string, float> fileData;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& original);
    BitcoinExchange& operator=(const BitcoinExchange& original);
    std::map <std::string, float> getFileData();
    std::string trim(std::string &str);
    std::vector <std::string> split_line(const std::string &str, char delimiter);
    void outputValues(char *file);
};



#endif