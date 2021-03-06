# lazy

## Synopsis

```cpp
template <class Exp>
struct lazy
{
  // unspecified
};
```

## Description

`Exp` is an angly bracket expression of metafunctions calling each other with
other angly bracket expressions as arguments. `lazy` forces the evaluation of
every argument before passing it to the enclosing metafunction call. Thus, for
example

```cpp
lazy<boost::mpl::plus<f<boost::mpl::int_<11>>, boost::mpl::int_<13>>::type
```

evaluates

```cpp
boost::mpl::plus<
  f< boost::mpl::int_<11>::type >::type,
  boost::mpl::int_<13>::type
>::type
```

Lazy can deal with templates taking not more than
`MPLLIBS_LIMIT_METAFUNCTION_ARITY` template arguments. This is macro and its
value is 10 by default.

## Header

```cpp
#include <mpllibs/metamonad/lazy.hpp>
```

## Expression semantics

For any `t` template, and `c1` ... `cn` classes

```cpp
lazy<t<c1, ..., cn>>::type
```

is equivalent to

```cpp
t<lazy<c1>::type, ..., lazy<cn>::type>::type
```

For any `c` class not being a template instance

```cpp
lazy<c>::type
```

is equivalent to

```cpp
c::type
```

For any `t` class the following are equivalent:

```cpp
lazy<lazy<t>>::type
lazy<t>::type
```

## Example

```cpp
using namespace boost::mpl;

template <class N>
struct fib :
  eval_if<
    typename less<N, int_<2>>::type,
    int_<1>,
    lazy<plus<fib<minus<N, int_<1>>>, fib<minus<N, int_<2>>>>>
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



