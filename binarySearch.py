lst=[10,12,13,16,20,25]

searchF=13

def searchL(lst,frm,to,findN):
  if to>=frm:
    centerIndex=int((frm+to)/2)# int(len(lst)/2)
    if findN==lst[centerIndex]:
      return centerIndex

    if findN<lst[centerIndex]:
      return searchL(lst,frm,centerIndex-1,findN)
    else:
      return searchL(lst,centerIndex+1,to,findN)
  else:
    return -1


resp=searchL(lst,0,len(lst)-1,searchF)
print("Find =",resp)
