import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class TestResults {
    public static void main(String[] args) throws FileNotFoundException, ParseException {
        Parser parser = new Parser();
        Parser.Tree tree = parser.parse(new FileInputStream("test/expression3.in"));
        new Visualizer().visualize(tree);
    }
}
