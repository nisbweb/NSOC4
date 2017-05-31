# A string is usually a bit of text you want to display to someone, or "export" out of the program you are writing.
# Python knows you want something to be a string when you put either " (double-quotes) or ' (single-quotes) around the text.
# Let’s look at some of the ways Python lets you write, print, and access strings in your code.
# Typing string values in Python code is fairly straightforward: They begin and end with a single quote.
spam = "That is Alice's cat."
# Escape characters
spam = 'Say hi to Bob\'s mother.'
print "Hello there!\nHow are you?\nI\'m doing fine."

# Multiline string with triple quotes
print '''Dear Alice,

Eve's cat has been arrested for catnapping, cat burglary, and extortion.

Sincerely,
Bob'''

# Index and slicing
# Strings use indexes and slices the same way lists do.
spam = 'Hello world!'
spam[0]   # 'H'
spam[4]   #  'o'
spam[-1]  #  '!'
spam[0:5]  #'Hello'
spam[6:]   # 'world!'
spam[:5]   #  'Hello'

# In and Not In operators with Strings
'Hello' in 'Hello World'            #True
'cats' not in 'cats and dogs'       #False

# The join() and split() string methods

# The join() method is useful when you have a list of strings that need to be joined together into a single string value.
', '.join(['cats', 'rats', 'bats'])         #  'cats, rats, bats'
' '.join(['My', 'name', 'is', 'Simon'])     #  'My name is Simon'
'ABC'.join(['My', 'name', 'is', 'Simon'])   #  'MyABCnameABCisABCSimon'

 # The split() method does the opposite
 'My name is Simon'.split()
 # ['My', 'name', 'is', 'Simon']
 'MyABCnameABCisABCSimon'.split('ABC')
 #  ['My', 'name', 'is', 'Simon']
'My name is Simon'.split('m')
# ['My na', 'e is Si', 'on']
