vector<vll> ncr(1001,vll (1001)); //upto 1000C1000

void calcncr(){
    ncr[0][0]=1;
    rep(n,0,1001){
        ncr[n][0]=1;
         rep(r,1,n) ncr[n][r]=ncr[n-1][r]+ncr[n-1][r-1];
        ncr[n][n]=1;
    }
}
