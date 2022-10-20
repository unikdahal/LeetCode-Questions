class Solution {
public:
    string intToRoman(int num) {
        
        string ans="";
        
        while(num!=0){
            
            if(num>=1000){
                ans.push_back('M');
                num=num-1000;
            }else if(num>=900){
                ans.push_back('C');
                ans.push_back('M');
                num=num-900;
            }else if(num>=500){
                ans.push_back('D');
                num=num-500;
            }else if(num>=400){
                ans.push_back('C');
                ans.push_back('D');
                num=num-400;
            }else if(num>=100){
                ans.push_back('C');
                num=num-100;
            }else if(num>=90){
                ans.push_back('X');
                ans.push_back('C');
                num=num-90;
            }else if(num>=50){
                ans.push_back('L');
                num=num-50;
            }else if(num>=40){
                ans.push_back('X');
                ans.push_back('L');
                num=num-40;
            }else if(num>=10){
                ans.push_back('X');
                num=num-10;
            }else if(num>=9){
                ans.push_back('I');
                ans.push_back('X');
                num=num-9;
            }else if(num>=5){
                ans.push_back('V');
                num=num-5;
            }else if(num>=4){
                ans.push_back('I');
                ans.push_back('V');
                num=num-4;
            }else{
                ans.push_back('I');
                num--;
            }
            
            
            
        }
        return ans;
        
        
    }
};