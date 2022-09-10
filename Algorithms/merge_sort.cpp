const int N = 1e5 + 5;
int n, a[N];

void merge (int l, int m, int r) {
   int n1 = m - l + 1;
   int n2 = r - m;
   int t1[n1], t2[n2];
   for (int i = 0; i < n1; i++) {
      t1[i] = a[l + i];
   }
   for (int i = 0; i < n2; i++) {
      t2[i] = a[m + 1 + i];
   }
   int i = 0, j = 0, k = l;
   while (i < n1 && j < n2) {
      if (t1[i] <= t2[j]) {
         a[k++] = t1[i];
         i++;
      } else {
         a[k++] = t2[j];
         j++;
      }
   }
   while (i < n1) {
      a[k++] = t1[i];
      i++;
   }
   while (j < n2) {
      a[k++] = t2[j];
      j++;
   }
}

void merge_sort(int l, int r) {
   if (l >= r) {
      return;
   }
   int m = l + (r - l) / 2;
   merge_sort(l, m);
   merge_sort(m + 1, r);
   merge(l, m, r);
}