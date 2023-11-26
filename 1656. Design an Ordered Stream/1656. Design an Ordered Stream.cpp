class OrderedStream {
private:
    vector<string> data;
    int i,x;
public:
    OrderedStream(int n) {
        x=n;
        data.resize(n,"");
        i=1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        data[idKey-1] = value;
        if(idKey == i){
            for(int j=i-1; j<x; ++j){
                if(!data[j].empty()) ans.push_back(data[j]),i++;
                else break;
            }
        }
        return ans;
    }
};