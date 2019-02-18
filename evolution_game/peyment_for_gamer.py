import n_for_gamer_i
import var
import random 

def peyment_for_gamer(i,sigma_gamers):
    v=sigma_gamers[i]*n_for_gamer_i.n_for_gamer_i(i,sigma_gamers)*var.J()
    v+=random.normalvariate(0, 0.5)
    return(v)
