import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Main {
    public static void main(String[] args) throws IOException {
        int size = 500;
        int[][] A = new int[size][size];
        int[][] B = new int[size][size];
        int[][] C = new int[size][size];
        Random rand = new Random();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                A[i][j] = rand.nextInt(101);
                B[i][j] = rand.nextInt(101);
            }
        }

        long start = System.currentTimeMillis();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        long end = System.currentTimeMillis();
        long executionTime = end - start;

        // Guardar en results.txt
        FileWriter writer = new FileWriter("/app/results/results.txt", true);
        writer.write("Java " + executionTime + "\n");
        writer.close();

        System.out.println("Tiempo de ejecución (Java): " + executionTime + " ms");
    }
}
