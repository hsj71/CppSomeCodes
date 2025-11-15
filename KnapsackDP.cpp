#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsackDP(int capacity, vector<int>& weights, vector<int>& values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    // Build the DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter the values and weights of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> values[i] >> weights[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    int maxValue = knapsackDP(capacity, weights, values, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;
    return 0;
}
