// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/lazy_if.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::lazy_if;

using boost::mpl::equal_to;
using boost::mpl::true_;
using boost::mpl::false_;
using boost::mpl::eval_if;

namespace
{
  const suite_path suite = suite_path("util")("lazy_if");
  
  typedef lazy_if<equal_to<int13, int13>, true_, false_> evaluated_condition;
  
  typedef
    eval_if<false_, lazy_if<can_not_be_instantiated, int11, int13>, true_>
    not_evaluated_condition;
}

MPLLIBS_ADD_TEST(suite, evaluated_condition)
MPLLIBS_ADD_TEST(suite, not_evaluated_condition)



