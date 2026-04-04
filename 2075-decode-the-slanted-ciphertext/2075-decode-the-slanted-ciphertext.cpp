class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
     int col=encodedText.size()/rows;
     string res="";
     for(int i=0;i<col;i++){
        for(int j=i;j<encodedText.size();j+=col+1){
            res+=encodedText[j];
        }
     }
     while(!res.empty()&&res.back()==' ') res.pop_back();
     return res;
    }
};