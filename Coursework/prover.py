from os.path import join
folder = 'numbers'

with open(join(folder, '1.txt'), 'r') as f:
  number_1 = f.read()

with open(join(folder, '2.txt'), 'r') as f:
  number_2 = f.read()

with open(join(folder, 'answer.txt'), 'r') as f:
  answer = f.read()

with open(join(folder, 'output.txt'), 'r') as f:
  output = f.read()

print("Num 1  len:", len(number_1))
print("Num 2  len:", len(number_2))
print("Answer len:", len(answer))
print("Output len:", len(output))

dprint = lambda x: print('-' * len(x), x, sep='\n')
dprint(
  "Output is correct!"
  if output == answer
  else "Output is incorrect!"
)