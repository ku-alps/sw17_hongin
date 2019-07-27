from collections import deque
string = input()
explosion = input()
q = deque(maxlen=1000000) # stack
i = 0 # match counter
l = len(explosion) # C4 --> 2
s = deque() # stack saving matches
for c in string:
	if c == explosion[i]:
		i += 1
	else: # mismatch
		if i > 0: # match was found (preceded)
			s.append(i) # save to stack
		if c == explosion[0]: # reset mach counter
			i = 1
		else:
			i = 0
	q.append(c)
	print(s) 
	print(q) 
	if i == l: # match counter reached length of explosion string
		for j in range(l): # pop as many as the length
			q.pop() 
		if s: 
			i = s.pop()
		else:
			i = 0
if q:
	print(''.join(q))
else:
	print("FRULA")
