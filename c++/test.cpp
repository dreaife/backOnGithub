sort(a,a+n);
sort(b,b+n);

for(int i=0,j=0;i<n||j<m;){
    if(a[i]>b[j]) j++;
    else if(a[i]<b[j]) i++;
    else res.push_back()
}
res ;
// o(n*logn)
// 1 3 4
// 3 4 5