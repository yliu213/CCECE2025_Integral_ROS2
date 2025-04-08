//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_QSFGeometricIntController_api.h
//
// Code generation for function 'QSFGeometricIntController'
//

#ifndef _CODER_QSFGEOMETRICINTCONTROLLER_API_H
#define _CODER_QSFGEOMETRICINTCONTROLLER_API_H

// Include files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void QSFGeometricIntController(real_T z[15], real_T k[13], real_T param[5],
                               real_T ref[15], real_T F[3], real_T xi_dot[3]);

void QSFGeometricIntController_api(const mxArray *const prhs[4], int32_T nlhs,
                                   const mxArray *plhs[2]);

void QSFGeometricIntController_atexit();

void QSFGeometricIntController_initialize();

void QSFGeometricIntController_terminate();

void QSFGeometricIntController_xil_shutdown();

void QSFGeometricIntController_xil_terminate();

#endif
// End of code generation (_coder_QSFGeometricIntController_api.h)
