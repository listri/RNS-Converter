#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int c = 32;
int M;
int N;
int mikro;
int s;
int X;
double final;
double XS;

vector <int> x;
vector <int> xp;
vector <int> m = { 3, 5, 7 };
vector <int> w;
vector <int> wp;
vector <double> y;
vector <double> yp;

void get_XRNS() {
    for (int i = 0; i < m.size(); i++)
        x.push_back(X % m[i]);
}

void calc_M() {
    M = 1;
    for (int i = 0; i < m.size(); i++)
        M *= m[i];
}

void calc_N() {
    N = ceil(log2(M * mikro) - 1);
}

void calc_mikro() {
    mikro = 0;
    for (int i = 0; i < m.size(); i++)
        mikro += m[i] - 1;
}

void multiplicative_inverse() {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 1; /*j < 100*/; j++) {
            if (((M / m[i]) * j) % m[i] == 1) {
                w.push_back(j);
                break;
            }
        }
        for (int j = 1; /*j < 100*/; j++) {
            if (((c * w[i]) * j) % m[i] == 1) {
                wp.push_back(j);
                break;
            }
        }
    }
}

void calc_xp() {
    for(int i = 0; i < x.size(); i++)
        xp.push_back((c * x[i]) % m[i]);
 }

void calc_y() {
    for(int i = 0; i < wp.size(); i++) {
        y.push_back((2./m[i]) * wp[i]);
        yp.push_back(ceil(pow(2.,s) * y[i]) * pow(2., -s));
    }
}

void calc_XS() {
    XS = 0;
    for(int i = 0; i < yp.size(); i++) {
        XS += yp[i]*xp[i];
    }
    if(XS >= 2 && XS / 2 == 0)
        XS = XS - floor(XS);
    else if (XS > 2 && XS / 2 != 0)
        XS = XS - floor(XS) + 1;
}

void calc_X() {
    final = floor(M / 2. * XS);
}

void printInfo();
void printValues();

int main() {


    calc_M();
    calc_mikro();
    calc_N();
    s = N + 1;

    multiplicative_inverse();
    calc_y();

    // jak chcesz zeby liczyło pojedynczego iksa i zeby wyswietlilo wszystkie dane to tylko zakomentuj for'a i odkomentuj reszte
    for (int i = 0; i < M; i++) {
        X = i;
        get_XRNS();
        calc_xp();
        calc_XS();
        calc_X();

        cout << "X[" << i << "]: " << final << endl;
        x.clear();
        xp.clear();
    }
    //calc_XS();
    //calc_X();
    //printInfo();
    //printValues();

    return 0;
}

void printInfo() {
    cout << "Baza = { ";
    for(int i =0; i < m.size(); i++)
        cout <<  m[i] << " ";
    cout << "}" << endl;

    cout << "X = { ";
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] <<" ";
    }
    cout << "}" << endl;

    cout << "M: " << M << endl;
    cout << "s: " << s << endl;
}

void printValues() {
    cout << "xp = { ";
    for(int i =0; i < xp.size(); i++)
        cout <<  xp[i] << " ";
    cout << "}" << endl;

    cout << "w = { ";
    for(int i =0; i < w.size(); i++)
        cout <<  w[i] << " ";
    cout << "}" << endl;

    cout << "wp = { ";
    for(int i =0; i < wp.size(); i++)
        cout <<  wp[i] << " ";
    cout << "}" << endl;

    cout << "y = { ";
    for(int i =0; i < y.size(); i++)
        cout <<  y[i] << " ";
    cout << "}" << endl;

    cout << "yp = { ";
    for(int i =0; i < yp.size(); i++)
        cout <<  yp[i] << " ";
    cout << "}" << endl;

    cout << "XS = " << XS << endl;
    cout << "X = " << final << endl;

}