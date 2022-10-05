def rob(nums):
    length = len(nums)
    
    if length == 0:
        return 0
    money = [None] * (length + 1)
    
    money[0] = 0
    money[1] = nums[0]
    
    for i in range(1, length):
        money[i + 1] = max(money[i], money[i - 1] + nums[i])
        
    return money[length]