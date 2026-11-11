#include <iostream>
using namespace std;

int& highest(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return marks[best];
}
int highestIndex(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[best]) best = i;
    return best;
}
// Deliberately unsafe: compile to observe warning; never call this function.
int& badReference() {
    int local = 50;
    return local;
}
int main() {
    int marks[] = {78, 91, 85, 88};
    highest(marks, 4) += 2;
    cout << "Highest after moderation: " << highest(marks, 4) << '\n';
    int index = highestIndex(marks, 4);
    cout << "Highest index: " << index << '\n';
    cout << "Updated marks: ";
    for (int x : marks) cout << x << ' ';
    cout << '\n';
}