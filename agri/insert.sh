#!/usr/bin/python
def insert_sort(arr):
	i=1
	l=len(arr)
	while i < l:
		tmp = arr[i]
		j = i-1
		while j >= 0:
			if tmp > arr[j]:
				break
			arr[j+1] = arr[j]
			j-=1
			print ("inner loop %s" %arr)
		arr[j+1] = tmp
		print ("outta loop %s" %arr)
		i += 1
a=[3,1,5,2,65,67,22,13,11]
insert_sort(a)
print a

