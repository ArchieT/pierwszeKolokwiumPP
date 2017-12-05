#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

std::string worker(std::string input) {
    return std::next_permutation(input.begin(), input.end())
           ? input
           : "No Successor";
}

int main() {
    std::string input;
    while (std::cin >> input) {
        if (input == "#") return 0;
        std::cout << worker(input) << std::endl;
    }
    return 0;
}