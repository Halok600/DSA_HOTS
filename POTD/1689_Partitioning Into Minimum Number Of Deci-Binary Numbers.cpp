//BRUTE FORCE APPROACH

//DELETING CHARACTER EVERY TIME

class Solution {
public:
    int minPartitions(string n) {
        int count = 0;
        while(true){
            bool change = false;
            for(char &ch : n){
                if(ch!='0'){
                    ch--;
                    change = true;
                }
                
            }
            if(!change)
                    break;
                count++;
        }
        return count;
    }
};


//OPTIMIZED SOLUTION

class Solution {
public:
    int minPartitions(string n) {
        char ans =  *max_element(n.begin(),n.end());
        return ans-'0';
    }
};