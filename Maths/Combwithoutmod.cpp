ll nCr(int n, int r) {
     long double sum=1;
     for(int i = 1; i <= r; i++){
          sum = sum * (n - r + i) / i;
     }
     return sum;
}