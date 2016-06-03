public class ParseException extends Exception {
   public ParseException(String message) {
       super(message);
   }

   public ParseException(String message, int pos) {
       System.err.println(String.format("ParseException at position %d: %s", pos, message));
   }
}
