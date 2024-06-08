import math

arr = [[] for _ in range(1000)]

for i in range(1000):
    arr[i].append(1)

def general(n, k):
    if (k == 0):
        return 1
    
    result = 1

    a = math.comb(n - k - 1, k - 1)

    if (k & 1):
        a *= -1
    
    result = int((a * n) / k)

    return result

def recursive(n, k):
    if k == 0: 
        return 1

    result = 0

    for m in range(k): 
        com = math.comb(n - (2 * m), k - m)
        
        result += com * arr[n][m]

    result *= -1

    arr[n].append(result)
    # arr[n][k] = result

    return result


for n in range(2, 500):
    for k in range(int(n/2) + 1):
        recurs = recursive(n, k)
        gen = general(n, k)

        # print(gen)

        if not recurs == gen:
            print(f'n: {n}, k: {k}')
            break


# for i in range(len(arr)):
#     print(arr[i])

