#access via index
numbers = [5, 6, 7, 8]
print "Adding the numbers at indices 0 and 2..."
print numbers[0] + numbers[2]
print "Adding the numbers at indices 1 and 3..."
print numbers[1] + numbers[3]

#assign values
 numbers[1]=10
 numbers[2]=15
 numbers[3]=8

#append
 letters = ['a', 'b', 'c']
letters.append('d')
#['a','b','c','d']
print letters

#extend
 t1 = ['a', 'b', 'c']
 t2 = ['d', 'e']
t1.extend(t2)
 print t1

#sort
 t = ['d', 'c', 'e', 'b', 'a']
 t.sort()
 print t

#slicing
 spam = ['a', 'b', 'c', 'd', 'e']
slice1 = spam[1:3]
print slice1 # ['b', 'c']
slice2 = spam[0:4]
print slice2 # ['a', 'b', 'c', 'd']

#concatenate
a = [1, 2, 3]
 b = [4, 5, 6]
 c = a + b
 print c

#replicate
 [0] * 4
 [1, 2, 3] * 3

#delete

#pop()
 t = ['a', 'b', 'c']
 x = t.pop(1)
 print t
#['a', 'c']
 print x

#del
  t = ['a', 'b', 'c']
 del t[1]
 print t

#remove
  t = ['a', 'b', 'c']
 t.remove('b')
 print t

#del with a slice index:
 t = ['a', 'b', 'c', 'd', 'e', 'f']
 del t[1:5]
print t
