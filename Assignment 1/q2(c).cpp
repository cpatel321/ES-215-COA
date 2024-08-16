// q2(c).cpp

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

//matrix product function 
void multiplyMatrices(vector<vector<int>>& A,vector<vector<int>>&B, vector<vector<int>>&C, int N) {
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
    int N = 1024; //{64, 128, 256, 512, 1024};

    vector<vector<int>> A(N, vector<int>(N, 1.0));
    vector<vector<int>> B(N, vector<int>(N, 1.0));
    vector<vector<int>> C(N, vector<int>(N, 0.0));

    auto start = high_resolution_clock::now();
    multiplyMatrices(A, B, C, N);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Matrix size: " << N << "x" << N << ", Meat Time taken: " << duration.count() << " ms" << endl;
    return 0;
}
