//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_QSFGeometricController_api.h
//
// Code generation for function 'QSFGeometricController'
//

#ifndef _CODER_QSFGEOMETRICCONTROLLER_API_H
#define _CODER_QSFGEOMETRICCONTROLLER_API_H

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
void QSFGeometricController(real_T z[12], real_T k[10], real_T param[5],
                            real_T ref[15], real_T F[3]);

void QSFGeometricController_api(const mxArray *const prhs[4],
                                const mxArray **plhs);

void QSFGeometricController_atexit();

void QSFGeometricController_initialize();

void QSFGeometricController_terminate();

void QSFGeometricController_xil_shutdown();

void QSFGeometricController_xil_terminate();

#endif
// End of code generation (_coder_QSFGeometricController_api.h)
