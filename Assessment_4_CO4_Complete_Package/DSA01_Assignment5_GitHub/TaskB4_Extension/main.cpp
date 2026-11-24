#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(std::string p) : patient(std::move(p)) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
};

class EmergencyBill : public Bill {
    double baseCharge, minutes, perMinute;
public:
    EmergencyBill(const std::string& patientName, double base,
                  double durationMinutes, double rate)
        : Bill(patientName), baseCharge(base), minutes(durationMinutes), perMinute(rate) {
        if (base < 0 || durationMinutes < 0 || rate < 0)
            throw std::invalid_argument("negative emergency charge");
    }
    double total() const override { return baseCharge + minutes * perMinute; }
    std::string type() const override { return "Emergency"; }
};

class OutPatientBill : public Bill {
    double consultation, tests;
public:
    OutPatientBill(const std::string& patientName, double c, double t)
        : Bill(patientName), consultation(c), tests(t) {}
    double total() const override { return consultation + tests; }
    std::string type() const override { return "OutPatient"; }
};

class Payer {
public:
    virtual double amountCovered(const Bill& bill) const = 0;
    virtual std::string name() const = 0;
    virtual ~Payer() = default;
};

class CorporatePayer : public Payer {
    double coveragePercent;
public:
    explicit CorporatePayer(double percent) : coveragePercent(percent) {
        if (percent < 0 || percent > 100)
            throw std::invalid_argument("invalid corporate coverage");
    }
    double amountCovered(const Bill& bill) const override {
        return bill.total() * coveragePercent / 100.0;
    }
    std::string name() const override { return "Corporate"; }
};

int main() {
    std::vector<std::unique_ptr<Bill>> bills;
    bills.push_back(std::make_unique<EmergencyBill>("Asha", 1000, 30, 50));
    bills.push_back(std::make_unique<OutPatientBill>("Ravi", 500, 1200));

    CorporatePayer corporate(80);
    for (const auto& bill : bills) {
        std::cout << bill->type() << " total=" << bill->total()
                  << ", " << corporate.name()
                  << " covers=" << corporate.amountCovered(*bill) << '\n';
    }
}
