#ifndef DUNE_COMMON_TUPLES_FIRSTINDEX_HH
#define DUNE_COMMON_TUPLES_FIRSTINDEX_HH

#include <cstddef>

#include <dune/common/static_assert.hh>
#include <dune/common/typetraits.hh>

#include <dune/common/tuples/tuples.hh>
#include <dune/common/tuples/tupleutility.hh>

namespace Dune
{

  // FirstPredicateIndex
  // -------------------

  /** \class FirstPredicateIndex
   *
   *  \brief Finding the index of a certain type in a tuple
   *
   *  \tparam Tuple     The tuple type to search in.
   *  \tparam Predicate Predicate which tells FirstPredicateIndex which types
   *                    in Tuple to accept.  This should be a class template
   *                    taking a single type template argument.  When
   *                    instantiated, it should contain a static member
   *                    constant \c value which should be convertible to bool.
   *                    A type is accepted if \c value is \c true, otherwise it
   *                    is rejected and the next type is tried.  Look at IsType
   *                    for a sample implementation.
   *  \tparam start     First index to try.  This can be adjusted to skip
   *                    leading tuple elements.
   *  \tparam size      This parameter is an implementation detail and should
   *                    not be adjusted by the users of this class.  It should
   *                    always be equal to the size of the tuple.
   *
   * This class can search for a type in tuple.  It will apply the predicate
   * to each type in tuple in turn, and set its member constant \c value to
   * the index of the first type that was accepted by the predicate.  If none
   * of the types are accepted by the predicate, a static_assert is triggered.
   */
  template<class Tuple, template<class> class Predicate, std::size_t start = 0,
      std::size_t size = tuple_size<Tuple>::value>
  class FirstPredicateIndex :
    public SelectType<Predicate<typename tuple_element<start,
                Tuple>::type>::value,
        integral_constant<std::size_t, start>,
        FirstPredicateIndex<Tuple, Predicate, start+1> >::Type
  {
    dune_static_assert(tuple_size<Tuple>::value == size, "The \"size\" "
                       "template parameter of FirstPredicateIndex is an "
                       "implementation detail and should never be set "
                       "explicitly!");
  };

#ifndef DOXYGEN
  template<class Tuple, template<class> class Predicate, std::size_t size>
  class FirstPredicateIndex<Tuple, Predicate, size, size>
  {
    dune_static_assert(AlwaysFalse<Tuple>::value, "None of the tuple element "
                       "types matches the predicate!");
  };
#endif // !DOXYGEN



  // FirstTypeIndex
  // --------------

  /** \class FirstTypeIndex
   *
   *  \brief Find the first occurance of a type in a tuple
   *
   *  \tparam Tuple The tuple type to search in.
   *  \tparam T     Type to search for.
   *  \tparam start First index to try.  This can be adjusted to skip leading
   *                tuple elements.
   *
   *  This class can search for a particular type in tuple.  It will check each
   *  type in the tuple in turn, and set its member constant \c value to the
   *  index of the first occurance of type was found.  If the type was not
   *  found, a static_assert is triggered.
   */
  template<class Tuple, class T, std::size_t start = 0>
  class FirstTypeIndex
  {
    template< class U >
    struct IsSameTypePredicate
    : public is_same< T, U >
    {};

  public:
    typedef typename FirstPredicateIndex<Tuple, IsSameTypePredicate, start >::type type;
  };

} // namespace Dune

#endif // #ifndef DUNE_COMMON_TUPLES_FIRSTINDEX_HH