#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 128

int main(int argc, char **argv) {
  FILE *fptr;
  fptr = fopen(*++argv, "r");
  if (NULL == fptr) {
    printf("Can't open file");
    exit(1);
  }
  char line[MAX_LEN];
  int scan_len = 0;
  int priority_sum = 0;
  while (fgets(line, MAX_LEN, fptr)) {
    scan_len = strlen(line) / 2;
    char second_compartment[MAX_LEN / 2] = "";
    strncpy(second_compartment, line + scan_len, MAX_LEN / 2);
    char *item;
    for (int i = 0; i < scan_len; i++) {
      item = strchr(second_compartment, line[i]);
      if (item) {
          if (line[i] >= 'a') priority_sum += line[i] - 'a' + 1;
          else if (line[i] <= 'Z') priority_sum += line[i] - 'A' + 27;
          break;
      }
    }
  }
  printf("%d\n",priority_sum);
}
