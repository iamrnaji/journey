bool solve(int n) {
    
    int number = n;
    int count = 0;
    while(number != 0)
    {
        number = number / 10;
        count++;
    }

    number = n;
    int digit  = 0;
    vector<int> j;

    while(number != 0)
    {
        j.push_back(number % 10);
        number = number / 10;
    }

    int sum = 0;

    for(int i = 0; i < j.size(); i++)
    {
        sum += pow(j[i], count);
    }

    if(sum == n)
    {
        return true;

    }
    else
    {
        return false;
    }
}
