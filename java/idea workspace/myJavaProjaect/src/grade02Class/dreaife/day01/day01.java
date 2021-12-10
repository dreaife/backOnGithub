package grade02Class.dreaife.day01;

import java.io.*;

class pp implements Serializable{
    @Serial
    private static  final  long serialVersionUID = 1L;

    private String id;
    private String name;

    public pp(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

public class day01 {
    public static void main(String[] args) {
        pp tp = new pp("001","dreaife");
        try {
            ObjectOutputStream  ops = new ObjectOutputStream(new FileOutputStream("./src/test.txt"));
            ops.writeObject(tp);
            ops.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            ObjectInputStream ips = new ObjectInputStream(new FileInputStream("./src/test.txt"));
            try {
                pp t = (pp) ips.readObject();
                System.out.println(t.getId());
                System.out.println(t.getName());
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }

            ips.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
