class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int p2 = 0;
        int lastServed = 0;
        queue<int> q;

        for (size_t i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }
        
        // when false, that means every student in the queue was checked for the top sandwich
        while (lastServed < q.size()) {
            if (q.front() == sandwiches[p2]) {
                q.pop();
                p2++;
                lastServed = 0;
            } else {
                lastServed++;
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};