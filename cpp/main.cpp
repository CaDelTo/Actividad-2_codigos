#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>

using namespace std;

// Función para generar una matriz aleatoria de tamaño N x N
vector<vector<double>> generate_matrix(int n) {
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX; // Números aleatorios entre 0 y 1
        }
    }
    return matrix;
}

// Función para multiplicar dos matrices de tamaño N x N
vector<vector<double>> multiply_matrices(const vector<vector<double>>& A, const vector<vector<double>>& B, int n) {
    vector<vector<double>> C(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    const int N = 200; // Tamaño de la matriz
    srand(time(0));

    vector<vector<double>> A = generate_matrix(N);
    vector<vector<double>> B = generate_matrix(N);

    auto start = chrono::high_resolution_clock::now();
    multiply_matrices(A, B, N);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "C++ execution time: " << duration << " ms" << endl;

    ofstream file("results/cpp_time.txt");
    file << duration;
    file.close();

    return duration;
}
