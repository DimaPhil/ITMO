import java.lang.reflect.Array;
import java.util.*;

public class ArraySet<T extends Comparable<T>> extends AbstractSet<T> implements NavigableSet<T> {
    T[] elements;
    int size;

    @Override
    public Comparator<? super T> comparator() {
        return null;
    }

    public ArraySet(T[] other) {
        Arrays.sort(other);
        size = other.length;
        for (int i = 0; i < size; i++) {
            elements[i] = other[i];
        }
    }

    public ArraySet(Collection<T> collection) {
        List<T> list = new ArrayList<T>(collection);
        Collections.sort(list);
        size = 0;
        for (T element : collection) {
            elements[size++] = element;
        }
    }

    private T firstElement(T value, Comparator <? super T> comparator) {
        int l = -1, r = elements.length;
        while (l < r - 1) {

        }
        return elements[r];
    }

    private T lastElement(T value, Comparator <? super T> comparator) {
        int l = 0, r = elements.length;
        while (l < r - 1) {
            int m = l + (r - l) >> 1;
            if (comparator.compare(elements[m], value) < 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return elements[l];
    }

    @Override
    public T lower(T t) {
        return lastElement(t, new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                int result = o1.compareTo(o2);
                return result < 0 ? -1 : (result == 0 ? 0 : 1);
            }
        });
    }

    @Override
    public T floor(T t) {
        return lastElement(t, new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                int result = o1.compareTo(o2);
                return result <= 0 ? -1 : 1;
            }
        });
    }

    @Override
    public T ceiling(T t) {
        return null;
    }

    @Override
    public T higher(T t) {
        return null;
    }

    @Override
    public T pollFirst() {
        return null;
    }

    @Override
    public T pollLast() {
        return null;
    }

    @Override
    public Iterator<T> iterator() {
        return null;
    }

    @Override
    public NavigableSet<T> descendingSet() {
        return null;
    }

    @Override
    public Iterator<T> descendingIterator() {
        return null;
    }

    @Override
    public NavigableSet<T> subSet(T fromElement, boolean fromInclusive, T toElement, boolean toInclusive) {
        return null;
    }

    @Override
    public NavigableSet<T> headSet(T toElement, boolean inclusive) {
        return null;
    }

    @Override
    public NavigableSet<T> tailSet(T fromElement, boolean inclusive) {
        return null;
    }

    @Override
    public SortedSet<T> subSet(T fromElement, T toElement) {
        return null;
    }

    @Override
    public SortedSet<T> headSet(T toElement) {
        return null;
    }

    @Override
    public SortedSet<T> tailSet(T fromElement) {
        return null;
    }

    @Override
    public T first() {
        return elements[0];
    }

    @Override
    public T last() {
        return elements[elements.length - 1];
    }

    @Override
    public int size() {
        return size;
    }

    public static void main(String[] args) {
        //Nothing to do here
    }
}
