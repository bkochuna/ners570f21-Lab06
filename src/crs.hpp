# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

void ax_cr ( int n, int nz_num, int ia[], int ja[], double a[], double x[],
  double w[] )

//****************************************************************************80
//
//  Discussion:
//
//    The Sparse Compressed Row storage format is used.
//
//    The matrix A is assumed to be sparse.  To save on storage, only
//    the nonzero entries of A are stored.  The vector JA stores the
//    column index of the nonzero value.  The nonzero values are sorted
//    by row, and the compressed row vector IA then has the property that
//    the entries in A and JA that correspond to row I occur in indices
//    IA[I] through IA[I+1]-1.
//
//    If your index vectors IA and JA are set up so that indexing is based 
//    at 1, then each use of those vectors should be shifted down by 1.
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

  for ( i = 0; i < n; i++ )
  {
    w[i] = 0.0;
    k1 = ia[i];
    k2 = ia[i+1];
    for ( k = k1; k < k2; k++ )
    {
      w[i] = w[i] + a[k] * x[ja[k]];
    }
  }
  return;
}
