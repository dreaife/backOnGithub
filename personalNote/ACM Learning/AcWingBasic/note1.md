# 排序

## 1. 快速排序

1. 原理

   对于一段无序的数列，若要将其排序，可以以此步骤进行：

   - 对于一段的数列，可以先任取一点`mid`作为判断点。(其中`mid`一般为数列中点)
   - 对于这段数列进行一次遍历，将大于`mid`的数放于右端，小于`mid`的数放于左端。
   - 然后对于分配过的序列，选取其`[l,p]`,`[p+1,r]`两个子段继续上述操作，直到长度为`1`。(其中`p`为上述左右两端的分界点)

2. 具体实现(代码)

   ***本代码思路参考自y总***

   ```c++
   void quick_sort(int a[],int l,int r){
   	if(l>=r) return;//设置退出条件
   	int i=l-1,j+1,mid = a[l+r>>1];//设置判断点
   	while(i<j){
   		do i++;while(a[i]<mid);
   		do j--;while(a[j]>mid);
   		if(i<j) swap(a[i],a[j]);
   	}
   	quick_sort(a,l,j);//继续对子段排序
   	quick_sort(a,j+1,r);
   }
   ```

   - 时间复杂度：$O(N*logN)$

3.相关题目

- [AcWing 785. 快速排序](https://www.acwing.com/problem/content/787/)
- [AcWing 786. 第k个数](https://www.acwing.com/problem/content/788/)



## 2. 归并排序

1. 原理

   对于一段无序的数列，与快速排序相似，若要将其排序，可以以此步骤进行：

   - 对于一段的数列，可以先任取一点`mid`作为分割点。(其中`mid`一般为数列中点)
   - 先选取其`[l,mid]`,`[mid+1,r]`两个子段继续排序，并假定其已经排序完成。
   - 然后对于已经排序过的两段子段，按照排序顺序先放入`b`数组中，然后再将排序过的数列覆盖原数列。

2. 具体实现(代码)

   ***本代码思路参考自y总***

   ```c++
   void merge_sort(int a[],int b[],int l,int r){
   	if(l>=r) return;//设置退出条件
   	int mid = l+r>>1,i=l,j=mid+1,k=0;//设置分割点
       merge_sort(a,b,l,mid);merge_sort(a,b,mid+1,r);//先对子段排序
   	while(i<=mid&&j<=r)
           if(a[i]<=a[j]) b[k++] = a[i++];
       	else b[k++] = a[j++];
       while(i<=mid) b[k++]=a[i++];
       while(j<=r) b[k++]=a[j++];
       for(i=l,j=0;i<=r;i++,j++) a[i]=b[j];
   }
   ```

   - 时间复杂度：$O(N*logN)$

3. 相关应用

   - 求逆序对

   当用归并排序对数组进行排序时，可以发现，当出现`a[i]>b[j]`时，即出现了逆序对，且对于当前`a[j]`来说，会出现`mid-i+1`个逆序对(即`a[j]`与`[i,mid]`共`mid-i+1`个数配对组合成逆序对)。由此我们可以在排序时求出对应数列中存在的逆序对。

   ```c++
   long long merge_sort(int a[],int b[],int l,int r){
       if(l>=r) return 0;
       int mid = l+r>>1,i=l,j=mid+1,k=0;
       long long ans = merge_sort(a,b,l,mid)+merge_sort(a,b,mid+1,r);
       while(i<=mid&&j<=r)
           if(a[i]<=a[j]) b[k++] = a[i++];
           else ans += mid-i+1,b[k++]=a[j++];
       while(i<=mid) b[k++] = a[i++];
       while(j<=r) b[k++] = a[j++];
       for(i=l,j=0;i<=r;i++,j++) a[i]=b[j];
       return ans;
   }
   ```

4. 相关题目

- [AcWing 787. 归并排序](https://www.acwing.com/problem/content/789/)
- [AcWing 788. 逆序对的数量](https://www.acwing.com/problem/content/790/)