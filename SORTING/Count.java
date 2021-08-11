public static void countSort(int[] arr) {
    
    int n = arr.length;
    int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    for (int i=0; i<n; ++i) {
        max = Math.max(max, arr[i]);
        min = Math.min(min, arr[i]);
    }

    int range = max - min + 1;
    int freq[] = new int[range];
     
    for (int i=0; i<n; ++i) 
        ++freq[arr[i] - min];
      
    for (int i=1; i<range; ++i) 
        freq[i] += freq[i-1];
        
    int ans[] = new int[n];
    for (int i=n-1; i>=0; --i) {
        int idx = freq[arr[i] - min];
        --idx;
        ans[idx] = arr[i];
        --freq[arr[i] - min];
    }
      
    for (int i=0; i<n; ++i)
        arr[i] = ans[i];
}