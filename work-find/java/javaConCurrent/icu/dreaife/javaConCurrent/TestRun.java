package icu.dreaife.javaConCurrent;

import java.lang.management.ManagementFactory;
import java.lang.management.ThreadInfo;
import java.lang.management.ThreadMXBean;

public class TestRun {

	private static Object resource1 = new Object();//资源 1
    private static Object resource2 = new Object();//资源 2
    
    public static void test(){
        // 获取 Java 线程管理 MXBean
	    ThreadMXBean threadMXBean = ManagementFactory.getThreadMXBean();
		// 不需要获取同步的 monitor 和 synchronizer 信息，仅获取线程和线程堆栈信息
		ThreadInfo[] threadInfos = threadMXBean.dumpAllThreads(false, false);
		// 遍历线程信息，仅打印线程 ID 和线程名称信息
		for (ThreadInfo threadInfo : threadInfos) {
			System.out.println("[" + threadInfo.getThreadId() + "] " + threadInfo.getThreadName());
		}
    }

	static void test1(){
		new Thread(() -> {
			synchronized (resource1) {
				System.out.println(Thread.currentThread() + "get resource1");
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println(Thread.currentThread() + "waiting get resource2");
				synchronized (resource2) {
					System.out.println(Thread.currentThread() + "get resource2");
				}
			}
		}, "线程 1").start();
  
  		new Thread(() -> {
			synchronized (resource1) {
				System.out.println(Thread.currentThread() + "get resource1");
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println(Thread.currentThread() + "waiting get resource2");
				synchronized (resource2) {
					System.out.println(Thread.currentThread() + "get resource2");
				}
			}
		}, "线程 2").start();
	}

    public static void main(String[] args) {
        test1();
    }
}
