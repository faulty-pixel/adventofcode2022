#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 128

char *search_common(char *line1, char *line2) {
  char *common = malloc(strlen(line2));
  common[0] = '\0';
  for (int i = 0; i < strlen(line1); i++) {
    char *ch_present;
    ch_present = strchr(line2, line1[i]);
    if (ch_present) {
      char item[2];
      item[1] = '\0';
      item[0] = line1[i];
      strcat(common, item);
    }
  }
  return common;
}

int main(int argc, char **argv) {
  FILE *fptr;
  fptr = fopen(*++argv, "r");
  if (NULL == fptr) {
    printf("Can't open file");
    exit(1);
  }
  char line[MAX_LEN];
  char line1[MAX_LEN];
  int line_num = 0;
  char common[MAX_LEN];
  int priority_sum = 0;
  while (fgets(line, MAX_LEN, fptr)) {
    if (line_num % 3 == 0) {
      strcpy(line1, line);
    } else if (line_num % 3 == 1) {
      strcpy(common, search_common(line1, line));
    } else {
      char gitem;
      gitem = search_common(common, line)[0];
      if (gitem >= 'a') priority_sum += gitem - 'a' + 1;
      else if (gitem <= 'Z') priority_sum += gitem - 'A' + 27;
    }
    line_num += 1;
  }
  printf("%d\n",priority_sum);
}
