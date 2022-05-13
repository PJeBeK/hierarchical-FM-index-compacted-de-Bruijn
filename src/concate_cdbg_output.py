# This code take the output of CDBG and concate its unitigs by putting character N between them
import sys

bv_file = open(sys.argv[1], 'w')

while True:
  try:
    ref = input()
  except:
    break
  if not ref:
    break
  unitig = input().strip()
  print('N' + unitig, end='')
  bv_file.write('1' + '0' * len(unitig))
bv_file.close()
