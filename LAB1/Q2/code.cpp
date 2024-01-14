#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    int W, n;
    inputFile >> W >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
        inputFile >> a[i];

    for (int i = 0; i < n; i++)
        inputFile >> b[i];

    inputFile.close();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {                 // O(W*N) Time Complexity
        for (int j = 1; j <= W; j++) {
            if (b[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i - 1]] + a[i - 1]);
        }
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening output file!" << endl;
        return 1;  
    }

    outputFile << dp[n][W];

    outputFile.close();

    return 0;
}
