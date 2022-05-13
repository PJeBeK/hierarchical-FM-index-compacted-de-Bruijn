# reads the output of fmcount function, and determines if a query appears in the concated contigs from the CDBG or not.
# If the query count is >0 then we add it to the query output and if it's 0, then we remove it from the query.

MAXIMUM_NUMBER_OF_QUERIES = 100000
t = 0

while True:
    try:
        line = input()
    except:
        break
    if not line:
        break

    number = line.split(" : ")[1]
    query = line.split(" : ")[0]
    if number != "0" and t < MAXIMUM_NUMBER_OF_QUERIES:
        print(query)
        t += 1
