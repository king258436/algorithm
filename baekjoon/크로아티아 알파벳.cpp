croatia = ["c=","c-","dz=","d-","lj","nj","s=","z="]
word = input()
for i in croatia:
    word = word.replace(i,'*') # word 의 문자열의 i 라는 서브문자열을 * 로 바꿔라.
print(len(word))
