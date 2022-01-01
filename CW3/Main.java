import javax.swing.*;
import java.util.ArrayList;
import java.util.Iterator;

public class Main extends JFrame{

    public static void main(String argsp[])  {
        Programm e = new Programm();
        //Προσθήκη Φοιτητών ,
        e.AddStudent("StefanosStefanou",2,"0001");
        e.AddStudent("Stefanos",3,"0002");
        e.AddStudent("Stefanos",2,"0003");

        //Διαγραφή φοιτητών
        e.DeleteStudent("0001");

        //Αναζήτηση φοιτητων με βάση το AM;
        e.SearchStudent("0002");

        //Αναζητηση φοιτητων με βαση ονοματεπωνυμο
        ArrayList<Record> byname = e.SearchByName("Stefanos");

        //Τροποποιησή πεδίων
        e.ChangeAMByAM("0002","0022");
        e.ChangeNameByAM("Stefanos","0022");
        e.ChangeSemesterByAM(3,"0003");

        //Λιστα φοιτητών με συγκεκριμενο εξάμηνο
        ArrayList<Record> bySem = e.SearchBySemester(2);

        //Εκτύπωση φοιτητων με συγκεκριμενο εξαμηνο
        e.printStudentsBySemester(3);

    }
}
