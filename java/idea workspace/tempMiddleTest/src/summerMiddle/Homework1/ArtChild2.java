package summerMiddle.Homework1;

public class ArtChild2 extends ArtChild{
    ArtChild2(){
        this.score = 0;
    }

    @Override
    void MySkill() {
        this.score += 3;
    }

    @Override
    void extraTalen() {
        this.score += 4;
    }

}
