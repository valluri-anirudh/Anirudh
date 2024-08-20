#include <stdio.h>

void main() {
    int np, ps, pt[20], nf, la, pn, index, pa, i, j;
    
    printf("\nEnter number of pages: ");
    scanf("%d", &np);
    
    printf("\nEnter page size: ");
    scanf("%d", &ps);
    
    printf("\nEnter page table: ");
    for(i = 0; i < np; i++)
        scanf("%d", &pt[i]);
    
    printf("\nEnter number of frames: ");
    scanf("%d", &nf);
    
    printf("\nEnter logical address: ");
    scanf("%d", &la);
    
    pn = la / ps;
    index = la % ps;
    pa = (pt[pn] * ps) + index; // Corrected the computation of physical address
    
    printf("\nPhysical address is %d", pa);
}
