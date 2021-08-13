public static int[] swap(int a[], int l, int r) {
        
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        return a;
    }
    
public static int[] reverse(int a[], int l, int r) {
        
    while (l < r) {
        int temp = a[l];
        a[l++] = a[r];
        a[r--] = temp;
    }
    return a;
}
    
public static boolean next_permutation(int a[]) {
        
    if (a.length <= 1)
        return false;
    int l = a.length - 2;
    while (l >= 0) {
        if (a[l] < a[l+1])
            break;
            --l;
    }
    if (l < 0)
        return false;
    int nextGreater = a.length - 1;
    for (int i=a.length-1; i>l; --i) {
        if (a[i] > a[l]) {
            nextGreater = i;
            break;
        }
    }
    a = swap(a, nextGreater, l);
    a = reverse(a, l+1, a.length-1);
    return true;
}