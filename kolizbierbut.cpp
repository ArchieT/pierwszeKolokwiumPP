#include <iostream>

using namespace std;

unsigned int pozostale(unsigned int n) {
    unsigned int zostawione = n%3;
    unsigned int wymienione = n - zostawione;
    unsigned int wymna = wymienione/3;
    return wymna + (zostawione+wymna>2 ? pozostale(zostawione+wymna) : 0);
}

int main() {
    unsigned int nzakupionych;
    cin >> nzakupionych;
    unsigned int wyjscie = nzakupionych+pozostale(nzakupionych);
    cout << wyjscie << endl;
    return 0;
}
