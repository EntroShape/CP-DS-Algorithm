#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate Fibonacci numbers modulo Q
vector<int> fibonacci_modulo(int n, int Q) {
    vector<int> fib(n);
    fib[0] = 1 % Q;
    if (n > 1) fib[1] = 1 % Q;
    for (int i = 2; i < n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % Q;
    }
    return fib;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, Q;
        cin >> n >> Q;

        // Calculate the first n Fibonacci numbers modulo Q
        vector<int> fib = fibonacci_modulo(n, Q);

        // Sort the Fibonacci numbers modulo Q
        sort(fib.begin(), fib.end());

        // Calculate the weighted sum modulo Q
        long long weighted_sum = 0;
        for (int i = 0; i < n; ++i) {
            weighted_sum = (weighted_sum + (i + 1LL) * fib[i]) % Q;
        }

        // Output the result
        cout << weighted_sum << endl;
    }

    return 0;
}
