const fs = require('fs');

function isPrime(n) {
    if (n < 2) return false;
    for (let i = 2; i * i <= n; i++) {
        if (n % i === 0) return false;
    }
    return true;
}

function sumPrimes(limit) {
    let count = 0, num = 2, total = 0;
    while (count < limit) {
        if (isPrime(num)) {
            total += num;
            count++;
        }
        num++;
    }
}

const start = Date.now();
sumPrimes(10000);
const end = Date.now();

console.log(`JS execution time: ${end - start} ms`);
fs.writeFileSync('results/javascript_time.txt', (end - start).toString());
