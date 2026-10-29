#include <stdio.h>
#include <math.h>

// Helper function to count the number of digits in a number
int getLength(long long number) {
    int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

// The Karatsuba Multiplication Function
long long karatsuba(long long x, long long y) {
    // Base Case: If the numbers are small (single digits), just multiply them normally
    if (x < 10 || y < 10) {
        return x * y;
    }

    // 1. Calculate the size of the numbers
    int xLength = getLength(x);
    int yLength = getLength(y);
    
    // Find the maximum length and split point (N / 2)
    int n = (xLength > yLength) ? xLength : yLength;
    int halfN = n / 2;

    // A multiplier value like 10^(N/2)
    long long multiplier = (long long)pow(10, halfN);

    // 2. Split the numbers into halves: x = (a * multiplier) + b,  y = (c * multiplier) + d
    long long a = x / multiplier; // Left half of x
    long long b = x % multiplier; // Right half of x
    long long c = y / multiplier; // Left half of y
    long long d = y % multiplier; // Right half of y

    // 3. The 3 Recursive Multiplications (The core Karatsuba magic)
    long long ac = karatsuba(a, c);               // Step 1: Multiply left halves
    long long bd = karatsuba(b, d);               // Step 2: Multiply right halves
    long long ab_cd = karatsuba(a + b, c + d);    // Step 3: Multiply the sums of halves

    // 4. Combine the results using the Karatsuba formula:
    // Result = ac * 10^(2*halfN) + (ab_cd - ac - bd) * 10^(halfN) + bd
    long long middleTerm = ab_cd - ac - bd;
    
    long long result = (ac * (long long)pow(10, 2 * halfN)) + (middleTerm * multiplier) + bd;

    return result;
}

int main() {
    long long num1 = 1234;
    long long num2 = 5678;

    printf("--- Karatsuba Multiplication ---\n");
    printf("Multiplying: %lld * %lld\n", num1, num2);

    long long expected = num1 * num2;
    long long actual = karatsuba(num1, num2);

    printf("Standard C Result:  %lld\n", expected);
    printf("Karatsuba Result:   %lld\n", actual);

    return 0;
}
