#include <iostream>
#include <cstdio>

using namespace std;

long long int abs(long long int x) {
    return x<0 ? -x : x;
}

int main() {
    while(true) {
        long long int left;
        long long int right;
        cin >> left;
        cin >> right;
        cout << abs(right-left) << endl;
        if(getchar()==EOF) return 0;
    }
}
