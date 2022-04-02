def next_row(row):
  row = [1] + row
  for i in range(1, len(row)-1):
    row[i] += row[i+1]
  return row

row, n = [], 67

for i in range(n + 1):
  row = next_row(row)

print("\n".join(map(str, row)))
