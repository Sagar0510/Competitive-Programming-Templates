
string decToBinary(int n){
    string binaryNum;
    int i = 0;
    while (n > 0) {
        binaryNum.pb(n % 2 + '0');
        n = n / 2;
        i++;
    }
    reverse(all(binaryNum));
    return binaryNum; 
}