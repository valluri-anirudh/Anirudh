#include<stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    printf("Memory management Scheme - First Fit");
    printf("\nEnter number of blocks: ");
    scanf("%d", &nb);
    printf("\nEnter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter size of blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter size of files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 1; i <= nf; i++) {
        printf(" %d\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
}
