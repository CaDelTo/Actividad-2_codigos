import numpy as np
import os

# Definir matrices
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])

# Multiplicación de matrices
resultado = np.dot(A, B)

# Ruta del archivo
file_path = "/app/results/results.txt"

# Crear directorio si no existe
os.makedirs(os.path.dirname(file_path), exist_ok=True)

# Escribir el resultado
with open(file_path, "a") as f:
    f.write("Resultado de la multiplicación de matrices:\n")
    np.savetxt(f, resultado, fmt="%d")
    f.write("\n")
