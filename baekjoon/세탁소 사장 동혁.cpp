g= int(input())
q,d,n,k = 25,10,5,1
li = [0,0,0,0]
for _ in range(g):
    c = int(input())
    while c>=q :
        li[0] +=1
        c= c-q
    while c>=d :
        li[1]+=1
        c= c-d
    while c>=n:
        li[2]+=1
        c= c-n
    while c>=k:
        li[3]+=1
        c= c-k

    for i in range(4):
        print(li[i], end=' ')
    print('')
    li = [0,0,0,0]