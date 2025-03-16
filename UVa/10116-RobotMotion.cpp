#include <bits/stdc++.h>
using namespace std;

int R, C, start_col;  // Grid dimensions and starting column
char grid[20][20];    // Grid instructions
int steps[20][20];    // Steps tracking

// Direction mapping
unordered_map<char, pair<int, int>> direction = {
    {'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}
};

void solve() {
    memset(steps, -1, sizeof(steps));  // Reset step matrix

    int r = 0, c = start_col - 1, step_count = 0;

    while (true) {
        if (r < 0 || r >= R || c < 0 || c >= C) {  // Check for exit
            cout << step_count << " step(s) to exit\n";
            return;
        }

        if (steps[r][c] != -1) {  // Loop detected
            int loop_start = steps[r][c];
            cout << loop_start << " step(s) before a loop of " 
                 << (step_count - loop_start) << " step(s)\n";
            return;
        }

        steps[r][c] = step_count++;  // Mark step at (r, c)
        
        auto [dr, dc] = direction[grid[r][c]];  // Get movement direction
        r += dr;
        c += dc;
    }
}

int main() {
    while (cin >> R >> C >> start_col, R) {  // Read input until 0 0 0
        for (int i = 0; i < R; i++)
            cin >> grid[i];  // Read grid
        
        solve();
    }
    return 0;
}
