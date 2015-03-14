#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_12_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_12_HPP

// Automatically generated header file

// Definitions before section 11.2
#include "11_2.hpp"

// Definitions of section 11.2
#include <mpllibs/metaparse/define_error.hpp>

MPLLIBS_DEFINE_ERROR(missing_primary_expression, "Missing primary expression");

struct plus_exp3;

using paren_exp4 = middle_of<lparen_token, plus_exp3, rparen_token>;

#include <mpllibs/metaparse/change_error_message.hpp>

using primary_exp3 = change_error_message<one_of<int_token, paren_exp4>, missing_primary_expression>;

using unary_exp3 = 
 foldrp< 
   minus_token, 
   primary_exp3, 
   boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type 
 >;

using mult_exp6 = 
 foldlp< 
   sequence<one_of<times_token, divides_token>, unary_exp3>, 
   unary_exp3, 
   boost::mpl::quote2<binary_op> 
 >;

struct plus_exp3 : 
 foldlp< 
   sequence<one_of<plus_token, minus_token>, mult_exp6>, 
   mult_exp6, 
   boost::mpl::quote2<binary_op> 
 > {};

using exp_parser20 = build_parser<plus_exp3>;

// query:
//    exp_parser20::apply<MPLLIBS_STRING("hello")>::type

#endif

