# -*- Makefile -*-
#
# michael a.g. aïvázis
# parasim
# (c) 1998-2018 all rights reserved
#

# display the numpy configuration
numpy.show:
	${call show.sec,"numpy",}
	${call show.var,"version",$(numpy.version)}
	${call show.var,"home",$(numpy.dir)}
	${call show.var,"incpath",$(numpy.incpath)}

# end of file
