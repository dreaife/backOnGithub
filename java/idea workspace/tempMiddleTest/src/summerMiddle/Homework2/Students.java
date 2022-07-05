package summerMiddle.Homework2;

import java.util.List;

public class Students {
    String stuNum;
    String name;
    int gender;
    int age;
    List<Books> books;

    public Students(String stuNum, String name, int gender, int age, List<Books> books) {
        this.stuNum = stuNum;
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.books = books;
    }

    public int getValue(){
        int values = 0;
        for(Books book : books){
            values += book.getValue();
        }return values;
    }

    @Override
    public String toString() {
        return "Students{" +
                "stuNum='" + stuNum + '\'' +
                ", name='" + name + '\'' +
                ", gender=" + gender +
                ", age=" + age +
                ", BooksValue=" + getValue() +
                '}';
    }
}
