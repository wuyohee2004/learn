#!/usr/bin/python

import os
from optparse import OptionParser
from setup import apps_setup
from tree import dir_tree

# fixme
version = '4.2'

if __name__ == '__main__':
	user = os.getenv('USER')
	if user == 'root':
		print 'cannot run as root!'
		exit()

	parser = OptionParser()
	parser.add_option('-v', '--version', dest='version',
					  default=False, action='store_true',
					  help='show PowerTool version and exit')

	(opts, args) = parser.parse_args()

	apps = apps_setup(user)

	if opts.version:
		print 'PowerTool v%s\nby MaxWit Software (http://www.maxwit.com)\n' % version
		exit()

	apps.config('name', apps.get_user_info())

	apps.setup()

	tree = dir_tree()
	tree.populate()
