#include <iostream>

using namespace std;

int main() {
    int A, L, C;
    cin >> A;
    cin >> L;
    cin >> C;
    if ((A * L * C) >= 50 && A >= 3) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
