/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:01 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/10 17:11:20 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if (argc != 2)
    {
        std::cerr << "Error: usage ./btc file" << std::endl;
        return 1;
    }
    char *fileName = argv[1];
    std::ifstream inputFile(fileName);
    if (!inputFile)
    {
        std::cerr << "Error: the file " << fileName << " does not exist!" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.outputValues(fileName);
    return 0;
}