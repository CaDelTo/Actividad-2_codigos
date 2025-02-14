import time
import random

def generate_matrix(n):
    return [[random.random() for _ in range(n)] for _ in range(n)]

def multiply_matrices(A, B, n):
    C = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C

N = 200
A = generate_matrix(N)
B = generate_matrix(N)

start_time = time.time()
multiply_matrices(A, B, N)
end_time = time.time()

execution_time = int((end_time - start_time) * 1000)
print(f"Python execution time: {execution_time} ms")

with open("results/python_time.txt", "w") as f:
    f.write(str(execution_time))
