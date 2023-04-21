x = int(input())
line = 1

while x>line:
    x-=line
    line+=1
a,b=0,0
if line%2==0:#짝수일때
    a=x
    b=line+1-x
else :
    a=line+1-x
    b=x

print(f"{a}/{b}")