// q2(a-double).cpp

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

//matrix product function 
void multiplyMatrices(vector<vector<double>>& A,vector<vector<double>>&B, vector<vector<double>>&C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    for (int N : sizes) {
        vector<vector<double>> A(N, vector<double>(N, 1.0));
        vector<vector<double>> B(N, vector<double>(N, 1.0));
        vector<vector<double>> C(N, vector<double>(N, 0.0));
        auto start = high_resolution_clock::now();
        multiplyMatrices(A, B, C, N);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Matrix size: " << N << "x" << N << ", Time taken: " << duration.count() << " ms" << endl;
    }
    return 0;
}
