vector<string> input(string input){
	vector<string> v;
	string line, l;
	ifstream file(input);

	if(file.is_open()){
		//read file one sentence at a time (delimiter used = '\n')
		//adds each sentence (separated by '.') in vector of strings
		while(getline(file, line, '\n')){
			stringstream ss(line);
        	while(getline(ss, l, '.')){
             	if(l.size()>1){
             		if(l[0]==' ') l = l.substr(1); 
             		v.push_back(l);	
             	}
        	}
		}
		file.close();
	}

	else cout<<"Error opening file"<<endl;

	return v;
}