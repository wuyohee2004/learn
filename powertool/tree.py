#!/usr/bin/python

import os
from xml.etree import ElementTree

version = 4.2

class dir_tree:
	def __init__(self):
		pass

	def populate(self):
		for fn in os.listdir('tree'):
			if not fn.endswith('.xml'):
				continue

			tree = ElementTree.parse('tree/'+fn)
			root = tree.getroot()

			top = root.attrib['name'].strip()
			if top[0] == '$':
				top = os.getenv(top[1:])
				if top == None:
					print '"%s" does NOT exists!' % top
					exit()

			elif top == '/maxwit':
				mounted = False
				fd_chk = open('/proc/mounts')
				for line in fd_chk:
					mount = line.split(' ')
					if mount[1] == top:
						mounted = True
						break
				fd_chk.close()

				if mounted == False:
					print '"%s" NOT mounted!' % top
					exit()

			if not os.access(top, 7):
				print 'Fail to access "' + top + '", permission denied!'
				exit()

			readme = top + '/readme'
			if not os.path.exists(readme):
				fd = open(readme, 'w+')
				# ....
				fd.write('MaxWit PowerTool v%s\n' % version)
				fd.close()

			print '[%s]' % top
			self.traverse(root, top)
			print

	def traverse(self, node, path):
		if not os.path.exists(path):
			print 'creating "%s"' % path
			os.mkdir(path)
		else:
			print "skipping \"%s\"" % path

		for n in node.getchildren():
			self.traverse(n, path + '/' + n.attrib['name'])
