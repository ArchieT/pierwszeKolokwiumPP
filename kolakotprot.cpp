#include <iostream>


#include BLADKOMPIL

void worker(unsigned int wysokosc, unsigned int liczbanajmniejszych) {
    unsigned int wieksze=0;
    unsigned int wieza=liczbanajmniejszych;
    for(unsigned int wysnaszego=wysok;wysnaszego>1;)
}

bool konec(unsigned int wysokosc, unsigned int liczba) {
    return wysokosc==0 && liczba==0;
}

bool routine() {
    unsigned int wysokosc;
    unsigned int liczba;
    cin >> wysokosc;
    cin >> liczba;
    return !konec(wysokosc, liczba);
}

int main() {
    while(routine());
    return 0;
}
