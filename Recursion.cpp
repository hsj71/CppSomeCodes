#include <iostream>
using namespace std;

// Global variables to count the steps
int recursiveStepCount = 0;
int iterativeStepCount = 0;

// Recursive function to calculate Fibonacci numbers
int fibonacciRecursive(int n) {
    recursiveStepCount++;
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Non-recursive (iterative) function to calculate Fibonacci numbers
int fibonacciIterative(int n) {
    iterativeStepCount = 0; // Reset step count for each call
    if (n <= 1) {
        iterativeStepCount++;
        return n;
    }
    int a = 0, b = 1, fib = 1;
    for (int i = 2; i <= n; ++i) {
        iterativeStepCount++;
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}
int main() {
int n;
cout << "Enter the position (n) for Fibonacci series: ";
cin >> n;
// Recursive approach
recursiveStepCount = 0; // Reset the step count
int fibRecursive = fibonacciRecursive(n);
cout << "Fibonacci (Recursive) of " << n << " is: " << fibRecursive << endl;
cout << "Number of steps (Recursive): " << recursiveStepCount << endl;
// Iterative approach
int fibIterative = fibonacciIterative(n);
cout << "Fibonacci (Iterative) of " << n << " is: " << fibIterative << endl;
cout << "Number of steps (Iterative): " << iterativeStepCount << endl;
return 0;
}
