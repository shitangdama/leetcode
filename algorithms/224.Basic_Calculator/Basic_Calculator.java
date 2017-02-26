public int calculate(String s) {
    Stack<Integer> stack = new Stack<Integer>();
    int result = 0;
    int number = 0;
    int sign = 1;
    for(int i = 0; i < s.length(); i++){
        char c = s.charAt(i);
        if(Character.isDigit(c)){
            number = 10 * number + (int)(c - '0');
        }else if(c == '+'){
            result += sign * number;
            number = 0;
            sign = 1;
        }else if(c == '-'){
            result += sign * number;
            number = 0;
            sign = -1;
        }else if(c == '('){
            //we push the result first, then sign;
            stack.push(result);
            stack.push(sign);
            //reset the sign and result for the value in the parenthesis
            sign = 1;   
            result = 0;
        }else if(c == ')'){
            result += sign * number;  
            number = 0;
            result *= stack.pop();    //stack.pop() is the sign before the parenthesis
            result += stack.pop();   //stack.pop() now is the result calculated before the parenthesis

        }
    }
    if(number != 0) result += sign * number;
    return result;
}
public int calculate(String s) {
    if(s == null)
        return 0;
    s = reform(s);
    int result = 0, num = 0, base = 1;
    for(char c: s.toCharArray())
        switch(c){
        case '+': result += num; num = 0; base = 1; break;
        case '-': result -= num; num = 0; base = 1; break;
        default: num += (c - '0') * base; base *= 10;
        }
    return result;
}

private String reform(String s) {
    StringBuilder sb = new StringBuilder();
    Stack<Boolean> stack = new Stack<>();
    stack.push(true);
    boolean add = true;
    for(char c: s.toCharArray())
        switch(c){
        case ' ': break;
        case '(': stack.push(add); break;
        case ')': stack.pop(); break;
        case '+': 
            add = stack.peek(); 
            sb.append(stack.peek() ? '+' : '-'); 
            break;
        case '-': 
            add = !stack.peek(); 
            sb.append(stack.peek() ? '-' : '+'); 
            break;
        default: sb.append(c);
        }
    if(sb.charAt(0) != '+' || sb.charAt(0) != '-')
        sb.insert(0, '+');
    return sb.reverse().toString();
}
public int calculate(String s) {
    if(s == null) return 0;

    int result = 0;
    int sign = 1;
    int num = 0;

    Stack<Integer> stack = new Stack<Integer>();
    stack.push(sign);

    for(int i = 0; i < s.length(); i++) {
        char c = s.charAt(i);

        if(c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');

        } else if(c == '+' || c == '-') {
            result += sign * num;
            sign = stack.peek() * (c == '+' ? 1: -1); 
            num = 0;

        } else if(c == '(') {
            stack.push(sign);

        } else if(c == ')') {
            stack.pop();
        }
    }

    result += sign * num;
    return result;
}