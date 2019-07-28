from collections import deque
string = input()
explosion = input()
q = deque(maxlen=1000000) # stack
s = deque(maxlen=1000000) # stack saving matches
i = 0 # match counter
l = len(explosion) # C4 --> 2
for c in string:
    if c == explosion[i]:
        i += 1
    else :
        if c == explosion[0] :
            i = 1
        else :
            i = 0
    q.append(c)
    s.append(i) # save to stack
    #print(q)
    #print(s)
    if i == l: # match counter reached length of explosion string
        for j in range(l): # pop as many as the length
            q.pop()
            i = s.pop()
        if s:
            i = s[-1]
        else:
            i = 0
if q:
    print(''.join(q))
else:
    print("FRULA")
