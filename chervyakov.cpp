#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int mikro;
int M;
int N;
int X = 12;
int final;
int XP;
vector<int> base = { 3,5,7 };
vector <int> x;
vector<double> k;
vector<double> kp;

void get_XRNS() {
    for (int i = 0; i < base.size(); i++) {
        x.push_back(X%base[i]);
    }
}

void calc_M() {
    int temp = 1;
    for (int i = 0; i < base.size(); i++) {
        temp *= base[i];
    }
    M = temp;
}

void calc_N() {
    N = ceil(log2(M *mikro) - 1);
}

void calc_mikro() {
    int temp = 0;
    for (int i = 0; i < base.size(); i++) {
        temp += base[i] - 1;
    }
    mikro = temp;
}

void multiplicative_inverse() {
    for (int i = 0; i < base.size(); i++) {
        for (int j = 1; ; j++) {
            if (((M / base[i]) * j) % base[i] == 1) {
                k.push_back((double)j / base[i]);
                kp.push_back(floor(k[i] * pow(2, N) + 1));
                break;
            }
        }
    }
}

void calc_X() {
    final = XP * M / pow(2, N);
}

void calc_XP() {
    for (int i = 0; i < x.size(); i++) {
        XP += x[i] * kp[i];
    }
    XP = XP % int(pow(2, N));
}

void printInfo() {
    cout << "Baza = { ";
    for(int i =0; i < base.size(); i++)
        cout <<  base[i] << " ";
    cout << "}" << endl;

    cout << "M: " << M << endl;
    cout << "N: " << N << endl;
    cout << "Mikro: " << mikro << endl;
}

void printValues() {
    for (int i = 0; i < k.size(); i++) {
        cout << "k[" << i << "]: " << k[i] << endl;
        cout << "kp[" << i << "]: " << kp[i] << endl;
    }

    cout << "X = { ";
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] <<" ";
    }
    cout << "}" << endl;

    cout << "XP = " << XP << endl;
    cout << "X = " << final << endl;
}

int main() {
    calc_M();
    calc_mikro();
    calc_N();

    multiplicative_inverse();
    //getXRNS();
    //calcXP();
    //calcX();
    //printInfo();
    //printValues();

    for (int i = 0; i < M; i++) {
        X = i;
        get_XRNS();
        calc_XP();
        calc_X();
        cout << "X: " << X << " = " << final << endl;

        x.clear();
        XP = 0;
    }

    return 0;
}