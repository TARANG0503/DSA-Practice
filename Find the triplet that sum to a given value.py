
def find3Numbers(A, n, X):
    # Your Code Here
    for i in range(n):
        A.sort()
        k=X-A[i]
        l=i
        j=n-1
        while l<j:
            if A[l]+A[j]==k:
                print("Triplet is", A[i],
                      ', ', A[l], ', ', A[j])
                return True
            elif A[l]+A[j]<k:
                l+=1
            else:
                j-=1
    return False


A = [1, 2, 4, 3, 6]
X = 10
n = len(A)

print(find3Numbers(A, n, X))
