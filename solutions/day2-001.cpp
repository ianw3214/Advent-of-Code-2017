#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Not enough arguments\n";
        return 1;
    }

    std::ifstream inp_file(argv[1]);
    std::string line;
    int sum = 0;
    while (std::getline(inp_file, line)) {
        int max = -1;
        int min = -1;
        std::string token;
        // parse the string char by char
        for (const char& c : line) {
            if (c == ' ' || c == '\t') {
                if (token.size() == 0) {
                    continue;
                } else {
                    int cur = std::stoi(token, nullptr, 10);
                    if (min == -1 || cur < min) min = cur;
                    if (max == -1 || cur > max) max = cur;
                }
                token = "";
            }
            token += c;
        }
        // also parse the last token
        int cur = std::stoi(token, nullptr, 10);
        if (min == -1 || cur < min) min = cur;
        if (max == -1 || cur > max) max = cur;
        sum += max - min;
    }

    std::cout << "The solution is: " << sum << '\n';

    return 0;
}