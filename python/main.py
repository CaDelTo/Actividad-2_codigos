import time
import math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def sum_primes(limit):
    count, num, total = 0, 2, 0
    while count < limit:
        if is_prime(num):
            total += num
            count += 1
        num += 1

start_time = time.time()
sum_primes(10000)
end_time = time.time()

execution_time = int((end_time - start_time) * 1000)
print(f"Python execution time: {execution_time} ms")
with open("results/python_time.txt", "w") as f:
    f.write(str(execution_time))
