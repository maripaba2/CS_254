#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << knapsack(W, wt, val, n) << endl;
    return 0;
}




// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Item {
//     int value;
//     int weight;
//     double density;
// };

// bool compare(Item i1, Item i2) {
//     return (i1.density > i2.density);
// }

// double fractionalKnapsack(int W, vector<Item>& items) {
//     sort(items.begin(), items.end(), compare);
//     double totalValue = 0.0;

//     for (int i = 0; i < items.size(); i++) {
//         if (W >= items[i].weight) {
//             totalValue += items[i].value;
//             W -= items[i].weight;
//         } else {
//             totalValue += (double)W / items[i].weight * items[i].value;
//             break;
//         }
//     }

//     return totalValue;
// }

// int main() {
//     vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
//     int W = 50;
//     cout << fractionalKnapsack(W, items) << endl;
//     return 0;
// }
