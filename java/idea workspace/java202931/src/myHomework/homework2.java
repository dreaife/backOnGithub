package myHomework;

import java.util.Scanner;

public class homework2 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int buyNum = 0;

		galge SakuraNoUta = new galge();

		// ��������
		System.out.println("����buy()����");
		SakuraNoUta.buy();
		System.out.println();

		System.out.println("����buy(int people)����");
		System.out.println("write the numbers you want to buy:");
		if (cin.hasNext())
			buyNum = cin.nextInt();
		SakuraNoUta.buy(buyNum);

		// �����|�෽��|ʵ������|ʵ������
		System.out.println("����SakuraNoUta��ʵ������cost:" + SakuraNoUta.cost);// ����ʵ������
		System.out.println("����SakuraNoUta�������num:" + SakuraNoUta.num);// ���������
		System.out.println("����SakuraNoUta��ʵ������getCost():" + SakuraNoUta.getCost());// ����ʵ������
		System.out.println("����SakuraNoUta���෽��getNum():" + SakuraNoUta.getNum());// �����෽��

	}

}
