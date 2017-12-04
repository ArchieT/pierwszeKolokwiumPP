#include <iostream>
#include <stdio.h>

using namespace std;

void worker() {
    char tab[1000];
    for(unsigned int ip=0; ip<1000;ip++) tab[ip]=0;
    char c = getchar();
    unsigned int poz = 0;
    while(c != '\n' && poz<1000) {
        tab[poz] = c;
        poz++;
        c = getchar();
    }
    unsigned int q;
    cin >> q;
    getchar();
    for(;q>0;q--) {
        bool y = true;
        unsigned int np=0;
        c = getchar();
        while(c != '\n') {
            //if(y && np<poz && tab[np]==c) y = true;
            y = y && np<poz && tab[np]==c;
            np++;
            c = getchar();
        }
        cout << (y?"y":"n") << endl;
    }
    return;
}

int main() {
    unsigned short int k;
    cin >> k;
    getchar();
    for(;k>0;k--) worker();
    return 0;
}
