#!/usr/bin/python
def dynamic(arr):
	max = arr[0]
	sum = arr[0]
	for i in range(1,len(arr)):
		print ("the %d st loop" %i)
		if sum >= 0:
			sum += arr[i]
		else:
			sum = arr[i]
		if sum > max:
			max = sum
	return max


a=[1,-9,12,-33,1,5,6,-99,10,20,12]
print dynamic(a)
