void saveState(vector<string>v, string address){
	ofstream file(address);
	if(file.is_open()){
		for(int i=0;i<v.size();i++) file<<v[i]<<".\n";
		file.close();
	}
}