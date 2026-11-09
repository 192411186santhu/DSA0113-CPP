#include <climits>
#include <iostream>
#include <limits>

int main() {
    bool valid = true;
    char option = 'A';
    int hour = 9;
    long long balancePaise = 250000;
    unsigned int zoneNumber = 2;
    double sampleRupees = 10.50;

    std::cout << std::boolalpha;
    std::cout << "bool size: " << sizeof(valid) << " byte(s)\n";
    std::cout << "char size: " << sizeof(option) << " byte(s)\n";
    std::cout << "int size: " << sizeof(hour) << " byte(s)\n";
    std::cout << "long long size: " << sizeof(balancePaise) << " byte(s)\n";
    std::cout << "unsigned int size: " << sizeof(zoneNumber) << " byte(s)\n";
    std::cout << "double size: " << sizeof(sampleRupees) << " byte(s)\n";
    std::cout << "INT_MAX: " << INT_MAX << '\n';
    std::cout << "LLONG_MAX: " << LLONG_MAX << '\n';
    std::cout << "Example values valid=" << valid << ", hour=" << hour
              << ", balance=" << balancePaise << " paise\n";
    std::cout << "3,000,000 journeys at 3,600 paise = "
              << 3000000LL * 3600 << " paise\n";
}
