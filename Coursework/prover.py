with open("num_1.txt", "r") as f:
  number1 = f.read()

with open("num_2.txt", "r") as f:
  number2 = f.read()

with open("output.txt", "r") as f:
  output = f.read()

print("File 1 length:", len(number1))
print("File 2 length:", len(number2))
print("Answer length:", len(output))

number1 = int(number1)
number2 = int(number2)
output = int(output)
answer = number1 * number2

dprint = lambda x: print('-' * len(x), x, sep='\n')
dprint(
  "Answer is correct!"
  if answer == output
  else "Answer is incorrect!"
)