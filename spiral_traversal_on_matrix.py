def spiralOrder(matrix):
    rowE=len(matrix)-1
    colE=len(matrix[0])-1
    rowB=0
    colB=0
    res=[]

    if not matrix:
        return res
    while rowB<=rowE and colB <=colE:
        for i in range(colB,colE+1):
            res.append(matrix[rowB][i])
        rowB+=1
        for i in range(rowB,rowE+1):
            res.append(matrix[i][colE])
        colE-=1
        if rowB<=rowE:

            for i in range(colE,colB-1,-1):
                res.append(matrix[rowE][i])
            rowE-=1
        if colB<=colE:

            for i in range(rowE,rowB-1,-1):
                res.append(matrix[i][colB])
            colB+=1
    return res


matrix = [[1, 2, 3, 4, 5, 6],
     [7, 8, 9, 10, 11, 12],
     [13, 14, 15, 16, 17, 18]]


print(spiralOrder(matrix))

