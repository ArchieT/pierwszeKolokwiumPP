#include <iostream>
#include <iomanip>

using namespace std;

//typedef unsigned long long long long int lo;
short unsigned last = 13;
bool pier[100];
short unsigned memo[100][100];

bool gp(short unsigned int p) {
    while(last<p) {
        ++last;
        pier[last]=true;
        for(short unsigned i=2;i<last;i++)
            if(pier[i] && last%i==0) {
                pier[last] = false;
                break;
            }
    }
    return pier[p];
}

void worker(short unsigned in, ostream &o) {
    cout << setw(3) << in << "! =" << endl;
    short unsigned cur = 2;
    for(;cur<in;)
}

int main() {
    pier[0]=false;
    pier[1]=false;
    pier[2]=true;
    pier[3]=true;
    pier[4]=false;
    pier[5]=true;
    pier[6]=false;
    pier[7]=true;
    pier[8]=false;
    pier[9]=false;
    pier[10]=false;
    pier[11]=true;
    pier[12]=false;
    pier[13]=true;
    short unsigned in;
    do cin >> in; while (in!=0);
    return 0;
}
