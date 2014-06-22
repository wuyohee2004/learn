#!/usr/bin/python
def insert_sort(arr):
	l=len(arr)
	for i in range(1,l):
		print("i=%d" %i)
		tmp=arr[i]
		for j in range(i-1,-2,-1):
			print ("j=%d" %j)
			if tmp > arr[j]:
				break
			arr[j+1] = arr[j]
			print("inner loop %s" %arr)
		arr[j+1] = tmp
		print("outta loop %s,%s" %(arr,arr[j]))
		i+=1
a=[3,1,5,2,65,67,22,13,11]
insert_sort(a)
print a
