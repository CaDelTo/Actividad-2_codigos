const fs = require("fs");

const SIZE = 500;
let A = Array.from({ length: SIZE }, () =>
  Array.from({ length: SIZE }, () => Math.floor(Math.random() * 101))
);
let B = Array.from({ length: SIZE }, () =>
  Array.from({ length: SIZE }, () => Math.floor(Math.random() * 101))
);
let C = Array.from({ length: SIZE }, () => Array(SIZE).fill(0));

const start = Date.now();
for (let i = 0; i < SIZE; i++) {
  for (let j = 0; j < SIZE; j++) {
    for (let k = 0; k < SIZE; k++) {
      C[i][j] += A[i][k] * B[k][j];
    }
  }
}
const end = Date.now();
const executionTime = end - start;

// Guardar en results.txt
fs.appendFileSync("/app/results/results.txt", `JavaScript ${executionTime}\n`);

console.log(`Tiempo de ejecución (JavaScript): ${executionTime} ms`);
