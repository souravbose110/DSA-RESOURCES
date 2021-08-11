public static void select (int[] a) {
	int n = a.length;
	for (int i=1; i<n; ++i) {
		for (int j=i-1; j>=0; --j) {
			if (a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
			else
				break;
		}
	}
}