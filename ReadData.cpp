vector<string> input(string input){
	vector<string> v;
	string para, l;
	ifstream file(input);

	if(file.is_open()){
		//read file one paragraph at a time (delimiter used = '\n')
		//for each paragraph is tokenized (as a vector of strings) into sentences separated by full stops (.)
		while(getline(file, para, '\n')){
			int len = para.length();
			//para with len>0
			if(len){
				//start index of a sentence
				int start = 0;
				//traversing the paragraph
				for(int i=0;;i++){
					//last character 
					if(i==len-1){
						if(para[i]!='.') v.push_back(para.substr(start, i-start+1));
						else v.push_back(para.substr(start, i-start));
						break;
					}
					//breaks sentences on full stops
					if(para[i]=='.'){
						//checks if '.' is a decimal pt
						if(isdigit(para[i+1]) && isdigit(para[i-1])) continue;
						v.push_back(para.substr(start, i-start));
						start = (para[i+1] == ' ' ? i+2 : i+1);
					}
				}

			}
		}
		file.close();
	}

	else cout<<"Error opening file"<<endl;

	return v;
}