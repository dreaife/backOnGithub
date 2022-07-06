package summerMiddle.HomeworkDay03.entity;

public class Club implements Comparable {
    private int club_id;
    private String club_name;
    private String club_age;

    public Club() {
    }

    public Club(int club_id, String club_name, String club_age) {
        this.club_id = club_id;
        this.club_name = club_name;
        this.club_age = club_age;
    }

    public int getClub_id() {
        return club_id;
    }

    public void setClub_id(int club_id) {
        this.club_id = club_id;
    }

    public String getClub_name() {
        return club_name;
    }

    public void setClub_name(String club_name) {
        this.club_name = club_name;
    }

    public String getClub_age() {
        return club_age;
    }

    public void setClub_age(String club_age) {
        this.club_age = club_age;
    }

    @Override
    public String toString() {
        return "Club{" +
                "club_id=" + club_id +
                ", club_name='" + club_name + '\'' +
                ", club_age='" + club_age + '\'' +
                '}';
    }

    @Override
    public int compareTo(Object o) {
        return 0;
    }
}