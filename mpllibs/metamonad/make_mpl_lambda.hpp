#ifndef MPLLIBS_METAMONAD_MAKE_MPL_LAMBDA_HPP
#define MPLLIBS_METAMONAD_MAKE_MPL_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/lambda.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(make_mpl_lambda, (T)) ((boost::mpl::lambda<T>));
  }
}

#endif

