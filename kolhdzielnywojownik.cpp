#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    while(true) {
        long long int left;
        long long int right;
        cin >> left;
        cin >> right;
        cout << right-left << endl;
        if(getchar()==EOF) return 0;
    }
}
