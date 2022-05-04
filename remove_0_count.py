#reads in the output from fmcount function and determines if a query appears in the concated contigs from the de Bruijn Graph or not. 
#If the query count is  >0 then we add it to the query output and if it's 0 then we remove it from the query list. 

string = ""

while True:
    try:
        line = input()
    except:
        break
    if not S:
        break
    
    number = line.split(" : ")[1]
    query =  line.split(" : ")[0]
    if number != "0":
        string += query + "\n"

print(string)


        
