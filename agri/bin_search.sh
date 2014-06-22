#!/usr/bin/python
def bin_search(arr,length,val):
	print "bin_search called"
	l = 0
	r = length
	while l <= r:
		mid = (l+r)/2
		if (arr[mid] < val):
			l = mid + 1
		else:
			r = mid - 1
		print "middle",mid,"l",l
	return l

def sort(arr):
	l = len(arr)
	i = 1
	while i < l:
		tmp = arr[i]
		index = bin_search(arr,i,tmp)
		j = i-1
		while j>=index and j>=0:
			arr[j+1] = arr[j]
			j -= 1
			print("inner loop%s" %arr)
		arr[index]=tmp
		print("outta loop%s" %arr)
		i+=1

a=[3,1,5,2,65,67,22,13,11]
sort(a)
print a
