public static void bubble (int[] a) {
	int n = a.length;
	for (int i=1; i<n; ++i) {
		for (int j=0; j<n-i; ++j) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}