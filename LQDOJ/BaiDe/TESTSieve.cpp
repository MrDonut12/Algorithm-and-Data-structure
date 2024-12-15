#include <iostream>
#include <map>
using namespace std;

map<int, bool> sieve(int limit) {
    map<int, bool> is_prime;

    // Kh?i t?o t?t c? c�c s? t? 2 d?n `limit` l� nguy�n t?
    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    // B?t d?u s�ng Eratosthenes
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false; // ��nh d?u c�c b?i c?a i l� kh�ng ph?i s? nguy�n t?
            }
        }
    }
    
    return is_prime; // Tr? v? map ch?a c�c s? nguy�n t?
}

int main() {
    int limit;
    cout << "Nh?p gi?i h?n: ";
    cin >> limit;

    map<int, bool> primes = sieve(limit);

    // In ra c�c s? nguy�n t? trong map
    cout << "C�c s? nguy�n t? t? 2 d?n " << limit << " l�: ";
    for (const auto& p : primes) {
        if (p.second) { // Ki?m tra n?u l� nguy�n t?
            cout << p.first << " ";
        }
    }
    cout << endl;

    return 0;
}

