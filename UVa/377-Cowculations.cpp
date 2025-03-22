#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Map for cow symbols to numerical values
map<char, int> symbolToInt = {{'V', 0}, {'U', 1}, {'C', 2}, {'D', 3}};
map<int, char> intToSymbol = {{0, 'V'}, {1, 'U'}, {2, 'C'}, {3, 'D'}};

// Function to add two cow numbers (5-digit) with carry handling
string addCowNumbers(string num1, string num2)
{
    string result = "VVVVVVVV"; // Initialize result with 8 'V's
    int carry = 0;

    // Perform addition from rightmost digit to leftmost digit
    for (int i = 7; i >= 0; i--)
    {
        int d1 = symbolToInt[num1[i]];
        int d2 = symbolToInt[num2[i]];

        int sum = d1 + d2 + carry;
        carry = sum / 4;
        sum %= 4;
        result[i] = intToSymbol[sum];
    }
    return result;
}

// Function to apply the given operations to Num2
string applyOperations(string num1, string num2, vector<char> ops)
{
    for (char op : ops)
    {
        if (op == 'A')
        {
            num2 = addCowNumbers(num1, num2);
        }
        else if (op == 'R')
        {
            num2 = "V" + num2.substr(0, 7); // Right shift, pad left with 'V'
        }
        else if (op == 'L')
        {
            num2 = num2.substr(1) + "V"; // Left shift, pad right with 'V'
        }
    }
    return num2;
}

int main()
{
    int N;
    cin >> N;
    cout << "COWCULATIONS OUTPUT" << endl;

    while (N--)
    {
        string num1, num2, expectedResult;
        vector<char> operations(3);

        cin >> num1 >> num2;
        for (int i = 0; i < 3; i++)
            cin >> operations[i];
        cin >> expectedResult;
        // convert both numbers to 8 digit numbers by adding V's to the left
        num1 = "VVV" + num1;
        num2 = "VVV" + num2;

        // Apply operations on Num2
        string result = applyOperations(num1, num2, operations);

        // Compare result with expected output
        if (result == expectedResult)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}
