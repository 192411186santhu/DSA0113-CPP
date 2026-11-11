#include <iostream>
using namespace std;

// Original: when full, shift nine values to make room.
class ShiftHistory {
    int data[10]{}, count = 0;
public:
    void add(int x) {
        if (count < 10) data[count++] = x;
        else {
            for (int i = 1; i < 10; ++i) data[i-1] = data[i];
            data[9] = x;
        }
    }
    void print() const {
        for (int i=0; i<count; ++i) cout << data[i] << ' ';
        cout << '\n';
    }
};
// Redesigned: circular index, O(1) insertion.
class CircularHistory {
    int data[10]{}, count = 0, next = 0;
public:
    void add(int x) {
        data[next] = x;
        next = (next + 1) % 10;
        if (count < 10) ++count;
    }
    void printOldestFirst() const {
        int start = (count == 10) ? next : 0;
        for (int i=0; i<count; ++i) cout << data[(start+i)%10] << ' ';
        cout << '\n';
    }
};
int main() {
    ShiftHistory original;
    CircularHistory redesigned;
    for (int i=1; i<=15; ++i) {
        original.add(i);
        redesigned.add(i);
    }
    cout << "Shift design: "; original.print();
    cout << "Circular design: "; redesigned.printOldestFirst();
}