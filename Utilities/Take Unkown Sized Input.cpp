vll takeUnkownInput(){
    vll v;
    string s;
    ll data;
    getline(cin, s);
    istringstream iss(s);
    while (iss >> data)
          v.push_back(data);

    return v;
}
