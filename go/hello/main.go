package main

import (
	"fmt"
	testFunc "hello/plugins"
	"strconv"
	"time"
	"unsafe"
)

var x, y int = 3, 0

// var ( // 这种因式分解关键字的写法一般用于声明全局变量
// 	a int
// 	b bool
// )

const (
	a = "123"
	b = len(a)
	c = unsafe.Sizeof(a)
)

type Books struct {
	title  string
	author string
	id     int
}

const Pi float64 = 3.1415926

func main() {
	test12()
}

func say(s string) {
	for i := 0; i < 5; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func sum(s []int, c chan int) {
	sum := 0
	for _, v := range s {
		sum += v
	}
	c <- sum
}

func fibonacci(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		c <- x
		x, y = y, x+y
	}
	close(c)
}

func test12() {
	//并发
	go say("hello")
	say("hello mainRoutine")

	// s := []int{7, 2, 8, -9, 4, 0}
	// c := make(chan int, 2)

	// go sum(s[len(s)/2:], c)
	// go sum(s[:len(s)/2], c)

	// x, y := <-c, <-c
	// fmt.Println(x, y, x+y)
	c := make(chan int, 10)
	go fibonacci(cap(c), c)
	for i := range c {
		fmt.Println(i)
	}
}

func test11() {
	// var a1 = [5]int{1, 2, 3, 5, 6}
	// a2 := a1[1:4] // [l,r)
	s1 := make([]int, 3, 5)

	fmt.Println(s1, len(s1), cap(s1))
	s1 = append(s1, 1)
	s1 = append(s1, 1)
	s1 = append(s1, 1)
	fmt.Println(s1, len(s1), cap(s1))

	//map
	// m := make(map[string]int)
	m := map[string]int{
		"apple":  1,
		"banana": 2,
		"orange": 3,
	}
	fmt.Println(m)
	v1 := m["apple"]
	delete(m, "orange")
	for k, v := range m {
		fmt.Println(k, v)
	}
	fmt.Println(v1)

	var num int
	num, _ = strconv.Atoi(a)
	fmt.Printf("%d, %T", num, num)

}

func test10() {
	var book1 = Books{"dreaife", "dreaife", 1}

	fmt.Println(book1)

	f := func(book *Books) {
		fmt.Println(book.title, book.id)
	}
	f(&book1)
}

func test9() {
	// Step 1: 创建数组
	values := [][]int{}

	// Step 2: 使用 append() 函数向空的二维数组添加两行一维数组
	row1 := []int{1, 2, 3}
	row2 := []int{4, 5}
	values = append(values, row1)
	values = append(values, row2)

	// Step 3: 显示两行数据
	fmt.Println("Row 1")
	fmt.Println(values[0])
	fmt.Println("Row 2")
	fmt.Println(values[1])

	// Step 4: 访问第一个元素
	fmt.Println("第一个元素为：")
	fmt.Println(values[1][0])

	a := [3][4]int{
		{0, 1, 2, 3}, /*  第一行索引为 0 */
		{4, 5, 6, 7}, /*  第二行索引为 1 */
		{8, 9, 10}}   /* 第三行索引为 2 */
	fmt.Println(a)

	/* 数组长度为 5 */
	var balance = [5]int{1000, 2, 3, 17, 50}
	var avg float32

	/* 数组作为参数传递给函数 */
	avg = getAverage(balance, 5)

	/* 输出返回的平均值 */
	fmt.Printf("平均值为: %f \n", avg)
	fmt.Println(float64(avg) / 100)
}

func getAverage(arr [5]int, size int) float32 {
	var i, sum int
	var avg float32

	for i = 0; i < size; i++ {
		sum += arr[i]
	}

	avg = float32(sum) / float32(size)

	return avg
}

func test8() {
	//数组
	var arrayT = [5]int{1, 2, 3: 3, 2: 5}
	for i := range arrayT {
		fmt.Println(arrayT[i])
	}
}

// 闭包使用方法，函数声明中的返回值(闭包函数)不用写具体的形参名称
func getSequence() func() int {
	i := 0
	return func() int {
		i += 1
		return i
	}
}

func test7() {
	// 函数
	a, b := 3, 4
	fmt.Printf("max(a,b) = %d\n", testFunc.Max(a, b))

	nexFun := getSequence()
	fmt.Println(nexFun())
	fmt.Println(nexFun())
	fmt.Println(nexFun())

	nexFun1 := getSequence()
	fmt.Println(nexFun1())
	fmt.Println(nexFun())
	fmt.Println(nexFun1())
}

func test6() {
	// 循环

	for k, s := range a {
		fmt.Println(k, s)
	}
}

func test5() {
	// 条件语句
	var e1 = 3
	switch e1 {
	case 1:
		fmt.Println(e1)
		e1--
		fallthrough
	case 2:
		fmt.Println(e1)
		e1--
		fallthrough
	case 3:
		fmt.Println(e1)
		e1--
		fallthrough
	case 4:
		fmt.Println(e1, 4)
		e1--
		fallthrough
	case 5:
		fmt.Println(e1)
		e1--
		fallthrough
	case 6:
		fmt.Println(e1)
		e1--
	}

	c1 := make(chan string)
	c2 := make(chan string)

	go func() {
		time.Sleep(0 * time.Second)
		c1 <- "one"
	}()
	go func() {
		time.Sleep(0 * time.Second)
		c2 <- "two"
	}()

	for i := 0; i < 2; i++ {
		select {
		case msg1 := <-c1:
			fmt.Println("received", msg1)
		case msg2 := <-c2:
			fmt.Println("received", msg2)
		}
	}

}

func test4() {
	// 运算符
	var a, b = 10, 5
	fmt.Printf("a+b= %d\n", a+b)
	a++
	fmt.Printf("a = %d\n", a)

	var c1, c2 = "aaa", "aaa"
	fmt.Printf("c1 == c2 ? %t\n", c1 == c2)

	a, b = 60, 13
	fmt.Printf("a & b = %b\n", a&b)
	fmt.Printf("a | b = %b\n", a|b)
	fmt.Printf("a ^ b = %b\n", a^b)

}

func Test3() {
	// 常量go
	const idn string = "abc"
	const c1 = "123"
	var c2 = 123
	fmt.Println(idn, c1, c2)
	fmt.Println(a, b, c)

	const (
		i = 1 << iota
		j = 3 << iota
		k
		l
	)
	fmt.Println("i=", i)
	fmt.Println("j=", j)
	fmt.Println("k=", k)
	fmt.Println("l=", l)

}

func test2() {
	var a int = 10
	var b *int = &a
	var c *int64 = (*int64)(unsafe.Pointer(b))
	fmt.Println(*c)
	var tx interface{} = *c
	t, op := tx.(int)
	if op {
		fmt.Println(t)
	}
}

func test1() {
	fmt.Println(x, Pi)
	fmt.Println("Hello Go World!")
	fmt.Println("yes" + "connect !")
	fmt.Println()

	var stockcode = 123
	var enddate = "2020-12-31"
	var url = "Code=%d&endDate=%s"
	var target_url = fmt.Sprintf(url, stockcode, enddate)
	fmt.Println(target_url)

	var res *int = &x
	fmt.Println(res, x, *res)
	fmt.Println(a, b)
	x = x + 1
	fmt.Println(*res)
}
