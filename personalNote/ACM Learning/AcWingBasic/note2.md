# 二分

## 1. 整数二分

### 1.1 算法原理

对于一个单调的队列，我们可以通过其单调的特性，对于要找到的数`k`可以通过以下方法找到：

> 1. 先确定寻找的范围`l`和`r`
> 2. 当`l<r`时，先取范围中点`mid`，将区间`[l,r]`分为`[l,mid]`和`[mid+1,r]`（此时`mid=l+r>>1`）或`[l,mid-1]`和`[mid,r]`（此时`mid=l+r+1>>1`）
> 3. 然后，在`l<r`条件下，根据`check(mid)`函数，对`l`，r进行更新，直到`l>=r`

### 1.2 代码实现

***本代码思路参考自y总***

```
//将区间[l,r]分为[l,mid]和[mid+1,r]
int bsearch_1(int l,int r){
	while(l<r){
		int mid = l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}return l;
}
//将区间[l,r]分为[l,mid-1]和[mid,r]
int bsearch_2(int l,int r){
	while(l<r){
		int mid = l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1
	}
}
```

### 1.3 相关题目

- [AcWing 789. 数的范围](https://www.acwing.com/problem/content/791/)



## 2. 浮点数二分

### 2.1 算法原理

对于一个单调的队列，我们可以通过其单调的特性，与整数二分相似，对于要找到的数`k`可以通过以下方法找到：

> 1. 先确定寻找的范围`l`和`r`
> 2. 当`r-l>eps`时，先取范围中点`mid`，`mid=(l+r)/2`
> 3. 然后，在`r-l>eps`条件下，根据`check(mid)`函数，对`l`，`r`进行更新，直到`r-l<=eps`

### 2.2 代码实现

***本代码思路参考自y总***

```
double bsearch(double l,double r){
	while(r-l>eps){
		double mid = (l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}return l;
}
```

### 2.3 相关题目

- [AcWing 790. 数的三次方根](https://www.acwing.com/problem/content/792/)

![](https://raw.githubusercontent.com/dreaife/PictureOfDreaife/main/picture/202112081934120.png?token=ARNBM5F2UAC2KPANFLKILQLBWCMI2)
