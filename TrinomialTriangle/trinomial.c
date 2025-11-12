int trinomial(int a[]) {

}

/*
to do
adds 3 numbers above, (row=n, each row has k entries)
rows are indexed from -k -> k, where |-k| = k
e.g. for nth row (say 4), k spans -3 -> 3 (total of 7 entries)
so k max or min can be expresses as n-1

value of entry in kth spot can be expressed as kpos(n)=kpos-1(n-1)+kpos(n-1)+kpos+1(n-1)
basically for entry k of row n, its the sum of entry k of row n-1 + entry k-1 of row n-1 + entry k+1 of row n-1
      1 a
   2  3  4 b
5  6  7  8  9c

i[7] = i[3]+i[3-1]+i[3+1]

so how do I determine what point 0 is then? 
oh just point 0 = kmax - n or kmin + n
*/