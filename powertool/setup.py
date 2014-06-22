#!/usr/bin/python

import os, re
import platform
from xml.etree import ElementTree
#fixme
class apps_setup:
	# fixme!
	def __init__(self, user):
		self.user = user
		self.home = os.getenv('HOME')
		self.conf = {}

	def name_to_mail(self, name):
		return name.lower().replace(' ', '.') + '@maxwit.com'

	def setup_git(self, distrib, version, group):
		fname = self.conf['name']
		if self.conf.has_key('email'):
			email = self.conf['email']
		else:
			email = self.name_to_mail(fname)

		# fixme
		#os.system('app/git/setup.sh "%s" "%s"' % (fname, email))

		rc = '%s/.gitconfig' % (self.home)
		fd_rc = open(rc, 'w+')
		fd_rc.write('[color]\n')
		fd_rc.write('\tui = auto\n')
		fd_rc.write('[user]\n')
		fd_rc.write('\tname = %s\n' % fname)
		fd_rc.write('\temail = %s\n' % email)
		fd_rc.write('[sendemail]\n')
		fd_rc.write('\tsmtpserver = /usr/bin/msmtp\n')
		fd_rc.write('[push]\n')
		fd_rc.write('\tdefault = matching')
		fd_rc.close()

	def setup_vim(self, distrib, version, group):
		dst = open(self.home + '/.vimrc', 'w+')
		src = open('app/vim/vimrc')
		for line in src:
			dst.write(line)
		src.close()
		dst.close()

	def setup_serial(self, distrib, version, group):
		dst = open(self.home + '/.kermrc', 'w+')
		src = open('app/kermit/kermrc')
		for line in src:
			dst.write(line)
		src.close()
		dst.close()

	def setup_fonts(self, distrib, version, group):
		os.system('sudo mkdir -p /usr/share/fonts/truetype/maxwit')
		os.system('sudo cp resource/fonts/* /usr/share/fonts/truetype/maxwit')
		os.system('sudo fc-cache -f')

	def get_user_info(self):
		fd_rept = open('/etc/passwd', 'r')
		full_name = ''

		for line in fd_rept:
			account = line.split(':')
			user_name = account[0]
			if user_name == self.user:
				full_name = account[4].split(',')[0]
				break

		fd_rept.close()

		return full_name

	def do_install(self, distrib, version, arch):
		upgrade  = ''
		install  = ''
		tree = ElementTree.parse(r'app/apps.xml')
		root = tree.getroot()

		for dist_node in root.getchildren():
			if dist_node.attrib['name'] == distrib:
				upgrade = dist_node.attrib['upgrade']
				install = dist_node.attrib['install']
				break

		if install == '':
			print 'Exception for %s!' % distrib
			return

		if upgrade != '':
			print 'Upgrading ...'
			os.system('sudo ' + upgrade)
			print

		for release in dist_node.getchildren():
			ver = release.attrib['version']
			if ver == 'any' or ver == version:
				for app_node in release.getchildren():
					if arch != app_node.get('arch', arch):
						continue

					#if install_list[0] == 'ALL' or pkg in members:
					group = app_node.get('group')

					print '[%s]\n%s' % (group, app_node.text)
					os.system('sudo ' + install + ' ' +  app_node.text)

					config = getattr(self, 'setup_' + group, None)
					if config != None:
						print '[%s] Configuring ...' % group
						members = re.split('\s+', app_node.text)
						config(distrib, version, members)

					print '[%s] Installation Done\n' % group

				if ver == version:
					break

	def config(self, key, val):
		self.conf[key] = val

	def setup(self):
		distrib = platform.dist()[0]
		version = platform.dist()[1]
		arch = platform.processor()

		print 'Installing packages for %s %s (%s)\n' % (distrib, version, arch)
		self.do_install(distrib.lower(), version, arch);
