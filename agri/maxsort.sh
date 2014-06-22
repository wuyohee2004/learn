#!/usr/bin/python
def max_sort(arr):
	i=0
	l=len(arr)
	while i < l:
		max=0
		j=0
		while j < (l-i):
			if arr[max] < arr[j]:
				max = j
			j+=1
		if max != l-i-1:
			(arr[max],arr[l-i-1]) = (arr[l-i-1],arr[max])
		i+=1

a=[3,1,5,2,65,67,22,13,11]
max_sort(a)
print a


