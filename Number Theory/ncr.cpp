
vector<vector<int>> ncr(1001,vector<int> (1001)); //upto 1000C1000

void calcncr(){
    ncr[0][0]=1;
    for(int n=0;n<=1000;n++){
        ncr[n][0]=1;
        for(int r=1;r<n;r++) ncr[n][r]=ncr[n-1][r]+ncr[n-1][r-1];
        ncr[n][n]=1;
    }
}
