

def n_for_gamer_i(i,sigma_gamers):
    n_for_gamer=0
    for j in range(len(sigma_gamers)):
        if i==j:
            continue
        n_for_gamer+=sigma_gamers[j]
    return(n_for_gamer)
    
