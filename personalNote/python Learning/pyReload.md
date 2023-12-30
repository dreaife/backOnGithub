# 变量

## 变量命名

字母、数字、下划线

## 数据类型

- 字符串

  title()/upper()/lower()/+/rstrip()

- 数字

  str()

  - 整数
  - 浮点数

- 注释

  #

# 列表

按特定顺序排列的元素**[]**

## 访问列表

从0索引

list[0]

## 修改列表

- 修改
  list[0] = change

- 添加

  append(item)/insert(index,item)

- 删除

  del list[index]/list.pop([index])/list.remove(val)

## 列表排序

- 永久排序sort()
- 临时排序sorted(list)
- 逆序打印reverse()
- 列表长度len(list)

## 列表操作

- 遍历列表
  for list in lists:

  缩进判断层次/循环冒号

- 数值列表

  range(l,r,step) list() **乘方

  min()/max()/sum()

  列表解析：`squares = [value**2 for value in range(1,11)] `

- 列表切片

  list[l:r] : [l,r) [-3:0] : 队尾三个

- 列表复制

  浅拷贝：new_list = list

  深拷贝：new_list = list[:]

## 元组

不可变的列表 **()**

- 定义元组
- 遍历元组
- 修改元组变量（内部不可修改，修改赋值变量）

# IF语句

- 条件测试

  == / != / >|>=|<|<= / and | or / in | not in / 布尔表达式

## if语句

- if condition:
- if condition:   else:
- if condition: else if condition: else:

# 字典

键值对**{key:val}**

## 使用字典

- 访问字典dict[key]
- 添加键值对dict[key] = val
- 空字典{}
- 修改字典dict[key] = new_val
- 删除键值对del dict[key]

## 遍历字典

- 遍历所有键值对 for k,v in dict.items()
- 遍历键 dict.keys()
- 遍历值 dict.values()
- 顺序遍历值 sorted(dict.values())

## 嵌套

字典存在列表中/列表存在字典中/...

# 输入和while循环

## 输入

input("程序提示")：程序暂停，等待输入

- 默认字符输入
- int()保证数值输入

## while循环

while condition:

- break退出循环
- continue下个循环
- ctrl+c退出死循环

### while修改循环列表/字典

- 列表间移动元素
- 删除包含特定值的所有列表元素
- 使用用户输入填充

# 函数

## 定义函数

- 无参 def func():
- 有参 def func(arg1,...)

## 传参

- 位置实参
- 关键字实参
- 默认值（默认值放在参数列后面）

## 返回值

return

## 传递列表

- 单参输入列表，返回循环答案

- 传入列表，修改列表

- 防止修改列表 func(list[:])

## 传递任意实参

- 接受多个形参 def func(*args):

- 多个参数需放在最后
- 使用任意数量关键字形参 **args接受字典

## 函数存储模块

- 导入import 
- 导入特定函数 from module_name import func_name
- 赋值别名给函数/模块 as

# 类

## 创建/使用类

- 定义类

`class Name():`

`def __init__(self):`构造函数

- 创造类 ClassName(arg)
- 调用方法/访问属性 class.XXX

## 继承

- Class(Father)继承
- 子类`__init__`调用super()构造
- 子类方法
- 重写父类方法
- 类包实例

## 导入类

- import
- 一个模块，多个类

# 文件和异常



