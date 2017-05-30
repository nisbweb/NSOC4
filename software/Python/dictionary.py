# Like a list, a dictionary is a collection of many values.
# But unlike indexes for lists, indexes for dictionaries can use many different data types, not just integers.
# Indexes for dictionaries are called keys,
# and a key with its associated value is called a key-value pair.
# In code, a dictionary is typed with braces, {}. Enter the following into the interactive shell:

myCat = {'size': 'fat', 'color': 'gray', 'disposition': 'loud'}

myCat['size']
'My cat has ' + myCat['color'] + ' fur.'

#Dictionaries vs List
# Unlike lists, items in dictionaries are unordered.
""" The first item in a list named spam would be spam[0]. But there is no “first” item in a dictionary.
While the order of items matters for determining whether two lists are the same,
it does not matter in what order the key-value pairs are typed in a dictionary.
Enter the following into the interactive shell:"""

spam = ['cats', 'dogs', 'moose']
bacon = ['dogs', 'moose', 'cats']
spam == bacon    #false

eggs = {'name': 'Zophie', 'species': 'cat', 'age': '8'}
ham = {'species': 'cat', 'age': '8', 'name': 'Zophie'}
eggs == ham         #true
# Because dictionaries are not ordered, they can’t be sliced like lists.

# checking whether a key or value exist in a dictionary
spam = {'name': 'Zophie', 'age': 7}
'name' in spam.keys()
'Zophie' in spam.values()
'color' in spam.keys()
'color' not in spam.keys()
'color' in spam
