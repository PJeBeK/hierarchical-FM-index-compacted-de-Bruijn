# This code take the output of CDBG and concate its unitigs by putting character N between them
result = ""
while True:
  try:
    ref = input()
    except:
      break
    if not ref:
      break
    unitig = input()
    result += 'N' + unitig
    
print(result)