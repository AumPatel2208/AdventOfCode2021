#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int part1() {
    std::ifstream file("input.txt");
    std::string text;

    int counter = 0;
    int iteration = 0;
    int previousNumber;
    int currentNumber;
    while (getline(file, text)) {
        if (iteration == 0) {
            previousNumber = std::stoi(text);
        } else {

            currentNumber = std::stoi(text);

            if (previousNumber < currentNumber) {
                counter += 1;
            }

            previousNumber = currentNumber;
        }
        iteration += 1;
        std::cout << text << "\n";
    }

    return counter;
}

int part2() {
    std::ifstream file("input.txt");
    std::string text;
    std::vector<int> numbers;

    while (getline(file, text)) {
        numbers.push_back(std::stoi(text));
    }

    std::vector<int> sums;

    for (int i = 0; i < numbers.size() - 2; i++) {
        // std::cout << numbers.at(i) << "\n";
        sums.push_back(numbers.at(i) + numbers.at(i + 1) + numbers.at(i + 2)); // push back the sum of 3
    }

    int counter = 0;
    int previousNumber;
    for (int i = 0; i < sums.size(); i++) {
        if (i == 0) {
            previousNumber = sums.at(i);
        } else {
            if (previousNumber < sums.at(i)) {
                counter += 1;
            }
        }
        previousNumber = sums.at(i);
    }

    return counter;
}

int main() {
    int answer = part2();
    std::cout << answer << "\n";

    return 0;
}