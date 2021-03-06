# let_c

## Synopsis

```cpp
template <class Name, class Exp, class Body>
struct let_c
{
  // unspecified
};
```

## Description

The same as [`let`](let.html), but `Exp` and `Body` are angle-bracket
expressions and not syntaxes.

## Header

```cpp
#include <mpllibs/metamonad/let_c.hpp>
```

## Expression semantics

For any `n`, `e` and `b` classes

```cpp
let_c<n, e, b>::type
```

is equivalent to

```cpp
let<n, syntax<e>, syntax<b>>::type
```

## Example

```cpp
using boost::mpl::times;
using boost::mpl::plus;
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

template <class N>
struct my_metafunction :
  eval_syntax<
    let_c<
      x, plus<n, int_<13>>,
      times<x, x>
    >
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



