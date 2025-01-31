#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5; 
int mu[MAX];

void compute_mobius() {
    fill(mu, mu + MAX, 1);
    vector<bool> is_prime(MAX, true);
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i; j < MAX; j += i) {
                is_prime[j] = (j == i);
                mu[j] *= -1;
            }
            for (int j = i * i; j < MAX; j += i * i) {
                mu[j] = 0;
            }
        }
    }
}
struct Factor {
    int prim,exponent;}
vector<Factor> factorize(int n) {
    vector<Factor> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

//生成Divisor
void generate_divisors(const vector<Factor> &factors, vector<int> &divisors, int index = 0, int current = 1) {
    if (index == factors.size()) {
        divisors.push_back(current);
        return;
    }
    int p = factors[index].prime;
    int exp = factors[index].exponent;
    int pow_p = 1;
    for (int e = 0; e <= exp; ++e) {
        generate_divisors(factors, divisors, index + 1, current * pow_p);
        pow_p *= p;
    }
}

int main() {
    compute_mobius(); 
    
    int X, N;
    cin >> X >> N;
    
    vector<Factor> factors = factorize(X); 
    vector<int> divisors;
    generate_divisors(factors, divisors); 
    
    int result = 0;
    for (int d : divisors) {
        result += mu[d] * (N / d); 
    }
    
    cout << result << endl;
    return 0;
}
