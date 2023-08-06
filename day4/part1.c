#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 128

int main(int argc, char **argv) {
  FILE *fptr;
  fptr = fopen(argv[1], "r");
  if (NULL == fptr) {
    printf("Can't open file");
    exit(1);
  }
  char line[MAX_LEN];
  int overlap_pairs = 0;
  int nums[4];
  while (fgets(line, MAX_LEN, fptr)) {
    int tmp = 0;
    int j = 0;
    for (int i = 0; i < strlen(line); i++) {
      if (line[i] == ',' || line[i] == '-' || line[i] == '\n') {
        nums[j] = tmp;
        tmp = 0;
        ++j;
        continue;
      }
      if (tmp != 0)
        tmp *= 10;
      tmp += line[i] - 48;
    }
    if ((nums[0] <= nums[2] && nums[1] >= nums[2]) ||
        (nums[0] <= nums[3] && nums[1] >= nums[3]) ||
        (nums[0] <= nums[2] && nums[1] >= nums[3]) ||
        (nums[0] >= nums[2] && nums[1] <= nums[3])) {
      ++overlap_pairs;
    }
  }
  printf("%d\n", overlap_pairs);
  return 0;
}
