#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>

#ifdef _WIN32
    #include <direct.h>  // Para Windows
    #define MKDIR(path) _mkdir(path)
#else
    #include <unistd.h>  // Para Linux/Mac
    #define MKDIR(path) mkdir(path, 0777)
#endif

void multiplyMatrices(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    multiplyMatrices(A, B, result);

    std::string dirPath = "/app/results";
    std::string filePath = dirPath + "/results.txt";

    // Crear directorio si no existe
    struct stat info;
    if (stat(dirPath.c_str(), &info) != 0) {
        MKDIR(dirPath.c_str());
    }

    // Escribir el archivo
    std::ofstream file(filePath, std::ios::app);
    if (!file) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    file << "Resultado de la multiplicación de matrices:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            file << result[i][j] << " ";
        }
        file << "\n";
    }
    file << "\n";
    file.close();

    return 0;
}
