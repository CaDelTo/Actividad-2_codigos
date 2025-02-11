import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void sumPrimes(int limit) {
        int count = 0, num = 2, total = 0;
        while (count < limit) {
            if (isPrime(num)) {
                total += num;
                count++;
            }
            num++;
        }
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        sumPrimes(10000);
        long end = System.currentTimeMillis();
        
        System.out.println("Java execution time: " + (end - start) + "ms");
        try (FileWriter writer = new FileWriter("results/java_time.txt")) {
            writer.write(Long.toString(end - start));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
