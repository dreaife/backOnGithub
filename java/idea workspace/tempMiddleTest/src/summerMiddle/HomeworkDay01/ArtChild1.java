package summerMiddle.HomeworkDay01;

public class ArtChild1 extends ArtChild{
    ArtChild1(){
        this.score = 0;
    }

    @Override
    void MySkill() {
        this.score += 5;
    }

    @Override
    void extraTalen() {
        this.score += 2;
    }
}
