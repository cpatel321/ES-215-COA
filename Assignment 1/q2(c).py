import numpy as np
import time

def multiply_matrices(A, B, N):
    C = np.zeros((N, N), dtype=int)
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C

N = 1024#[64, 128, 256, 512, 1024]
A = np.ones((N, N), dtype=int)
B = np.ones((N, N), dtype=int)

start_time = time.time()
C = multiply_matrices(A, B, N)
end_time = time.time()

duration = (end_time - start_time) * 1000  

print(f"Matrix size: {N}x{N}, Time taken: {duration:.2f} ms")