import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

class windows extends JFrame implements ActionListener {
    JPanel windMain;
    Box b11,b12,b1,b21,b22,b0,b2,bMain;
    JLabel Snum,Sn,Grade;
    JTextField textSnum,textSn,textGrade;
    JButton selectAll,selectSnum,insertD,updateD,deleteD,winExit;
    JTextArea showArea;

    Connection con;
    Statement state;
    String sql;
    ResultSet res;

    windows(){
        super("title");
        setLayout(new FlowLayout());

        windMain = new JPanel();
        Snum = new JLabel("学号");                Sn = new JLabel("姓名");          Grade = new JLabel("成绩");
        textGrade = new JTextField(10);     textSn = new JTextField(10);    textSnum = new JTextField(10);
        selectSnum = new JButton("按学号查询");  selectAll = new JButton("查询所有数据");
        updateD = new JButton("更新");            deleteD = new JButton("删除");     insertD = new JButton("插入");
        showArea = new JTextArea(20,20);    winExit = new JButton("退出");

        selectAll.addActionListener(this);
        selectSnum.addActionListener(this);
        updateD.addActionListener(this);
        deleteD.addActionListener(this);
        insertD.addActionListener(this);
        winExit.addActionListener(this);

        bMain = Box.createVerticalBox();    b1 = Box.createHorizontalBox();
        b11 = Box.createVerticalBox();      b12 = Box.createVerticalBox();
        b0 = Box.createHorizontalBox();

        b0.add(Box.createVerticalStrut(16));
        b0.add(winExit);       bMain.add(b0);
        bMain.add(Box.createVerticalStrut(20));

        bMain.add(new JLabel("学生成绩管理系统"));
        bMain.add(Box.createVerticalStrut(20));

        b11.add(Snum);      b11.add(Box.createVerticalStrut(8));
        b11.add(Sn);        b11.add(Box.createVerticalStrut(8));
        b11.add(Grade);
        b1.add(b11);        b1.add(Box.createHorizontalStrut(10));
        b12.add(textSnum);  b12.add(Box.createVerticalStrut(8));
        b12.add(textSn);    b12.add(Box.createVerticalStrut(8));
        b12.add(textGrade);
        b1.add(b12);
        bMain.add(b1);      bMain.add(Box.createVerticalStrut(20));

        b2 = Box.createVerticalBox();       b21 = Box.createHorizontalBox();
        b22 = Box.createHorizontalBox();
        b21.add(selectAll);     b21.add(Box.createHorizontalStrut(10));
        b21.add(selectSnum);
        b2.add(b21);            b2.add(Box.createVerticalStrut(8));
        b22.add(insertD);       b22.add(Box.createHorizontalStrut(10));
        b22.add(deleteD);       b22.add(Box.createHorizontalStrut(10));
        b22.add(updateD);
        b2.add(b22);            b2.add(Box.createVerticalStrut(8));
        bMain.add(b2);          bMain.add(Box.createVerticalStrut(20));

        bMain.add(showArea);
        windMain.add(bMain);
        add(windMain);

        setBounds(200,200,350,600);
        setVisible(true);
        setResizable(false);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    void DBroad(){
        try {
            Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
            showArea.setText("");
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }try {
            con = DriverManager.getConnection("jdbc:derby:D:/codeS/backOnGithub/JavaDB/dreaife;create=false");
            state = con.createStatement();
            sql="";
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    void DBqueAndShow(ActionEvent p,String sqlstr){
        try {
            String sno,sn;
            int grade;
            if(p.getSource() == selectAll || p.getSource() == selectSnum){
                res = state.executeQuery(sqlstr);
                showArea.append("查询成功\n");
            }
            if(p.getSource() != selectAll && p.getSource() != selectSnum) {
                if (!state.execute(sqlstr)) {
                    showArea.append("更新成功\n");
                }else {
                    showArea.append("更新失败\n");
                    return;
                }res = state.executeQuery("select * from stuGradeManSys");
            }showArea.append("学生成绩如下：\n");
            while (res.next()){
                sno = res.getString("sno");
                sn = res.getString("sn");
                grade = res.getInt("grade");

                showArea.append(sno + "\t" + sn + "\t" + grade + "\n");
            }
        } catch (SQLException e) {
            showArea.append("操作失败，请重新尝试\n");
        }
    }

    void DBclose(){
        try {
            res.close();
            state.close();
            con.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        DBroad();
        if (e.getSource() == selectAll){
            sql = "select * from stuGradeManSys";
        }else if (e.getSource() == selectSnum){
            sql = "select * from stuGradeManSys where sno = '" + textSnum.getText() + "'";
        }else if (e.getSource() == insertD){
            sql = "insert into stuGradeManSys (sno,sn,grade) values ('" + textSnum.getText() + "','"
                    + textSn.getText() + "'," + Integer.parseInt(textGrade.getText()) + ")";
        }else if (e.getSource() == deleteD){
            sql = "delete from stuGradeManSys where sno = '" + textSnum.getText() + "'";
        }else if (e.getSource() == updateD){
            sql = "update stuGradeManSys set " + " grade = " + Integer.parseInt(textGrade.getText())
                    + " where sno = '" + textSnum.getText() + "'";
        }else{
//            this.dispose();
            this.setVisible(false);
            System.exit(0);
        }
        DBqueAndShow(e,sql);
        DBclose();
    }
}

public class homework8 {
    public static void main(String[] args) {
        new windows();
    }
}
