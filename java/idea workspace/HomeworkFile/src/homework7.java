class javaRunWork implements Runnable{
    Thread run1;
    Thread run2;
    int fes;
    int i;
    boolean target;

    public javaRunWork() {
        run1 = new Thread(this);
        run2 = new Thread(this);
        fes = 0;target = false;i=0;
    }
    synchronized void setFes(int k){
        fes = k;
    }

    public int  getFes(){
        return fes;
    }

    @Override
    public void run() {
        for(;i<=10;){
            if(Thread.currentThread() == run1){
                if(!target) target = true;
                int t = getFes();
                setFes(t+i++);
                System.out.println(getFes()+" "+Thread.currentThread().getName());
            }else if(Thread.currentThread() == run2){
                if(target) target = false;
                int t = getFes();
                setFes(t-i++);
                System.out.println(getFes()+" "+Thread.currentThread().getName());
            }
//			System.out.println(i);
        }
    }
}

public class homework7 {

    public static void main(String[] args) {
        javaRunWork t = new javaRunWork();
        t.setFes(10);
        t.run1.start();
        t.run2.start();
    }

}
