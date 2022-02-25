class Solution {
public:
    int compareVersion(string v1, string v2) {
        int p1=0,p2=0, n1=v1.size(),n2=v2.size(),cnt1=0,cnt2=0;
        
        while(p1<n1 || p2<n2){
            
            while(p1<n1 && v1[p1]!='.'){  
                cnt1=cnt1*10+v1[p1]-'0';  //store the values upto '.' in an integer variable for version 1
                p1++;
                
            }
            while(p2<n2 && v2[p2]!='.'){
                cnt2=cnt2*10+v2[p2]-'0'; //store the values upto '.' in an integer variable for version 2
                p2++;
            }
			// compare
            if(cnt1>cnt2) return 1;
            else if (cnt1<cnt2) return -1;
            
            cnt1=0; //reset the variables
            cnt2=0;
            p1++; //increase pointers for '.'
            p2++;
        }
        return 0;
        
    }
};