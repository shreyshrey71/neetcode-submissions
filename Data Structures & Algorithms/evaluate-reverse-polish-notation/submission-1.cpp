class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operationStack;
        unordered_map<string, int> operationMap = {
            {"+",0},
            {"-",1},
            {"*",2},
            {"/",3}
        };
        for(string token : tokens) {
            if(operationMap.count(token)){
                int val2 = operationStack.top();
                operationStack.pop();
                int val1 = operationStack.top();
                operationStack.pop();
                switch(operationMap[token]) {
                    case 0 : {
                        operationStack.push(val1 + val2);
                        break;
                    }
                    case 1 : {
                        operationStack.push(val1 - val2);
                        break;
                    }
                    case 2 : {
                        operationStack.push(val1 * val2);
                        break;
                    }
                    case 3 : {
                        operationStack.push(val1 / val2);
                        break;
                    }
                }
            } else
                operationStack.push(stoi(token));
        }
        return operationStack.top();
    }
};
