# either

## Synopsis

```cpp
template <class L, class R>
struct either_tag;

template <class T> struct left;
template <class T> struct right;
```

## Description

Algebraic data type with two constructors: `left` and `right`. It can be used to
represent values that fall into one of two categories. When it is used for error
reporting, `right` represents success and `left` represents failure.

## Header

```cpp
#include <mpllibs/metamonad/either.hpp>
```

## Example

```cpp
using boost::mpl::equal_to;
using boost::mpl::int_;

struct division_by_zero;

template <class A, class B>
struct divide :
  if_<
    equal_to<A, int_<0>>,
    left<division_by_zero>,
    right<divides<A, B>>
  >
  {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



