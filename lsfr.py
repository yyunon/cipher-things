import numpy as np

#provide the constants 
L = 10 # degree
coeffs        = [0,0,0,1,1,0,0,1,0,1]
prev_state    = [0,0,0,0,0,1,1,1,1,1] # initialize as given in part (a),but indexes are reversed:(s0 ...s9)
next_state    = [0,0,0,0,0,1,1,1,1,1]
output = []
iteration_count = 20
def Reverse(lst): 
    lst.reverse() 
    return lst
def update(num_times=1):
    for j in range(num_times): # Number of times to observe the output
        output.append(prev_state[0])
        for i in range(L-1): # iterate on next state
            next_state[i] = prev_state[i+1]
            prev_state[i] = next_state[i]
        next_state[L-1] = prev_state[L-4] ^ prev_state[L-5] ^ prev_state[L-8] ^ prev_state[L-10]
        prev_state[L-1] = next_state[L-1]
        print("The output of iteration number", j+1, end=": ") 
        print(Reverse(next_state), sep=", ", end="\n")

print("States are                      : [s9,s8,s7,s6,s5,s4,s3,s2,s1,s0]")
print("The output of iteration number 0", end=": ") 
print(Reverse(next_state), sep=", ", end="\n")
update(iteration_count)
output.reverse()
print(f"The output of first {iteration_count} bits: {output}")

