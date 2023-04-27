n,m = map(int, input().split())
six,per = 1000,1000
for i in range(m):
    a,b = map(int, input().split())
    if a < six :
        six = a
    if b < per :
        per = b
mix = (n//6)*six + (n%6)*per
all_six=0
if n%6 == 0 :
    all_six = n//6*six
else :
    all_six = (n//6+1)*six
all_per = n*per

res = 0
res = min(mix,all_six)
res = min(res, all_per)
print(res)
