

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> splitString(std::string input, char delimiter)
{
    std::istringstream iss(input);
    std::vector<int> tokens;
    std::string token;
    while (std::getline(iss, token, delimiter))
    {
        tokens.push_back(std::stoi(token));
    }
    return tokens;
}

int findLowest(int a, int b, int c)
{
    int lowest = a;

    if (b < lowest)
    {
        lowest = b;
    }

    if (c < lowest)
    {
        lowest = c;
    }

    return lowest;
}

int main()
{
    std::string filePath = "in.txt";
    std::ifstream inputFile(filePath);
    std::string line;
    int output = 0;
    while (std::getline(inputFile, line))
    {
        const char *myString = "x";
        char delim = myString[0];
        
        std::vector<int> tokens = splitString(line, delim);

        int l = tokens[0];
        int w = tokens[1];
        int h = tokens[2];
        int lineTotal = (l + l + w + w) + (l * w * h);
        output = output + lineTotal;
    }
    std::cout << output << std::endl;

    inputFile.close();

    return 0;
}
