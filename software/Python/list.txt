# List data type
a = [1, 2, 3]
b = ["Cat", "Dog", "Elephant"]
spam = ['hello', 3.14, True, None, 42]

spam

# Index
spam[0]
spam[1]

spam = [['cat', 'bat'], [10, 20, 30, 40, 50]]
spam[0]
spam[0][1]
# cat
spam[1][4]
# 50
# Negative index
b[-1]
b[-2]
spam = ['cat', 'bat', 'rat', 'elephant']
'The ' + spam[-1] + ' is afraid of the ' + spam[-3] + '.'

# Getting sublist by slices
spam[0:4]
spam[1:3]
spam[0:-1]
spam[:2]
spam[1:]
spam[:]

# Getting length of the list
spam = ['cat', 'dog', 'moose']
len(spam)

# Changing values in alist with indexes
spam = ['cat', 'bat', 'rat', 'elephant']
spam[1] = 'aardvark'
print spam
spam[2] = spam[1]

# List Concatenation and List Replication

[1, 2, 3] + ['A', 'B', 'C']
['X', 'Y', 'Z'] * 3
spam = [1, 2, 3]
spam = spam + ['A', 'B', 'C']
print spam

# Removing values from list using del

spam = ['cat', 'bat', 'rat', 'elephant']
del spam[2]
print spam
