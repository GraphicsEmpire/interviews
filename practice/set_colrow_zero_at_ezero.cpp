/*
 * Write an algorithm such that if an element in an MxN matrix is 0,
 * its entire row and column is set to 0.
 */
int zero_row_col(int matrix[][], int m, int n) {

  vector<pair<int,int>> zero_coords;
  for(int r = 0; r < m; r++) {
    for(int c = 0; c < n; c++) {
      int e = matrix[r][c];
      if(e == 0) {
        zero_coords.push_back(std::make_pair(r, c));
      }
    }
  }

  for(int i=0; i < zero_coords.size(); i++) {
    nr = zero_coords[i].first();
    nc = zero_coords[i].second();

    for(int c = 0; c < n; c++)
       matrix[nr][c] = 0;

    for(int r = 0; r < m; r++)
       matrix[r][nc] = 0;
  }

  return zero_coords.size();
}
