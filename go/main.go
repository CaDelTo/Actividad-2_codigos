package main

import (
	"os"
	"strconv"
	"time"
)

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func sumPrimes(limit int) {
	count, num := 0, 2
	for count < limit {
		if isPrime(num) {
			count++
		}
		num++
	}
}

func main() {
	start := time.Now()
	sumPrimes(10000)
	duration := time.Since(start)

	println("Go execution time:", duration, "ms")
	file, _ := os.Create("results/go_time.txt")
	defer file.Close()
	file.WriteString(strconv.FormatInt(duration.Milliseconds(), 10))
}
