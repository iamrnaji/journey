bool solve(string s) {
    
    string holder = "";
    int size = s.size() - 1;
    while(!(holder.size() == s.size()))
    {
        holder+= s[size];
        size--;
    }
    if(holder == s)
    {
        return true;

    }
    else
    {
        return false;
    }
}
