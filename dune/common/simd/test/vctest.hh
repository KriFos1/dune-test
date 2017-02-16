#ifndef DUNE_COMMON_SIMD_TEST_VCTEST_HH
#define DUNE_COMMON_SIMD_TEST_VCTEST_HH

#include <dune/common/simd/test.hh>
#include <dune/common/simd/vc.hh>

namespace Dune {
  namespace Simd {

    // Vc::Vector types
    extern template
    void UnitTest::checkVector<Vc::Vector<short             > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<unsigned short    > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<int               > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<unsigned          > >();

#if 0 // missing broadcast
    extern template
    void UnitTest::checkVector<Vc::Vector<long              > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<long unsigned     > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<long long         > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<long long unsigned> >();
#endif

    extern template
    void UnitTest::checkVector<Vc::Vector<float             > >();
    extern template
    void UnitTest::checkVector<Vc::Vector<double            > >();

    // Vc::Mask types
    extern template
    void UnitTest::checkMask<Vc::Mask<short             > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<unsigned short    > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<int               > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<unsigned          > >();

#if 0 // missing broadcast
    extern template
    void UnitTest::checkMask<Vc::Mask<long              > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<long unsigned     > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<long long         > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<long long unsigned> >();
#endif

    extern template
    void UnitTest::checkMask<Vc::Mask<float             > >();
    extern template
    void UnitTest::checkMask<Vc::Mask<double            > >();

    // Vc::SimdArray types with 4 lanes
    extern template
    void UnitTest::checkVector<Vc::SimdArray<int,                4> >();

    // Vc::SimdMaskArray types with 4 lanes
    extern template
    void UnitTest::checkMask<Vc::SimdMaskArray<int,                4> >();

    // Vc::SimdArray types with 8 lanes
    extern template
    void UnitTest::checkVector<Vc::SimdArray<int,                8> >();

    // Vc::SimdMaskArray types with 8 lanes
    extern template
    void UnitTest::checkMask<Vc::SimdMaskArray<int,                8> >();

  } // namespace Simd
} // namespace Dune

#endif // DUNE_COMMON_SIMD_TEST_VCTEST_HH
