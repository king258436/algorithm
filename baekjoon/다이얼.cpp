dial = ["ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]

str = input()
res = 0
for s in str:
    for i in range(len(dial)):
        if s in dial[i]: res+=i+3
print(res)