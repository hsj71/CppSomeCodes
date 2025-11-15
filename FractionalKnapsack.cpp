#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an item with value and weight
struct Item {
    double value;
    double weight;
    // Constructor
    Item(double v, double w) : value(v), weight(w) {}
};
// Comparator to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}
// Function to solve the fractional knapsack problem
double fractionalKnapsack(vector<Item>& items, double capacity) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0; // Total value of the knapsack
    for (auto& item : items) {
        if (capacity == 0) // If knapsack is full
            break;
        if (item.weight <= capacity) {
            // Take the entire item
            totalValue += item.value;
            capacity -= item.weight;
        } else {
          totalValue += (item.value / item.weight) * capacity;
            capacity = 0; // Knapsack is full after taking the fraction
        }
    }
    return totalValue;
}
int main() {
    int n;
    double capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> items;
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        double value, weight;
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    double maxValue = fractionalKnapsack(items, capacity);
    cout << "Maximum value in knapsack = " << maxValue << endl;
    return 0;
}
