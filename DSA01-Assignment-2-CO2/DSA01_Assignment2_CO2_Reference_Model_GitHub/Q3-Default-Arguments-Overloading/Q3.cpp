#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};
double charge(double kg, bool express = false, bool insured = false) {
    double total = kg * 40.0;
    if (express) total += 50.0;
    if (insured) total += 20.0;
    return total;
}
double charge(int grams) { return charge(static_cast<double>(grams) / 1000.0); }
double charge(const Parcel& p) { return charge(p.weightKg, p.express, p.insured); }

int main() {
    cout << "charge(2) = " << charge(2) << '\n';
    cout << "charge(2.0) = " << charge(2.0) << '\n';
    cout << "charge(2.0f) = " << charge(2.0f) << '\n';
    cout << "charge(500) = " << charge(500) << '\n';
    cout << "charge(1.5, true) = " << charge(1.5, true) << '\n';
    Parcel p{2.0, true, true};
    cout << "charge(Parcel) = " << charge(p) << '\n';
}