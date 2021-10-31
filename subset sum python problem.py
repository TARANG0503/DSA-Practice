def subsetsum(sset, n, s):
    if s == 0:
        return True
    if n == 0:
        return False

    if sset[n - 1] > s:
        return subsetsum(sset, n - 1, s)

    return subsetsum(sset, n - 1, s) or subsetsum(sset, n - 1, s - sset[n - 1])

sset = [13, 34, 65, 12, 43, 1]
s = 77
n = len(sset)
if subsetsum(sset, n, s):
    print("Found a subset with given sum")
else:
    print("No subset with given sum")

