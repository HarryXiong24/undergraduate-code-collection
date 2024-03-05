import type { Equal, Expect } from '@type-challenges/utils'

type E =  'ab' extends 'abc' ? true : false

type cases = [
  Expect<Equal<StartsWith<'abc', 'ac'>, false>>,
  Expect<Equal<StartsWith<'abc', 'ab'>, true>>,
  Expect<Equal<StartsWith<'abc', 'abcd'>, false>>,
]
