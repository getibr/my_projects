import random_sigmas


def start_strategies(N):
    data = []
    with open("start_sigmas.txt") as f:
      for line in f:
        data.append([int(x) for x in line.split()])
    f.close()
    data1=[]
    for i in data:
        data1.append(i[0])
    start_sigmas=data1
    if len(start_sigmas)==N:
        return(start_sigmas)
    
    else:
        random_sigmas.start_new_strategies(N)
        start_sigmas=start_strategies(N)
        return(start_sigmas)

            

