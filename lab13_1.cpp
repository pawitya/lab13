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
    void stat(const double data[], int n, double result[]) {
    double sum = 0.0, sum_squares = 0.0, product = 1.0, harmonic_sum = 0.0;
    double max_val = data[0], min_val = data[0];
    
    for (int i = 0; i < n; ++i) {
        sum += data[i];
        sum_squares += data[i] * data[i];
        product *= data[i];
        harmonic_sum += 1.0 / data[i];
        
        if (data[i] > max_val) max_val = data[i];
        if (data[i] < min_val) min_val = data[i];
    }
      double mean = sum / n;
    double variance = (sum_squares / n) - (mean * mean);
    double stddev = sqrt(variance);
    double geom_mean = pow(product, 1.0 / n);
    double harmonic_mean = n / harmonic_sum;
    
    result[0] = mean;
    result[1] = stddev;
    result[2] = geom_mean;
    result[3] = harmonic_mean;
    result[4] = max_val;
    result[5] = min_val;
}