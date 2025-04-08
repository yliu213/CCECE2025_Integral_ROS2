//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_QSFGeometricIntController_info.cpp
//
// Code generation for function 'QSFGeometricIntController'
//

// Include files
#include "_coder_QSFGeometricIntController_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4]{
      "789cc553cb4ec240149d2a12372889718f1fa0c1266cdc56302c146dd9a035b5b4179938"
      "d391e9f0d0bd6b7fc1a59fe1ce8ff067a44f0b71521210efe6f6f474"
      "7ace3d378394e6b98210da4151bd15a35e8a7139ee1b68b6e67945d293da4285997309ff"
      "1a778779022622029e4d213de9328a3ddb13eda747401c7c4646e086",
      "4c0f1368630a46165c04883632540a022a78d6fae03c18438a78dfff7148b220cde34332"
      "6f61c13c2c491ee539fea67e7b7d6272e6aba6a6d5b5ba5a556b95c3"
      "8ade3254d3b3b9cb7c2b88883342805b94b9b887c1ad588259789adc3db789796534ce80"
      "51101c3b4d4f68e9f747349d67b2e43c7b39f324fc6068fbd82759d7",
      "e1fbc4c7dd923e8a521f11e3b26197c0eaf6d891eacdf2abd8e32fd94d3718555e7ebb0b"
      "ce23bba725b41df6cff72f659d7a072f9dcd75ea25f55f7acbdec37d"
      "895e798e37f0f3b83a728e6b20745b35d4c169b7a5677c5ce6e8e4f94012fcd7ffff0613"
      "b888cc",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1720U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9]{"Version",
                                 "ResolvedFunctions",
                                 "Checksum",
                                 "EntryPoints",
                                 "CoverageInfo",
                                 "IsPolymorphic",
                                 "PropertyList",
                                 "UUID",
                                 "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8]{
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("QSFGeometricIntController"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString(
                    "Z:\\ros2\\CCECE2025 - ROS2\\nardos_controller_modified "
                    "_to_integral\\QSFGeometricIntController.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739715.61530092591));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.1.0.2603908 (R2024a) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("2OyUYWilmsWo98ZoPxdonD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

// End of code generation (_coder_QSFGeometricIntController_info.cpp)
