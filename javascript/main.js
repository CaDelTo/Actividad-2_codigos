const fs = require('fs');

function generateMatrix(n) {
    return Array.from({ length: n }, () => 
        Array.from({ length: n }, () => Math.random())
    );
}
function multiplyMatrices(A, B, n) {
    let C = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

const N = 200;
const A = generateMatrix(N);
const B = generateMatrix(N);

const start = Date.now();
multiplyMatrices(A, B, N);
const end = Date.now();

console.log(`JS execution time: ${end - start} ms`);
fs.writeFileSync('results/javascript_time.txt', (end - start).toString());
