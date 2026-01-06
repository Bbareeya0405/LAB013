#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double d[], int N, double B[])
{
    long double sum = 0;
    long double sum_sq = 0;
    long double geo = 1;
    long double harm = 0;

    long double max = d[0], min = d[0];

    for (int i = 0; i < N; i++) {
        sum += d[i];
        sum_sq += d[i] * d[i];
        geo *= d[i];
        harm += 1.0 / d[i];

        if (d[i] > max) max = d[i];
        if (d[i] < min) min = d[i];
    }

    B[0] = sum / N;

    B[1] = sqrt((sum_sq / N) - (B[0] * B[0]));

    B[2] = pow(geo, 1.0 / N);

    B[3] = N / harm;

    B[4] = max;
    B[5] = min;
}
