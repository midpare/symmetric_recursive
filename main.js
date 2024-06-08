const arr = Array.from(new Array(51), () => new Array(51).fill(0));

for (let n = BigInt(2); n <= 50; n++) {
    for (let k = BigInt(0); k <= (n / BigInt(2)); k++) {
        const recurs = recursive(n, k);
        const gen = general(n, k);

        // if (recurs != gen) {
        //     console.log(`n: ${n}, k: ${k}`)
        // }
    }
}

console.log(arr)

function general(n, k) {
    if (k == 0) {
        return 1;
    }

    let result = BigInt(1);

    let a = BigInt(1);

    for (let i = BigInt(1); i <= k; i++) {
        a *= i;
    }

    let b = BigInt(1);
    for (let i = BigInt(1); i < k; i++) {
        b *= (n - (k + i));
    }

    if (k % BigInt(2) == 1) {
        result *= BigInt(-1);
    }

    result *= (b * n) / a;

    return result;
}

function recursive(n, k)
{
    if (k == 0) {
        return 1;
    }

    let result = BigInt(1);

    for (let m = BigInt(1); m < k; m++) {
        let com = combination(n - (BigInt(2) * m), k - m);
        
        result += com * arr[n][m];
    }

    result *= BigInt(1);

    arr[n][k] = result;

    return result;
}

function combination(n, r)
{
    let a = BigInt(1);
    let b = BigInt(1);

    for (let i = BigInt(0); i < r; i++) {
        a *= n - i;
    }

    for (let i = BigInt(1); i <= r; i++) {
         b *= i;
    }

    return a / b;
}

