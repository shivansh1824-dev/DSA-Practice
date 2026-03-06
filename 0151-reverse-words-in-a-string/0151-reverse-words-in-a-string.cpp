class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        while(i<n && s[i]==' '){
            i++;
        } 
        while(i<n){
            if(s[i]==' ' && s[i-1]==' '){
                i++;
            }else{
                s[j++]=s[i++];
            }
        }
        if(j>0 && s[j-1]==' ') j--;
        s.resize(j);
        reverse(s.begin(),s.end());
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' ' || i==s.size()){
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }    
        return s;
    }
}; 