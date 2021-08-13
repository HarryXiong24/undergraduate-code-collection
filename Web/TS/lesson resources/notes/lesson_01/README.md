# 第一节
## 1.TS的安装与编译

****

**安装TypeScripe**
```bash
npm install -g typescript
```

**编译TypeScript**
假设此时已有ts文件index.ts
```bash
tsc index.ts
```

## 2.VSCode自动编译ts文件到js文件

**2.1 生成tsconfig.json文件**
项目根目录下运行命令
```bash
tsc --init
```

**2.2 配置tsconfig.json文件**
打开tsconfig.json文件，配置如下：
![tsconfig配置文件1](images/lesson_01/tsconfig_01.png)
修改**outDir**属性，解除注释，将**outDir**属性的值改为需要保存的路径（默认为当前路径）
此时我们改为根目录下的js文件中。如下图：
![tsconfig配置文件2](images/lesson_01/tsconfig_02.png)

**2.3 修改VSCode监听任务**
VSCode中点击“任务/Terminal” => "运行任务/Run Task" => "监视tsconfig.json/tsc:watch tsconfig.json"。这样既可边写代码VSCode就边将代码转为js代码保存在设置的outDir路径下。