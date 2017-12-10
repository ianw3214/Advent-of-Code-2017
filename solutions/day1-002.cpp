#include <iostream>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Not enough arguments...\n";
        return 1;
    }

    // first we have to get the length of the argument
    char *sequence = argv[1];
    int length = 0;
    while (*sequence != '\0') {
        length++;
        sequence++;
    }

    sequence = argv[1];
    int sum = 0;
    // don't worry too much about divide by 2 because we are guaranteed even number
    for (int i = 0; i < length / 2; ++i) {
        if (*(sequence + i) == *(sequence + length / 2 + i)) {
            sum += (*(sequence + i) - 48) * 2;
        }
    }

    std::cout << "The solution is: " << sum << '\n';

    return 0;
}