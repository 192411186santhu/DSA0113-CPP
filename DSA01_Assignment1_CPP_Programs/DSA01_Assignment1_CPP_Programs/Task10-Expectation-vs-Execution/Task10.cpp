#include <iomanip>
#include <iostream>

int main() {
    constexpr long long journeys[] = {20000, 500000, 3000000};
    constexpr long long farePaise = 1800; // illustrative fixed fare: Rs 18
    std::cout << "Illustrative fixed fare: Rs 18.00 per journey\n";
    for (long long count : journeys) {
        const long long exactPaise = count * farePaise;
        const double rupees = static_cast<double>(count) * 18.0;
        std::cout << "Journeys: " << count
                  << " | exact total: " << exactPaise << " paise"
                  << " | double total: Rs " << std::fixed
                  << std::setprecision(2) << rupees << '\n';
    }
    std::cout << "INT_MAX: " << 2147483647 << '\n';
    std::cout << "At 3,000,000 journeys, 5,400,000,000 paise exceeds "
                 "a common 32-bit int range.\n";
}
