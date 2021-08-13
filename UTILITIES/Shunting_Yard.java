// SHUNTING YARD IS USED TO CONVERT INFIX TO POSTFIX

public static int func(char ch) {
     
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
       return -1;
}

public static void ShuntingYard(String s) {

    char[] line = s.toCharArray();
    Stack<Character> s = new Stack<Character>();
    String ans = new String("");
    for (char c : line) {
        if (Character.isLetter(c))
            ans += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.peek() != '(')
                ans += s.pop();
            s.pop();
        }
        else {
            while (!s.empty() && func(c) <= func(s.peek()))
                    ans += s.pop();
            s.push(c);
        }
    }   
    while (!s.empty())
        ans += s.pop();
    out.println(ans);
}