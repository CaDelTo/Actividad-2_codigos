#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 500;

int main() {
    srand(time(0));
    vector<vector<int>> A(SIZE, vector<int>(SIZE));
    vector<vector<int>> B(SIZE, vector<int>(SIZE));
    vector<vector<int>> C(SIZE, vector<int>(SIZE, 0));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 101;
            B[i][j] = rand() % 101;
        }
    }

    clock_t start = clock();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end = clock();
    int executionTime = (end - start) * 1000 / CLOCKS_PER_SEC;

    // Guardar en results.txt
    ofstream file("/app/results/results.txt", ios::app);
    file << "C++ " << executionTime << "\n";
    file.close();

    cout << "Tiempo de ejecución (C++): " << executionTime << " ms" << endl;
    return 0;
}
