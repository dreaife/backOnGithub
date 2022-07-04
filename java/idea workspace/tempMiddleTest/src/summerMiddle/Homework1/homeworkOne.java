package summerMiddle.Homework1;

public class homeworkOne {
    static ArtChild[] child;
    static int[] lastScore;

    homeworkOne(){
        child = new ArtChild[10];
        for(int i=0;i<10;i++) {
            if (i % 2 == 0) child[i] = new ArtChild1();
            else child[i] = new ArtChild2();
        }
        lastScore = new int[10];
    }

    static void getScore(int tar){
        child[tar].addScore();
        lastScore[tar] = child[tar].getScore();
    }

    static Integer getAns(){
        int ans=-1,ans2=-1;
        for(int i=0;i<10;i++){
            if(lastScore[i]>ans2) {
                ans = i;
                ans2 = lastScore[i];
            }
        }return (Integer) ans;
    }
    static public void main(String[] args) {
        homeworkOne one = new homeworkOne();

        for(int i=0;i<10;i++){
            int tar = (int) (Math.random()*10);
//            System.out.println(tar);
            getScore(tar);
//            System.out.println(child[tar].getScore());
        }
        String ans = "Child" + getAns().toString();
        System.out.println("得分最多的ArtChild是:");
        System.out.println(ans);
    }
}
