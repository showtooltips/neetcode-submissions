class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int total_score = 0;

        for (size_t i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int last = scores.top();
                scores.pop();
                int second_to_last = scores.top();
                scores.push(last);
                total_score += (last + second_to_last);
                scores.push(last + second_to_last);
            } else if (operations[i] == "D") {
                total_score += scores.top() * 2;
                scores.push(scores.top() * 2);
            } else if (operations[i] == "C") {
                total_score -= scores.top();
                scores.pop();
            } else {
                int int_value = stoi(operations[i]);
                scores.push(int_value);
                total_score += int_value;
            }
        }
        return total_score;
    }
};