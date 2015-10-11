//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/sqrteps.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check sqrteps behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::sqrteps;
  using boost::simd::Sqrteps;

  STF_TYPE_IS(decltype(Sqrteps<T>()), T);
  STF_EQUAL(Sqrteps<T>(), T(1));
  STF_EQUAL(sqrteps( as(T{}) ),T(1));
}

STF_CASE_TPL( "Check sqrteps behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::sqrteps;
  using boost::simd::Sqrteps;
  using boost::simd::Eps;

  STF_TYPE_IS(decltype(Sqrteps<T>()), T);
  auto z1 = Sqrteps<T>();
  STF_ULP_EQUAL(z1*z1, Eps<T>(), 0.5);
  auto z2 = sqrteps( as(T{}) );
  STF_ULP_EQUAL(z2*z2, Eps<T>(), 0.5);

}
