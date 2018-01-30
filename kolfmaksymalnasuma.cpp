//
// Created by mf on 30.01.18.
//

#include <iostream>
#include <cassert>
//#include <sys/resource.h>

using namespace std;

/*short unsigned*/ int n;
short int t[100][100];
//bool q[101][101][101][101];
//int qb[101][101][101][101];

int max(int a, int b, int c) {
    if (a > b) {
        if (c > a) return c;
        return a;
    } else {
        if (c > b) return c;
        return b;
    }
}
int max(int a, int b, int c, int d, int e) {
    return max(max(a,b,c),d,e);
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
    int a, b, c, d, e;
    /*short unsigned*/int u;
    if (leftfirst + 1 == rightend) {
        if (topfirst + 1 == bottomend)
            return t[topfirst][leftfirst];
        else if (topfirst + 2 == bottomend) {
            a = t[topfirst][leftfirst];
            b = t[topfirst + 1][leftfirst];
            c = a + b;
            return max(a, b, c);
        } else {
            e=0;
            for(int i=topfirst;i<bottomend;i++)
                e+=t[i][leftfirst];
            a = worker(leftfirst,rightend,topfirst+1,bottomend);
            b = worker(leftfirst,rightend,topfirst,bottomend-1);
            return max(a,b,e);
        }
    } else if (topfirst + 1 == bottomend) {
        if (leftfirst + 2 == rightend) {
            a = t[topfirst][leftfirst];
            b = t[topfirst][leftfirst + 1];
            c = a + b;
            return max(a, b, c);
        } else {
            e=0;
            for(int j=leftfirst;j<rightend;j++)
                e+=t[topfirst][j];
            a = worker(leftfirst+1,rightend,topfirst,bottomend);
            b = worker(leftfirst,rightend-1,topfirst,bottomend);
            return max(a,b,e);
        }
    }
    e = 0;
    for (int i = topfirst; i < bottomend; i++)
        for (int j = leftfirst; j < rightend; j++)
            e += t[i][j];
    a = worker(leftfirst+1,rightend,topfirst,bottomend);
    b = worker(leftfirst,rightend-1,topfirst,bottomend);
    c = worker(leftfirst,rightend,topfirst+1,bottomend);
    d = worker(leftfirst,rightend,topfirst,bottomend-1);
    return max(a,b,c,d,e);
}

int main() {
//    const rlim_t kStackSize = 16 * 1024 * 1024;
//    struct rlimit rl;
//    int result;
//    if (result == 0) {
//        if (rl.rlim_cur < kStackSize) {
//            rl.rlim_cur = kStackSize;
//            setrlimit(RLIMIT_STACK, &rl);
//        }
//    }
    cin >> n;
    for (short unsigned i = 0; i < n; i++)
        for (short unsigned j = 0; j < n; j++)
            cin >> t[i][j];
    cout << worker(0, n, 0, n) << endl;
}