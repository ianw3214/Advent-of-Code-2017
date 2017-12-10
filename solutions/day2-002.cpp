#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{

    if (argc < 2) {
        std::cout << "Not enough arguments\n";
        return 1;
    }

    std::ifstream inp_file(argv[1]);
    std::string line;
    std::vector<int> tokens;
    int sum = 0;
    while (std::getline(inp_file, line)) {
        tokens.clear();
        std::string token;
        // parse the string char by char
        for (const char &c : line) {
            if (c == ' ' || c == '\t') {
                if (token.size() == 0) {
                    continue;
                } else {
                    int cur = std::stoi(token, nullptr, 10);
                    tokens.push_back(cur);
                }
                token = "";
            }
            token += c;
        }
        // also parse the last token
        int cur = std::stoi(token, nullptr, 10);
        tokens.push_back(cur);
        // loop through the vector twice
        for (int i = 0; i < tokens.size(); ++i) {
            bool found = false; // for some reason goto statements aren't working :/
            for (int j = i + 1; j < tokens.size(); ++j) {
                if (found) continue;
                if (tokens[i] % tokens[j] == 0) {
                    sum += tokens[i] / tokens[j];
                    found = true;
                }
                if (tokens[j] % tokens[i] == 0) {
                    sum += tokens[j] / tokens[i];
                    found = true;
                }
            }
        }
    }

    std::cout << "The solution is: " << sum << '\n';

    return 0;
}