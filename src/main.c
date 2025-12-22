#include <stdio.h>

#define BASE 26
#define BASEL 26L

#define N 50000
#define LEN (26L * N) / 3 + 1

unsigned j, predigit, nines, a[LEN], digit;
long x, q, k, len, i;
FILE *fptr;

void output_digit(FILE *fptr, int d) {
    fprintf(fptr, "%c", 'A' + d);
}

int main() {
    fptr = fopen("pi.txt", "w");

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
                output_digit(fptr, predigit+x/BASE);
            }

            for (; nines; --nines) {
                if (j) --j, fprintf(fptr, x >= BASE ? "A" : "Z");
            }

            predigit = (unsigned)k;
	    }

        if (j % 500 == 0) printf("%d%%\n", (N-j)*100/N);
    }
    
    fclose(fptr);
    printf("\n");

    return 0;
}
