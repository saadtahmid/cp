#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x, int b)
{
    int result = 0, power = 1;
    while (x > 0)
    {
        int digit = x % 10;      // Extract last digit
        result += digit * power; // Apply base power multiplication
        power *= b;              // Move to the next power of base
        x /= 10;                 // Remove last digit
    }
    return result;
}
signed main()
{
    int t;        // Number of test cases
    cin >> t;     // Read number of test cases
    cin.ignore(); // Ignore newline after reading t

    while (t--)
    {
        string line;
        getline(cin, line); // Read the full equation

        int a, b, c;
        char plus, equals;

        // Extract numbers from the string using a stringstream
        stringstream ss(line);
        ss >> a >> plus >> b >> equals >> c;
         
        // Check if the equation is correct
        int z = 0;
        for (int x = 1; x <= 18; x++)
        {   
            if(x==1){
                //check if there is any digit > 1 we skip the base 1
                bool done = false;
                //convert a,b,c to string
                string stra = to_string(a);
                string strb = to_string(b);
                string strc = to_string(c);
                for(int i = 0; i<stra.size(); i++){
                    if(stra[i] != '1'){
                        done = true;
                        break;
                    }
                }
                for(int i = 0; i<strb.size(); i++){
                    if(strb[i] != '1'){
                        done = true;
                        break;
                    }
                }
                for(int i = 0; i<strc.size(); i++){
                    if(strc[i] != '1'){
                        done = true;
                        break;
                    }
                }
                if(done) continue;
            }
            // check if there is any digit > x we skip the base x
            else{bool done = false;
            int temp = a;
            while(temp>0){
                if(temp%10 >= x){
                    done = true;
                    break;
                }
                temp/=10;
            }
            temp = b;
            while(temp>0){
                if(temp%10 >= x){
                    done = true;
                    break;
                }
                temp/=10;
            }
            temp = c;
            while(temp>0){
                if(temp%10 >= x){
                    done = true;
                    break;
                }
                temp/=10;
            }
            if(done) continue;}
            

            if (f(a, x) + f(b, x) == f(c, x))
            {
                cout << x << endl;
                z = 1;
                break;
            }
        }
        if (z == 0)
            cout << 0 << endl;
    }
}
