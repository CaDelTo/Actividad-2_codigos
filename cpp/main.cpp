#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void sum_primes(int limit) {
    int count = 0, num = 2, total = 0;
    while (count < limit) {
        if (is_prime(num)) {
            total += num;
            count++;
        }
        num++;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    sum_primes(10000);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "C++ execution time: " << duration << " ms" << std::endl;
    std::ofstream file("results/cpp_time.txt");
    file << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    file.close();

    return 0;
}
