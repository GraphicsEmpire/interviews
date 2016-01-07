/*
 * Given an image represented by an NxN matrix, where each pixel in the image
 * is 4 bytes, write a method to rotate the image by 90 degrees.
 */
 struct RGBA {
   char r;
   char g;
   char b;
   char a;
 };

 int rotate90(int n, RGBA** input) {
   RGBA** output = new RGBA*[n];
   for(int i=0; i<n; i++) {
     output[i] = new RGBA[n];
   }

   int oc = 0;
   int or = 0;

   //loop over input rows from end to start
   for(int r=n-1; r >= 0; r--) {
     //reset to first row of output matrix
     or = 0;
     for(int c=0; c < n; c++) {
       output[or][oc] = input[r][c];
       or++;
     }
     oc ++;
   }

   memcpy(input, output, n*n * sizeof(RGBA));

   return 1;
 }
