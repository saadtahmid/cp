#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

// Function to convert base-b number (as string) to its decimal mod m
int baseToDecimalMod(string num, int b, int m) {
    int result = 0;
    for (char digit : num) {
        result = (result * b + (digit - '0')) % m;
    }
    return result;
}

// Function to convert a decimal number to base-b
string decimalToBase(int num, int b) {
    if (num == 0) return "0";  // Edge case: If remainder is 0, return "0"
    
    string result = "";
    while (num > 0) {
        result += (num % b) + '0';
        num /= b;
    }
    reverse(result.begin(), result.end());
    return result;
}

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (true) {
        int b;
        string p, m;
        cin >> b;
        if (b == 0) break;  // Termination condition

        cin >> p >> m;

        // Convert m to decimal 
        int m_dec = 0;
        for (char digit : m) {
            m_dec = m_dec * b + (digit - '0');
        }

        // Convert p to decimal mod m
        int remainder = baseToDecimalMod(p, b, m_dec);

        // Convert the remainder to base-b and print the result
        cout << decimalToBase(remainder, b) << endl;
    }

    return 0;

}

