#include <stdio.h>
#include <iostream>

#include BLADKOMPIL

using namespace std;

void worker() {
    short unsigned int cyfry[10];
    short unsigned int liczba = 0;
    char c;
    while(true) {
        c = getchar();
        short unsigned int cyfra = 0;
        switch(c) {
            case '9': cyfra++;
            case '8': cyfra++;
            case '7': cyfra++;
            case '6': cyfra++;
            case '5': cyfra++;
            case '4': cyfra++;
            case '3': cyfra++;
            case '2': cyfra++;
            case '1': cyfra++;
            case '0': liczba++;
            case EOF: goto byleof;
        }
        cyfry[liczba] = cyfra;
    }
    bool pali = true;
    for(short unsigned int i = 0; i<)
    byleof:
}

int main() {
    unsigned int n;
    cin >> n;
    getchar();
    for(;n>0;n--) worker();
}
