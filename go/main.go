package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

const SIZE = 500

func main() {
	A := make([][]int, SIZE)
	B := make([][]int, SIZE)
	C := make([][]int, SIZE)

	for i := range A {
		A[i] = make([]int, SIZE)
		B[i] = make([]int, SIZE)
		C[i] = make([]int, SIZE)
		for j := range A[i] {
			A[i][j] = rand.Intn(101)
			B[i][j] = rand.Intn(101)
		}
	}

	start := time.Now()
	for i := 0; i < SIZE; i++ {
		for j := 0; j < SIZE; j++ {
			for k := 0; k < SIZE; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}
	elapsed := time.Since(start).Milliseconds()

	// Guardar en results.txt
	file, _ := os.OpenFile("/app/results/results.txt", os.O_APPEND|os.O_WRONLY|os.O_CREATE, 0644)
	defer file.Close()
	fmt.Fprintf(file, "Go %d\n", elapsed)

	fmt.Printf("Tiempo de ejecución (Go): %d ms\n", elapsed)
}
