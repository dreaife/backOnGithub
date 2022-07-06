package summerMiddle.HomeworkDay02;

import java.util.*;

public class homeworkTwo {
    public static void main(String[] args) {
        TreeSet<Students> stu = new TreeSet<>(new Comparator<Students>() {
            @Override
            public int compare(Students o1, Students o2) {
                return (o1.getValue() - o2.getValue());
            }
        });
        stu.add(new Students("12345","ww",1,18,new ArrayList<>(){{
            add(new Books(1));add(new Books(3));add(new Books(2));
        }}));
        stu.add(new Students("12346","wn",0,19,new ArrayList<>(){{
            add(new Books(4));add(new Books(1));add(new Books(2));
        }}));
        stu.add(new Students("12347","qq",1,22,new ArrayList<>(){{
            add(new Books(1));add(new Books(2));
        }}));
        stu.add(new Students("12348","bt",0,17,new ArrayList<>(){{
            add(new Books(1));add(new Books(3));
        }}));
        stu.add(new Students("12349","bw",1,20,new ArrayList<>(){{
            add(new Books(1));add(new Books(3));add(new Books(2));
            add(new Books(4));
        }}));

        System.out.println("按照借阅书本价值升序对学生排序：");
        for (Students students : stu) {
            System.out.println(students.toString());
        }
    }
}
