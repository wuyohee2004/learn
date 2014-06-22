#!/usr/bin/python
def shell_sort(arr):
	l = len(arr)
	gap = l/2
	while gap >= 1:
		for i in range(l):
			tmp = arr[i]
			j = i
			while j >= gap and arr[j-gap] > tmp :
				arr[j] = arr[j-gap]
				j -= gap
			arr[j] = tmp
			print "inner loop err %s" % arr
		if gap == 1:
			gap = 0
		else:
			gap /= 2
			
#		gap = gap/2 if gap/2 else (0 if gap == 1 else 1)

a = [3,1,2,4,6,11,22,88,99,254,5]
shell_sort(a)
print a

