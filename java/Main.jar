import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        int[][] A = {{1, 2}, {3, 4}};
        int[][] B = {{5, 6}, {7, 8}};
        int[][] result = new int[2][2];

        // Multiplicación de matrices
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // Ruta del archivo
        String filePath = "/app/results/results.txt";
        File file = new File(filePath);

        try {
            // Crear directorio si no existe
            file.getParentFile().mkdirs();
            // Crear el archivo si no existe
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter writer = new FileWriter(file, true);
            writer.write("Resultado de la multiplicación de matrices:\n");
            for (int[] row : result) {
                for (int val : row) {
                    writer.write(val + " ");
                }
                writer.write("\n");
            }
            writer.write("\n");
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
