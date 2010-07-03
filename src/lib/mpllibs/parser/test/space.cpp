// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/space.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, ' ', 'e', 'l', 'l', 'o'> str__ello;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::space::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Space_TestWithText;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::space::apply<str__ello>::type::first,
      boost::mpl::integral_c<char, ' '>
    >
    Space_TestWithSpace;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::space::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Space_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(Space_TestWithText)
MPLLIBS_ADD_TEST(Space_TestWithSpace)
MPLLIBS_ADD_TEST(Space_TestWithEmptyString)

