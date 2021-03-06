# multi_let

## Synopsis

```cpp
template <class ValueMap, class Body>
struct multi_let
{
  // unspecified
};
```

## Description

Variable substitution in an angly-bracket expression. The list of variables are
defined by the `boost::mpl::map` value `ValueMap`. The keys are the classes
representing the variable names, the values are syntaxes to replace the
variables with. The result of `multi_let` is `Body` with all occurrences of the
variable names replaced by the corresponding value.

## Header

```cpp
#include <mpllibs/metamonad/multi_let.hpp>
```

## Expression semantics

For any `k >= 0`, `n1`, ..., `nk` and `v1`, ..., `vk` classes and `b`
angly-bracket expressions

```cpp
multi_let<
  boost::mpl::map<
    pair<n1, v1>,
    // ...
    pair<nk, vk>
  >,
  b
>::type
```

is equivalent to

```cpp
let<
  n1, v1,
  let<
    n2, v2,

    // ...

    let<
      nk, vk,
      b
    >::type

    // ...

  >::type
>::type
```

## Example

```cpp
using namespace boost::mpl;
using namespace mpllibs::metamonad::name;

typedef
  eval_syntax<multi_let<map<pair<x, syntax<double>>>, syntax<x>>>::type
  this_is_double;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



