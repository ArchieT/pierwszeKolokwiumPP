#include <iostream>
#include <cstdio>

long long int abs(long long int x) {
    return x<0 ? -x : x;
}

int main() {
    long long int left;
    long long int right;
    while(std::cin>>left>>right)
        std::cout << abs(right-left) << std::endl;
    return 0;
}
