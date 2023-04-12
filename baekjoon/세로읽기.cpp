arr = []
maximum = int(0)
for _ in range(5):
    a = input()
    if len(a) > maximum:
        maximum = len(a)
    arr.append(a)  # arr 배열에 a문자열을 넣음 문자열 배열이라고 생각해도됨.

for y in range(maximum):
    for x in range(5):
        if y < len(arr[x]):
            print(arr[x][y], end='')
