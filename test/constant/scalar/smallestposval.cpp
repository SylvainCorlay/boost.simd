//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check smallestposval behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::smallestposval;
  using boost::simd::Smallestposval;

  STF_TYPE_IS(decltype(Smallestposval<T>()), T);
  STF_EQUAL(Smallestposval<T>(), T(1));
  STF_EQUAL(smallestposval( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check smallestposval behavior for float"
            , (float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::smallestposval;
  using boost::simd::Smallestposval;

  STF_TYPE_IS(decltype(Smallestposval<T>()), T);
  STF_IEEE_EQUAL(Smallestposval<T>(), 1.1754944e-38f);
  STF_IEEE_EQUAL(smallestposval( as(T{}) ), 1.1754944e-38f);
}
STF_CASE_TPL( "Check smallestposval behavior for double"
            , (double)
            )
{
  using boost::simd::as;
  using boost::simd::functional::smallestposval;
  using boost::simd::Smallestposval;

  STF_TYPE_IS(decltype(Smallestposval<T>()), T);
  STF_IEEE_EQUAL(Smallestposval<T>(), 2.2250738585072013831e-308);
  STF_IEEE_EQUAL(smallestposval( as(T{}) ), 2.2250738585072013831e-308);
}
