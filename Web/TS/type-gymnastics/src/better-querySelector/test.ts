import { Equal, Expect } from '@type-challenges/utils'
import { ParseSelector, querySelector } from '.'

type Tests = [
  Expect<Equal<ParseSelector<''>, Element>>,
  Expect<Equal<ParseSelector<'my-web-component'>, Element>>,
  Expect<Equal<ParseSelector<'.text-center'>, Element>>,
  Expect<Equal<ParseSelector<'#submit'>, Element>>,
  Expect<Equal<ParseSelector<'[type=email]'>, Element>>,
  Expect<Equal<ParseSelector<'body div'>, HTMLDivElement>>,
  Expect<Equal<ParseSelector<'body section'>, HTMLElement>>,
  Expect<Equal<ParseSelector<'form > button'>, HTMLButtonElement>>,
  Expect<Equal<ParseSelector<'h1 ~ p'>, HTMLParagraphElement>>,
  Expect<Equal<ParseSelector<'h1 + p'>, HTMLParagraphElement>>,
  Expect<Equal<ParseSelector<' h2 '>, HTMLHeadingElement>>,
  Expect<Equal<ParseSelector<'div, span'>, HTMLDivElement | HTMLSpanElement>>,
  Expect<Equal<ParseSelector<'span.text-center'>, HTMLSpanElement>>,
  Expect<Equal<ParseSelector<'button#submit'>, HTMLButtonElement>>,
  Expect<Equal<ParseSelector<'input[type=email]'>, HTMLInputElement>>,
  Expect<Equal<ParseSelector<'.wrapper div.box'>, HTMLDivElement>>,
  Expect<
    Equal<ParseSelector<'.wrapper div.box, .sidebar div.alert'>, HTMLDivElement>
  >,
  Expect<
    Equal<
      ParseSelector<'.container > #sign-up-form > div#notice, span.tip'>,
      HTMLDivElement | HTMLSpanElement
    >
  >
]

const el: HTMLDivElement | HTMLSpanElement | null = querySelector(
  '.container > #sign-up-form > div#notice, span.tip'
)
