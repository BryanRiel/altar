//-*- C++ -*-
//-*- coding: utf-8 -*-

#if !defined(altar_extensions_transfer_h)
#define altar_extensions_transfer_h

// Declare namespace and function
namespace altar {
    namespace extensions {

        // Copy GSL data to Numpy array
        extern const char * const copy_gsl_to_numpy__name__;
        extern const char * const copy_gsl_to_numpy__doc__;
        PyObject * copy_gsl_to_numpy(PyObject *, PyObject *);
        
        // Copy Numpy array data to GSL matrix
        extern const char * const copy_numpy_to_gsl__name__;
        extern const char * const copy_numpy_to_gsl__doc__;
        PyObject * copy_numpy_to_gsl(PyObject *, PyObject *);

    }
}

#endif

// end of file
