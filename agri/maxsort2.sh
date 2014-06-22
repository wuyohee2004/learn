#!/usr/bin/python
def max_sort(arr):
	l=len(arr)
	for i in range(0,l-1):
		max=0
		for j in range(0,l-i-1):
			if arr[max] < arr[j]:
				max=j
		(arr[max],arr[l-i-1]) = (arr[l-i-1],arr[max])
a=[10,11,22,12,5,7,4,3,2,1]
max_sort(a)
print a
