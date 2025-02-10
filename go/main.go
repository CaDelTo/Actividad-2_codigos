package main

import (
	"fmt"
	"os"
)

func multiplyMatrices(A, B [2][2]int) [2][2]int {
	var result [2][2]int
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				result[i][j] += A[i][k] * B[k][j]
			}
		}
	}
	return result
}

func main() {
	A := [2][2]int{{1, 2}, {3, 4}}
	B := [2][2]int{{5, 6}, {7, 8}}
	result := multiplyMatrices(A, B)

	dirPath := "/app/results"
	filePath := dirPath + "/results.txt"

	// Crear directorio si no existe
	if _, err := os.Stat(dirPath); os.IsNotExist(err) {
		err := os.MkdirAll(dirPath, os.ModePerm)
		if err != nil {
			fmt.Println("Error al crear directorio:", err)
			return
		}
	}

	// Crear/abrir archivo y escribir resultado
	file, err := os.OpenFile(filePath, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		fmt.Println("Error al abrir el archivo:", err)
		return
	}
	defer file.Close()

	// Escribir los datos en el archivo
	file.WriteString("Resultado de la multiplicación de matrices:\n")
	for _, row := range result {
		for _, val := range row {
			fmt.Fprintf(file, "%d ", val)
		}
		file.WriteString("\n")
	}
	file.WriteString("\n")
}
