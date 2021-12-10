package myHomework;

class SetuException extends Exception{
	public String warnMess(){
		return "³åÌ«¿ìÀ²";
	}
}

class  LoliException extends  Exception{
	String burnMess(){
		return  "kami!!";
	}
}

class SetuBot{
	static int num = 0;
	void get(String ques) throws SetuException,LoliException{
		num ++ ;
		if(ques == "shiratama"){
			throw new LoliException();
		}
		if(num > 3){
			throw new SetuException();
		}
		System.out.println("setu.jpg\n>_<");
	}
}

public class homework4 {

	public static void main(String[] args) {

		SetuBot setuBot = new SetuBot();

		try {
			for(int i=0;i<5;i++){
				if(i==2) setuBot.get("shiratama");
				setuBot.get("setu!!!");
			}
		}catch (SetuException e1){
			System.out.println(e1.warnMess());
		}catch (LoliException e2){
			System.out.println(e2.burnMess());
		}finally {
			System.out.println("shinku saikao");
		}
	}
}
