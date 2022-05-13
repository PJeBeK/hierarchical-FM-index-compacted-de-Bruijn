# This code read a file and make it in format FASTA
while True:
    try:
        line = input()
    except:
        break
    if not line:
        break
    print(">ref")
    print(line)
