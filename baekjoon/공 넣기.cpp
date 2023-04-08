n,m = map(int, input().split())
array = [0]*(n+1)
for _ in range(m):
    i,j,k = map(int, input().split())
    for idx in range(i,j+1):
        array[idx] = k

for i in range(1,n+1) :
    print(array[i],end=' ')
