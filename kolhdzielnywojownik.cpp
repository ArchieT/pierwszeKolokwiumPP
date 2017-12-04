#include <iostream>
#include <cstdio>

long long int abs(long long int x) {
    return x<0 ? -x : x;
}

int main() {
    while(true) {
        long long int left;
        long long int right;
        std::cin >> left;
        std::cin >> right;
        std::cout << abs(right-left) << std::endl;
        if(std::cin.eof()) return 0;
    }
}
