class Solution {
public:
    string numToWord(int n, string str){
        if(n==0) return "";
        string ones[20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        string tens[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

        string s = "";
        string hund = ones[n/100];
        string rest = "";
        n = n%100;
        if(n>19){
            rest = tens[n/10] + ones[n%10];
        }
        else{
            rest = ones[n];
        }
        if(hund != "")
            s = hund + "Hundred " + rest + str;
        else
            s = rest + str;
            
        return s;
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";

        string res = "";
        res += numToWord((num/1000000000), "Billion ");
        res += numToWord((num/1000000)%1000, "Million ");
        res += numToWord((num/1000)%1000, "Thousand ");
        res += numToWord(num%1000, "");
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        return res;

    }
};
