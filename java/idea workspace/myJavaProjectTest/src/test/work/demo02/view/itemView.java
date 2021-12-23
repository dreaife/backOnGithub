package test.work.demo02.view;

import test.work.demo02.dao.itemDao;
import test.work.demo02.entity.Item;

import java.sql.SQLException;
import java.util.List;
import java.util.Scanner;

public class itemView {
    public static void showItem(){
        itemDao dao = new itemDao();
        System.out.println("��Ʒ��Ϣ���£�");
        int page = 1;
        int maxPage = 0;
        try {
            List<Item> list = dao.goToPage(page, 4);
            maxPage = dao.getMaxPage(4);
            for(Item item : list){
                System.out.println(item);
            }
            Scanner sc = new Scanner(System.in);
            while(true){
                System.out.println("��ѡ�����ݣ�");
                System.out.println("1,��һҳ");
                System.out.println("2,��һҳ");
                System.out.println("3,�˳�");
                String cmd = sc.nextLine();
                if("1".equals(cmd)){
                    if(page>1){
                        page = page-1;
                    }
                    list = dao.goToPage(page, 4);
                    for(Item item : list){
                        System.out.println(item);
                    }
                }else if("2".equals(cmd)){
                    if(page<maxPage){
                        page = page + 1;
                    }
                    list = dao.goToPage(page, 4);
                    for(Item item : list){
                        System.out.println(item);
                    }
                }else if("3".equals(cmd)){
                    break;
                }
            }
            sc.close();
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("ϵͳά����~~~");
        }
    }

    public static void main(String[] args) {
        showItem();
    }
}
