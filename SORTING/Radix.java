public static void radixSort(int[] arr) {
      
    int max = Integer.MIN_VALUE;
    for (int i : arr)
        max = Math.max(max, i);
    int exp = 1;
    while (exp <= max) {
        countSort(arr, exp);
        exp *= 10;
    }
  }

  public static void countSort(int[] arr, int exp) {
    
    int n = arr.length;
    int freq[] = new int[10];
     
    for (int i=0; i<n; ++i) 
        ++freq[arr[i] / exp % 10];
      
    for (int i=1; i<10; ++i) 
        freq[i] += freq[i-1];
        
    int ans[] = new int[n];
    for (int i=n-1; i>=0; --i) {
        int idx = freq[arr[i]/ exp % 10];
        --idx;
        ans[idx] = arr[i];
        --freq[arr[i] / exp % 10];
    }
      
    for (int i=0; i<n; ++i)
        arr[i] = ans[i];