package myHomework;

import java.util.Spliterators.AbstractDoubleSpliterator;

interface work{
	abstract void goToWork();
	abstract void doWork();
	abstract void leaveWork();
}

interface fun{
	abstract void game();
	abstract void book();
	abstract void sport();
}

class Erogers implements work,fun{

	@Override
	public void game() {
		// TODO 自动生成的方法存根
		System.out.println("eroge!");
	}

	@Override
	public void book() {
		// TODO 自动生成的方法存根
		System.out.println("ZYPRESSEN");
	}

	@Override
	public void sport() {
		// TODO 自动生成的方法存根
		System.out.println("run!");
	}

	@Override
	public void goToWork() {
		// TODO 自动生成的方法存根
		System.out.println("everyday 0:00 A.M.");
	}

	@Override
	public void doWork() {
		// TODO 自动生成的方法存根
		System.out.println("time leap!");
	}

	@Override
	public void leaveWork() {
		// TODO 自动生成的方法存根
		System.out.println("everyday 12:00 P.M.");
	}
}

class Producers implements work,fun{

	@Override
	public void game() {
		// TODO 自动生成的方法存根
		System.out.println("osu!");
	}

	@Override
	public void book() {
		// TODO 自动生成的方法存根
		System.out.println("no game no life");
	}

	@Override
	public void sport() {
		// TODO 自动生成的方法存根
		System.out.println("ride");
	}

	@Override
	public void goToWork() {
		// TODO 自动生成的方法存根
		System.out.println("everyday 10:00 A.M.");
	}

	@Override
	public void doWork() {
		// TODO 自动生成的方法存根
		System.out.println("work for my idols!");
	}

	@Override
	public void leaveWork() {
		// TODO 自动生成的方法存根
		System.out.println("everyday 5:30 P.M.");
	}
}

public class homework3 {
	
	public static void main(String[] args) {
		work w;
		fun f;
		
//		abstract void goToWork();
//		abstract void doWork();
//		abstract void leaveWork();
		
//		abstract void game();
//		abstract void book();
//		abstract void sport();
		
		System.out.println("For a progucer ,let's we see his work way:");
		w = new Producers();
		System.out.println("When he go to work,it's ");
		w.goToWork();
		System.out.println("When he do work,it's time :");
		w.doWork();
		System.out.println("When he leave work,it's time :");
		w.leaveWork();
		
		System.out.println("For a eroger ,let's we see his fun way:");
		f = new Erogers();
		System.out.println("When he go to game,it's ");
		f.game();
		System.out.println("When he read book,he like :");
		f.book();
		System.out.println("When he go sport ,it's always is :");
		f.sport();
		
	}

}
