n,m = map(int,input().split())
box = [i for i in range(n+1)]

for _ in range(m):
    i,j,k = map(int, input().split())
    box = box[:i]+box[k:j+1]+box[i:k]+box[j+1:]

for i in range(1,n+1):
    print(box[i],end=' ')
