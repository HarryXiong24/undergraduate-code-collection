import type { Equal, Expect } from '@type-challenges/utils'

type cases = [
  Expect<Equal<ReplaceAllX<'foobar', 'bar', 'foo'>, 'foofoo'>>,
  Expect<Equal<ReplaceAllX<'foobar', 'bag', 'foo'>, 'foobar'>>,
  Expect<Equal<ReplaceAllX<'foobarbar', 'bar', 'foo'>, 'foofoofoo'>>,
  Expect<Equal<ReplaceAllX<'t y p e s', ' ', ''>, 'types'>>,
  Expect<Equal<ReplaceAllX<'foobarbar', '', 'foo'>, 'foobarbar'>>,
  Expect<Equal<ReplaceAllX<'barfoo', 'bar', 'foo'>, 'foofoo'>>,
  Expect<Equal<ReplaceAllX<'foobarfoobar', 'ob', 'b'>, 'fbarfbar'>>,
  Expect<Equal<ReplaceAllX<'foboorfoboar', 'bo', 'b'>, 'fobrfobar'>>,
  Expect<Equal<ReplaceAllX<'', '', ''>, ''>>,
]
