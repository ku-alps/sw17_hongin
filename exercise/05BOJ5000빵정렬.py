#!usr/bin/python3
import collections

def rotate(seq, ind):
	if ind >= 2:	
		temp = seq[ind]
		seq[ind] = seq[ind-1]
		seq[ind-1] = seq[ind-2]
		seq[ind-2] = temp
	elif ind == 1:
		temp = seq[ind+1]
		seq[ind+1] = seq[ind]
		seq[ind] = seq[ind-1]
		seq[ind-1] = temp
	elif ind == 0:
		temp = seq[ind+2]
		seq[ind+2] = seq[ind+1]
		seq[ind+1] = seq[ind]
		seq[ind] = temp

if __name__ == "__main__":
	n = int(input())
	seq = collections.deque(input().split())
	boss = collections.deque(input().split())
	
	for bread in boss:
		if bread not in seq:
			print("Impossible")
			exit()	
		else:
			while (seq.index(bread) != 0):
				if len(seq) >= 3:
					rotate(seq, seq.index(bread))
				else:
					print("Impossible")
					exit()
#				print(seq)
			seq.popleft()
	print("Possible")

