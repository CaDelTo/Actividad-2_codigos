import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Main {
    public static double[][] generateMatrix(int n) {
        double[][] matrix = new double[n][n];
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand.nextDouble();
            }
        }
        return matrix;
    }

    public static double[][] multiplyMatrices(double[][] A, double[][] B, int n) {
        double[][] C = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    public static void main(String[] args) {
        int N = 200; // Tamaño de la matriz
        double[][] A = generateMatrix(N);
        double[][] B = generateMatrix(N);

        long start = System.currentTimeMillis();
        multiplyMatrices(A, B, N);
        long end = System.currentTimeMillis();

        long executionTime = end - start;
        System.out.println("Java execution time: " + executionTime + " ms");

        try (FileWriter writer = new FileWriter("results/java_time.txt")) {
            writer.write(Long.toString(executionTime));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
