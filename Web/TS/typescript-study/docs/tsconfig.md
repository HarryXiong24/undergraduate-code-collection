<h1 align="center">
  typescript-study
</h1>

## 目录

### File Inclusion

|选项|类型|默认|描述|
|---|----|---|---|
|exclude|`string[]`|`['node_modules', 'bower_components', 'jspm_packages']`|需要排除的文件|
|extends|`string`|-|从指定的文件中继承配置，这里配置的是继承文件的路径|
|files|`string[]`|-|指定包含在程序中的文件列表，如果文件未找到则会报错|

### Project Options

|选项|类型|默认|描述|
|---|----|---|---|
|[`allowJs`](#allowJs)|`boolean`|`false`|允许编译JS文件|
|[`checkJs`](#checkJs)|`boolean`|`false`|	报告JS文件中的错误。|
|[`declaration`](#declaration)|`boolean`|`false`|生成类型定义文件|
|[`declarationDir`](#declarationDir)|`string`|`n/a`|指定类型定义文件目录|
|[`declarationMap`](#declarationMap)|`boolean`|`false`|生成类型定义的source map|
|[`emitDeclarationOnly`](#emitDeclarationOnly)|`boolean`|`false`|只生成类型定义文件|
|[`jsx`](#jsx)|`react`\|`react-jsx`\|`react-jsxdev`\|`preserve`\|`react-native`|-|指定 `jsx` 代码的生成类型|
|[`noEmit`](#noEmit)|`boolean`|`false`|禁止生成文件|
|[`outDir`](#outDir)|`string`|--|指定输出目录|
|[`removeComments`](#removeComments)|`boolean`|`false`|删除编译后的所有的注释|
|[`rootDir`](#rootDir)|`string`|-|指定输入文件的根目录，用于指定`outDir`控制输出目录结构。|
|[`sourceMap`](#sourceMap)|`boolean`|`false`|生成相应的 `.map` 文件|
|[`target`](#target)|`ES3`\|`ES5`\|`ES6`\|`ES2015`\|`ES2016`\|`ES2017`\|`ES2018`\|`ES2019`\|`ES2020`\|`ESNEXT`|`ES3`|指定 ECMAScript 目标版本|

### Module Resolution

|选项|类型|默认|描述|
|---|----|---|---|
|[`allowSyntheticDefaultImports`](#allowSyntheticDefaultImports)|`boolean`|`false`|允许对不包含默认导出的模块使用默认导入。这个选项不会影响生成的代码，只会影响类型检查。|
|[`baseUrl`](#baseUrl)|`string`|-|定义根目录，进行绝对路径文件解析|
|[`paths`](#paths)|`object`|-|模块名到基于 `baseUrl` 的路径映射的列表|

### Strict Checks

## 编译选项

### allowJs

设置为`true`时，js文件将被 tsc 编译，否则不会。

使用场景：

- 项目中使用`TS`、`JS`进行混合开发

查看示例：

- [allowJs-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/allowJs-true)
- [allowJs-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/allowJs-false)

```
# 设置为 true 时，编译后的文件包含 foo.js
├── dist
│   ├── foo.js
│   └── index.js
├── src
│   ├── foo.js
│   └── index.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 false 时，编译后的文件不包含 foo.js
├── dist
│   └── index.js
├── src
│   ├── foo.js
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)

### checkJs

和`allowJs`配合使用，设置为`true`时，则会报告JS文件中的错误

使用场景：

- 项目中使用`TS`、`JS`进行混合开发

查看示例：

- [checkJs-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/checkJs-true)
- [checkJs-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/checkJs-false)

```js
// constants.js
// parseFloat(3.124); 参数只能为字符串，编译报错
module.exports.pi = parseFloat(3.124);
```

[⇧ 回到目录](#目录)

### declaration

设置为`true`时，生成类型定义文件

使用场景：

- 开发组件库、工具库需要生成类型定义文件时使用

查看示例：

- [declaration-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/declaration-true)
- [declaration-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/declaration-false)

```
# 设置为 true 时，编译后的文件包含 *.d.ts
├── dist
│   ├── index.d.ts
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 false 时，编译后的文件不包含 *.d.ts
├── dist
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)

### declarationDir

和`declaration`配合使用，指定类型定义文件目录

使用场景：

- 开发组件库、工具库需要生成类型定义文件时使用

查看示例：

- [declarationDir](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/declarationDir)

```
# 设置为 dist/types 时，则类型文件将输出到 dist/types
├── dist
│   ├── types
│   │   └── index.d.ts
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)

### declarationMap

生成类型定义的source map

使用场景：

- 开发组件库、工具库需要生成类型定义文件时使用

查看示例：

- [declarationMap-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/declarationMap-true)
- [declarationMap-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/declarationMap-false)

```
# 设置为 true 时，编译后的文件包含 *.d.ts.map
├── dist
│   ├── index.d.ts
│   ├── index.d.ts.map
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 false 时，编译后的文件不包含 *.d.ts.map
├── dist
│   ├── index.d.ts
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)

### emitDeclarationOnly

设置为`true`，只生成类型定义文件

使用场景：

- 只需要类型定义的时候使用

查看示例：

- [emitDeclarationOnly-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/emitDeclarationOnly-true)
- [emitDeclarationOnly-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/emitDeclarationOnly-false)

```
# 设置为 true 时，不会包含 *.js
├── dist
│   └── index.d.ts
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 false 时，包含 *.js
├── dist
│   ├── index.d.ts
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)

### jsx

指定 `jsx` 代码的生成类型

查看示例：

- [jsx-preserve](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/jsx-preserve)
- [jsx-react](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/jsx-react)
- [jsx-react-jsx](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/jsx-react-jsx)
- [jsx-react-jsxdev](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/jsx-react-jsxdev)
- [jsx-native](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/jsx-native)

```tsx
// 源代码
export const helloWorld = () => <h1>Hello world</h1>;
```

```tsx
// jsx 设置为 react
import React from 'react';
export const helloWorld = () => React.createElement('h1', null, 'Hello world');
```

```tsx
// jsx 设置为 preserve
export const helloWorld = () => <h1>Hello world</h1>;
```

```tsx
// jsx 设置为 react-native
export const helloWorld = () => <h1>Hello world</h1>;
```

```tsx
// jsx 设置为 react-jsx
import { jsx as _jsx } from 'react/jsx-runtime';
export const helloWorld = () => _jsx('h1', { children: 'Hello world' }, void 0);
```

```tsx
// jsx 设置为 react-jsxdev
import { jsxDEV as _jsxDEV } from 'react/jsx-dev-runtime';
const _jsxFileName = '**/typescript-study/examples/project-options/jsx-react-jsxdev/src/index.tsx';
export const helloWorld = () => _jsxDEV('h1', { children: "Hello world" }, void 0, false, { fileName: _jsxFileName, lineNumber: 3, columnNumber: 42 }, this);
```

### noEmit

设置为`true`，禁止生成文件

查看示例：

- [noEmit-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/noEmit-true)
- [noEmit-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/noEmit-false)

```
# 设置为 true 时，不会生成编译文件
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 false 时，生成编译文件
├── dist
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)

### rootDir

指定输入文件的根目录，用于指定`outDir`控制输出目录结构。

查看示例：

- [rootDir](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/rootDir)

```
# 设置为 `.` 时，目录如下
├── dist
│   └── src
│       └── a.js
├── src
│   └── a.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 `./src` 时，目录如下
├── dist
│   └── a.js
├── src
│   └── a.ts
├── package.json
└── tsconfig.json
```

### outDir

指定输出目录

查看示例：

- [outDir](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/outDir)

```
# 设置为 `lib` 时，生成目录如下
├── lib
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

### removeComments

设置为`true`，删除编译后的所有的注释

查看示例：

- [removeComments-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/removeComments-true)
- [removeComments-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/removeComments-false)

```ts
// src/index.ts code
/** The translation of 'Hello world' into Portuguese */
export const helloWorldPTBR = "Olá Mundo";

// 设置为 true 时，删除编译后的所有的注释
"use strict";
exports.__esModule = true;
exports.helloWorldPTBR = void 0;
exports.helloWorldPTBR = "Olá Mundo";

// 设置为 false 时，保留注释
"use strict";
exports.__esModule = true;
exports.helloWorldPTBR = void 0;
/** The translation of 'Hello world' into Portuguese */
exports.helloWorldPTBR = "Olá Mundo";
```

### sourceMap

生成相应的 `.map` 文件

查看示例：

- [sourceMap-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/sourceMap-true)
- [sourceMap-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/sourceMap-false)

```
# 设置为 true 时，不会生成 .map 文件
├── dist
│   ├── index.js
│   └── index.js.map
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

```
# 设置为 false 时，不生成 .map 文件
├── dist
│   └── index.js
├── src
│   └── index.ts
├── package.json
└── tsconfig.json
```

### target

指定 ECMAScript 目标版本

查看示例：

- [target-es5](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/target-es5)
- [target-es2015](https://github.com/wangxingkang/typescript-study/tree/main/examples/project-options/target-es2015)

```ts
// src/index.ts code
export let helloWorld = 'hi';

// 设置为 ES5 时，编译结果
"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.helloWorld = void 0;
exports.helloWorld = 'hi';

// 设置为 ES2015 时，编译结果
export let helloWorld = 'hi';
```

### allowSyntheticDefaultImports

允许对不包含默认导出的模块使用默认导入。这个选项不会影响生成的代码，只会影响类型检查。

`export = foo` 是 ts 为了兼容 commonjs 创造的语法，它对应于 commonjs 中的 `module.exports = foo`。

在 ts 中，如果要引入一个通过 `export = foo` 导出的模块，标准的语法是 `import foo = require('foo')`，或者 `import * as foo from 'foo'`。

当它设置为 true 时，允许使用 `import foo from 'foo'` 来导入一个通过 `export = foo` 导出的模块。当它设置为 false 时，则不允许，会报错。

比如 React 的声明文件中，就是通过 export = React 来导出类型：

```ts
export = React;
export as namespace React;

declare namespace React {
  // 声明 React 的类型
}
```

查看示例：

- [allowSyntheticDefaultImports-true](https://github.com/wangxingkang/typescript-study/tree/main/examples/module-resolution/allowSyntheticDefaultImports-true)
- [allowSyntheticDefaultImports-false](https://github.com/wangxingkang/typescript-study/tree/main/examples/module-resolution/allowSyntheticDefaultImports-false)

```
# 设置为 true 时，可以正常使用
import React from 'react';
```

```
# 设置为 false 时，报错
import React from 'react';
// 需要这样使用
import * as React from 'react';
```

### baseUrl

定义根目录，进行绝对路径文件解析

查看示例：

- [baseUrl](https://github.com/wangxingkang/typescript-study/tree/main/examples/module-resolution/baseUrl)

```
# 设置为`./src`时，则可以写绝对路径
# import { helloWorld } from 'hello/world';
├── src
│   ├── hello
│   │   └── world.ts
│   └── index.ts
├── package.json
└── tsconfig.json
```

[⇧ 回到目录](#目录)
 
### paths

和 `baseUrl` 配合使用，模块名到基于 `baseUrl` 的路径映射的列表

使用场景：

- 指定多个别名，防止写更多的相对路径，一般设置`@`指向项目的`src`目录

查看示例：

- [paths](https://github.com/wangxingkang/typescript-study/tree/main/examples/module-resolution/paths)

```
# 目录如下
├── src
│   ├── hello
│   │   └── world.ts
│   └── index.ts
├── package.json
└── tsconfig.json

# 设置为`{ "@/*": ["src/*"] }`时，则可以写绝对路径
# src/index.ts 引入 src/hello/world.ts，代码如下：
# import { helloWorld } from '@/hello/world';
```

[⇧ 回到目录](#目录)