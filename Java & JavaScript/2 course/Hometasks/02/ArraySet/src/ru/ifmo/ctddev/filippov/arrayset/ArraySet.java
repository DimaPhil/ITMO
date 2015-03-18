package ru.ifmo.ctddev.filippov.arrayset;

import java.util.*;

public class ArraySet<T> extends AbstractSet<T> implements NavigableSet<T> {
    private List<T> elements;
    private Comparator<? super T> comparator;
    private boolean hasComparator = false;
    private boolean reversed = false;

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

    public ArraySet() {
        elements = new ArrayList<T>();
        comparator = null;
    }

    private ArraySet(List<T> collection, Comparator<? super T> comparator, boolean hasComparator, boolean isSorted, boolean reversed) {
        if (!isSorted) {
            Collections.sort(collection, comparator);
            this.elements = unique(collection, comparator);
        } else {
            this.elements = collection;
        }
        this.comparator = comparator;
        this.hasComparator = hasComparator;
        this.reversed = reversed;
    }

    private ArraySet(List<T> collection, Comparator<? super T> comparator, boolean hasComparator, boolean isSorted) {
        this(collection, comparator, hasComparator, isSorted, false);
    }

    private ArraySet(List<T> collection, Comparator<? super T> comparator) {
        this(collection, comparator, true, true);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Collection<T> collection, Comparator<? super T> comparator) {
        this(Arrays.asList((T[]) collection.toArray()), comparator, true, false);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Collection<T> collection) {
        this(Arrays.asList((T[]) collection.toArray()), (o1, o2) -> ((Comparable) o1).compareTo(o2), false, false);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Object[] other, Comparator<? super T> comparator) {
        this(Arrays.asList((T[]) other), comparator, true, false);
    }

    @SuppressWarnings("unchecked")
    public ArraySet(Object[] other) {
        this(Arrays.asList((T[]) other), (o1, o2) -> ((Comparable) o1).compareTo(o2), false, false);
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
        int pointer;
        boolean reversed;

        public MyIterator(boolean reversed) {
            this.reversed = reversed;
            this.pointer = reversed ? elements.size() - 1 : 0;
        }

        private void nextPointer() {
            pointer += reversed ? -1 : 1;
        }

        @Override
        public boolean hasNext() {
            return reversed ? pointer >= 0 : pointer < elements.size();
        }

        @Override
        public T next() {
            T answer = elements.get(pointer);
            nextPointer();
            return answer;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    @Override
    public Iterator<T> iterator() {
        return new MyIterator(reversed);
    }

    @Override
    public NavigableSet<T> descendingSet() {
        reversed ^= true;
        if (elements.size() == 0) {
            return new ArraySet<T>();
        }
        if (reversed) {
            return new ArraySet<T>(elements, comparator, hasComparator, true, true);
        } else {
            return new ArraySet<T>(elements, comparator, hasComparator, true, false);
        }
    }

    @Override
    public Iterator<T> descendingIterator() {
        return new MyIterator(!reversed);
    }

    private NavigableSet<T> subSet(T fromElement, boolean fromInclusive, T toElement, boolean toInclusive, boolean reversed) {
        if (reversed) {
            return headSet(toElement, toInclusive).tailSet(fromElement, fromInclusive);
        } else {
            return tailSet(fromElement, fromInclusive).headSet(toElement, toInclusive);
        }
    }

    @Override
    public NavigableSet<T> subSet(T fromElement, boolean fromInclusive, T toElement, boolean toInclusive) {
        return subSet(fromElement, fromInclusive, toElement, toInclusive, reversed);
    }

    @Override
    public NavigableSet<T> headSet(T toElement, boolean inclusive) {
        int toIndex = -1;
        if (!reversed) {
            toIndex = lessOrEqualIndex(toElement);
        } else {
            toIndex = greaterOrEqualIndex(toElement);
        }
        if (toIndex == -1) {
            return new ArraySet<T>();
        }
        if (comparator.compare(elements.get(toIndex), toElement) == 0 && !inclusive) {
            toIndex += reversed ? 1 : -1;
        }
        if (!reversed) {
            return new ArraySet<T>(elements.subList(0, toIndex + 1), comparator);
        } else {
            return new ArraySet<T>(elements.subList(toIndex, elements.size()), comparator, hasComparator, true, true);
        }
    }

    @Override
    public NavigableSet<T> tailSet(T fromElement, boolean inclusive) {
        int fromIndex = -1;
        if (!reversed) {
            fromIndex = greaterOrEqualIndex(fromElement);
        } else {
            fromIndex = lessOrEqualIndex(fromElement);
        }
        if (fromIndex == -1) {
            return new ArraySet<T>();
        }
        if (comparator.compare(elements.get(fromIndex), fromElement) == 0 && !inclusive) {
            fromIndex += reversed ? -1 : 1;
        }
        if (!reversed) {
            return new ArraySet<T>(elements.subList(fromIndex, elements.size()), comparator);
        } else {
            return new ArraySet<T>(elements.subList(0, fromIndex + 1), comparator, hasComparator, true, true);
        }
    }

    @Override
    public SortedSet<T> subSet(T fromElement, T toElement) {
        return subSet(fromElement, true, toElement, false);
    }

    @Override
    public SortedSet<T> headSet(T toElement) {
        if (elements.size() == 0) {
            return new ArraySet<T>();
        }
        if (!reversed) {
            return subSet(elements.get(0), toElement);
        } else {
            return subSet(elements.get(elements.size() - 1), toElement);
        }
    }

    @Override
    public SortedSet<T> tailSet(T fromElement) {
        if (elements.size() == 0) {
            return new ArraySet<T>();
        }
        if (!reversed) {
            return subSet(fromElement, true, elements.get(elements.size() - 1), true);
        } else {
            return subSet(fromElement, true, elements.get(0), true);
        }
    }

    @Override
    public T first() {
        if (elements.size() == 0) {
            throw new NoSuchElementException();
        }
        return reversed ? elements.get(elements.size() - 1) : elements.get(0);
    }

    @Override
    public T last() {
        if (elements.size() == 0) {
            throw new NoSuchElementException();
        }
        return reversed ? elements.get(0) : elements.get(elements.size() - 1);
    }

    @Override
    public int size() {
        return elements.size();
    }
}