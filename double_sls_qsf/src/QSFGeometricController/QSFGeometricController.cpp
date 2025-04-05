//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// QSFGeometricController.cpp
//
// Code generation for function 'QSFGeometricController'
//

// Include files
#include "QSFGeometricController.h"
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

void QSFGeometricController(const double z[12], const double k[10],
                            const double param[5], const double ref[15],
                            double F[3])
{
  __m128d r;
  __m128d r1;
  double b_z[9];
  double b_nu3[3];
  double dr[3];
  double a;
  double a_tmp;
  double b_k_idx_0_tmp;
  double ddnu3;
  double de3;
  double dnu3;
  double k_idx_0;
  double k_idx_0_tmp;
  double nu3;
  double scale;
  double t;
  double z_idx_2_tmp;
  double z_idx_3_tmp;
  //  <- hardcoded instead of param(5)
  de3 = z[8] - ref[11];
  nu3 = (-k[8] * (z[2] - ref[10]) + -k[9] * de3) + ref[12];
  ddnu3 = nu3 - ref[12];
  dnu3 = (-k[8] * de3 + -k[9] * ddnu3) + ref[13];
  ddnu3 = (-k[8] * ddnu3 + -k[9] * (dnu3 - ref[13])) + ref[14];
  dr[0] = z[5] * z[10] - z[4] * z[11];
  dr[1] = z[3] * z[11] - z[5] * z[9];
  dr[2] = z[4] * z[9] - z[3] * z[10];
  t = z[5] * z[5];
  a_tmp = param[0] * param[3];
  a = a_tmp * t / (nu3 - 9.81);
  de3 = z[3] / z[5];
  scale = dr[0] / z[5] - dr[2] * z[3] / t;
  z_idx_2_tmp = z[4] / z[5];
  z_idx_3_tmp = dr[1] / z[5] - dr[2] * z[4] / t;
  k_idx_0_tmp = dr[2] * dr[2];
  b_k_idx_0_tmp = rt_powd_snf(z[5], 3.0);
  k_idx_0 = ((((-k[0] * (z[0] - ref[0]) + -k[1] * (z[6] - ref[1])) +
               -k[2] * (de3 * (nu3 - 9.81) - ref[2])) +
              -k[3] * ((de3 * dnu3 + scale * (nu3 - 9.81)) - ref[3])) +
             ref[4]) -
            ((de3 * ddnu3 + 2.0 * dnu3 * scale) +
             2.0 * (z[3] * k_idx_0_tmp / b_k_idx_0_tmp - dr[0] * dr[2] / t) *
                 (nu3 - 9.81));
  de3 =
      ((((-k[4] * (z[1] - ref[5]) + -k[5] * (z[7] - ref[6])) +
         -k[6] * (z_idx_2_tmp * (nu3 - 9.81) - ref[7])) +
        -k[7] * ((z_idx_2_tmp * dnu3 + z_idx_3_tmp * (nu3 - 9.81)) - ref[8])) +
       ref[9]) -
      ((z_idx_2_tmp * ddnu3 + 2.0 * dnu3 * z_idx_3_tmp) +
       2.0 * (z[4] * k_idx_0_tmp / b_k_idx_0_tmp - dr[1] * dr[2] / t) *
           (nu3 - 9.81));
  scale = 3.3121686421112381E-170;
  ddnu3 = std::abs(z[9]);
  if (ddnu3 > 3.3121686421112381E-170) {
    z_idx_2_tmp = 1.0;
    scale = ddnu3;
  } else {
    t = ddnu3 / 3.3121686421112381E-170;
    z_idx_2_tmp = t * t;
  }
  ddnu3 = std::abs(z[10]);
  if (ddnu3 > scale) {
    t = scale / ddnu3;
    z_idx_2_tmp = z_idx_2_tmp * t * t + 1.0;
    scale = ddnu3;
  } else {
    t = ddnu3 / scale;
    z_idx_2_tmp += t * t;
  }
  ddnu3 = std::abs(z[11]);
  if (ddnu3 > scale) {
    t = scale / ddnu3;
    z_idx_2_tmp = z_idx_2_tmp * t * t + 1.0;
    scale = ddnu3;
  } else {
    t = ddnu3 / scale;
    z_idx_2_tmp += t * t;
  }
  z_idx_2_tmp = scale * std::sqrt(z_idx_2_tmp);
  b_nu3[0] = (nu3 - 9.81) / z[5];
  b_nu3[1] = a * 0.0 * k_idx_0 + -a * de3;
  b_nu3[2] = a * k_idx_0 + a * 0.0 * de3;
  dr[0] = a_tmp / param[2] * (z_idx_2_tmp * z_idx_2_tmp);
  dr[1] = 0.0;
  dr[2] = 0.0;
  de3 = param[0] + param[1];
  b_z[0] = z[3] * de3;
  b_z[3] = -z[4] * z[3] / z[5];
  b_z[6] = (z[3] * z[3] - 1.0) / z[5];
  b_z[1] = z[4] * de3;
  b_z[4] = (-(z[4] * z[4]) + 1.0) / z[5];
  b_z[7] = z[3] * z[4] / z[5];
  b_z[2] = z[5] * de3;
  b_z[5] = -z[4];
  b_z[8] = z[3];
  r = _mm_loadu_pd(&b_nu3[0]);
  r1 = _mm_loadu_pd(&dr[0]);
  _mm_storeu_pd(&b_nu3[0], _mm_add_pd(r, r1));
  de3 = b_nu3[0];
  ddnu3 = b_nu3[1];
  scale = b_nu3[2];
  r = _mm_loadu_pd(&b_z[0]);
  r = _mm_mul_pd(r, _mm_set1_pd(de3));
  r1 = _mm_loadu_pd(&b_z[3]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(ddnu3));
  r = _mm_add_pd(r, r1);
  r1 = _mm_loadu_pd(&b_z[6]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(scale));
  r = _mm_add_pd(r, r1);
  _mm_storeu_pd(&F[0], r);
  F[2] = (b_z[2] * de3 + b_z[5] * ddnu3) + b_z[8] * scale;
}

// End of code generation (QSFGeometricController.cpp)
