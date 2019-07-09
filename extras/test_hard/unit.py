# -*- coding: utf-8 -*-

import re
import os

from deepthought.correction.units.c import CUnit

#Ce script est franchement tiré de l'ancien car j'ai pas la foi de bidouiller les fichiers de correction dans tous les sens
#pour les rendre parfaitement compatible. A faire une autre fois.

class Unit(CUnit):

	nolib = 0
	count = 0
	total_tests = 1
	buf = 0
	srcfiles = []
	corrfiles = []

	def __init__(self, *args, **kwargs):
		super(Unit, self).__init__(*args, **kwargs)
		self.srcfiles = [
				"libft",
				"get_next_line.c",
				"get_next_line.h"
				]
		self.corrfiles = [
				"Makefile",
				"main.c",
				"tests.h",
				"test_*.c",
				"test3.in",
				]
		self.ucopy(self.srcfiles, cd=True)

	def precheck(self):
		if not os.path.isdir("./libft"):
			self.trace("No libft found")
			self.nolib = 1

		if self.nolib == 0:
			if not self.execute("make -C libft/ fclean && make -C libft/", "compil_userlib_output", required_files=self.srcfiles, trace_output=True, trace_cmd=False, copyback_files=["libft"], maxtime=30):
				self.comment("KO (Does not compile)")

		self.rcopy(self.corrfiles)
		self.execute("grep -c \"^# *define BUFF_SIZE[\t ]*[(0-9)]*$\" get_next_line.h", "grep_output", required_files=self.corrfiles + self.srcfiles, trace_output=False, trace_cmd=False)

		with open("grep_output", "r") as fp:
			output = fp.read()

		if (output == "1\n"):
			self.trace("Define found")
		else:
			self.comment("KO (Define not found or multiple define)")
			self.trace("KO (Define not found or multiple define)")
			self.ko()
			return

	def check( self, buff_size ):
		self.buf = buff_size
		if self.execute("sed -i -- \"s/^# *define BUFF_SIZE[\t ]*[(0-9)]*$/# define BUFF_SIZE {}/g\" get_next_line.h".format(buff_size), "sed_output", required_files=self.corrfiles + self.srcfiles, copyback_files=["get_next_line.h"], trace_output=True, trace_cmd=False):
			self.trace("BUFF_SIZE changed to {}".format(buff_size))

		if self.nolib == 1:
		        self.srcfiles = [
				"get_next_line.c",
				"get_next_line.h"
				]
			if not self.execute("clang -Wall -Werror -Wextra -o get_next_line.o -c get_next_line.c && clang -Wall -Werror -Wextra -o main.o -c main.c && clang -Wall -Werror -Wextra -o test_hard.o -c test_hard.c && clang -o test_gnl test_hard.o main.o get_next_line.o", "compil_test_output", required_files=self.corrfiles + self.srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		else:
			if not self.execute("make fclean && make test_gnl", "compil_test_output", required_files=self.corrfiles + self.srcfiles, trace_output=True, trace_cmd=False, copyback_files=["test_gnl"], maxtime=30):
				self.comment("KO (Could not compile test executable with your functions)")
				self.ko()
				return
		
		self.execute("./test_gnl", "test_output", required_files=self.corrfiles + self.srcfiles, trace_output=True, trace_cmd=False)

		with open("test_output", "r") as fp:
			output = fp.read()

		lines = output.split('\n')
		reg = re.compile('test_[a-z_0-9]+: \[ok\]')

		for line in lines:
			if reg.match(line):
				self.count += 1

		return
		# return self.execute("./test_gnl", "test_output", required_files=self.corrfiles + self.srcfiles, trace_output=True, trace_cmd=False)

	def run(self):

		try:
		 	self.precheck()
			self.check( 50000 )

		except:
			self.trace("\n[!] Error with hard tests - Buffer: " + str(self.buf) + " - Nb chars in fd: 235436\n")				
			self.ko()
			return
		finally:
			# with open("test_output", "r") as fp:
			# 	output = fp.read()

			# lines = output.split('\n')
			# reg = re.compile('test_[a-z_0-9]+: \[ok\]')

			# self.count = len( filter( lambda line: reg.match(line), lines ) )
			
			self.trace("%d/%d correct tests" % (self.count, self.total_tests))
			self.comment("%d/%d correct test" % (self.count, self.total_tests))
			self.set_grade(( self.count * 10 ) / self.total_tests)
			if self.count != self.total_tests:	
				self.ko()
			return
