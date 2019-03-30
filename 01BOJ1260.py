#!/usr/bin/python3
import sys
sys.setrecursionlimit(10**8)
class Graph :
	def __init__(self, v_no, e_no, s_ind):
		self.graph = {}
		for i in range(v_no):
			self.graph[(i+1)] = []
	def remove_vertex(self, v):
		for i in range(len(self.graph)):
			if v in self.graph[i+1]:
				self.graph[i+1].remove(v)
	def add_edge(self, sta_v, end_v):
		self.graph[sta_v].append(end_v)
		self.graph[end_v].append(sta_v)
		#self.show()
	def show(self):
		print(self.graph)
	def sort(self):
		for i in range(len(self.graph)):
			self.graph[i+1].sort()
	def sortr(self):
		for i in range(len(self.graph)):
			self.graph[i+1].sort(reverse=True)
	def dfs(self, vertex, answer):
		answer.append(str(vertex))
		self.remove_vertex(vertex)
		#self.show()
		if not self.graph[vertex]:
			return
		else:
			while self.graph[vertex]:
				self.dfs(self.graph[vertex].pop(0), answer)
	def dfsnr(self, start):
		answer = []
		visited, stack = set(), [start]
		while stack:
			top = stack.pop()
			if top not in visited:
				visited.add(top)
				#print(top)
				answer.append(str(top))
				for vertex in self.graph[top]:
					stack.append(vertex)
					#answer.append(str(i+1))
		print(*answer, sep=' ')
	def bfs(self, vertex):
		queue = []
		visited = []
		for i in range(len(self.graph)):
			visited.append(False)
		queue.append(vertex)
		
		visited[vertex-1] = True
		#print(str(queue)+", "+str(visited))
		
		bfs = str(vertex) + " "
		while queue:
			smallest = queue.pop(0)

			for i in self.graph[smallest]:
				if visited[i-1] == False:
					queue.append(i)
					bfs += str(i)+" "
					visited[i-1] = True
			
			#print(str(queue)+", "+str(visited))
		print(bfs.rstrip())
if __name__=="__main__":
	first = input().split()
	graph = Graph(int(first[0]), int(first[1]), int(first[2]))
	gbf = Graph(int(first[0]), int(first[1]), int(first[2]))
	for i in range(int(first[1])):
		edge = input().split()
		graph.add_edge(int(edge[0]), int(edge[1]))
		gbf.add_edge(int(edge[0]), int(edge[1]))
	graph.sortr()
	#graph.show()
	#answer = []
	graph.dfsnr(int(first[2]))
	#print(*answer, sep=' ')
	gbf.sort()
	gbf.bfs(int(first[2]))
