def Split(x,y,n):
    if n==1:
        return graph[x][y]
    else:
        List=[Split(x, y, n // 2),Split(x, y + (n // 2), n // 2),Split(x + (n // 2), y, n // 2),Split(x + (n // 2), y + (n // 2), n // 2)]
        List.sort()
        return List[1]

N=int(input())

graph=[list(map(int,input().split())) for i in range(N)]

print(Split(0,0,N))