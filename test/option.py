#!/usr/bin/python
from optparse import OptionParser
option = OptionParser()
option.add_option('-v','--version',dest='version',
				default=False, action ='store_true',
				help = 'Show tools version')

option.add_option('-f','--file',dest='file',
				action ='store',
				help = 'Chose file')

option.add_option('-a','--address',dest='address',
				action ='store_false',
				help = 'Show address')
args = ['-f','foo.txt']
(opt,args) = option.parse_args(args)

if opt.version:
	print "version Ture: version %s args %s" %(opt.version,args)
print "File Ture : File %s args %s" %(opt.file,args)
if not opt.address:
	print "address Ture: address %s args %s" %(opt.address,args)

