public class hello {
    String PersonName;
    hello(String name){
        this.PersonName = name;
    }
    void Sayhello(){
        System.out.print("hello world!\nI'm ");
        System.out.println(this.PersonName);
    }
}
