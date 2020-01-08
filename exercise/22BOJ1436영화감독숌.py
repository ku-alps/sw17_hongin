N = int(input())

cnt = 0
n = 0
if N == 1:
    print('666')
else:
    while n < 10000000:
        n += 1
        if str(n).find('666') >= 0:
            cnt+=1
        if cnt == N:
            print(n)
            break
