def closedPaths(number):

    c=0
    while(number>0):
        d=number%10
        if(d==0 or d==4 or d==6 or d==9):
            c=c+1
        elif(d==8):
            c=c+2
        else:
            c=c+0
        number = int(number/10)
    return c
