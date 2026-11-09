#include <iostream>
#include <string>

enum class Zone { Inner, Middle, Outer };
constexpr long long BASE[] = {1000, 2000, 3000};

bool isPeak(int hour, int minute) {
    const int t = hour * 60 + minute;
    return (t >= 480 && t < 600) || (t >= 1020 && t < 1200);
}
long long calculateFare(Zone zone, int hour, int minute, bool concession) {
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) return -1;
    const int index = static_cast<int>(zone);
    if (index < 0 || index >= 3) return -1;
    long long amount = BASE[index];
    if (concession) amount = (amount + 1) / 2;
    if (isPeak(hour, minute)) amount += (amount * 20 + 50) / 100;
    return amount;
}
int main() {
    struct Test {
        const char* name; Zone zone; int hour; int minute;
        bool concession; long long expected;
    };
    const Test tests[] = {
        {"Inner off-peak", Zone::Inner, 12, 0, false, 1000},
        {"Middle morning peak", Zone::Middle, 9, 0, false, 2400},
        {"Outer evening peak", Zone::Outer, 18, 0, false, 3600},
        {"10 AM boundary", Zone::Inner, 10, 0, false, 1000},
        {"8 PM boundary", Zone::Outer, 20, 0, false, 3000},
        {"Student Middle peak", Zone::Middle, 17, 0, true, 1200}
    };
    int passed = 0;
    for (const Test& test : tests) {
        const long long actual = calculateFare(test.zone, test.hour,
                                               test.minute, test.concession);
        const bool ok = actual == test.expected;
        if (ok) ++passed;
        std::cout << test.name << ": expected " << test.expected
                  << ", actual " << actual << " -> "
                  << (ok ? "PASS" : "FAIL") << '\n';
    }
    std::cout << passed << "/" << (sizeof(tests) / sizeof(tests[0]))
              << " tests passed\n";
}
