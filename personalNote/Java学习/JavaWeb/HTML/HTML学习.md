# HTML学习

[MDN官方文档](https://developer.mozilla.org/zh-CN/)

## 1. 结构

```html
<!DOCTYPE html>
<html lang="zh-CN">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width,initial-scale=1.0">
    <title>Web应用课</title>
</head>

<body>
    <h1>第一讲</h1>
</body>

</html>
```

- `<html>`

HTML文档顶级元素

- `<head>`

规定文档相关的配置信息（元数据），包括文档的标题，引用的文档样式和脚本等。

- `<body>`

表示文档的内容。`document.body`

- `<title>`

文档标题。

- `<meta>`

表示那些不能由其它 HTML 元相关（meta-related）元素（(`<base>、<link>, <script>、<style> 或 <title>`）之一表示的任何元数据信息。

> - charset
>
> `<meta charset="UTF-8">`
>
> - name content
>
> ```html
> <meta name="viewport" content="width=device-width,initial-scale=1.0">
> <meta name="description" content="练习页面">
> <meta name="keywords" content="test">
> ```

- icon

`<link rel="icon" href="images/icon.png">`

- 多行注释

```html
<!--
	注释测试
-->
```

## 2. 文本标签

- `<div>`

通用型的流内容容器，在不使用CSS的情况下，其对内容或布局没有任何影响。块状，末尾带回车。

eg.`<h1> <p> <pre> <ul> <ol> <table>`

- `<span>`

短语内容的通用行内容器，并没有任何特殊语义。可以使用它来编组元素以达到某种样式意图（通过使用类或者 Id 属性），或者这些元素有着共同的属性。

eg.`<i> <b> <del> <ins> <td> <a>`

- `<h1>`

标题`<h1>-<h6>`

- `<p>`

段落，过滤掉空格和回车。

- `<pre>`

表示预定义格式文本。在该元素中的文本通常按照原文件中的编排，以等宽字体的形式展现出来，文本中的空白符（比如空格和换行符）都会显示出来。

`&lt; == <			&gt; == >`

- `<br>`

回车，换行。

`&nbsp; == 空格`

- `<hr>`

横线

- `<i>`

斜体

- `<b> | <strong>`

加粗

- `<del>`

删除线

- `<ins>`

下划线

- `<mark>`

标注



## 3. 图片

```html
<img width="100px" src="/mountain.jpg" alt="大山">
```

- src

图片的文件路径

- alt

图片的文字描述，非强制

- height

高度，单位CSS像素

- width

宽度，单位CSS像素

## 4. 音频和视频

- 音频

`<audio>`

> - 播放单个音频
>
> ```html
> <audio
>     controls
>     src="/audios/bgm.mp3">
>         播放失败
> </audio>
> ```
>
> - 播放多个音频
>
> ```html
> <audio controls>
>     <source src="/audios/sound1" type="audio/mpeg"/>
>     <source src="/audios/sound2" type="audio/mpeg"/>
> </audio>
> ```

- 视频

`<video>`

```html
<video controls width="500">

    <source src="/videos/video1.mp4" type="video/mp4">

    <source src="/videos/video2.mp4" type="video/mp4">

    播放失败
</video>
```

## 5. 超链接

`<a href="https://dreaife.cc" target="_blank">dreaife</a>`

点击跳到新页面`target="_blank"`

## 6. 表单

`form`

- `<input>`

```html
<form>
    <label for="aaa">AAA</label>
    <input type="text" name="AaA" id="aaa" placeholder="fdalflaf">
    <button type="submit">提交</button>
</form>
```

> `type=""`
>
> - text
>
> 创建基础的单行文本框
>
> - number
>
> 输入一个数字，拒绝非数字输入，提供步进箭头
>
> - email
>
> 输入或编辑一个电子邮箱地址
>
> - password
>
> 输入密码，其中文本被遮蔽以致于无法读取，通常通过用诸如星号（“*”）或点（“•”）等符号替换每个字符来实现
>
> - radio
>
> 默认渲染为小型圆圈图表，填充即为激活，类似于checkbox
>
> 相同name互斥

常用属性有：

`name	id	maxlength	minlength	required	placeholder(当表单控件为空时，控件中显示的内容)`

- `action` 提交后跳转。

- `<textarea>`
- `<select> & <option>`

```html
<label for="lang">语言</label>
<select name="lang" id="lang">
	<option value="">select...</option>
	<option value="cpp">cpp</option>
</select>
```

## 7. 列表

- `<ul>`

无序列表

- `ol`

有序列表

```html
<ul>
  <li>first item</li>
  <li>second item</li>
  <li>third item</li>
</ul>

<ol>
  <li>Fee</li>
  <li>Fi</li>
  <li>Fo</li>
  <li>Fum</li>
</ol>
```

- `<dl> <dt> <dd>`

```html
<dl>
    <dt>Name</dt>
    <dd>Godzilla</dd>
    <dt>Born</dt>
    <dd>1952</dd>
    <dt>Birthplace</dt>
    <dd>Japan</dd>
    <dt>Color</dt>
    <dd>Green</dd>
    <dd>Orange</dd>
</dl>
```

`<dt>` 不tab

`<dd>` 加tab

## 8. 表格

```html
<table>
        <caption>成绩单</caption>		<!--标题-->
        <thead>							<!--表头-->
            <tr>
                <th>姓名</th>
                <th>数学</th>
                <th>语文</th>
                <th>英语</th>
            </tr>
        </thead>
        <tbody>							<!--数据-->
            <tr>
                <td>Alice</td>
                <td>100</td>
                <td>99</td>
                <td>98</td>
            </tr>
            <tr>
                <td>Bob</td>
                <td>99</td>
                <td>98</td>
                <td>97</td>
            </tr>
        </tbody>
    </table>
```

- table
- thead
- tbody
- tr
- th
- td
- caption

## 9. 语义标签

- header

用于展示介绍性内容，通常包含一组介绍性的或是辅助导航的实用元素。

- nav

表示页面的一部分，其目的是在当前文档或其他文档中提供导航链接。

- section

表示一个包含在 HTML 文档中的独立部分。

- figure

在主文中引用的图片，插图，表格，代码段等等，当这部分转移到附录中或者其他页面时不会影响到主体。

- figcaption

是与其相关联的图片的说明/标题，用于描述其父节点 &lt;figure&gt; 元素里的其他数据。

- article

表示文档、页面、应用或网站中的独立结构，其意在成为可独立分配的或可复用的结构。

- aside

示一个和其余页面内容几乎无关的部分，被认为是独立于该内容的一部分并且可以被单独的拆分出来而不会使整体受影响。

- footer

表示最近一个章节内容或者根节点元素的页脚。一个页脚通常包含该章节作者、版权数据或者与文档相关的链接等信息。

```html
	<header>
        <h3>我的收藏夹</h3>
    </header>
    <section>
        <h4>图片</h4>
        <figure>
            <img width="100" src="/images/logo.png" alt="logo">
            <figcaption>logo</figcaption>
        </figure>
    </section>
    <section>
        <h4>古诗</h4>
        <article>
            <h5>春晓</h5>
            <p>春眠不觉晓，处处闻啼鸟。夜来风雨声，花落知多少。</p>
        </article>
    </section>
    <footer>
        &copy;2018-2022 Me 版权所有
    </footer>
```

## 10. 特殊符号

| HTML源代码 | 显示结果 | 描述                   |
| ---------- | -------- | ---------------------- |
| `&lt;`     | &lt;     | 小于号或显示标记       |
| `&gt;`     | &gt;     | 大于号或显示标记       |
| `&amp;`    | &amp;    | 可用于显示其它特殊字符 |
| `&quot;`   | &quot;   | 引号                   |
| `&reg;`    | &reg;    | 已注册                 |
| `&copy;`   | &copy;   | 版权                   |
| `&trade;`  | &trade;  | 商标                   |
| `&nbsp;`   | &nbsp;   | 不断行的空白           |

