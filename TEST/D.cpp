#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll k;
    cin >> k;

    ll count = 0;

    // Duy?t qua c�c d? d�i c� th? c?a d�y li�n ti?p
    for (ll L = 1; L * (L + 1) / 2 <= k; L++) {
        // Ki?m tra xem 2k c� chia h?t cho L hay kh�ng
        if ((2 * k) % L == 0) {
            ll temp = (2 * k / L - L + 1);
            if (temp > 0 && temp % 2 == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}

