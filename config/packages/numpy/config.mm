# -*- Makefile -*-
#
# michael a.g. aïvázis
# parasim
# (c) 1998-2018 all rights reserved
#

# add me to the pile
packages += numpy

# compiler flags
numpy.flags ?=
# enable {numpy} aware code
numpy.defines ?=
# the canonical form of the include directory
numpy.incpath ?= $(numpy.dir)/include

# end of file
