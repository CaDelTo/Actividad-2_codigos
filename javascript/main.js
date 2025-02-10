const fs = require('fs');
const path = "/app/results/results.txt";

// Crear directorio si no existe
if (!fs.existsSync("/app/results")) {
    fs.mkdirSync("/app/results", { recursive: true });
}

// Definir matrices
let A = [
    [1, 2],
    [3, 4]
];
let B = [
    [5, 6],
    [7, 8]
];
let result = [[0, 0], [0, 0]];

// Multiplicación de matrices
for (let i = 0; i < 2; i++) {
    for (let j = 0; j < 2; j++) {
        for (let k = 0; k < 2; k++) {
            result[i][j] += A[i][k] * B[k][j];
        }
    }
}

// Guardar resultado en el archivo
let data = "Resultado de la multiplicación de matrices:\n";
result.forEach(row => {
    data += row.join(" ") + "\n";
});
data += "\n";

fs.appendFileSync(path, data);
