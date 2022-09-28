# CSS学习

CSS：层叠样式表，用于修饰HTML标签

## 1. 样式定义方式

- 行内样式表

在行内定义，只影响行内内容

```html
<!--style-->
<img src="static/images/icon.png" alt="" style="width: 300px;">
```

- 内部样式表

在head中定义，对同一页面元素产生影响。

```html
    <style type="text/css">
        img {
            width: 200px;
            height: 200px;
        }
        div {
            width: 200px;
            height: 200px;
            border-radius: 50%;
        }
        p {
            width: 50px;
            height: 50px;
            background-color: red;
        }
        .tAA {
            background-color: aqua;
        }
        .big {
            width: 70px;
            height: 70px;
        }
    </style>
```

- 外部样式表

定义在css文件中，通过link进行导入，可以对多个页面产生影响。

注释时使用`/*注释*/`，不能使用`//`

导入多个css文件时，对于相同的项目，后面的css文件配置会覆盖前面的css文件配置。

同样，css文件内类部配置冲突时，当同时调用，后位配置覆盖前方配置。

```html
<link rel="stylesheet" href="static/css/style.css">
```

## 2. 选择器

- 标签选择器

```css
div {
	width: 200px;
	height: 200px;
	border-radius: 50%;
}
```

- ID选择器

```css
#test {
	width: 200px;
	height: 200px;
	border-radius: 50%;
}
```

- 类选择器

```css
.test {
	width: 200px;
	height: 200px;
	border-radius: 50%;
}
```

- 伪类选择器

```css
.effect:hover {
    transform: scale(1.1);
    transition: 0500ms;
    background-color: lightblue;
}
```

> - 链接伪类选择器：
>
>   - `link`：链接访问前的样式
>
>   - `visited`：链接访问后的样式
>
>   - `hover`：鼠标悬停时的样式
>
>   - `active`：鼠标点击后长按时的样式
>
>   - `focus`：聚焦后的样式
>
> - 位置伪类选择器：
>   - `nth-child(an + b)`：选择是其父标签第`a*n+b`个子元素的所有元素。e.g. `even`偶，`odd`奇。
>
> - 目标伪类选择器：
>   - `target`：当url指向该元素时生效。

- 复合选择器
  由两个及以上基础选择器组合而成的选择器。

  - `element1, element2`：同时选择元素element1和元素element2。
  - `element.class`：选则包含某类的element元素。
  - `element1 + element2`：选择紧跟element1的element2元素。
  - `element1 element2`：选择element1内的所有element2元素。
  - `element1 > element2`：选择父标签是element1的所有element2元素。

- 通配符选择器

  - `*`：选择所有标签
  - `[attribute]`：选择具有某个属性的所有标签
  - `[attribute=value]`：选择attribute值为value的所有标签

- 伪元素选择器
  将特定内容当做一个元素，选择这些元素的选择器被称为伪元素选择器。

  - `first-letter`：选择第一个字母

  - `first-line`：选择第一行

  - `selection`：选择已被选中的内容

  - `after`：可以在元素后插入内容

  - `before`：可以在元素前插入内容

- 样式渲染优先级
  - 权重大小，越具体的选择器权重越大：`!important` > 行内样式 > ID选择器 > 类与伪类选择器 > 标签选择器 > 通用选择器
  - 权重相同时，后面的样式会覆盖前面的样式
  - 继承自父元素的权重最低

## 3. 颜色

- 预设颜色：`black、white、red、green、blue、lightblue等`
- 16进制表示：`#AABBCC`

其中第1-2位表示红色，第3-4位表示绿色，第5-6位表示蓝色。

- RGB表示：`rgb(173,216,230)`

- RGBA表示：`rgba(173,216,230,0.5)`最后是透明度。
- 取色
  - 网站中`F12`查看元素信息
  - QQ截图

## 4. 文本

