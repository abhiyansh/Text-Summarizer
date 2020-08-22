//takes in the original file and indices to be included in summary
void output(vector<string>v, vector<unsigned int>indices, string address){
	sort(indices.begin(), indices.end());
	// for(int i=0;i<indices.size();i++) cout<<indices[i]<<endl;
	ofstream file(address);
	if(file.is_open()){
		for(int i=0;i<indices.size();i++) file<<v[indices[i]]<<".\n";
		file.close();
	}
}