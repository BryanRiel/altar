// -*- C++ -*-
//
// michael a.g. aïvázis <michael.aivazis@para-sim.com>
//
// (c) 2013-2018 parasim inc
// (c) 2010-2018 california institute of technology
// all rights reserved
//

#if !defined(altar_extensions_capsules_h)
#define altar_extensions_capsules_h

// capsules
namespace altar {

    // cov
    namespace extensions {
        const char * const capsule_t = "altar.cov";
        void free(PyObject *);
    }

    // vectors
    namespace vector {
        const char * const capsule_t = "gsl.vector";
    }
    // matrix
    namespace matrix {
        const char * const capsule_t = "gsl.matrix";
    }
}
// local

#endif

// end of file
