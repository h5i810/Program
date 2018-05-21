def sequentialSearch(alist,target):
    pos=0                #指示位置
    found=False           #用于指示是否找到

    while pos<len(alist) and not found:
        if alist[pos]==target:
            found=True
        else:
            pos+=1

    if pos<len(testlist):
       return found,pos
    else:
       return found

testlist=[1,2,32,8,17,19,42,13,0]
print(sequentialSearch(testlist,3))
print(sequentialSearch(testlist,13))