package myHomework;

import java.io.File;

public class test {
    public static void main(String[] args) {
        File dir = new File("D:\\document\\Java eclipse workspace\\java202931\\data");
        System.out.println(dir.getName());
        if(!dir.exists())
            try {
                dir.mkdir();
                System.out.println("access");
            }catch (Exception e){
                e.printStackTrace();
            }
    }
}
