# pip install networkx
import networkx as nx
import random

def biased_random_connected_bipartite(n, m, k):
  G = nx.Graph()

  # These will be the two components of the bipartite graph
  N = set(range(n)) 
  M = set(range(n, n+m))
  G.add_nodes_from(N)
  G.add_nodes_from(M)

  # Create a first random edge 
  u0 = random.choice(tuple(N))
  v0 = random.choice(tuple(M))
  G.add_edge(u0, v0)

  isolated_N = set(N-{u0})
  isolated_M = set(M-{v0})
  while isolated_N and isolated_M:
    # Pick any isolated node:
    isolated_nodes = isolated_N|isolated_M
    u = random.choice(tuple(isolated_nodes))

    # And connected it to the existing connected graph:
    if u in isolated_N:
      v = random.choice(tuple(M-isolated_M))
      G.add_edge(u, v)
      isolated_N.remove(u)
    else:
      v = random.choice(tuple(N-isolated_N))
      G.add_edge(u, v)
      isolated_M.remove(u)

  # Add missing edges
  for i in range(k-len(G.edges())):
    u = random.choice(tuple(N))
    v = random.choice(tuple(M))
    G.add_edge(u, v)

  return G

if __name__ == "__main__":
    total = 100
    m = 50
    n = total - m
    minedges = 5
    maxedges = 20

    n_files = 5
    for i in range(n_files):
        B = biased_random_connected_bipartite(m, n, random.randint(minedges, maxedges))
        e = list(B.edges)
        e.sort()
        edges = {i:[] for i in range(m)}
        for j in e:
            edges[j[0]].append(j[1])
        f = open("testcase"+str(i+1)+'.txt', 'w')
        f.write(str(m)+'\n')
        f.write(str(n)+'\n')
        for i in edges:
            if(len(edges[i]) != 0):
                f.write(str(i))
                for j in edges[i]:
                    f.write(" "+str(j))
                f.write("\n")
        f.close()
    
