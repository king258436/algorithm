T = int(input())
for _ in range(T):
    r, str = input().split()
    r= int(r)
    for i in range(len(str)):
        print(str[i]*r,end='')
    print()