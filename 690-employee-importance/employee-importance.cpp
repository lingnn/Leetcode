/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> q;
        q.push(id);

        int total = 0;

        while (!q.empty()) {
            int currentId = q.front();
            q.pop();

            for (Employee* employee : employees) {
                if (employee->id == currentId) {

                    total += employee->importance;

                    for (int subId : employee->subordinates) {
                        q.push(subId);
                    }

                    break;
                }
            }
        }

        return total;
    }
};