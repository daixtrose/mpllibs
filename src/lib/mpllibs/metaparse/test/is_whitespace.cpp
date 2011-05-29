// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_whitespace.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::is_whitespace;

using boost::mpl::apply;

namespace
{
  const suite_path suite = suite_path("util")("is_whitespace");

  typedef apply<is_whitespace, char_space> test_space;
  
  typedef apply<is_whitespace, char_tab> test_tab;
  
  typedef apply<is_whitespace, char_a> test_non_whitespace;
}

MPLLIBS_ADD_TEST(suite, test_space)
MPLLIBS_ADD_TEST(suite, test_tab)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_non_whitespace)


