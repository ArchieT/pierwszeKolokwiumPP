#include <iostream>
#include <cstdio>

using namespace std;

//wykonywanie jednego testu, zwracanie exitcode
unsigned char worker() {
    int tab[1000]; //tablica 1000 pierwszych znaków
    for (int &ip : tab) ip = 0; //zerowanie tablicy
    int c = getchar(); //inicjalizowanie pierwszym - już z łańcucha S
    unsigned int poz = 0; //aktualna pozycja w tab
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
    return 0;
}

int main() {
    unsigned short int k; //liczba testów
    cin >> k; //biorę ją iostream
    getchar(); //a potem zabieram chara tego newline'a
    unsigned char exitcode;
    for (; k > 0; k--) // k-razy odpalam workera
        if ((exitcode = worker()) > 0) //chcę debugować exitcode'ami
            return exitcode;
    return 0;
}
