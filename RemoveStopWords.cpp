string removeWord(string str, string word) 
{ 
	string modified_string = "", curr_word;
    stringstream iss(str);  
        while(iss >> curr_word){
        	if(curr_word!=word) modified_string+= (" " + curr_word);
        }
    if(modified_string.size()) modified_string = modified_string.substr(1);
    return modified_string;
}

void remove(vector<string> &f, const vector<string> &sw){
	for(int i=0;i<f.size();i++){
		for(int j=0;j<sw.size();j++) f[i] = removeWord(f[i], sw[j]);
	}
}

void removeStopWords(vector<string> &f){
	//load stopwords.txt
	string input = "stopwords.txt";
	vector<string> v;
	string line;
	ifstream file(input);
	if(file.is_open()){
		//read file one word at a time (delimiter used = '\n'); adds each word in vector of strings
		while(getline(file, line, '\n')) v.push_back(line);
		file.close();
		remove(f, v);
	}
	else cout<<"Error opening file containing stopwords"<<endl;
}