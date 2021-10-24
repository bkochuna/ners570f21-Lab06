# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

void ax_coo ( int n, int nz_num, int ia[], int ja[], double a[], double x[],
  double w[] )

//****************************************************************************80
//
//  Discussion:
//
//    The COO storage format is used.
//
//  Parameters:
//
//    Input, int N, the order of the system.
//
//    Input, int NZ_NUM, the number of nonzeros.
//
//    Input, int IA[N+1], JA[NZ_NUM], the row and column indices
//    of the matrix values.  The row vector has been compressed.
//
//    Input, double A[NZ_NUM], the matrix values.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double W[N], the value of A*X.
{
  int i;
  int k;
  int k1;
  int k2;

  for ( i = 0; i < nz_num; i++ ){

    w[i] = 0.0;
    k1 = ia[i];
    k2 = ja[i];
    w[k1] = w[k1] + a[i] * x[k2];
    
  }
  return;
}
                                                                 57,1          Bot

