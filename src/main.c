#include <stdio.h>

#define BASE 26
#define BASEL 26L
#define N 1000
#define LEN (26L * N) / 3 + 1

unsigned j, predigit, nines, a[LEN], digit;
long x, q, k, len, i;

void output_digit(int d) {
    printf("%c", 'A' + d);
}

int main() {
    int digit = 0;
    for (j=N; j; ) {
	    q = 0;
	    k = LEN + LEN - 1;

	    for (i = LEN; i; i--) {
            x = (j == N ? 2*BASE : BASEL*a[i-1]) + q*i;
            q = x / k;
            a[i-1] = (unsigned)(x-q*k);
            k -= 2;
	    }

	    k = x % BASE;
	    if (k == BASE-1) ++nines;
        else {
            if (j) {
                --j;
                output_digit(predigit+x/BASE);
            }

            for (; nines; --nines) {
                if (j) --j, printf(x >= BASE ? "A" : "Z");
            }

            predigit = (unsigned)k;
	    }
    }
    return 0;
}
