//
// Created by mf on 30.01.18.
//

#include <iostream>

using namespace std;

struct repr {
    short unsigned i,v,x,l,c;
};

repr glob[101];

repr sum(repr a, repr b) {
    repr c{a.i+b.i,a.v+b.v,a.x+b.x,a.l+b.l,a.c+b.c};
    return c;
}

repr calc(short unsigned in) {
    repr o{0,0,0,0,0};
    if(in==100) {
        o.c++; return o;
    };
    if(in>=90) {
        o.x++;
        o.c++;
        in-=90;
    }
    if(in>=50) {
        o.l++;
        in-=50;
    }
    if(in>=40) {
        o.l++;
        o.x++;
        in-=40;
    }
    while(in>=10) {
        o.x++;
        in-=10;
    }
    if(in==9) {
        o.x++;
        o.i++;
        return o;
    }
    while(in>=5) {
        o.v++;
        in-=5;
    }
    if(in==4) {
        o.v++;
        o.i++;
        return o;
    }
    while(in>0) {
        o.i++;
        in--;
    }
    return o;
}

void doit() {
    glob[0] = repr{0,0,0,0,0};
    for(unsigned short i=1;i<101;i++)
        glob[i]=sum(glob[i-1],calc(i));
}

void worker(short unsigned in) {
    cout << in << ": ";
    repr cur = glob[in];
    cout << cur.i << " i, "
         << cur.v << " v, "
         << cur.x << " x, "
         << cur.l << " l, "
         << cur.c << " c" << endl;
}

int main() {
    doit();
    short unsigned in;
    do { cin >> in; worker(in); } while (in!=0);
    return 0;
}