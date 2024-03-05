import type { Equal, Expect } from '@type-challenges/utils'


type P = Parameters<(arg0: string, arg1: number, arg2: boolean) => void>
type RR = ReturnType<(arg0: string, arg1: number, arg2: boolean) => void>
type R = Reverse<P>
type F = FlipArguments<(arg0: string, arg1: number, arg2: boolean) => void>

type cases = [
  Expect<Equal<FlipArguments<() => boolean>, () => boolean>>,
  Expect<Equal<FlipArguments<(foo: string) => number>, (foo: string) => number>>,
  Expect<Equal<FlipArguments<(arg0: string, arg1: number, arg2: boolean) => void>, (arg0: boolean, arg1: number, arg2: string) => void>>,
]
