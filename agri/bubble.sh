#!/usr/bin/python
def bubble_sort(arr):
		l = len(arr)
		for i in range (l-1):
			for j in range(l-1):
				if arr[j] > arr[j+1]:
					arr[j],arr[j+1] = arr[j+1],arr[j]
					print arr
a = [3,1,2,4,6,11,22,88,99,254,5]
bubble_sort(a)
print a
