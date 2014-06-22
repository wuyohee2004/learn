#!/usr/bin/python
def dynamic(arr):
	max = arr[0]
	sum = arr[0]
	i = 0
	while i < len(arr):
		if sum >= 0:
			sum += arr[i]
		else:
			sum = arr[i]
		if max < sum:
		   max = sum
		i += 1
	return max

a=[1,-9,12,-33,1,5,6,-99,10,20,12]

print dynamic(a)
