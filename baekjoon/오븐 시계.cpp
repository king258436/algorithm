hour,minitue = map(int,input().split())

sum= int(input())

minitue = minitue + sum
hr = minitue//60
mi = minitue%60
hour = (hour + hr)%24
print(hour,mi)