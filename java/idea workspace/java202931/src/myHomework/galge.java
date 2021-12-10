//galge.java
package myHomework;

public class galge {
	int cost = 8800;
	static int num = 0;
	
	public int getCost() {
		return cost;
	}
	public void setCost(int cost) {
		this.cost = cost;
	}
	public static int getNum() {
		return num;
	}
	public static void setNum(int num) {
		galge.num = num;
	}
	
	public void buy() {
		System.out.println("Thanks to buy our good!\nYou're cost "+cost+" money.");
		setNum(num+1);
	}
	
	public void buy(int people) {
		System.out.println("Thanks to buy our good!\nYou're cost "+cost*people+" money.");
		setNum(num+people);
	}
}
