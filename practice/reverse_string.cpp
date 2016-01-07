

int reverse_string(char* chr, int n) {
  //char* output = new char[n];
  int mid = n / 2;
  for(int i=0; i < mid; i++) {
    chr[i] = chr[n-i-2];
  }

  return 1;
}
