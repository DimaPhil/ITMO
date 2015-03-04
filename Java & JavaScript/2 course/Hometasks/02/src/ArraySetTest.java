import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.NavigableSet;

public class ArraySetTest {
    public static void print(ArraySet<Integer> set) {
        for (Iterator<Integer> i = set.iterator(); i.hasNext();) {
            Integer x = i.next();
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<Integer>();
        list.add(1);
        list.add(2);
        list.add(3);
        ArraySet<Integer> set = new ArraySet<Integer>(list);
        ArraySet<Integer> descendingSet= (ArraySet<Integer>)set.descendingSet();
        print(descendingSet);
        ArraySet<Integer> subDescendingSet = (ArraySet<Integer>)descendingSet.subSet(2, 1);
        print(subDescendingSet);
    }
}
