#!/usr/bin/env python3
import networkx as nx
import matplotlib.pyplot as plt
from collections import Counter
import networkx.algorithms.community as nx_comm
import igraph as ig
import leidenalg as la
from queue import PriorityQueue

#http://konect.cc/networks/twitter_mpi/

fh=open('out.ego-twitter') # adjust file here.
G=nx.read_weighted_edgelist(fh,comments='%',delimiter='\t',create_using=nx.DiGraph) # check the delimiter in file and adjust if necesary
size = G.number_of_nodes()
G = ig.Graph.from_networkx(G)
#print(G)
partition = la.find_partition(G, la.ModularityVertexPartition)

#print(partition)
#per cominity the node is orderd on degree.
sort_part=[]
for i in range(len(partition)):
	tempy=PriorityQueue()
	for j in range(len(partition[i])):
		d = G.degree(partition[i][j],mode="out")
		tempy.put((d*-1,partition[i][j]))
		#print(j)
	sort_part.append(tempy)
	
#convertion for new order perpaird.
order=[]
convert=[0]*size
i=0
for element in sort_part:
	while not element.empty():
		next_item, node = element.get()
		#print(node)
		convert[node]=i
		order.append(node)
		i=i+1

#the nodes get their new order.
neig=[]
for i in order:
	temp=G.neighbors(i, mode='out')
	l=[]
	if not temp:
		l.append(' ')
	else:
		for e in temp:
			l.append(convert[e])
	neig.append(l)

#write two file
with open(r'data.txt', 'w') as fp:
	fp.write("%s\n" % size)
	for element in neig:
		print(element)
		fp.write("%s\n" % ' '.join(map(str,element)))




#465017 big twitter
#23,370 small twitter
