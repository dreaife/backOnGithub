import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * @author 何庆晟
 */

public class MyFrame2201何庆晟 extends JFrame implements ActionListener {
    Box b11,b12,b1,b2,b3,bMain;
    JLabel lenText,WidText,SolText;
    JTextField lenEdit,widEdit,solEdit;
    JButton getSum,getArea;

    MyFrame2201何庆晟(){
        super("求矩形周长和面积");
        setLayout((new FlowLayout()));

        lenText = new JLabel("输入矩形的长：");
        WidText = new JLabel("输入矩形的宽：");
        SolText = new JLabel("结果为：");

        lenEdit = new JTextField(10);
        widEdit = new JTextField(10);
        solEdit = new JTextField(10);

        getSum = new JButton("求周长");
        getArea = new JButton("求面积");

        getSum.addActionListener(this);
        getArea.addActionListener(this);

        bMain = Box.createVerticalBox();b1 = Box.createHorizontalBox();
        b11 = Box.createVerticalBox();b12 = Box.createVerticalBox();
        b2 = Box.createHorizontalBox();b3 = Box.createHorizontalBox();
        b11.add(lenText);b11.add(Box.createVerticalStrut(10));
        b11.add(WidText);
        b1.add(b11);b1.add(Box.createHorizontalStrut(10));
        b12.add(lenEdit);b12.add(Box.createVerticalStrut(10));
        b12.add(widEdit);
        b1.add(b12);
        bMain.add(b1);bMain.add(Box.createVerticalStrut(10));
        b2.add(getSum);b2.add(Box.createHorizontalStrut(10));
        b2.add(getArea);
        bMain.add(b2);bMain.add(Box.createVerticalStrut(10));
        b3.add(SolText);b3.add(Box.createHorizontalStrut(10));
        b3.add(solEdit);bMain.add(b3);

        add(bMain);

        setBounds(200,200,350,500);
        setVisible(true);
        setResizable(false);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new MyFrame2201何庆晟();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == getSum){
            double a = Double.parseDouble(lenEdit.getText());
            double b = Double.parseDouble(widEdit.getText());
            solEdit.setText(Double.toString(2*(a+b)));
        }else if(e.getSource() == getArea){
            double a = Double.parseDouble(lenEdit.getText());
            double b = Double.parseDouble(widEdit.getText());
            solEdit.setText(Double.toString(a*b));
        }
    }
}
