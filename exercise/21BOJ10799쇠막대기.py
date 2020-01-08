line = str(input())

ans = 0
stack = 0
for i in range(0, len(line)):
    #print('index', i, 'target', line[i], 'stack', stack, 'ans', ans)
    if line[i] == '(':
        # laser
        if line[i+1] == ')':
            ans += stack
        # bar
        else:
            stack += 1
    elif line[i] == ')':
        if i != 0 and line[i-1] != '(':
            stack -= 1
            ans += 1

    

print(ans)
            

