#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Not enough arguments passed in...\n";
        return 1;
    }

    // get the input number
    int target = std::stoi(argv[1], nullptr);

    // first find how big our current square is
    int current_length = 1;
    while (current_length * current_length < target) current_length += 2;

    int inner_sum = (current_length - 2) * (current_length - 2);
    int intermediate = target - inner_sum;
    
    int horizontal_distance = 0;
    int vertical_distance = 0;
    // if number is on the bottom half
    if (intermediate > (current_length - 1) * 3 - (current_length - 1) / 2 || intermediate < (current_length - 1) / 2) {                       
        if (intermediate >= (current_length - 1) * 3) {
            // if number is on the very bottom
            vertical_distance = (current_length - 1) / 2;
        } else if (intermediate > (current_length - 1) * 2) {
            // if the number is on the bottom left
            vertical_distance = intermediate - (current_length - 1) * 3 + (current_length - 1) / 2;
        } else {
            // then the number has to be on the bottom right
            vertical_distance = (current_length - 1) / 2 - intermediate;
        }
    }
    // if the number is on the top half
    if (intermediate < (current_length - 1) * 3 - (current_length- 1) / 2 && intermediate > (current_length - 1) / 2) {
        if (intermediate < (current_length - 1)) {
            // if number is on top right
            vertical_distance = intermediate - (current_length - 1) / 2;
        } else if (intermediate < (current_length - 1) * 2) {
            // if number is directly on top
            vertical_distance = (current_length - 1) / 2;
        } else {
            // then the number has to be on the top left
            vertical_distance = (current_length - 1) * 2 + (current_length - 1) / 2 - intermediate;
        }
    }
    // if the number is on the left
    if (intermediate > (current_length - 1) * 2 - (current_length - 1) / 2 && intermediate < (current_length - 1) * 3 + (current_length - 1) / 2) {
        if (intermediate < (current_length - 1) * 2) {
            // if the number is on the top left
            horizontal_distance = (current_length - 1) / 2 - (current_length - 1) * 2 + intermediate;
        } else if (intermediate <= (current_length - 1) * 3) {
            // if the number is directly to the left
            horizontal_distance = (current_length - 1) / 2;
        } else {
            // then the number has to be on the bottom left
            horizontal_distance = (current_length - 1) / 2 - intermediate + (current_length - 1) * 3;
        }
    }
    // if the number is on the right
    if (intermediate < (current_length - 1) + (current_length - 1) / 2 || intermediate > (current_length - 1) * 3 + (current_length - 1) / 2) {
        if (intermediate < (current_length - 1) || intermediate == (current_length - 1) * 4) {
            // if the number is directly to the right
            horizontal_distance = (current_length - 1) / 2;
        } else if (intermediate < (current_length - 1) + (current_length - 1) / 2) {
            // if the number is on the top right
            horizontal_distance = (current_length - 1) / 2 - intermediate + (current_length - 1);
        } else {
            // then the number has to be on the bottom right
            horizontal_distance = (current_length - 1) / 2 - (current_length - 1) * 4 + intermediate;
        }
    }

    std::cout << "Horizontal distance: " << horizontal_distance << '\n';
    std::cout << "Vertical distance: " << vertical_distance << '\n';
    std::cout << "The total distance is: " << vertical_distance + horizontal_distance << '\n';

    return 0;
    
}