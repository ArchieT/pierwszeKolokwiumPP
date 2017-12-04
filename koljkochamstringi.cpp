#include <iostream>
#include <cstdio>

using namespace std;

void worker() {
    int tab[1000];
    for (int &ip : tab) ip = 0;
    int c = getchar();
    unsigned int poz = 0;
    while (c != '\n' && poz < 1000) {
        tab[poz] = c;
        poz++;
        c = getchar();
    }
    unsigned int q;
    cin >> q;
    getchar();
    for (; q > 0; q--) {
        bool y = true;
        unsigned int np = 0;
        c = getchar();
        while (c != '\n') {
            //if(y && np<poz && tab[np]==c) y = true;
            y = y && np < poz && tab[np] == c;
            np++;
            c = getchar();
        }
        cout << (y ? "y" : "n") << endl;
    }
}

int main() {
    unsigned short int k;
    cin >> k;
    getchar();
    for (; k > 0; k--) worker();
    return 0;
}
