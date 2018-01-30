//
// Created by mf on 30.01.18.
//

#include <iostream>
#include <cassert>

using namespace std;

/*short unsigned*/ int n;
short int t[100][100];
//bool q[101][101][101][101];
//int qb[101][101][101][101];

int max(int a, int b, int c) {
    if(a>b) {
        if (c>a) return c;
        return a;
    } else {
        if(c>b) return c;
        return b;
    }
}

int worker(/*short unsigned*/int leftfirst,
           /*short unsigned*/int rightend,
           /*short unsigned*/int topfirst,
           /*short unsigned*/int bottomend) {
    //if(q[leftfirst][rightend][topfirst][bottomend])])
    assert(leftfirst >= 0);
    assert(rightend <= n);
    assert(topfirst >= 0);
    assert(bottomend <= n);
    int a, b, c;
    /*short unsigned*/int u;
    if (leftfirst + 1 == rightend) {
        if (topfirst + 1 == bottomend)
            return t[topfirst][leftfirst];
        else if (topfirst + 2 == bottomend) {
            a = t[topfirst][leftfirst];
            b = t[topfirst + 1][leftfirst];
            c = a + b;
            return max(a,b,c);
        } else {
            short unsigned u = (topfirst + bottomend) >> 1;
            a = worker(leftfirst, rightend, topfirst, u);
            b = worker(leftfirst, rightend, u, bottomend);
            c = a + b;
            return max(a,b,c);
        }
    } else if (leftfirst + 2 == rightend) {
        if (topfirst + 1 == bottomend) {
            a = t[topfirst][leftfirst];
            b = t[topfirst][leftfirst + 1];
            c = a + b;
            return max(a, b, c);
        } else {
            u = (topfirst + bottomend) >> 1;
            a = worker(leftfirst, rightend, topfirst, u);
            b = worker(leftfirst, rightend, u, bottomend);
            c = a + b;
            return max(a, b, c);
        }
    } else if (topfirst>=bottomend-2) {
        u = (leftfirst + rightend) >> 1;
        a = worker(leftfirst, u, topfirst, bottomend);
        b = worker(u, rightend, topfirst, bottomend);
        c = a + b;
        return max(a,b,c);
    } else {
        u = (topfirst + bottomend) >> 1;
        a = worker(leftfirst, rightend, topfirst, u);
        b = worker(leftfirst, rightend, u, bottomend);
        c = a + b;
        return max(a,b,c);
    }
}

int main() {
    cin >> n;
    for (short unsigned i = 0; i < n; i++)
        for (short unsigned j = 0; j < n; j++)
            cin >> t[i][j];
    cout << worker(0, n, 0, n) << endl;
}