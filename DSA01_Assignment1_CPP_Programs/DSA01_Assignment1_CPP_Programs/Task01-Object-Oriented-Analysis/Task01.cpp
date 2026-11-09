#include <iostream>
#include <string>
#include <vector>

enum class Zone { Inner, Middle, Outer };

class Passenger {
    std::string name_;
    bool concession_;
public:
    Passenger(std::string name, bool concession)
        : name_(std::move(name)), concession_(concession) {}
    bool hasConcession() const { return concession_; }
    const std::string& name() const { return name_; }
};

class Journey {
    Zone zone_;
    int hour_;
    int minute_;
public:
    Journey(Zone zone, int hour, int minute)
        : zone_(zone), hour_(hour), minute_(minute) {}
    Zone zone() const { return zone_; }
    int hour() const { return hour_; }
    int minute() const { return minute_; }
};

class FarePolicy {
public:
    static long long baseFarePaise(Zone zone) {
        switch (zone) {
            case Zone::Inner: return 1000;
            case Zone::Middle: return 2000;
            case Zone::Outer: return 3000;
        }
        return -1;
    }
    static bool isPeak(int hour, int minute) {
        const int t = hour * 60 + minute;
        return (t >= 480 && t < 600) || (t >= 1020 && t < 1200);
    }
    static long long calculate(const Journey& journey, const Passenger& passenger) {
        long long fare = baseFarePaise(journey.zone());
        if (fare < 0) return -1;
        if (passenger.hasConcession()) fare = (fare + 1) / 2;
        if (isPeak(journey.hour(), journey.minute()))
            fare += (fare * 20 + 50) / 100;
        return fare;
    }
};

class SmartCard {
    long long balancePaise_;
public:
    explicit SmartCard(long long balance) : balancePaise_(balance) {}
    bool pay(long long fare) {
        constexpr long long MIN_REMAINING = 5000;
        if (fare < 0 || balancePaise_ - fare < MIN_REMAINING) return false;
        balancePaise_ -= fare;
        return true;
    }
    long long balance() const { return balancePaise_; }
};

int main() {
    Passenger student("Student", true);
    Journey trip(Zone::Middle, 9, 15);
    SmartCard card(10000);
    const long long fare = FarePolicy::calculate(trip, student);
    std::cout << "Passenger: " << student.name() << '\n';
    std::cout << "Fare (paise): " << fare << '\n';
    std::cout << (card.pay(fare) ? "Journey accepted" : "Journey denied") << '\n';
    std::cout << "Remaining balance (paise): " << card.balance() << '\n';
}
