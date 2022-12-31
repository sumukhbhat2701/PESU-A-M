import random

seedValue = 27
random.seed(seedValue)
n_files = 5
for i in range(3):
    f = open("testcase"+str(i+1)+'.txt', 'w')
    n = 100
    f.write(str(n)+'\n')
    edges = {i:[] for i in range(n)}
    maxcost = 100
    mincost = 10
    for j in range(n):
        ne = 2*(random.randint(1,(n/2)) - 1)

        for k in range(ne):
            v = random.randint(0,n-1)
            if(v!=j):
                edges[j].append(v)
                edges[v].append(j)
    
    for i in edges:
        if(len(edges[i]) % 2 != 0):
            edges[i] = edges[i][:-1]
        f.write(str(i))
        for j in edges[i]:
            f.write(" "+str(j))
        f.write("\n")
    f.close()
