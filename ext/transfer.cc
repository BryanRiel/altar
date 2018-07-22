//-*- C++ -*-
//-*- coding: utf-8 -*-

// Build
#include <portinfo>

// std
#include <iostream>
#include <cstring>

// gsl
#include <gsl/gsl_matrix.h>

// Python
#include <Python.h>
// Numpy
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarraytypes.h>

// Local includes
#include "capsules.h"
#include "transfer.h"

// copy_gsl_to_numpy
const char * const altar::extensions::copy_gsl_to_numpy__name__ = "copy_gsl_to_numpy";
const char * const altar::extensions::copy_gsl_to_numpy__doc__ =
    "Copy GSL matrix data to Numpy array";

PyObject *
altar::extensions::copy_gsl_to_numpy(PyObject *, PyObject * args) {
    // the arguments
    PyObject * capsule;
    PyArrayObject * npArray;

    // unpack the argument tuple
    int status = PyArg_ParseTuple(args, "O!O:copy_gsl_to_numpy",
                                  &PyCapsule_Type, &capsule,
                                  &npArray);
    if (!status)
        return 0;

    // bail out if the capsule is not valid
    if (!PyCapsule_IsValid(capsule, altar::matrix::capsule_t)) {
        PyErr_SetString(PyExc_TypeError, "invalid matrix capsule");
        return 0;
    }

    // Get the gsl matrix
    gsl_matrix * m = static_cast<gsl_matrix *>(
        PyCapsule_GetPointer(capsule, altar::matrix::capsule_t)
    );

    // Get pointer to numpy array data
    double * npData = static_cast<double *>(PyArray_DATA(npArray));

    // Get size
    const size_t n_elem = m->size1 * m->size2;

    // Use memcpy to copy data from gsl to numpy
    std::memcpy(npData, m->data, n_elem * sizeof(double));
    
    // return None
    Py_INCREF(Py_None);
    return Py_None;
}

// copy_numpy_to_gsl
const char * const altar::extensions::copy_numpy_to_gsl__name__ = "copy_numpy_to_gsl";
const char * const altar::extensions::copy_numpy_to_gsl__doc__ =
    "Copy Numpy array data to GSL matrix";

PyObject *
altar::extensions::copy_numpy_to_gsl(PyObject *, PyObject * args) {
    // the arguments
    PyObject * capsule;
    PyArrayObject * npArray;

    // unpack the argument tuple
    int status = PyArg_ParseTuple(args, "OO!:copy_numpy_to_gsl",
                                  &npArray,
                                  &PyCapsule_Type, &capsule);
    if (!status)
        return 0;

    // bail out if the capsule is not valid
    if (!PyCapsule_IsValid(capsule, altar::matrix::capsule_t)) {
        PyErr_SetString(PyExc_TypeError, "invalid matrix capsule");
        return 0;
    }

    // Get the gsl matrix
    gsl_matrix * m = static_cast<gsl_matrix *>(
        PyCapsule_GetPointer(capsule, altar::matrix::capsule_t)
    );

    // Get pointer to numpy array data
    double * npData = static_cast<double *>(PyArray_DATA(npArray));

    // Get size
    const size_t n_elem = m->size1 * m->size2;

    // Use memcpy to copy data from numpy to gsl
    std::memcpy(m->data, npData, n_elem * sizeof(double));
    
    // return None
    Py_INCREF(Py_None);
    return Py_None;
}

// end of file
