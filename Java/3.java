import java.io.*;
class fileReading
{
public static void main(String[] args) throws IOException
{
  FileReader Fr=new FileReader(args[0]);
  BufferedReader br=new BufferedReader(Fr);
   String s;
int count=0,sent=0;
  while((s=br.readLine())!=null)
  {
    sent++;
    String[] sa=s.split(" ");
   for(int i=0;i<sa.length;i++)
    {
       count++;
    }
    
  }

  System.out.println("No of lines : "+sent);
  System.out.println("No of words:"+count);



   br.close();
  Fr.close();
}
}