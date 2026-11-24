#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

using Clock = std::chrono::steady_clock;

struct Bill {
    virtual double total() const = 0;
    virtual ~Bill() = default;
};
struct OP : Bill {
    double a, b;
    OP(double x, double y) : a(x), b(y) {}
    double total() const override { return a + b; }
};
struct IP : Bill {
    double days, rate, extra;
    IP(double d, double r, double e) : days(d), rate(r), extra(e) {}
    double total() const override { return days * rate + extra; }
};

enum class Kind { OP, IP };
struct Record { Kind kind; double a, b, c; };

double switchTotal(const Record& r) {
    switch (r.kind) {
        case Kind::OP: return r.a + r.b;
        case Kind::IP: return r.a * r.b + r.c;
    }
    return 0.0;
}

int main() {
    constexpr std::size_t N = 1000000;
    std::vector<std::unique_ptr<Bill>> polymorphic;
    std::vector<Record> records;
    polymorphic.reserve(N);
    records.reserve(N);

    for (std::size_t i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            polymorphic.push_back(std::make_unique<OP>(500, 1200));
            records.push_back({Kind::OP, 500, 1200, 0});
        } else {
            polymorphic.push_back(std::make_unique<IP>(3, 2500, 40000));
            records.push_back({Kind::IP, 3, 2500, 40000});
        }
    }

    auto t1 = Clock::now();
    double s1 = 0;
    for (const auto& bill : polymorphic) s1 += bill->total();
    auto t2 = Clock::now();

    double s2 = 0;
    for (const auto& record : records) s2 += switchTotal(record);
    auto t3 = Clock::now();

    std::cout << "virtual_ms "
              << std::chrono::duration<double, std::milli>(t2 - t1).count() << '\n';
    std::cout << "switch_ms "
              << std::chrono::duration<double, std::milli>(t3 - t2).count() << '\n';
    std::cout << "checksums " << s1 << ' ' << s2 << '\n';
    if (s1 != s2) {
        std::cerr << "ERROR: results do not match\n";
        return 1;
    }
}
