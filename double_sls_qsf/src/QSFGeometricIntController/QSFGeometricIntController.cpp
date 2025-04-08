//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// QSFGeometricIntController.cpp
//
// Code generation for function 'QSFGeometricIntController'
//

// Include files
#include "QSFGeometricIntController.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <emmintrin.h>

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

void QSFGeometricIntController(const double z[15], const double k[13],
                               const double param[5], const double ref[15],
                               double F[3], double xi_dot[3])
{
  __m128d r;
  __m128d r1;
  double d_z[9];
  double c_z[5];
  double b_z[3];
  double dr[3];
  double a;
  double a_tmp;
  double absxk;
  double b_a_tmp;
  double b_k;
  double b_z_tmp;
  double ddnu3;
  double de3;
  double dnu3;
  double e1;
  double e2;
  double e3;
  double k_idx_0;
  double nu3;
  double scale;
  double z_tmp;
  //  <- hardcoded instead of param(5)
  e3 = z[2] - ref[10];
  de3 = z[8] - ref[11];
  nu3 = ((-k[10] * z[14] + -k[11] * e3) + -k[12] * de3) + ref[12];
  absxk = nu3 - ref[12];
  dnu3 = ((-k[10] * e3 + -k[11] * de3) + -k[12] * absxk) + ref[13];
  ddnu3 =
      ((-k[10] * de3 + -k[11] * absxk) + -k[12] * (dnu3 - ref[13])) + ref[14];
  dr[0] = z[5] * z[10] - z[4] * z[11];
  dr[1] = z[3] * z[11] - z[5] * z[9];
  dr[2] = z[4] * z[9] - z[3] * z[10];
  e1 = z[0] - ref[0];
  e2 = z[1] - ref[5];
  a_tmp = z[5] * z[5];
  b_a_tmp = param[0] * param[3];
  a = b_a_tmp * a_tmp / (nu3 - 9.81);
  c_z[0] = z[12];
  c_z[1] = e1;
  c_z[2] = z[6] - ref[1];
  absxk = z[3] / z[5];
  c_z[3] = absxk * (nu3 - 9.81) - ref[2];
  de3 = dr[0] / z[5] - dr[2] * z[3] / a_tmp;
  c_z[4] = (absxk * dnu3 + de3 * (nu3 - 9.81)) - ref[3];
  scale = 0.0;
  for (int i{0}; i < 5; i++) {
    scale += -k[i] * c_z[i];
  }
  c_z[0] = z[13];
  c_z[1] = e2;
  c_z[2] = z[7] - ref[6];
  z_tmp = z[4] / z[5];
  c_z[3] = z_tmp * (nu3 - 9.81) - ref[7];
  b_z_tmp = dr[1] / z[5] - dr[2] * z[4] / a_tmp;
  c_z[4] = (z_tmp * dnu3 + b_z_tmp * (nu3 - 9.81)) - ref[8];
  b_k = 0.0;
  for (int i{0}; i < 5; i++) {
    b_k += -k[i + 5] * c_z[i];
  }
  double b_k_idx_0_tmp;
  double k_idx_0_tmp;
  k_idx_0_tmp = dr[2] * dr[2];
  b_k_idx_0_tmp = rt_powd_snf(z[5], 3.0);
  k_idx_0 =
      (scale + ref[4]) -
      ((absxk * ddnu3 + 2.0 * dnu3 * de3) +
       2.0 * (z[3] * k_idx_0_tmp / b_k_idx_0_tmp - dr[0] * dr[2] / a_tmp) *
           (nu3 - 9.81));
  de3 = (b_k + ref[9]) -
        ((z_tmp * ddnu3 + 2.0 * dnu3 * b_z_tmp) +
         2.0 * (z[4] * k_idx_0_tmp / b_k_idx_0_tmp - dr[1] * dr[2] / a_tmp) *
             (nu3 - 9.81));
  scale = 3.3121686421112381E-170;
  absxk = std::abs(z[9]);
  if (absxk > 3.3121686421112381E-170) {
    a_tmp = 1.0;
    scale = absxk;
  } else {
    ddnu3 = absxk / 3.3121686421112381E-170;
    a_tmp = ddnu3 * ddnu3;
  }
  absxk = std::abs(z[10]);
  if (absxk > scale) {
    ddnu3 = scale / absxk;
    a_tmp = a_tmp * ddnu3 * ddnu3 + 1.0;
    scale = absxk;
  } else {
    ddnu3 = absxk / scale;
    a_tmp += ddnu3 * ddnu3;
  }
  absxk = std::abs(z[11]);
  if (absxk > scale) {
    ddnu3 = scale / absxk;
    a_tmp = a_tmp * ddnu3 * ddnu3 + 1.0;
    scale = absxk;
  } else {
    ddnu3 = absxk / scale;
    a_tmp += ddnu3 * ddnu3;
  }
  a_tmp = scale * std::sqrt(a_tmp);
  dr[0] = (nu3 - 9.81) / z[5];
  dr[1] = a * 0.0 * k_idx_0 + -a * de3;
  dr[2] = a * k_idx_0 + a * 0.0 * de3;
  b_z[0] = b_a_tmp / param[2] * (a_tmp * a_tmp);
  b_z[1] = 0.0;
  b_z[2] = 0.0;
  absxk = param[0] + param[1];
  d_z[0] = z[3] * absxk;
  d_z[3] = -z[4] * z[3] / z[5];
  d_z[6] = (z[3] * z[3] - 1.0) / z[5];
  d_z[1] = z[4] * absxk;
  d_z[4] = (-(z[4] * z[4]) + 1.0) / z[5];
  d_z[7] = z[3] * z[4] / z[5];
  d_z[2] = z[5] * absxk;
  d_z[5] = -z[4];
  d_z[8] = z[3];
  r = _mm_loadu_pd(&dr[0]);
  r1 = _mm_loadu_pd(&b_z[0]);
  _mm_storeu_pd(&dr[0], _mm_add_pd(r, r1));
  de3 = dr[0];
  scale = dr[1];
  absxk = dr[2];
  r = _mm_loadu_pd(&d_z[0]);
  r = _mm_mul_pd(r, _mm_set1_pd(de3));
  r1 = _mm_loadu_pd(&d_z[3]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(scale));
  r = _mm_add_pd(r, r1);
  r1 = _mm_loadu_pd(&d_z[6]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(absxk));
  r = _mm_add_pd(r, r1);
  _mm_storeu_pd(&F[0], r);
  F[2] = (d_z[2] * de3 + d_z[5] * scale) + d_z[8] * absxk;
  xi_dot[0] = e1;
  xi_dot[1] = e2;
  xi_dot[2] = e3;
}

// End of code generation (QSFGeometricIntController.cpp)
