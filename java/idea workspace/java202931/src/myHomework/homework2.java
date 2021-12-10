package myHomework;

import java.util.Scanner;

public class homework2 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int buyNum = 0;

		galge SakuraNoUta = new galge();

		// 方法重载
		System.out.println("调用buy()函数");
		SakuraNoUta.buy();
		System.out.println();

		System.out.println("调用buy(int people)函数");
		System.out.println("write the numbers you want to buy:");
		if (cin.hasNext())
			buyNum = cin.nextInt();
		SakuraNoUta.buy(buyNum);

		// 类变量|类方法|实例变量|实例方法
		System.out.println("访问SakuraNoUta的实例变量cost:" + SakuraNoUta.cost);// 访问实例变量
		System.out.println("访问SakuraNoUta的类变量num:" + SakuraNoUta.num);// 访问类变量
		System.out.println("访问SakuraNoUta的实例方法getCost():" + SakuraNoUta.getCost());// 访问实例方法
		System.out.println("访问SakuraNoUta的类方法getNum():" + SakuraNoUta.getNum());// 访问类方法

	}

}
