#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

// Function to determine the minimum base required for a given number
int minBase(const string &num) {
    char maxDigit = '0';
    for (char c : num) {
        if (c > maxDigit) maxDigit = c;  // Find the max character
    }
    return (isdigit(maxDigit) ? maxDigit - '0' : maxDigit - 'A' + 10) + 1;
}
//Function to convert a number from decimal to a given base
string toBase(long long value, int base) {
    string result;
    while (value > 0) {
        int digit = value % base;
        result.push_back(digit < 10 ? digit + '0' : digit - 10 + 'A');
        value /= base;
    }
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

// Function to convert a number from a given base to decimal
long long toDecimal(const string &num, int base) {
    long long value = 0;
    for (char c : num) {
        value = value * base + (isdigit(c) ? c - '0' : c - 'A' + 10);
        if (value < 0) return -1; // Overflow case
    }
    return value;
}

int main() {
    string x, y;
    while (cin >> x >> y) {  // Read input pairs until EOF
        int minBaseX = minBase(x);
        int minBaseY = minBase(y);
        bool found = false;

        for (int baseX = max(minBaseX,2); baseX <= 36; baseX++) {
            long long valueX = toDecimal(x, baseX);
            if (valueX == -1) continue;  // Skip overflow cases

            for (int baseY = max(minBaseY,2); baseY <= 36; baseY++) {
                long long valueY = toDecimal(y, baseY);
                if (valueY == -1) continue;  // Skip overflow cases

                if (valueX == valueY) {
                    cout << x << " (base " << baseX << ") = " << y << " (base " << baseY << ")\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            cout << x << " is not equal to " << y << " in any base 2..36\n";
        }
    }

    return 0;
}
