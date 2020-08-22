//calculates and returns tf(term frequncy) of a string
map<string, int> tfCalc(string s){
	map<string, int> tf;
		
	string curr_word;
    stringstream iss(s);  
        
    while(iss >> curr_word){
       	if (tf.find(curr_word) == tf.end()) tf[curr_word] = 1;
		else tf[curr_word]++;
    }

    return tf;
}

//calculates Cosine Similarity of two strings
double csStrings(string s1, string s2){
	
	if(s1.size()==0 or s2.size()==0) return 0.0;

	map<string, int> tf1 = tfCalc(s1);
	map<string, int> tf2 = tfCalc(s2);

	//set of words in s1 U s2
	set<string> vocab;

	for(auto i:tf1) vocab.insert(i.first);
	for(auto i:tf2) vocab.insert(i.first);

	//vectors of s1, s2
	vector<int>v1(vocab.size(), 0);
	vector<int>v2(vocab.size(), 0);

	set<string> :: iterator it;

	int i=0;

	for(it = vocab.begin(); it != vocab.end(); ++it) 
    { 
        if(tf1.find(*it) != tf1.end()) v1[i] = tf1[*it];
		if(tf2.find(*it) != tf2.end()) v2[i] = tf2[*it];
		i++;
    }

    double res = 0.0;
    int num = 0, abs1 = 0, abs2=0;

    //res = cos(angle(v1, v2)) = (v1.v2)/(||v1||+||v2||)
    for(int i=0;i<vocab.size();i++){
    	num+=(v1[i]*v2[i]);
    	abs1+=pow(v1[i], 2);
    	abs2+=pow(v2[i], 2);
    }

    res = num/(sqrt((double)abs1)+sqrt((double)abs2));

   	return res;
}


//normalises L (axis = 0)
void normalise(vector<vector<double> > &L, int n){	
	for(int i=0;i<n;i++){
		double sum = 0.0;
		for(int j=0;j<n;j++) sum+=L[j][i];
		for(int j=0;j<n;j++) L[j][i]/=sum;
	}
}

//return matrix L(nxn) containing similarity grid/graph
vector<vector<double> > SentenceSimilarity(const vector<string> &v){
	int n = v.size();
	double temp;
	//initialise matrix L with 1s
	vector<vector<double> > L(n , vector<double> (n, 1));
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			temp = csStrings(v[i], v[j]);
			L[i][j] = temp;
			L[j][i] = temp;
		}
	}

	normalise(L, n);
	return L;
}