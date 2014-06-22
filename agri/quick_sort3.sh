#!/usr/bin/python

def part(arr, p, q):
	x = arr[p]
	i = p
	j = p+1
	while j < q:
		if arr[j] <= x:
			i += 1
			arr[j],arr[i] = arr[i],arr[j]
		j +=1
	arr[p],arr[i] = arr[i],arr[p]
	return i+1
											     
def sort(arr,p,q):
	print "p=%d,q=%d" %(p,q)
	if p < q:
		r = part(arr,p,q)
		print "r=%d" % r
		sort(arr,p,r-1)
		print "left part func for arr %s,p=%d,q=%d" % (arr,p,q)
		sort(arr,r,q)	
		print "right part func for arr %s,p=%d,q=%d" % (arr,p,q)
	print 'loop done'
a=[3,1,5,2,65,67,22,13,11]
sort(a,0,len(a))
print a
