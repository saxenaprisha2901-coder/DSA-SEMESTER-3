{
    string prefix;

    cout << "Enter Prefix Expression: ";
    getline(cin, prefix);

    vector<string> tokens;
    stringstream ss(prefix);
    string token;

    while (ss >> token)
    {
        tokens.push_back(token);
    }

    stack<int> st;

    
    for (int i = tokens.size() - 1; i >= 0; i--)
    {
        token = tokens[i];

        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1))
        {
            st.push(stoi(token));
        }
        else
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            int r;

            switch (token[0])
            {
                case '+':
                    r = a + b;
                    break;

                case '-':
                    r = a - b;
                    break;

                case '*':
                    r = a * b;
                    break;

                case '/':
                    r = a / b;
                    break;

                case '^':
                    r = pow(a, b);
                    break;

                default:
                    cout << "Invalid Operator";
                    return 0;
            }

            st.push(r);
        }
    }

    cout << "Result = " << st.top() << endl;

    return 0;
}