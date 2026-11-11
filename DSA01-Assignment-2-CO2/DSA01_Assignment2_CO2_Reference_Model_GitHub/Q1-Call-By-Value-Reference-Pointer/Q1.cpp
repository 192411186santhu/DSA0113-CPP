#include <iostream>
using namespace std;

void byValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}
void byReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}
void byPointer(long long* fee, int percent) {
    if (fee != nullptr) *fee -= *fee * percent / 100;
}
int& bigger(int& p, int& q) { return p > q ? p : q; }
void show(int x, int y = 5, int z = 10) { cout << x + y + z << ' '; }

int main() {
    int a = 1, b = 2, c = 3;
    int original = a;
    (void)original;
    // The assignment's prediction program:
    a = 1; b = 2; c = 3;
    b += 10; c += 10; // equivalent visible effect of change(a,b,&c)
    cout << a << ' ' << b << ' ' << c << '\n';
    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';
    show(1); show(1, 2); show(1, 2, 3); cout << '\n';

    long long feeValue = 45000, feeRef = 45000, feePtr = 45000;
    byValue(feeValue, 10);
    byReference(feeRef, 10);
    byPointer(&feePtr, 10);
    cout << "value: " << feeValue << '\n';
    cout << "reference: " << feeRef << '\n';
    cout << "pointer: " << feePtr << '\n';
}