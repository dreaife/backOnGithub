留一个作业

子类 需要继承父类，在其基础上进行更改
```
ArtChild  extends  ArtGroupPerson {
    得分的属性 int   score
    
    MySkill（）{
        +5分
    }
    extraTalen（）{
        +2
    }
}


// 在一个公有的方法里   循环3次数

子类1 编号默认就是1

子类2  编号就是2

子类3  编号就是3

for （int  i=0;i<10;i++){

// 1=10

int  shu = (int) Math.random()*3+1

随机到谁了，谁的综合得分（技能分数和额外的技能分数）增加

随机的编号是2  轮到2号人物出场表演

}
```

最后统计谁的得分最多

将源码 和  运行截图直接粘贴就可以，粘贴不了就打包，提交这个平台