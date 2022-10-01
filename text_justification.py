# Dynamic Programming implementation of text justification problem

def minimum(l):
    m = 2**64-1
    ind = 0

    for i in range(len(l)):
        if m > l[i]:
            m = l[i]
            ind = i

    return m, ind


text = input().split(' ')
width = int(input())

n = len(text)
size = []

weight = [[0 for i in range(n)] for j in range(n)]

for i in text:
    size.append(len(i))

for i in range(n):

    for j in range(n):

        if i == j:
            weight[i][j] = (width-size[i])**2
        elif i > j:
            weight[i][j] = 0
        else:
            s = 0
            a = 0
            for k in range(i, j+1):
                s += size[k]
                a += 1
            if s > width:
                weight[i][j] = 'inf'
            else:
                weight[i][j] = (width-s-(a-1))**2

cost = [0 for i in range(n)]
order = [0 for i in range(n)]
l = []

i = j = n-1

while i >= 0:

    if i == j:
        cost[i] = weight[i][j]
        order[i] = j
        i -= 1
    else:
        if weight[i][j] != 'inf':
            cost[i] = weight[i][j]
            order[i] = j
            i -= 1
        else:
            l = [0 for p in range(j-i)]
            for k in range(j, i, -1):
                if weight[i][k-1] == 'inf':
                    l[k-(i+1)] = 2**64-1
                else:
                    l[k-(i+1)] = weight[i][k-1]+cost[k]

            m, ind = minimum(l)
            x = len(l)-ind
            ind = j-x

            cost[i] = m
            order[i] = ind

            i -= 1
            j = n-1

print('The cost is', cost[0])
print('The order of words is', order, ':')

i = 0

while i < n:

    for j in range(i, order[i]+1):

        print(text[j], end=' ')

    print()
    i = order[i]+1
