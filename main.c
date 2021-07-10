#include <stdio.h>
#include <stdlib.h>



int main() {
  int n;
  scanf("%d", & n);
  int peaks[n], maxSeg = 0, top = 0, topSeg, toptemp = 0, topSegtemp = 0, k = 0, t = -1;

  for (int i = 0; i < n; i++) {
    scanf("%d", & peaks[i]);
    maxSeg += peaks[i];

  }
  int mountain[maxSeg];
  char p[maxSeg];
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 0) {
      toptemp -= peaks[i];
      topSegtemp += peaks[i];
      for (k; k < topSegtemp; k++) {
        mountain[k] = t;
        p[k] = '\\';
        t--;
      }
    } else {
      toptemp += peaks[i];
      topSegtemp += peaks[i];
      for (k; k < topSegtemp; k++) {
        t++;
        mountain[k] = t;
        p[k] = '/';
      }
    }
    if (top < toptemp) {
      top = toptemp;
      topSeg = topSegtemp;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < maxSeg; j++) {
      if (j == topSeg) {
        if (i == 0)
          printf("o");
        else if (i == 1)
          printf("|");
        else
          printf(" ");
      } else if (j == topSeg - 1) {
        if (i == 1)
          printf("/");
        else if (i == 2)
          printf("<");
        else
          printf(" ");
      } else if (j == topSeg + 1) {
        if (i == 1)
          printf("\\");
        else if (i == 2)
          printf(">");
        else
          printf(" ");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  for (int i = 0; i < top; i++) {
    for (int j = 0; j < maxSeg; j++) {
      if (i == ((top - 1) - mountain[j]))
        printf("%c", p[j]);
      else
        printf(" ");
      if (j + 1 == topSeg)
        printf(" ");
    }
    printf("\n");
  }
  return 0;
}
