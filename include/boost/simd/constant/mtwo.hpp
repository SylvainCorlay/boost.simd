//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MTWO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MTWO_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Mtwo Mtwo (function template)

  Generates the constant@c -2

  @headerref{<boost/simd/constant/mtwo.hpp>}

  @par Description

  1.  @code
      template<typename T> T Mtwo();
      @endcode

  2.  @code
      template<typename T> T Mtwo( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T that evaluates to -2.

  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `T(-2)`:

  @par Requirements
  - **T** models Value
**/

#include <boost/simd/constant/scalar/mtwo.hpp>
#include <boost/simd/constant/simd/mtwo.hpp>

#endif
