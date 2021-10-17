import java.io.*;
import java.util.*;
public class toggleCase {

	public static String toggleCase(String str){
		//write your code here
		String toggled="";
		for(int i=0;i<str.length();i++){
		    char letter=str.charAt(i);
		    if(Character.isUpperCase(letter)){
		        letter=Character.toLowerCase(letter);
		    }
		    else{
		        letter=Character.toUpperCase(letter);
		    }
		    toggled=toggled+letter;
		}

		return toggled;
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(toggleCase(str));
	}

}
