import java.awt.*;

public class Qualification extends Frame {
    CheckboxGroup cg = new CheckboxGroup();
    Checkbox r1= new Checkbox("Undergra",  false);
    Checkbox r2=new Checkbox( "Graduate" , false);
    Checkbox r3=new Checkbox( "Post Graduate" ,false);
    Checkbox r4=new Checkbox( "Doctorate" ,false);
    Label lbl=new Label( "What s your primary qualification?" );

    public Qualification(String s) {
        super(s);
        setLayout(new GridLayout(6, 1));
        add(lbl);
        add(r1);
        add(r2);
        add(r3);
        add(r4);
    }

    public static void main(String[] args) {
        Qualification q = new Qualification("Literacy");
        q.setSize(400, 400);
        q.setVisible(true);
    }
}
