# TS中的模块

## 概念

**模块的概念（官方）**

关于术语的一点说明：请务必注意一点，TS 1.5里术语已经发生了变化。“内部模块”现在称作“命名空间”。“外部模块”现在称为“模块”，模块在其自身的作用域里执行，而不是在全局作用域里；这意味着定义在一个模块里的变量、函数、类等等在模块外部是不可见的，除非你明确地使用`export`形式之一导出他们。相反，如果想使用其他模块导出的变量、函数、类、接口等等，你必须要导入它们，可以使用`import`形式之一。

**模块的概念（自己理解）**

我们可以把一些公共的功能单独抽离成一个文件作为一个模块。

模块里面的变量、函数、类等默认是私有的，如果我们要在外部访问模块里面的数据（变量、函数、类……），我们需要通过`export`暴露模块里面的数据（变量、函数、类……）。

暴露后我们通过`import`引入模块就可以使用模块里面暴露的数据（变量、函数、类……）。

## 暴露数据的方法

方法一

```ts
export function getData():void {
    /* TODO */
}

export a = 100;
```

方法二

```ts
function getData():void {
    /* TODO */
}

const a = 100;

export {getData, a};
```

## export default 默认导出

每个模块都可以有一个default导出。默认导出使用default关键字标记，并且一个模块只能够有一个default导出。需要使用一种特殊的导入形式来导入。 

export default在一个模块中只能用一次。

```ts
function getData(): void {
    /* TODO */
}

export default getData;
```

使用export default的时候，引入时使用下面这种方法：

```ts
import getData from './test';
```

## import 

import可以使用关键字对引入模块方法的自定义命名。

```ts
import {getData as get} from './test';

get();              // 调用getData()
```