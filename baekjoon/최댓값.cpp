table = [list(map(int, input().split())) for _ in range(9)]

max_num = int(0)
y, x = int(0), int(0)

for i in range(9):
    for j in range(9):
        if max_num < table[i][j]:
            max_num = table[i][j]
            y = i
            x = j
print(max_num)
print(y+1,x+1)
