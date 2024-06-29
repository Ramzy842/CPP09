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