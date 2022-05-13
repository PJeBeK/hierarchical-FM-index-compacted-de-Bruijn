# This code read output of CDBG (in FASTA format) and generate queries with length 50
from random import randrange

query_length = 50
while True:
    try:
        line = input()
    except:
        break
    if not line:
        break
    if line[0]=='N':
        continue
    # We can run this part multiple times if we need more queries,
    # or we can run it with a probability if we need less queries
    if len(line) > query_length:
        x = randrange(len(line)-query_length)
        print(">query")
        print(line[x:x+query_length])
        
