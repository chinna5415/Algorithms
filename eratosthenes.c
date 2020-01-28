#include <stdio.h>
void eratosthenes(int);

int main() {
    int n;
    printf("enter the range of prime up to n : ");
    scanf("%d",&n);
    eratosthenes(n);

    return 0;
}

void eratosthenes(int n) {
  int prime[n+1];
  for (int i = 0 ; i <= n ; i++)
      prime[i] = 1;

  int p = 2;
  while (p*p <= n) {
    if (prime[p])
       for (int i = p*p ; i < n+1 ; ) {
         prime[i] = 0;
         i += p;
       }
    p++;
  }

  for (int i = 2 ; i < n ; i++)
      if (prime[i])
          printf("%d ",i);
}
