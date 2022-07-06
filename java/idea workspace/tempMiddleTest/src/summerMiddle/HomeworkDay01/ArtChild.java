package summerMiddle.HomeworkDay01;

public class ArtChild extends ArtGroupPerson{
    int score;
    ArtChild(){
        this.score = 0;
    }

    @Override
    void MySkill() {
        this.score += 1;
    }

    @Override
    void extraTalen() {
        this.score += 1;
    }

    public int getScore() {
        return score;
    }
}
