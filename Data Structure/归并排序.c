#include <stdio.h>

int data[101];
int tmp[101];

void msort(int s, int t)
{
	int mid, i, j, k;
	if (s == t)
		return;
	
	mid = (s+t)/2;
	msort(s, mid);
	msort(mid+1, t);

	i = s;
	j = mid + 1;
	k = s;
	while ( i <= mid && j <= t)
	{
		if ( data[i] <= data[j] )
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while ( i <= mid)
		tmp[k++] = data[i++];
	while ( j <= t)
		tmp[k++] = data[j++];

	for(i= s; i<=t; ++i)
		data[i] = tmp[i];
}

int main()
{
	int i, n;
	scanf("%d", &n);
	for(i=1; i<=n; ++i)
		scanf("%d", &data[i]);

	msort(1, n);

	for(i=1; i<=n; ++i)
		printf("%d  ", data[i]);
	return 0;
}