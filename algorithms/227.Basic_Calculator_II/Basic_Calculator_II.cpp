<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}
};
 int calculate(string s) {
    int sum = 0; 
    if(s.size() < 1) return sum; 
    int i = 0; 
    int last = 0, last_result = 1;  
    char last_operator = '+'; //remember the last operator
    int sign = 1; 
    while(i < s.size()){
        if(s[i] == ' '){++i; continue;}
        if(s[i] == '+' || s[i] == '-'){
            sum += last_result * sign;
            sign = s[i++] == '+' ? 1 : -1; 
            last_result = 1;
            last_operator = '+'; 
        }
        else if(s[i] == '/' || s[i] == '*'){
            last_operator = s[i];
            ++i; 
        }
        if(isdigit(s[i])){
            last = 0; 
            while(i < s.size() && isdigit(s[i])){
                last =  last * 10 + s[i++] - '0'; 
            }

            if(last_operator == '*') last_result *= last;
            else if(last_operator == '/') last_result /= last;
            else  last_result = last; 
        }
    }
    sum += last_result * sign;
    return sum; 
}
public class Solution {
public int calculate(String s) {
    int len;
    if(s==null || (len = s.length())==0) return 0;
    Stack<Integer> stack = new Stack<Integer>();
    int num = 0;
    char sign = '+';
    for(int i=0;i<len;i++){
        if(Character.isDigit(s.charAt(i))){
            num = num*10+s.charAt(i)-'0';
        }
        if((!Character.isDigit(s.charAt(i)) &&' '!=s.charAt(i)) || i==len-1){
            if(sign=='-'){
                stack.push(-num);
            }
            if(sign=='+'){
                stack.push(num);
            }
            if(sign=='*'){
                stack.push(stack.pop()*num);
            }
            if(sign=='/'){
                stack.push(stack.pop()/num);
            }
            sign = s.charAt(i);
            num = 0;
        }
    }

    int re = 0;
    for(int i:stack){
        re += i;
    }
    return re;
}
int main() {
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}
};
 int calculate(string s) {
    int sum = 0; 
    if(s.size() < 1) return sum; 
    int i = 0; 
    int last = 0, last_result = 1;  
    char last_operator = '+'; //remember the last operator
    int sign = 1; 
    while(i < s.size()){
        if(s[i] == ' '){++i; continue;}
        if(s[i] == '+' || s[i] == '-'){
            sum += last_result * sign;
            sign = s[i++] == '+' ? 1 : -1; 
            last_result = 1;
            last_operator = '+'; 
        }
        else if(s[i] == '/' || s[i] == '*'){
            last_operator = s[i];
            ++i; 
        }
        if(isdigit(s[i])){
            last = 0; 
            while(i < s.size() && isdigit(s[i])){
                last =  last * 10 + s[i++] - '0'; 
            }

            if(last_operator == '*') last_result *= last;
            else if(last_operator == '/') last_result /= last;
            else  last_result = last; 
        }
    }
    sum += last_result * sign;
    return sum; 
}
public class Solution {
public int calculate(String s) {
    int len;
    if(s==null || (len = s.length())==0) return 0;
    Stack<Integer> stack = new Stack<Integer>();
    int num = 0;
    char sign = '+';
    for(int i=0;i<len;i++){
        if(Character.isDigit(s.charAt(i))){
            num = num*10+s.charAt(i)-'0';
        }
        if((!Character.isDigit(s.charAt(i)) &&' '!=s.charAt(i)) || i==len-1){
            if(sign=='-'){
                stack.push(-num);
            }
            if(sign=='+'){
                stack.push(num);
            }
            if(sign=='*'){
                stack.push(stack.pop()*num);
            }
            if(sign=='/'){
                stack.push(stack.pop()/num);
            }
            sign = s.charAt(i);
            num = 0;
        }
    }

    int re = 0;
    for(int i:stack){
        re += i;
    }
    return re;
}
int main() {
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
