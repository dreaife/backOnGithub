public class hello {
    String PersonName;
    hello(String name){
        this.PersonName = name;
    }
    void Sayhello(){
        System.out.println("hello world!\nI'm ");
        System.out.println(this.PersonName);
    }
}
