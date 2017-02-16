#if HAVE_CONFIG_H
#include "config.h"
#endif

#if !HAVE_VC
#error Inconsistent buildsystem.  This program should not be built in the \
  absence of Vc.
#endif

#include <cstdlib>

#include <dune/common/simd/test.hh>
#include <dune/common/simd/test/vctest.hh>
#include <dune/common/simd/vc.hh>

int main()
{
  using Vc::Vector;

  Dune::Simd::UnitTest test;

  test.checkVector<Vector<short             > >();
  test.checkVector<Vector<unsigned short    > >();
  test.checkVector<Vector<int               > >();
  test.checkVector<Vector<unsigned          > >();
#if 0 // missing broadcast
  test.checkVector<Vector<long              > >();
  test.checkVector<Vector<long unsigned     > >();
  test.checkVector<Vector<long long         > >();
  test.checkVector<Vector<long long unsigned> >();
#endif

  test.checkVector<Vector<float             > >();
  test.checkVector<Vector<double            > >();

  return test.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}
