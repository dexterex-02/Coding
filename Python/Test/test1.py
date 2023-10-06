import math

def count_pairs_with_gcd(I, x):
    count = 0
    for a in range(1, I+1):
        for b in range(a, I+1):
            if math.gcd(a, b) == x:
                count += 1
    return count

# Read input values
I, x = map(int, input().split())

# Calculate and print the result
result = count_pairs_with_gcd(I, x)
print(result)