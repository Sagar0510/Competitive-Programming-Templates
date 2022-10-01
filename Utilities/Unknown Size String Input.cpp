
vector<string> takeUnkownInput(){
    vector<string> v;
    string s;
    string data;
    getline(cin, s);
    istringstream iss(s);
    while (iss >> data)
          v.push_back(data);

    return v;
}
