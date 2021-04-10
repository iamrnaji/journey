int solve(int n) {
    int i = 1;
    int sum = 0;
    for(int j = 1; j <= n; j++)
    {
        
        sum += i;
        i += 2;
    }

    return sum;
}
