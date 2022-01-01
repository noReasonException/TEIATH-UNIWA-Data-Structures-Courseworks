import com.sun.org.apache.regexp.internal.RE;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Created by stefstef on 21/5/2017.
 */
public class Programm {
    private ListA<Record> mainList = new ListA<>();
    public void AddStudent(String FullName,int Semester,String AM){
        this.mainList.Add(new Record(FullName,Semester),AM);
    }
    public void DeleteStudent(String AM){
        this.mainList.Delete(AM);
    }
    public Record SearchStudent(String AM){
        ListA.Node returnVal= this.mainList.Search(AM);
        if(returnVal==null){
            throw new IllegalArgumentException("No AM found");
        }
        return (Record) returnVal.Data;
    }
    public void ChangeNameByAM(String Name,String AM){
        Record tmp = this.SearchStudent(AM);
        if(tmp==null){
            throw new IllegalArgumentException("AM not found!");
        }
        tmp.Fullname=Name;
    }
    public void ChangeSemesterByAM(int Semester,String AM){
        Record tmp = this.SearchStudent(AM);
        if(tmp==null){
            throw new IllegalArgumentException("AM not found!");
        }
        tmp.Semester=Semester;
    }
    public void ChangeAMByAM(String OldAM,String AM){
        Record tmp = this.SearchStudent(OldAM);
        if(tmp==null){
            throw new IllegalArgumentException("AM not found!");
        }
        String Name = tmp.Fullname;
        int Semester = tmp.Semester;
        this.mainList.Delete(OldAM);
        this.AddStudent(Name,Semester,AM);
    }
    public ArrayList<Record> SearchByName(String FullName){
        ArrayList<Record> returnRecords = new ArrayList<>();
        Iterator itr = this.mainList.iterator();
        Record tmp;
        while(itr.hasNext()){
            tmp=(Record) itr.next();
            if(tmp.Fullname.equals(FullName)){
                returnRecords.add(tmp);
            }
        }
        return returnRecords;
    }
    public ArrayList<Record> SearchBySemester(int Semester){
        ArrayList<Record> returnRecords = new ArrayList<>();
        Iterator itr = this.mainList.iterator();
        Record tmp;
        while(itr.hasNext()){
            tmp=(Record) itr.next();
            if(tmp.Semester==Semester){
                returnRecords.add(tmp);
            }
        }
        return returnRecords;
    }
    public void printStudentsBySemester(int Semester){
        Iterator tmpIterator = this.SearchBySemester(Semester).iterator();
        while(tmpIterator.hasNext()){
            System.out.print(tmpIterator.next());
        }

    }
}
