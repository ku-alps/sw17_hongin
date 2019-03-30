#!/usr/bin/python3
def newmask(i):
	mask = 0
	digit = 0
	while i > 0:
		if i & 1 == 1:
			mask = mask|(31<<(5*digit))
		else:
			mask = mask|(0<<(5*digit))
		i = i >> 1
		digit +=1
	return mask

def tointeger(i):
	if i == 0:
		return 0
	integer = 1;
	while i > 0:
		cluster = i & 31
		if cluster == 0:
			integer *= 1
		else:
			integer *= cluster
		i = i >>5
	return integer

answer = []
caseno = int(input())
for i in range(caseno):
	attrno = int(input())
	category = []
	attr = []
	for j in range(attrno):
		line = input().split()
		if line[1] not in category:
			category.append(line[1])
			attr.append(1)
		else:
			attr[category.index(line[1])] += 1
	
	'''totalbit = 0
	for number in attr:
		fivebit = 31&number
		totalbit = (totalbit << 5) | fivebit

	#print("totalbit {0:b}".format(totalbit))
	num = 0	
	for i in range(2**len(attr)):
		bitresult = newmask(i)&totalbit
		#print("mask for {0} is {1:b}".format(i, newmask(i)))
		#print("bitresult for {0} is {1:b}".format(i, bitresult))
		#print("int multiplied value is "+ str(tointeger(bitresult)))
		num += tointeger(bitresult)'''
	num = 1
	for n in attr:
		num *= (n+1)
	answer.append(num-1)
print(*answer, sep = ' ')
