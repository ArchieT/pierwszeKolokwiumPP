//#include <stdio.h>
#include <iostream>

using namespace std;

const unsigned pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

unsigned reverse(unsigned in) {
    unsigned out = 0;
    short exponent = 0;
    for (short i = 9; i >= 0; i--) {
        unsigned digit = ((in / pow[i]) % 10);
        if (exponent == 0 && digit != 0) exponent = i;
        if (exponent > 0) out += digit * pow[exponent - i];
    }
    return out;
}

bool palindrome(unsigned in) {
    unsigned left = 0;
    unsigned right = in;
    unsigned srodek = 0;
    for (short i = 9; i >= 0; i--) {
        left = left*10 + right / pow[i];
        right = right % pow[i];
        if (right == reverse(left)) return true;
        if (right!=0 && right == reverse(left/10)) return true;
    }
    return false;
}

struct Result {
    //Result *prev;
    short unsigned count;
    unsigned current;

    Result(short unsigned count, unsigned current/*, Result *prev*/)
            : count(count), current(current)/*, prev(prev)*/ {}

    explicit Result(unsigned current) : count(0), current(current)/*, prev(0)*/ {}

    bool done() {
        return palindrome(current);
    }

    Result next() {
        return Result(count + (short) 1, current + reverse(current)/*, this*/);
    }

    Result *last() {
        return done() ? this : next().last();
    }
};

void worker() {
    unsigned in;
    cin >> in;
    Result last = *(Result(in).last());
    cout << last.count << " " << last.current << endl;
}

int main() {
    unsigned n;
    cin >> n;
    //getchar();
    for (; n > 0; n--) worker();
    return 0;
}
