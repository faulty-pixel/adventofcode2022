#include <stdio.h>
#include <stdlib.h>
#define LINE_LEN 4

int main() {
  FILE *fptr;
  fptr = fopen("input", "r");
  if (NULL == fptr) {
    printf("File can't be opened");
    exit(1);
  }
  char line[LINE_LEN];
  int points = 0;
  int tmp = 0;
  int res = 0;
  int hand = 0;
  while (fgets(line, LINE_LEN, fptr)) {
    if (line[0] < 'A' || line[0] > 'C') {
      tmp = 0;
      continue;
    }
    if (line[2] < 'X' || line[2] > 'Z') {
      tmp = 0;
      continue;
    }
    res = (line[2] - 'X');
    points += res * 3;
    hand = line[0] - 'A' + 1;
    // Draw
    if (res == 1)
      points += hand;
    // Win
    else if (res == 2) {
        if (hand == 3) points += 1;
        else points += hand +1;
    }
    else {
        if (hand == 1) points += 3;
        else points += hand -1;
    }
  }
  printf("%d\n", points);
  fclose(fptr);
  return 0;
}
