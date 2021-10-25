def productExceptSelf(nums, n):

    pre=[1]*n
    suf=[1]*n
    prod=[1]*n
    for i in range(1,n):
        pre[i]=nums[i-1]*pre[i-1]
    for i in range(n-2,-1,-1):
        suf[i]=nums[i+1]*suf[i+1]
    for i in range(0,n):
        prod[i]=pre[i]*suf[i]
    return prod

arr = [10, 3, 5, 6, 2]
n = len(arr)
print("The product array is:")
print(productExceptSelf(arr, n) )