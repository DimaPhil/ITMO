public class ArrayDequeADT {
    private Object[] elements = new Object[2];
    private int start = 0, end = 0;
    private int size = 0;

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
    public static void addFirst(ArrayDequeADT deque, Object o) {
        deque.ensureCapacity(deque);
        ++deque.size;
        deque.elements[deque.end] = o;
        deque.end = next(deque.end, deque.elements.length);
    }
    //post: Object o was pushed to the begin of deque: size = size' + 1, end = end' + 1, e_(end - 1) = o, e_i = e'_i for i = start'..end' - 1

    //pre: !isEmpty(), e'_start', ..., e'_(end' - 1)
    public static Object removeFirst(ArrayDequeADT deque) {
        assert !deque.isEmpty(deque);
        --deque.size;
        int last = prev(deque.end, deque.elements.length);
        Object result = deque.elements[last];
        deque.elements[last] = null;
        deque.end = last;
        return result;
    }
    //post: result = e'_(end' - 1), size = size' - 1, e_i = e'_i for i = start'..end' - 1

    //pre: !isEmpty()
    public static Object peekFirst(ArrayDequeADT deque) {
        assert !deque.isEmpty(deque);
        return deque.elements[prev(deque.end, deque.elements.length)];
    }
    //post: result = object at the begin of deque
    
    //pre: e'_start', ..., e'_(end' - 1)
    public static void addLast(ArrayDequeADT deque, Object o) {
        deque.ensureCapacity(deque);
        ++deque.size;
        deque.start = prev(deque.start, deque.elements.length);
        deque.elements[deque.start] = o;
    }
    //post: Object o was pushed to the end of deque: size = size' + 1, start = start' - 1, e_start = o, e_i = e'_i for i = start'..end' - 1

    //pre: !isEmpty(), e'_start', ..., e'_(end' - 1)
    public static Object removeLast(ArrayDequeADT deque) {
        assert !deque.isEmpty(deque);
        --deque.size;
        Object result = deque.elements[deque.start];
        deque.elements[deque.start] = null;
        deque.start = next(deque.start, deque.elements.length);
        return result;
    }
    //post: result = e'_start, size = size' - 1, e_i = e'_i for i = next(start')..end' - 1

    //pre: !isEmpty()
    public static Object peekLast(ArrayDequeADT deque) {
        assert !deque.isEmpty(deque);
        return deque.elements[deque.start];
    }
    //post: result = object at the end of deque

    //pre:
    public static int size(ArrayDequeADT deque) {
        return deque.size;
    }
    //post: result = size of deque     

    //pre:
    public static boolean isEmpty(ArrayDequeADT deque) {
        return deque.size == 0;
    }
    //post: result = is deque empty or not

    //pre: 
    private static void ensureCapacity(ArrayDequeADT deque) {
        if (deque.end == deque.start && deque.size > 0) {
            Object[] e = new Object[2 * deque.elements.length];
            int p = 0;
            e[p++] = deque.elements[deque.start];
            for (int i = next(deque.start, deque.elements.length); i != deque.end; i = next(i, deque.elements.length)) {
                e[p++] = deque.elements[i];
            }
            assert deque.size == p;
            deque.start = 0;
            deque.end = deque.size;
            deque.elements = e;
        }
    }
    //post: if deque is full, it's size multiplies by 2, all elements moves at the begin
}