# Python program to print all words that
# have the same unique character set

# Function to group all strings with same characters
from collections import Counter

def groupStrings(input):
	# traverse all strings one by one
	# dict is an empty dictionary
	dict={}
	
	for word in input:
		# sort the current string and take it's
		# sorted value as key
		# sorted return list of sorted characters
		# we need to join them to get key as string
		# Counter() method returns dictionary with frequency of
		# each character as value
		wordDict=Counter(word)

		# now get list of keys
		key = wordDict.keys()

		# now sort these keys
		key = sorted(key)

		# join these characters to produce key string
		key = ''.join(key)
		
		# now check if this key already exist in
		# dictionary or not
		# if exist then simply append current word
		# in mapped list on key
		# otherwise first assign empty list to key and
		# then append current word in it
		if key in dict.keys():
			dict[key].append(word)
		else:
			dict[key]=[]
			dict[key].append(word)

		# now traverse complete dictionary and print
		# list of mapped strings in each key separated by ,
	for (key,value) in dict.items():
		print (','.join(dict[key]))
		
# Driver program
if __name__ == "__main__":
	input=['may','student','students','dog','studentssess','god','cat','act','tab','bat','flow','wolf','lambs','amy','yam','balms','looped','poodle']
	groupStrings(input)
