/**
 * Created by stefstef on 21/5/2017.
 */
public class Record {
    public String Fullname = new String();
    public int Semester;
    Record(String FullName,int Semester){
        this.Fullname=FullName;
        this.Semester=Semester;
    }
    @Override
    public String toString(){
        return this.Fullname+"  "+Semester+"\n";
    }
}
