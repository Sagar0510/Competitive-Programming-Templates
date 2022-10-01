
vector<vector<int>> prefixSum2D(int n,int m,vector<vector<int>>& a) {
    vector<vector<int>> psa(n,vector<int> (m));
    psa[0][0] = a[0][0];
  
    for (int i = 1; i < m; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < n; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];
 
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + a[i][j];
 
    return psa;
}
