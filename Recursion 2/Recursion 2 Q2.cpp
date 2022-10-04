int countDistinctWayToClimbStair(long long nStairs)
{
    if(nStairs < 0)
    {
        return 0;
    }
    
    if(nStairs == 0)
    {
        return 1;
    }
    
    return countDistinctWayToClimbStair(nStairs - 1) + countDistinctWayToClimbStair(nStairs - 2);
}