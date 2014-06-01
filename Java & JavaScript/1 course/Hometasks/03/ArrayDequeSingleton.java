public class ArrayDequeSingleton {
    private static Object[] elements = new Object[2];
    private static int start = 0, end = 0;
    private static int size = 0;

    //invariant - size > 0, (end - start + elements.length) % elements.length == size

    //pre: i = [0..elemenths.length - 1]
    private static int next(int i, int n) {
        return i + 1 == n ? 0 : i + 1;
    }
    //post: result = [0..elements.length - 1], result - следующее за i по циклу

    //pre: i = [0..elements.length - 1]
    private static int prev(int i, int n) {
        return i == 0 ? n - 1 : i - 1;
    }
    //post: result = [0..elements.lengths - 1], result - перед i по циклу

    //pre: e'_start', ..., e'_(end' - 1)
    public static void addFirst(Object o) {
        ensureCapacity();
        ++size;
        elements[end] = o;
        end = next(end, elements.length);
    }
    //post: Object o was pushed to the begin of deque: size = size' + 1, end = end' + 1, e_(end - 1) = o, e_i = e'_i for i = start'..end' - 1

    //pre: !isEmpty(), e'_start', ..., e'_(end' - 1)
    public static Object removeFirst() {
        assert !isEmpty();
        --size;
        int last = prev(end, elements.length);
        Object result = elements[last];
        elements[last] = null;
        end = last;
        return result;
    }
    //post: result = e'_(end' - 1), size = size' - 1, e_i = e'_i for i = start'..end' - 1

    //pre: !isEmpty()
    public static Object peekFirst() {
        assert !isEmpty();
        return elements[prev(end, elements.length)];
    }
    //post: result = object at the begin of deque
    
    //pre: e'_start', ..., e'_(end' - 1)
    public static void addLast(Object o) {
        ensureCapacity();
        ++size;
        start = prev(start, elements.length);
        elements[start] = o;
    }
    //post: Object o was pushed to the end of deque: size = size' + 1, start = start' - 1, e_start = o, e_i = e'_i for i = start'..end' - 1

    //pre: !isEmpty(), e'_start', ..., e'_(end' - 1)
    public static Object removeLast() {
        assert !isEmpty();
        --size;
        Object result = elements[start];
        elements[start] = null;
        start = next(start, elements.length);
        return result;
    }
    //post: result = e'_start, size = size' - 1, e_i = e'_i for i = next(start')..end' - 1

    //pre: !isEmpty()
    public static Object peekLast() {
        assert !isEmpty();
        return elements[start];
    }
    //post: result = object at the end of deque

    //pre:
    public static int size() {
        return size;
    }
    //post: result = size of deque     

    //pre:
    public static boolean isEmpty() {
        return size == 0;
    }
    //post: result = is deque empty or not

    //pre: 
    private static void ensureCapacity() {
        if (end == start && size > 0) {
            Object[] e = new Object[2 * elements.length];
            int p = 0;
            e[p++] = elements[start];
            for (int i = next(start, elements.length); i != end; i = next(i, elements.length)) {
                e[p++] = elements[i];
            }
            assert size == p;
            start = 0;
            end = size;
            elements = e;
        }
    }
    //post: if deque is full, it's size multiplies by 2, all elements moves at the begin
}