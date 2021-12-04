#include <fstream>
#include <iostream>
#include <string>

#include <bits/stdc++.h>

struct Counter {
    int zeros;
    int ones;
};

long Part1() {
    std::ifstream file("input.txt");
    std::string text;

    std::vector<Counter> counter(12);

    while (getline(file, text)) {
        // increment the counter for each bit
        for (int i = 0; i < 12; i++) {
            if (text.at(i) == '0') {
                counter.at(i).zeros += 1;
            } else {
                counter.at(i).ones += 1;
            }
        }
    }

    std::string gammaString = "";
    for (int i = 0; i < 12; i++) {
        if (counter.at(i).zeros > counter.at(i).ones) {
            gammaString += "0";
        } else {
            gammaString += "1";
        }
    }

    std::bitset<12> gammaBinary(gammaString);

    std::cout << "Gamma String: " << gammaString << std::endl;
    std::cout << "Gamma Binary: " << gammaBinary << std::endl;

    ulong gammaValue = gammaBinary.to_ulong();
    std::cout << "Gamma Long: " << gammaValue << std::endl;

    std::bitset<12> epsilonBinary = gammaBinary.flip();
    ulong epsilonValue = epsilonBinary.to_ulong();

    std::cout << "Epsilon Binary: " << epsilonBinary << std::endl;
    std::cout << "Epsilon Long: " << epsilonValue << std::endl;

    return (gammaValue * epsilonValue);
}

int main() {
    std::cout << Part1() << "\n";

    return 0;
}