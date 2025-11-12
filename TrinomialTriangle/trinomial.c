#include "header.h"
#include <stdio.h>

unsigned int* trinomial(int rows) {
    static unsigned int a[100] = { 1 };
    int current_row = 0;
    int arr_pos = 0;
    int plus2 = 2;
    
    for (int i = 0; i <= rows; i++) {
        int max = current_row - 1;
        int min = max * -1;

        if (arr_pos - plus2 + 1 >= 100) {
            return 0;
        }

        for (int k = min; k <= max; k++) {
            if (k <= min || k >= max) {
                a[arr_pos] = 1;
            }
            if (k == min+1) {
                a[arr_pos] = a[arr_pos - plus2] + a[arr_pos - plus2 + 1];
            }
            if (k == max - 1) {
                a[arr_pos] = a[arr_pos - plus2 - 1] + a[arr_pos - plus2];
            }
            else {
                a[arr_pos] = a[arr_pos-plus2-1] + a[arr_pos - plus2] + a[arr_pos - plus2+1];
            }
            printf("%3d", a[arr_pos]);
            arr_pos++;
        }
        plus2 += 2;
        current_row++;
        printf("\n");
    }
    return a;
}

/*
to do
adds 3 numbers above, (row=n, each row has k entries)
rows are indexed from -k -> k, where |-k| = k
e.g. for nth row (say 4), k spans -3 -> 3 (total of 7 entries)
so k max or min can be expresses as n-1

value of entry in kth spot can be expressed as kpos(n)=kpos-1(n-1)+kpos(n-1)+kpos+1(n-1)
basically for entry k of row n, its the sum of entry k of row n-1 + entry k-1 of row n-1 + entry k+1 of row n-1
              |1 | 
         |2   |3 |  |4 
     |5  |6   |7 |  |8   |9
10   |11 |12  |13|  |14  |15  16
i[7] = i[3]+i[3-1]+i[3+1]

actually the middle values position is always greater than the position below by an additional 2 each row
taking the middle 1->3->7->13->21->31 1+2=3 3+4=7 7+6=13 13+8=21
this ordered difference pattern is also seen on the outer positions although slightly varied

so how do I determine what point 0 is then? 
oh just point 0 = kmax - n or kmin + n
*/
//I could maybe look to clear unneeded values in the array as a challenge