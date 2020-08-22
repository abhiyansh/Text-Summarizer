// removes extra spaces
string removeExtraSpace(string s){
	string out;
	unique_copy(s.begin(), s.end(), back_insert_iterator<string>(out), [](char x, char y){ return isspace(x) && isspace(y);});
	return out;
}

// removes punctuations, special characters and digits
// converts every word to lower case
string processString(string s){
	//removes punctuations and special characters
	s.erase(remove_if(s.begin (), s.end (), ::ispunct), s.end());
	//removes digits
	s.erase(remove_if(s.begin(), s.end(), ::isdigit), s.end());
	//converts to lower case
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	//removes extra spaces
	s = removeExtraSpace(s);
	return s;
}

//iterates through each sentence
void preProcess(vector<string> &in){
	for(int i=0;i<in.size();i++) in[i] = processString(in[i]);
}