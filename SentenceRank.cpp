//returns list of indices to be included in the final summary
vector<unsigned int> RankSentences(const vector<vector<double> > &L, unsigned int n, int T){
	
	//initilise rank matrices r_i and r_i+1
	vector<double> r(n, 1.0/n);
	vector<double> r1(n);

	//defining threshold, current_error and damping factor d
	double thresh = 0.00001, error = 1.0, d = 0.85;
	
	//calculates the final rank vector
	while(error>thresh){
		error = 0.0;
		// d*(L.r) + (1-d)/n
		for(unsigned int i=0;i<n;i++){
			r1[i] = 0.0;
			for(unsigned int j=0;j<n;j++) r1[i] += L[i][j]*r[j] ;
			r1[i] = d*r1[i] + (1-d)/n;
			error += fabs(r1[i]-r[i]);
		}
		error/=n;
		r = r1;
	}

	//sorting the rank matrix and preserving the previous indices
	vector<unsigned int> result;
	vector<pair <double, unsigned int> > vp;
	
	for(unsigned int i=0;i<n;i++) vp.push_back(make_pair(r[i], i));
	
	sort(vp.begin(), vp.end());
	
	//storing the indices of top T ranks
	for(unsigned int i=n;i>0;i--){
		if(T-- > 0) result.push_back(vp[i-1].second);
		else break;
	}
	
	return result;	
}