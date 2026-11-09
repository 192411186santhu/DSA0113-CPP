#include <iostream>

enum class Zone { Inner, Middle, Outer };
constexpr long long BASE_FARE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_RATE_PERCENT = 20;
constexpr int CONCESSION_PERCENT = 50;
constexpr long long MIN_REMAINING_PAISE = 5000;

int main() {
    const long long fare = BASE_FARE_PAISE[static_cast<int>(Zone::Middle)];
    std::cout << "Middle base fare: " << fare << " paise\n";
    std::cout << "Peak rate: " << PEAK_RATE_PERCENT << "%\n";
    std::cout << "Concession: " << CONCESSION_PERCENT << "%\n";
    std::cout << "Minimum remaining: " << MIN_REMAINING_PAISE << " paise\n";
}
