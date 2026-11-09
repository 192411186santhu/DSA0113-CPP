#include <iomanip>
#include <iostream>
#include <limits>

int main() {
    int hour = -1;
    std::cout << "Enter journey hour (0-23): ";
    if (!(std::cin >> hour)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input: please enter a number.\n";
        return 1;
    }
    if (hour < 0 || hour > 23) {
        std::cout << "Invalid hour. Allowed range is 0 to 23.\n";
        return 1;
    }

    long long farePaise = 1235;
    std::cout << "Journey hour: " << hour << '\n';
    std::cout << "Fare: Rs " << farePaise / 100 << '.'
              << std::setw(2) << std::setfill('0') << farePaise % 100 << '\n';
}
