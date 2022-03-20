class Solution {
public:
    string makeEven(string s, int &step){
    if(s[s.size()-1] == '0' || s.size()==1) return s;
    
    step++;

    int i = s.size()-1;
    while(i >= 0){
        if(s[i] == '1'){
            s[i] = '0';
        }
        else{
            s[i] = '1';
            break;
        }
        i--;
    }
    if(i < 0){
        s = '1' + s;
    }
   
    return s;
}

int numSteps(string s) {
    if(s.size()==1) return 0;
    
    int step = 0;

    s = makeEven(s, step);

    while(s.size()>1){
		//providing s.size()-1 as length to substr function means right- shifting by 1.
        s = makeEven(s.substr(0, s.size()-1), step);
        step++;
    }
    
    return step;
}

};
// 278675673186014705
// 278675673186014720