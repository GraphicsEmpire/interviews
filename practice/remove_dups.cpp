
/*
 *  Design an algorithm and write code to remove the duplicate characters in a
 * string without using any additional buffer.
 * NOTE: One or two additional variables are fine. An extra copy of the array
 * is not.
 */

int remove_dups(char* str, int len) {
  bool usage[256];

  memset(&usage, 0, sizeof(usage));

  int j = 0;
  for(int i = 0; i < len; i++) {
    char cur = str[i];
    if(!usage[cur]) {
      usage[cur] = true;
      str[j] = cur;
      j++;
    }
  }

  //new length of the string
  return j;
}
