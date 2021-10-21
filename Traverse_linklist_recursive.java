public int length(Node current){

 if(current == null){

   return 0;

 }

 return 1+length(current.next());

}
