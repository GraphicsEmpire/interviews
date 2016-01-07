/*
* Write an algorithm that check if two strings are anagrams
*/

bool is_anagram(char* str1, int n1, char* str2, int n2) {
  if(n1 != n2)
    return false;
  if(n1 < 2 || str1 == NULL || str2 == NULL)
    return false;

  int hit[256];
  for(int i=0; i < 256; i++)
    hit[i] = 0;

  for(int i=0; i < n1; i++) {
    char c = str[i];
    hit[c]++;
  }

  for(int i=0; i < n2; i++) {
    char c = str[i];
    hit[c]--;
  }

  for(int i=0; i < 256; i++) {
    if(hit[i] != 0)
      return false;
  }

  return true;
}
