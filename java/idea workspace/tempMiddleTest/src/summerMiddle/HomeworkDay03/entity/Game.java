package summerMiddle.HomeworkDay03.entity;

public class Game implements Comparable{
    private int game_id;
    private String game_name;
    private int game_value;
    private String game_age;
    private String game_club;

    public Game() {
    }

    public Game(int game_id, String game_name, int game_value, String game_age, String game_club) {
        this.game_id = game_id;
        this.game_name = game_name;
        this.game_value = game_value;
        this.game_age = game_age;
        this.game_club = game_club;
    }

    public int getGame_id() {
        return game_id;
    }

    public void setGame_id(int game_id) {
        this.game_id = game_id;
    }

    public String getGame_name() {
        return game_name;
    }

    public void setGame_name(String game_name) {
        this.game_name = game_name;
    }

    public int getGame_value() {
        return game_value;
    }

    public void setGame_value(int game_value) {
        this.game_value = game_value;
    }

    public String getGame_age() {
        return game_age;
    }

    public void setGame_age(String game_age) {
        this.game_age = game_age;
    }

    public String getGame_club() {
        return game_club;
    }

    public void setGame_club(String game_club) {
        this.game_club = game_club;
    }

    @Override
    public String toString() {
        return "Game{" +
                "game_id=" + game_id +
                ", game_name='" + game_name + '\'' +
                ", game_value=" + game_value +
                ", game_age='" + game_age + '\'' +
                ", game_club='" + game_club + '\'' +
                '}';
    }

    @Override
    public int compareTo(Object o) {
        return 0;
    }
}
