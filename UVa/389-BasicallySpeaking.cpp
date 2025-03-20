#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;


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
    string x; int b1, b2;
    while (cin >> x >>b1>>b2) {  
        //covert x from b1 to b2
        long long value = toDecimal(x, b1);
        string result = toBase(value, b2);  
       
        if (result.size() > 7) {
            cout << right << setw(7) << "ERROR" << endl;
        } else {
            cout << right << setw(7) << result << endl;
        }
    }

    return 0;
}
