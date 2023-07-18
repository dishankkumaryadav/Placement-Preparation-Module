int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	if(m == 0)
		return 0;
	if(m>n)
		return -1;

	int count = 0;
	for(int i=0; i< n; i++){
		if(s[i] == p[0]){
			if(s.substr(i, m) == p)
				count++;
		}
	}
	return count;
}