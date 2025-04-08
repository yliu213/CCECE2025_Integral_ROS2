//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// main.cpp
//
// Code generation for function 'main'
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include files
#include "main.h"
#include "QSFGeometricIntController.h"
#include "QSFGeometricIntController_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_15x1_real_T(double result[15]);

static void argInit_1x13_real_T(double result[13]);

static void argInit_1x5_real_T(double result[5]);

static double argInit_real_T();

// Function Definitions
static void argInit_15x1_real_T(double result[15])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 15; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

static void argInit_1x13_real_T(double result[13])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 13; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x5_real_T(double result[5])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 5; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static double argInit_real_T()
{
  return 0.0;
}

int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_QSFGeometricIntController();
  // Terminate the application.
  // You do not need to do this more than one time.
  QSFGeometricIntController_terminate();
  return 0;
}

void main_QSFGeometricIntController()
{
  double z_tmp[15];
  double dv[13];
  double dv1[5];
  double F[3];
  double xi_dot[3];
  // Initialize function 'QSFGeometricIntController' input arguments.
  // Initialize function input argument 'z'.
  argInit_15x1_real_T(z_tmp);
  // Initialize function input argument 'k'.
  // Initialize function input argument 'param'.
  // Initialize function input argument 'ref'.
  // Call the entry-point 'QSFGeometricIntController'.
  argInit_1x13_real_T(dv);
  argInit_1x5_real_T(dv1);
  QSFGeometricIntController(z_tmp, dv, dv1, z_tmp, F, xi_dot);
}

// End of code generation (main.cpp)
