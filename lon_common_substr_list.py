strlst=["geeksforgeeks", "geeks", "geek", "geezer"]

strlst.sort()
print(strlst)
prefix=strlst[0]
long_c_substr=""

for index in range(len(prefix)):
  val=0
  for word in strlst:
    if prefix[0:index+1]==word[0:index+1]:
      val+=1

  print(val)
  if val==len(strlst):
    long_c_substr=prefix[0:val-1]




print(long_c_substr)
