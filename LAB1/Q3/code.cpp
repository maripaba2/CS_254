#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;

int tsp(int n, vector<vector<int>>& distances, vector<vector<int>>& dp, int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return distances[pos][0];  // Return to the starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) {
            int newMask = mask | (1 << next);
            ans = min(ans, distances[pos][next] + tsp(n, distances, dp, newMask, next));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;  // Exit with an error code
    }

    int n;
    inputFile >> n;

    vector<vector<int>> distances(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> distances[i][j];
        }
    }

    inputFile.close();

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    int minCost = tsp(n, distances, dp, 1, 0);  // Start from city 0 with mask 1

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "Error opening output file!" << endl;
        return 1;  // Exit with an error code
    }

    outputFile << minCost;

    outputFile.close();

    return 0;
}
