//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_ONEO_12_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_ONEO_12_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant oneo_12.

    @return The Oneo_12 constant for the proper type
  **/
  template<typename T> T Oneo_12();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant oneo_12.

      @return The Oneo_12 constant for the proper type
    **/
    const boost::dispatch::functor<tag::oneo_12_> oneo_12 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/oneo_12.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
