class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int sqrt_r = std::sqrt(r);
    std::vector<int> primes = sieve(sqrt_r);

    int special_count = 0;
    for (int prime : primes) {
        int special_num = prime * prime;
        if (special_num >= l && special_num <= r) {
            ++special_count;
        }
    }

    int total_count = r - l + 1;
    return total_count - special_count;
    }
std::vector<int> sieve(int n) {
    std::vector<bool> is_prime(n + 1, true);
    std::vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
};