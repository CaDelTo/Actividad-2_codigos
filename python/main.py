import time
import random

size = 500
A = [[random.randint(0, 100) for _ in range(size)] for _ in range(size)]
B = [[random.randint(0, 100) for _ in range(size)] for _ in range(size)]
C = [[0] * size for _ in range(size)]

start = time.time()
for i in range(size):
    for j in range(size):
        C[i][j] = sum(A[i][k] * B[k][j] for k in range(size))
end = time.time()

execution_time = int((end - start) * 1000)
print(execution_time)
