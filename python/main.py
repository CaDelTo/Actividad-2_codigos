import os

# Crear el directorio si no existe
results_dir = "/app/results"
os.makedirs(results_dir, exist_ok=True)

# Definir las matrices
A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
B = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]

# Verificar que se pueden multiplicar
rows_A, cols_A = len(A), len(A[0])
rows_B, cols_B = len(B), len(B[0])

if cols_A != rows_B:
    raise ValueError("No se pueden multiplicar estas matrices")

# Inicializar la matriz resultado con ceros
C = [[0 for _ in range(cols_B)] for _ in range(rows_A)]

# Multiplicación de matrices
for i in range(rows_A):
    for j in range(cols_B):
        for k in range(cols_A):
            C[i][j] += A[i][k] * B[k][j]

# Guardar en archivo
result_path = os.path.join(results_dir, "results.txt")
with open(result_path, "w") as f:
    for row in C:
        f.write(" ".join(map(str, row)) + "\n")

print(f"Resultado guardado en {result_path}")
