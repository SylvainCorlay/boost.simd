//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/pack.hpp>

//! [scalar-dot]
template <typename Value>
Value dot(Value* first1, Value* last1, Value* first2)
{
  Value v(0);

  for (; first1 < last1; ++first1, ++first2) {
    v += (*first1) * (*first2);
  }

  return v;
}
//! [scalar-dot]
