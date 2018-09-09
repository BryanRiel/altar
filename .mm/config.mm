# -*- Makefile -*-
#
# michael a.g. aïvázis
# parasim
# (c) 1998-2018 all rights reserved
#

fftw.version = 3.3
fftw.dir = /opt/local
fftw.flavor = 3

gsl.version = 2.4
gsl.dir = /opt/local

hdf5.version = 1.10
hdf5.dir = /opt/local

mpi.version = 3.0
mpi.dir = /opt/local
mpi.bindir = $(mpi.dir)/bin
mpi.incdir = $(mpi.dir)/include/openmpi-clang60
mpi.libdir = $(mpi.dir)/lib/openmpi-clang60
mpi.flavor = openmpi
mpi.executive = mpirun-openmpi-clang60

openblas.version = 0.3.20
openblas.dir = /opt/local

pyre.version = 1.0
pyre.dir = ${HOME}/apps/tools

python.version = 3.6
python.dir = /opt/local/library/frameworks/python.framework/versions/$(python.version)

numpy.dir = /opt/local/Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/site-packages/numpy/core

# end of file
