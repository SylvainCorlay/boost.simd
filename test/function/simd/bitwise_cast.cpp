//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

STF_CASE( "Check bitwise_cast between integer types" )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<uint16_t>::static_size;

  {
    using ps_t = bs::pack<std::uint16_t,N>;
    using pc_t = bs::pack<std::uint8_t,2*N>;

    STF_EQUAL ( bs::bitwise_cast<ps_t>( pc_t(0x01) )  , ps_t(0x0101)  );
    STF_EQUAL ( bs::bitwise_cast<pc_t>( ps_t(0x0101) ), pc_t(0x01)     );
  }

  {
    using ps_t = bs::pack<std::uint16_t,N/2>;
    using pc_t = bs::pack<std::uint8_t,N>;

    STF_EQUAL ( bs::bitwise_cast<ps_t>( pc_t(0x01) )  , ps_t(0x0101)  );
    STF_EQUAL ( bs::bitwise_cast<pc_t>( ps_t(0x0101) ), pc_t(0x01)     );
  }

  {
    using ps_t = bs::pack<std::uint16_t,2*N>;
    using pc_t = bs::pack<std::uint8_t,4*N>;

    STF_EQUAL ( bs::bitwise_cast<ps_t>( pc_t(0x01) )  , ps_t(0x0101)  );
    STF_EQUAL ( bs::bitwise_cast<pc_t>( ps_t(0x0101) ), pc_t(0x01)     );
  }
}

STF_CASE( "Check bitwise_cast between integer & real types" )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<float>::static_size;

  {
    using pf_t = bs::pack<float,N>;
    using pi_t = bs::pack<std::uint32_t,N>;
    STF_EQUAL ( bs::bitwise_cast<pi_t>( pf_t(1.f) )         , pi_t(0x3F800000UL)  );
    STF_EQUAL ( bs::bitwise_cast<pf_t>( pi_t(0x3F800000UL) ), pf_t(1.f)           );
  }

  {
    using pf_t = bs::pack<float,N/2>;
    using pi_t = bs::pack<std::uint32_t,N/2>;
    STF_EQUAL ( bs::bitwise_cast<pi_t>( pf_t(1.f) )         , pi_t(0x3F800000UL)  );
    STF_EQUAL ( bs::bitwise_cast<pf_t>( pi_t(0x3F800000UL) ), pf_t(1.f)           );
  }

  {
    using pf_t = bs::pack<float,N*2>;
    using pi_t = bs::pack<std::uint32_t,N*2>;
    STF_EQUAL ( bs::bitwise_cast<pi_t>( pf_t(1.f) )         , pi_t(0x3F800000UL)  );
    STF_EQUAL ( bs::bitwise_cast<pf_t>( pi_t(0x3F800000UL) ), pf_t(1.f)           );
  }
}

STF_CASE_TPL( "Check bitwise_cast between arithmetic & logical types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  static const std::size_t N = bs::pack<T>::static_size;

  {
    using pa_t = bs::pack<T,N>;
    using pl_t = bs::pack<bs::logical<T>,N>;
    STF_IEEE_EQUAL ( bs::bitwise_cast<pa_t>( pl_t(true) )         , bs::Allbits<pa_t>() );
    STF_IEEE_EQUAL ( bs::bitwise_cast<pl_t>( bs::Allbits<pa_t>() ), pl_t(true)          );
  }

  {
    using pa_t = bs::pack<T,N/2>;
    using pl_t = bs::pack<bs::logical<T>,N/2>;
    STF_IEEE_EQUAL ( bs::bitwise_cast<pa_t>( pl_t(true) )         , bs::Allbits<pa_t>() );
    STF_IEEE_EQUAL ( bs::bitwise_cast<pl_t>( bs::Allbits<pa_t>() ), pl_t(true)          );
  }

  {
    using pa_t = bs::pack<T,N*2>;
    using pl_t = bs::pack<bs::logical<T>,N*2>;
    STF_IEEE_EQUAL ( bs::bitwise_cast<pa_t>( pl_t(true) )         , bs::Allbits<pa_t>() );
    STF_IEEE_EQUAL ( bs::bitwise_cast<pl_t>( bs::Allbits<pa_t>() ), pl_t(true)          );
  }
}
