#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../utils/aum_string.h"

struct Movement {
    int horizontal;
    int depth;
    int aim;

    Movement(int h, int d, int a) {
        horizontal = h;
        depth = d;
        aim = a;
    }

    ~Movement() {
    }

    // Functions for part 2
    void Forward2(const int &val, Movement &movement) {
        movement.horizontal += val;
        movement.depth += movement.aim * val;
    }

    void Vertical2(const int &val, Movement &movement, const bool &isDown) {
        if (isDown) {
            movement.aim += val;
        } else {
            movement.aim -= val;
        }
    }

    // general total
    int Total() {
        return horizontal * depth;
    }
};

int Part1() {
    std::ifstream file("input.txt");
    std::string text;

    Movement movement{0, 0, 0};

    std::vector<std::string> splitLine;

    while (getline(file, text)) {
        splitLine = aum_string::split(text, ' ');
        if (splitLine.at(0) == "forward") {
            movement.horizontal += std::stoi(splitLine.at(1));
        } else if (splitLine.at(0) == "up") {
            movement.depth -= std::stoi(splitLine.at(1));
        } else if (splitLine.at(0) == "down") {
            movement.depth += std::stoi(splitLine.at(1));
        }
    }
    return movement.Total();
}

int Part2(){
        std::ifstream file("input.txt");
    std::string text;

    Movement movement{0, 0, 0};

    std::vector<std::string> splitLine;

    while (getline(file, text)) {
        splitLine = aum_string::split(text, ' ');
        if (splitLine.at(0) == "forward") {
            movement.Forward2(std::stoi(splitLine.at(1)),movement);
        } else if (splitLine.at(0) == "up") {
            movement.Vertical2(std::stoi(splitLine.at(1)),movement, false);
        } else if (splitLine.at(0) == "down") {
            movement.Vertical2(std::stoi(splitLine.at(1)),movement, true);
        }
    }
    return movement.Total();
}

int main() {
    std::cout << Part2() << "\n";

    return 0;
}