import java.io.*;
import java.nio.charset.StandardCharsets;

public class test {
    public static void main(String[] args) {
        File dir = new File("./data");
        File f = new File(dir,"data1.txt");
        File f2 = new File(dir,"data2.txt");

        byte [] a = new byte[100];
        try {
            if(!dir.exists())
                dir.mkdir();
            if(!f.exists())
                f.createNewFile();
            if(!f2.exists())
                f2.createNewFile();
            FileInputStream in = new FileInputStream(f);
            FileOutputStream out = new FileOutputStream(f);
            out.write("shinku saikao!!\n".getBytes(StandardCharsets.UTF_8));
            out.write("Favorite Game\n".getBytes(StandardCharsets.UTF_8));
            out.write("dreams are the seedings of the realities.\n".getBytes(StandardCharsets.UTF_8));
            out.close();
            int n = -1;
            while((n = in.read(a))!=-1){
                String s = new String(a,0,n);
                System.out.println(s);
            }in.close();

            FileWriter out2 = new FileWriter(f2);
            char [] b = ("shinku saikao!!\n"+"Favorite Game\n"+"dreams are the seedings of the realities.\n").toCharArray();
            out2.write(b,0,b.length);
            out2.close();
            FileReader in2 = new FileReader(f2);
            char c[] = new char[100];
            StringBuffer s = new StringBuffer();
            while((n = in2.read(c,0,100))!=-1){
                String temp = new String(a,0,n);
                s.append(temp);
            }in2.close();
            System.out.println(new String(s));

        } catch (IOException e) {
            System.out.println(e);
        }


    }
}
