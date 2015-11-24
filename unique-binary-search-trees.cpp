int numTrees(int n) {
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    if(n==2)
    return 2;
    int ret=0;
    for(int i=1;i<=n;i++)
    {   
        if(i==1||i==n)
        ret=ret+numTrees(n-1);
        else
        {
        ret=ret+numTrees(i-1)*numTrees(n-i);
        }
    }
    return ret;
}