#include <iostream>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Not enough arguments...\n";
        return 1;
    }

    char *sequence = argv[1];
    int sum = 0;
    while (*sequence != '\0') {
        
    }

    std::cout << "The solution is: " << sum << '\n';

    return 0;
}