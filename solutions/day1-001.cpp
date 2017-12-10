#include <iostream>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Not enough arguments...\n";
        return 1;
    }

    char * sequence = argv[1];
    int sum = 0;
    while(*sequence != '\0') {
        if ((*sequence == *(sequence + 1)) || (*(sequence + 1) == '\0' && *sequence == *(argv[1]))) {
            sum += *sequence - 48;
        }
        sequence++;
    }

    std::cout << "The solution is: " << sum << '\n';

    return 0;

}