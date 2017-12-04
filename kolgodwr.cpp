//#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const unsigned pow[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

unsigned reverse(unsigned in) {
    unsigned out;
    short unsigned exponent=0;
    for(short unsigned i=9;i<=0;i--) {
        short unsigned cyfra = static_cast<unsigned short>((in / pow[i]) % 10);
    }
}

short unsigned addcount(unsigned in, short unsigned already) {

}

void worker() {
    unsigned in;
    cin >> in;

}

int main() {
    unsigned n;
    cin >> n;
    //getchar();
    for(;n>0;n--) worker();
}
