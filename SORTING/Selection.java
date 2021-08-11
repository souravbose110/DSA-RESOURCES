public static void select (int[] a) {
	int n = a.length;
	for (int i=0; i<n; ++i) {
		int min = i;
		for (int j=i+1; j<n; ++j) {
			if (a[min] > a[j])
				min = j;
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}