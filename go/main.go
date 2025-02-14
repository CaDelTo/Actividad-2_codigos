package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

func generateMatrix(n int) [][]float64 {
	matrix := make([][]float64, n)
	for i := range matrix {
		matrix[i] = make([]float64, n)
		for j := range matrix[i] {
			matrix[i][j] = rand.Float64()
		}
	}
	return matrix
}

func multiplyMatrices(A, B [][]float64, n int) [][]float64 {
	C := make([][]float64, n)
	for i := range C {
		C[i] = make([]float64, n)
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}
	return C
}

func main() {
	const N = 200
	rand.Seed(time.Now().UnixNano())

	A := generateMatrix(N)
	B := generateMatrix(N)

	start := time.Now()
	multiplyMatrices(A, B, N)
	duration := time.Since(start)

	fmt.Println("Go execution time:", duration.Milliseconds(), "ms")

	file, _ := os.Create("results/go_time.txt")
	defer file.Close()
	file.WriteString(strconv.FormatInt(duration.Milliseconds(), 10))
}
