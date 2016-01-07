
/*
 * Replace all spaces in a string with "%20"
 */
int replace_spaces(char* str, int len, char** strout, int * lenout) {

  int count_spaces = 0;
  for(int i=0; i < len; i++) {
    if(str[i] == ' ') {
      count_spaces++;
    }
  }

  *lenout = len + 2 * count_spaces;
  *strout = new char[*lenout];
  int j = 0
  for(int i=0; i < len; i++) {
    if(str[i] == ' ') {
      *strout[j++] = '%';
      *strout[j++] = '2';
      *strout[j++] = '0';
    }
    else {
      *strout[j++] = str[i];
    }
  }

  return count_spaces;
}
