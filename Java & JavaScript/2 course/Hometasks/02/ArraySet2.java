import java.util.*;

public class ArraySetTL<T> extends AbstractSet<T> implements NavigableSet<T> {
    private List<T> elements;
    private Comparator<? super T> comparator;
    private boolean hasComparator = false;

    @Override
    public Comparator<? super T> comparator() {
        return hasComparator ? this.comparator : null;
    }

    private List<T> unique(List<T> elements, Comparator<? super T> comparator) {
        Collections.sort(elements, comparator);
        List<T> result = new ArrayList<T>();
        if (elements.size() == 0) {
            return result;
        }
        result.add(elements.get(0));
        for (int i = 1; i < elements.size(); i++) {
            final T element = elements.get(i);
            if (comparator.compare(elements.get(i - 1), element) != 0) {
                result.add(element);
            }
        }
        return result;
    }

    public
    ArraySet() {
        elements = new ArrayList<T>();
        comparator = null;
    }

    private ArraySet(List<T> collection, Comparator<? super T> comparator, boolean hasComparator, boolean isSorted) {
        if (!isSorted) {
            Collections.sort(collection, comparator);
            this.elements = unique(collection, comparator);
        } else {
            this.elements = collection;
        }
        this.comparator = comparator;
        this.hasComparator = hasComparator;
    }

    private ArraySet(List<T> collection, Comparator<? super T> comparator, boolean hasComparator) {
        this(collection, comparator, hasComparator, true);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Object[] other, Comparator<? super T> comparator) {
        this(Arrays.asList((T[]) other), comparator, true, false);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Object[] other) {
        this(Arrays.asList((T[]) other), (o1, o2) -> ((Comparable) o1).compareTo(o2), false, false);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Collection<T> collection, Comparator<? super T> comparator) {
        this(Arrays.asList((T[]) collection.toArray()), comparator, true, false);
    }

    private ArraySet(List<T> collection, Comparator<? super T> comparator) {
        this(collection, comparator, true);
    }


    @SuppressWarnings("unchecked")
    public ArraySet(Collection<T> collection) {
        this(Arrays.asList((T[]) collection.toArray()), (o1, o2) -> ((Comparable) o1).compareTo(o2), false, false);
    }

    @SuppressWarnings("unchecked")
    private ArraySet(List<T> collection) {
        this(collection, (o1, o2) -> ((Comparable) o1).compareTo(o2), false);
    }

    @Override
    @SuppressWarnings("unchecked")
    public boolean contains(Object o) {
        T key = (T) o;
        return Collections.binarySearch(elements, key, comparator) >= 0;
    }

    private int lessIndex(T key) {
        int index = Collections.binarySearch(elements, key, comparator);
        if (index < 0) {
            index = -index - 2;
        } else {
            index--;
        }
        return (0 <= index && index < elements.size()) ? index : -1;
    }

    private int lessOrEqualIndex(T key) {
        int index = Collections.binarySearch(elements, key, comparator);
        if (index < 0) {
            index = -index - 2;
        }
        return (0 <= index && index < elements.size()) ? index : -1;
    }

    private int greaterIndex(T key) {
        int index = Collections.binarySearch(elements, key, comparator);
        if (index < 0) {
            index = -index - 1;
        } else {
            index++;
        }
        return (0 <= index && index < elements.size()) ? index : -1;
    }

    private int greaterOrEqualIndex(T key) {
        int index = Collections.binarySearch(elements, key, comparator);
        if (index < 0) {
            index = -index - 1;
        }
        return (0 <= index && index < elements.size()) ? index : -1;
    }

    @Override
    public T lower(T key) {
        int index = lessIndex(key);
        return index != -1 ? elements.get(index) : null;
    }

    @Override
    public T floor(T key) {
        int index = lessOrEqualIndex(key);
        return index != -1 ? elements.get(index) : null;
    }

    @Override
    public T ceiling(T key) {
        int index = greaterOrEqualIndex(key);
        return index != -1 ? elements.get(index) : null;
    }

    @Override
    public T higher(T key) {
        int index = greaterIndex(key);
        return index != -1 ? elements.get(index) : null;
    }

    @Override
    public T pollFirst() {
        throw new UnsupportedOperationException();
    }

    @Override
    public T pollLast() {
        throw new UnsupportedOperationException();
    }

    @Override
    public void clear() {
        throw new UnsupportedOperationException();
    }

    private class MyIterator implements Iterator<T> {
        Iterator<T> iterator;

        public MyIterator() {
            iterator = elements.iterator();
        }

        @Override
        public boolean hasNext() {
            return iterator.hasNext();
        }

        @Override
        public T next() {
            return iterator.next();
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    @Override
    public Iterator<T> iterator() {
        return new MyIterator();
    }

    @Override
    @SuppressWarnings("unchecked")
    public NavigableSet<T> descendingSet() {
        List<T> newElements = new ArrayList<T>();
        for (int i = elements.size() - 1; i >= 0; i--) {
            newElements.add(elements.get(i));
        }
        return new ArraySet(newElements, comparator.reversed());
    }

    @Override
    public Iterator<T> descendingIterator() {
        return descendingSet().iterator();
    }

    @Override
    public NavigableSet<T> subSet(T fromElement, boolean fromInclusive, T toElement, boolean toInclusive) {
        return tailSet(fromElement, fromInclusive).headSet(toElement, toInclusive);
    }

    @Override
    @SuppressWarnings("unchecked")
    public NavigableSet<T> headSet(T toElement, boolean inclusive) {
        int toIndex = lessOrEqualIndex(toElement);
        if (toIndex == -1) {
            return new ArraySet();
        }
        if (comparator.compare(elements.get(toIndex), toElement) == 0 && !inclusive) {
            --toIndex;
        }
        return new ArraySet(elements.subList(0, toIndex + 1), comparator);
    }

    @Override
    @SuppressWarnings("unchecked")
    public NavigableSet<T> tailSet(T fromElement, boolean inclusive) {
        int fromIndex = greaterOrEqualIndex(fromElement);
        if (fromIndex == -1) {
            return new ArraySet();
        }
        if (comparator.compare(elements.get(fromIndex), fromElement) == 0 && !inclusive) {
            ++fromIndex;
        }
        return new ArraySet(elements.subList(fromIndex, elements.size()), comparator);
    }

    @Override
    public SortedSet<T> subSet(T fromElement, T toElement) {
        return subSet(fromElement, true, toElement, false);
    }

    @Override
    @SuppressWarnings("unchecked")
    public SortedSet<T> headSet(T toElement) {
        if (elements.size() == 0) {
            return new ArraySet();
        }
        return subSet(elements.get(0), toElement);
    }

    @Override
    @SuppressWarnings("unchecked")
    public SortedSet<T> tailSet(T fromElement) {
        if (elements.size() == 0) {
            return new ArraySet();
        }
        return subSet(fromElement, true, elements.get(elements.size() - 1), true);
    }

    @Override
    public T first() {
        if (elements.size() == 0) {
            throw new NoSuchElementException();
        }
        return elements.get(0);
    }

    @Override
    public T last() {
        if (elements.size() == 0) {
            throw new NoSuchElementException();
        }
        return elements.get(elements.size() - 1);
    }

    @Override
    public int size() {
        return elements.size();
    }

    public static void main(String[] args) {
        /*List<Integer> list = new ArrayList<Integer>();
        list.add(0);
        list.add(3);
        list.add(2);
        ArraySet<Object> set = new ArraySet(list, (o1, o2) -> ((Comparable) o1).compareTo(o2));
        System.out.println(set.lower(2));
        System.out.println("Done!");*/
    }
}
